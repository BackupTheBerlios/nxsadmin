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
#include "tos-nxsession.h"
#include "tos-staff.h"

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    requireMinArgs(argc, 1);

    ifstream in(argv[1]);
    assure(in, argv[1]);

    XorgConf xconfig;
    NXSession nx;

    if (xconfig.parseTOSConfig(in))
    {
        cout << "tos-miniconf: Xorg section parsed normal" << endl;        
        in.clear(); // clear iostate of ifstream operations
    }
    xconfig.buildXorgConfig();

    if (nx.parseTOSConfig(in))
    {
        cout << "tos-miniconf: NX section parsed normal" << endl;        
        in.clear(); // clear iostate of ifstream operations
    }
    nx.buildSession(xconfig.getXRes(), xconfig.getYRes());

    in.close();

    return (EXIT_SUCCESS);
}

