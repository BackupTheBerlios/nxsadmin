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

#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "tos-xconf.h"
#include "tos-sessions.h"
#include "tos-staff.h"
#include "str_tokenizer.h"

using namespace std;

int main(int argc, char** argv)
{
//    requireMinArgs(argc, 1);
//
//    ifstream in(argv[1]);
//    assure(in, argv[1]);
//
//    XorgConf xconfig;
//    if (xconfig.parseTOSConfig(in))
//    {
//        cout << "tos-miniconf: Xorg section parsed normal" << endl;
//    }
//    xconfig.buildXorgConfig();
//
//    in.close();
    
    std::string tempStr = "maxt=1";
    StringTokenizer strtok(tempStr, "=");
            
    while (strtok.hasMoreTokens())
    {
        cout << strtok.nextToken() << endl;
    }
    
    //cout << strtok.nextToken("=") << endl;

    return (EXIT_SUCCESS);
}

