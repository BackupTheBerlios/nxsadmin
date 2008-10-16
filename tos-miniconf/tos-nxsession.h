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

#ifndef _TOS_NXSESSIONS_H
#define	_TOS_NXSESSIONS_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class NXSession
{
public:

    NXSession();

    virtual ~NXSession()
    {
    };

    bool parseTOSConfig(std::ifstream & in);
    void buildSession();

private:

    std::string upperCaseNX(const std::string & s) const;
    
     // Tool to strip spaces and quotes from both ends of string
    std::string nxtrim(const std::string & s) const;
            
    typedef struct
    {
        std::string theSession;    // session identifier
        std::string theTitle;      // session title
        std::string theGroup;      // options group
        std::string theOptionKey;  // option name
        std::string theValue;      // option value
    } NXStruct;

    NXStruct theNXStruct;
    std::vector<NXStruct> theNXStructArray;
};

#endif	/* _TOS_SESSIONS_H */

