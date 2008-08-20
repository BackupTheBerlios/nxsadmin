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

    while (getline(in, buf))
    {
        option = buf.substr((buf.find("=") + 1), buf.size());
        optionName = buf.substr(0, buf.find("="));
        
        if (optionName == "SCREEN_RESOLUTION" && option != "")
        {            
           opts.SCREEN_RESOLUTION = option;
        }
        if (optionName == "SCREEN_COLOR_DEPTH" && option != "")
        {
            opts.SCREEN_COLOR_DEPTH = option;
        }
        if (optionName == "SCREEN_BLANK_TIME" && option != "") 
        {
            opts.SCREEN_BLANK_TIME = option;
        }
        if (optionName == "SCREEN_STANDBY_TIME" && option != "")
        {
            opts.SCREEN_STANDBY_TIME = option;
        }
        if (optionName == "SCREEN_SUSPEND_TIME" && option != "")
        {
            opts.SCREEN_SUSPEND_TIME = option;
        }
        if (optionName == "SCREEN_OFF_TIME" && option != "")
        {
            opts.SCREEN_OFF_TIME = option;
        }
        if (optionName == "MOUSE_PROTOCOL" && option != "")
        {
            opts.MOUSE_PROTOCOL = option;
        }
        if (optionName == "MOUSE_DEVICE" && option != "")
        {
            opts.MOUSE_DEVICE = option;
        }
        if (optionName == "MOUSE_RESOLUTION" && option != "")
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
  
//    ifstream in("/etc/X11/xorg.conf.tpl");
    ifstream in("/home/tester/NetBeansProjects/tos-miniconf/dist/Debug/GNU-Linux-x86/xorg.conf.tpl");
//    assure(in, "/etc/X11/xorg.conf.tpl");
    assure(in, "/home/tester/NetBeansProjects/tos-miniconf/dist/Debug/GNU-Linux-x86/xorg.conf.tpl");

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

//    ofstream out("/etc/X11/xorg.conf");
    ofstream out("/home/tester/NetBeansProjects/tos-miniconf/dist/Debug/GNU-Linux-x86/xorg.conf");
    out << s2 << flush;
    out.close();
}
