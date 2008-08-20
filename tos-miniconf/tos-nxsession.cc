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

#include "tos-nxsession.h"
#include "tos-staff.h"
#include "Tokenizer.h"

NXSession::NXSession()
{

}

bool NXSession::parseTOSConfig(std::ifstream & in)
{
    using namespace std;    
    
    Tokenizer str;
    string token;    
    string buf;
    int counter = 0;
        
    in.seekg(0, ios::beg);
    
    str.setDelimiter("_=");

    while (getline(in, buf))
    {        
//        str.setString(buf);
//        while ((token = str.next()) != "")            
//        {
//            if 
//            ++counter;
//            cout << counter << ": " << token << endl;
//        }
        cout << buf << endl;
    }    
    return true;
}

void NXSession::buildSession()
{

}
