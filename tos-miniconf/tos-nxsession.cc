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

#include "Tokenizer.h"
#include "tos-staff.h"

NXSession::NXSession()
{

}

bool NXSession::parseTOSConfig(std::ifstream & in)
{
    using namespace std;

    Tokenizer str;
    string token;
    string value;
    string buf;
    string pattern;
    string test;

    in.seekg(0, ios::beg);

    while (!in.eof())
    {
        getline(in, buf);
        if (startsWith(buf, "SESSION"))
        {
            str.set(buf, "=");
            pattern = str.next();
            token = pattern;
            value = str.next();

            if ((token == pattern) && (upperCase(value) == "NX"))
            {
                getline(in, buf);
                str.set(buf, "_=");
                pattern = str.next();
                pattern += "_";
                pattern += str.next();
                pattern += "_";
                pattern += str.next();

                str.setDelimiter("=");
                token = str.next();
                value = str.next();
                theNXStruct.theTitle = value; // There is we have value of SESSION_XX_TITLE

                if (token == pattern)
                {
                    // This block for build SESSION_XX_NX pattern
                    getline(in, buf);
                    str.set(buf, "_=");
                    pattern = str.next();
                    pattern += "_";
                    pattern += str.next();
                    pattern += "_";
                    pattern += str.next();
                    theNXStruct.theSession = pattern;
                    size_t pattern_size = pattern.size();
                    ++pattern_size;

                    // This loop for extrating options and values
                    // of current session
                    while (startsWith(buf, pattern))
                    {
                        test = buf;
                        test.erase(0, pattern_size);
                        str.set(test, "=");
                        token = str.next();
                        value = str.next();
                        str.set(token, "_");
                        theNXStruct.theGroup = this->upperCaseNX(str.next());
                        token = replaceAll(token, "_", " ");
                        token.erase(0, theNXStruct.theGroup.size() + 1);
                        theNXStruct.theOptionKey = this->upperCaseNX(token);
                        theNXStruct.theValue = value;
                        theNXStructArray.push_back(theNXStruct);
                        getline(in, buf);
                    }
                }
            }
        }
    }
    return true;
}

void NXSession::buildSession()
{
    using namespace std;

    ofstream out;
    
    string nxsession;
    string currnxsession;
    string nxtitle;
    string currnxtitle;
    string nxgroup;
    string currnxgroup;

    bool flag = false;

    size_t end = theNXStructArray.size();    
    size_t i = 0;
    while (i < end)
    {
        flag = false;
        nxtitle = this->nxtrim(theNXStructArray[i].theTitle);
        nxtitle += ".nxs";

        if (currnxtitle != nxtitle)
        {
            // create new nx file;
            string nxfile("/home/termos/.nx/config/" + nxtitle);

            // USE THIS ONLY FOR TESTING!!!
            //string nxfile("/home/maxim/NetBeansProjects/tos-miniconf/" + nxtitle);

            out.open(nxfile.c_str());
            assure (out, nxfile.c_str());
            out << "<!DOCTYPE NXClientSettings>" << endl;
            out << "<NXClientSettings application=\"nxclient\" version=\"1.3\" >" << endl;
            currnxtitle = nxtitle;
        }

        nxsession = theNXStructArray[i].theSession;
        currnxsession = nxsession;
        while (currnxsession == nxsession && i < end)
        {
            nxgroup = theNXStructArray[i].theGroup;

            if (currnxgroup != nxgroup && flag)
            {
                out << "</group>" << endl;
                flag = false;
            }

            if (currnxgroup != nxgroup && !flag)
            {
                out << "<group name=\""
                        << nxgroup
                        << "\" >" << endl;
                currnxgroup = nxgroup;
                flag = true;
            }

            out << "<option key=\""
                    << theNXStructArray[i].theOptionKey
                    << "\""
                    << " value="
                    << theNXStructArray[i].theValue
                    << " />"
                    << endl;
            
            ++i;

            if (i < end)
            {
                nxsession = theNXStructArray[i].theSession;
            }
        }
        out << "</group>" << endl;
        out << "</NXClientSettings>" << endl << flush;
        out.close();
    }
}

std::string NXSession::upperCaseNX(const std::string & s) const
{
    using namespace std;

    Tokenizer str;

    str.set(s);
    string token = str.next();
    string lower = token;

    if (lower != "VNC" && lower != "TCP" && lower != "ZLIB" && lower != "SSL" &&
            lower != "CUPSD" && lower != "JPEG" && lower != "RDP" &&
            lower != "PNG" && lower != "IPPPort" && lower != "IPPPrinting")
    {
        for (size_t i = 1; i < lower.length(); ++i)
        {
            lower[i] = tolower(lower[i]);
        }
    }

    while (token != "")
    {
        token = str.next();

        if (token != "VNC" && token != "TCP" && token != "ZLIB" &&
                token != "SSL" && token != "CUPSD" && token != "JPEG" &&
                token != "RDP" && token != "PNG" && token != "IPPPort" &&
                token != "IPPPrinting")
        {
            lower += " " + lowerCase(token);
        }
        else
        {
            lower += " " + token;
        }
    }
    return trim(lower);
}

std::string NXSession::nxtrim(const std::string & s) const
{
    using namespace std;
    if (s.length() == 0)
    {
        return s;
    }
    size_t begin = s.find_first_not_of(" \a\b\f\n\r\t\v\"");
    size_t end = s.find_last_not_of(" \a\b\f\n\r\t\v\"");
    if (begin == string::npos)
    {
        return "";
    }
    return string(s, begin, end - begin + 1);
}
