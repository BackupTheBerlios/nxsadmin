/***************************************************************************
 *   Copyright (C) 2008 Computer Group "Drohobych"                         *
 *   developer@drohobych.com.ua                                            *
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

#include "tos-xconf.h"

#include "tos-staff.h"

XorgConf::XorgConf()
{
    opts.SCREEN_RESOLUTION = "800x600";
    opts.SCREEN_COLOR_DEPTH = "16";
    opts.SCREEN_BLANK_TIME = "10";
    opts.SCREEN_STANDBY_TIME = "20";
    opts.SCREEN_SUSPEND_TIME = "30";
    opts.SCREEN_OFF_TIME = "40";
    opts.MOUSE_PROTOCOL = "Microsoft";
    opts.MOUSE_DEVICE = "/dev/ttyS0";
    opts.MOUSE_RESOLUTION = "100";
}

bool XorgConf::parseTOSConfig(std::ifstream & in)
{
    using namespace std;
    string buf;
    string option;
    string optionName;
    
    in.seekg(0, ios::beg);

    while (!in.eof())
    {
        getline(in, buf);
        option = buf.substr((buf.find("=") + 1), buf.size());
        optionName = buf.substr(0, buf.find("="));
        
        if ("SCREEN_RESOLUTION" == optionName && option != "")
        {            
           opts.SCREEN_RESOLUTION = option;
        }
        if ("SCREEN_COLOR_DEPTH" == optionName && option != "")
        {
            opts.SCREEN_COLOR_DEPTH = option;
        }
        if ("SCREEN_BLANK_TIME" == optionName && option != "") 
        {
            opts.SCREEN_BLANK_TIME = option;
        }
        if ("SCREEN_STANDBY_TIME" == optionName && option != "")
        {
            opts.SCREEN_STANDBY_TIME = option;
        }
        if ("SCREEN_SUSPEND_TIME" == optionName && option != "")
        {
            opts.SCREEN_SUSPEND_TIME = option;
        }
        if ("SCREEN_OFF_TIME" == optionName && option != "")
        {
            opts.SCREEN_OFF_TIME = option;
        }
        if ("MOUSE_PROTOCOL" == optionName && option != "")
        {
            opts.MOUSE_PROTOCOL = option;
        }
        if ("MOUSE_DEVICE" == optionName && option != "")
        {
            opts.MOUSE_DEVICE = option;
        }
        if ("MOUSE_RESOLUTION" == optionName && option != "")
        {
            opts.MOUSE_RESOLUTION = option;
        }
        buf.clear();
    }
    return true;
}

void XorgConf::buildXorgConfig() const
{
    using namespace std;
  
    ifstream in("/etc/X11/xorg.conf.tpl");
    assure(in, "/etc/X11/xorg.conf.tpl");
    // USE THIS ONLY FOR TESTING!!!
    //ifstream in("/home/maxim/NetBeansProjects/tos-miniconf/xorg.conf.tpl");
    //assure(in, "/home/maxim/NetBeansProjects/tos-miniconf/xorg.conf.tpl");

    // Read entire file into string;
    ostringstream ss;
    ss << in.rdbuf();
    in.close();
    
    string s = ss.str();
    replaceAll(s, "TOS_SCREEN_BLANK_TIME", opts.SCREEN_BLANK_TIME);
    replaceAll(s, "TOS_SCREEN_STANDBY_TIME", opts.SCREEN_STANDBY_TIME);
    replaceAll(s, "TOS_SCREEN_SUSPEND_TIME", opts.SCREEN_SUSPEND_TIME);
    replaceAll(s, "TOS_SCREEN_OFF_TIME", opts.SCREEN_OFF_TIME);
    replaceAll(s, "TOS_MOUSE_PROTOCOL", opts.MOUSE_PROTOCOL);
    replaceAll(s, "TOS_MOUSE_DEVICE", opts.MOUSE_DEVICE);
    replaceAll(s, "TOS_COLOR_DEPTH", opts.SCREEN_COLOR_DEPTH);
    string s2 = replaceAll(s, "TOS_SCREEN_RESOLUTION", opts.SCREEN_RESOLUTION);

    ofstream out("/etc/X11/xorg.conf");
    assure(out, "/etc/X11/xorg.conf");    
    // USE THIS ONLY FOR TESTING!!!
    //ofstream out("/home/maxim/NetBeansProjects/tos-miniconf/xorg.conf");
    //assure(out, "/home/maxim/NetBeansProjects/tos-miniconf/xorg.conf");
    
    out << s2 << flush;
    out.close();
}

int XorgConf::getXRes() const
{
    using namespace std;
    
    string res = opts.SCREEN_RESOLUTION;
    string X = res.substr(0, res.find("x"));
    
    return (atoi(X.c_str()));        
}

int XorgConf::getYRes() const
{
    using namespace std;
    
    string res = opts.SCREEN_RESOLUTION;
    string Y = res.substr((res.find("x") + 1), res.size());
    
    return (atoi(Y.c_str())); 
}
