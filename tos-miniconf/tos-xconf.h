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

#ifndef _TOS_XCONF_H
#define	_TOS_XCONF_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class XorgConf
{
public:

    XorgConf();

    virtual ~XorgConf()
    {
    };

    bool parseTOSConfig(std::ifstream & in);
    void buildXorgConfig() const;
    
    int getXRes() const;
    int getYRes() const;

private:

    struct Xoptions
    {
        std::string SCREEN_RESOLUTION;
        std::string SCREEN_COLOR_DEPTH;
        std::string SCREEN_BLANK_TIME;
        std::string SCREEN_STANDBY_TIME;
        std::string SCREEN_SUSPEND_TIME;
        std::string SCREEN_OFF_TIME;
        std::string MOUSE_PROTOCOL;
        std::string MOUSE_DEVICE;
        std::string MOUSE_RESOLUTION;
    } opts;
};

#endif	/* _TOS_XCONF_H */

