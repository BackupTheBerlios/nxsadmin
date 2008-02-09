/***************************************************************************
 *   Copyright (C) 2007 by Maxim Stjazhkin                                 *
 *   maxt_t@drohobych.com.ua                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "sa_process_window.h"
//----------------------------------------------------------------------------
MyProcessWindow::MyProcessWindow()
{
    this->set_default_size(600, 400);
    this->set_position(Gtk::WIN_POS_CENTER);
    this->set_border_width(5);
    this->set_title("Processes list of user: ");
    
    theVBox = Gtk::manage(new Gtk::VBox);
    theVBox->set_spacing(10);
    this->add(*theVBox);
    
    this->createTreeView();
    
    theButtonRefresh = Gtk::manage(new Gtk::Button(Gtk::Stock::REFRESH));
    theButtonRefresh->signal_clicked().connect(sigc::mem_fun(*this,
            &MyProcessWindow::onButtonRefreshClicked));
    theButtonClose = Gtk::manage(new Gtk::Button(Gtk::Stock::CLOSE));
    theButtonClose->signal_clicked().connect(sigc::mem_fun(*this,
            &MyProcessWindow::onButtonCloseClicked));
    
    theHButtonBox = Gtk::manage(new Gtk::HButtonBox(Gtk::BUTTONBOX_END, 10));
    theHButtonBox->pack_start(*theButtonRefresh, Gtk::PACK_SHRINK, 5);
    theHButtonBox->pack_start(*theButtonClose, Gtk::PACK_SHRINK, 5);
    theVBox->pack_start(*theHButtonBox, Gtk::PACK_SHRINK, 5);
    
    this->show_all_children();
}
//----------------------------------------------------------------------------
MyProcessWindow::~MyProcessWindow()
{
    
}
//----------------------------------------------------------------------------
void MyProcessWindow::onButtonRefreshClicked()
{
    
}
//----------------------------------------------------------------------------
void MyProcessWindow::onButtonCloseClicked()
{
    this->hide();
}
//----------------------------------------------------------------------------
bool MyProcessWindow::createProcessesList(std::string & aUserName)
{
    gint result;
    std::string stdmsg;
    std::string stderr;
    std::string command("ps -U " + aUserName + " -u " + aUserName + " u");
    this->set_title(aUserName + " processes list");
    
    Gtk::TreeModel::Row row = *(theTreeModel->append());
    row[theColumns.theSelect] = true;
    
    std::string test("test");
    row.set_value(1, test);
    
    try
    {
        Glib::spawn_command_line_sync(command, &stdmsg, &stderr, &result);
    }
    catch (Glib::Exception & e)
    {
        return false;
    }
    
    // 11 columns
    // maxim     6978  0.2  2.0  31212 15764 ?        S    12:15   0:00 konsole
    std::string::iterator it = stdmsg.begin();
    while (it != stdmsg.end())
    {
        for (gint i = 1; i < 12; ++i)
        {
            std::cout << i << std::endl;
        }
        //std::cout << (*it);
        ++it;
    }
    
    return true;
}
//----------------------------------------------------------------------------
void MyProcessWindow::createTreeView()
{
    theTreeView = Gtk::manage(new Gtk::TreeView);
    theTreeModel = Gtk::ListStore::create(theColumns);
    theTreeModelSort = Gtk::TreeModelSort::create(theTreeModel);
    
    theTreeView->set_model(theTreeModelSort);
    theTreeView->append_column_editable("Select", theColumns.theSelect);
    theTreeView->append_column("USER", theColumns.theUSER);
    theTreeView->append_column("PID", theColumns.thePID);
    theTreeView->append_column("CPU", theColumns.theCPU);
    theTreeView->append_column("MEM", theColumns.theMEM);
    theTreeView->append_column("VSZ", theColumns.theVSZ);
    theTreeView->append_column("RSS", theColumns.theRSS);
    theTreeView->append_column("TTY", theColumns.theTTY);
    theTreeView->append_column("STAT", theColumns.theSTAT);
    theTreeView->append_column("START", theColumns.theSTART);
    theTreeView->append_column("TIME", theColumns.theTIME);
    theTreeView->append_column("COMMAND", theColumns.theCOMMAND);
    
    Gtk::TreeView::Column * column = theTreeView->get_column(0);
    if (column)
        column->set_sort_column(theColumns.theSelect);
    
    column = theTreeView->get_column(1);
    if (column)
        column->set_sort_column(theColumns.theUSER);
    
    column = theTreeView->get_column(2);
    if (column)
        column->set_sort_column(theColumns.thePID);
    
    column = theTreeView->get_column(3);
    if (column)
        column->set_sort_column(theColumns.theCPU);
    
    column = theTreeView->get_column(4);
    if (column)
        column->set_sort_column(theColumns.theMEM);
    
    column = theTreeView->get_column(5);
    if (column)
        column->set_sort_column(theColumns.theVSZ);
    
    column = theTreeView->get_column(6);
    if (column)
        column->set_sort_column(theColumns.theRSS);
    
    column = theTreeView->get_column(7);
    if (column)
        column->set_sort_column(theColumns.theTTY);
    
    column = theTreeView->get_column(8);
    if (column)
        column->set_sort_column(theColumns.theSTAT);
    
    column = theTreeView->get_column(9);
    if (column)
        column->set_sort_column(theColumns.theSTART);
    
    column = theTreeView->get_column(10);
    if (column)
        column->set_sort_column(theColumns.theTIME);
    
    column = theTreeView->get_column(11);
    if (column)
        column->set_sort_column(theColumns.theCOMMAND);
    
    for (guint i = 0; i < 12; ++i)
    {
        column = theTreeView->get_column(i);
        column->set_alignment(Gtk::ALIGN_CENTER);
        column->set_resizable(true);
    }
    
    theScrolledWindow = Gtk::manage(new Gtk::ScrolledWindow);
    theScrolledWindow->add(*theTreeView);
    theScrolledWindow->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    theScrolledWindow->set_shadow_type(Gtk::SHADOW_OUT);
    theVBox->pack_start(*theScrolledWindow, Gtk::PACK_EXPAND_WIDGET);
}
