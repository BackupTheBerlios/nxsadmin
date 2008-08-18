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

#include <iostream>
#include "str_tokenizer.h"

StringTokenizer::StringTokenizer(const std::string & aString, const std::string & aDelim)
{
    using namespace std;

    if (aString.empty() || aDelim.empty()) return;

    theTokenStr = aString;
    theDelim = aDelim;

    size_t curr_pos = 0;

    // this removed sequantial delimiters
    while ((curr_pos = theTokenStr.find(theDelim, curr_pos)) != string::npos)
    {
        curr_pos += theDelim.length();

        while (theTokenStr.find(theDelim, curr_pos) == curr_pos)
        {
            theTokenStr.erase(curr_pos, theDelim.length());
        }
    }

    // trims the leading and ending delimiters
    if (theTokenStr.find(theDelim, 0) == 0)
    {
        theTokenStr.erase(0, theDelim.length());
    }

    curr_pos = 0;
    if ((curr_pos = theTokenStr.rfind(theDelim)) != string::npos)
    {
        if (curr_pos != (theTokenStr.length() - theDelim.length())) return;
        theTokenStr.erase(theTokenStr.length() - theDelim.length(), theDelim.length());
    }
}

int StringTokenizer::countTokens() const
{
    using namespace std;
    
    size_t prev_pos = 0;
    int num_tokens = 0;

    if (!theTokenStr.empty())
    {
        size_t curr_pos = 0;
        while ((curr_pos = theTokenStr.find(theDelim, curr_pos)) != string::npos)
        {
            num_tokens++;
            prev_pos = curr_pos;
            curr_pos += theDelim.length();
        }
        return ++num_tokens;
    }
    return 0;
}

bool StringTokenizer::hasMoreElements() const
{
    return (this->hasMoreTokens());
}

bool StringTokenizer::hasMoreTokens() const
{
    return (theTokenStr.length() > 0);
}

std::string StringTokenizer::nextElement()
{
    return (this->nextToken(theDelim));
}

std::string StringTokenizer::nextToken()
{
    return (this->nextToken(theDelim));
}

std::string StringTokenizer::nextElement(const std::string & aDelim)
{
    return (this->nextToken(aDelim));
}

std::string StringTokenizer::nextToken(const std::string & aDelim)
{
    if (theTokenStr.empty()) return "";

    std::string tmp_str;
    size_t pos = theTokenStr.find(aDelim, 0);

    if (pos != std::string::npos)
    {
        tmp_str = theTokenStr.substr(0, pos);
        theTokenStr = theTokenStr.substr(pos + aDelim.length(),
                                         theTokenStr.length() - pos);
    }
    else
    {
        tmp_str = theTokenStr.substr(0, theTokenStr.length());
        theTokenStr = "";
    }

    return tmp_str;
}
