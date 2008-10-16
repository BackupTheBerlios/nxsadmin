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

#include "tos-staff.h"

std::string & replaceAll(std::string & context, const std::string & from,
                         const std::string & to)
{
    using namespace std;
    size_t lookHere = 0;
    size_t foundHere;
    while ((foundHere = context.find(from, lookHere))
            != string::npos)
    {
        context.replace(foundHere, from.size(), to);
        lookHere = foundHere + to.size();
    }
    return context;
}

bool startsWith(const std::string & base, const std::string & key)
{
    return base.compare(0, key.size(), key) == 0;
}

std::string upperCase(const std::string & s)
{
    using namespace std;
    string upper(s);
    for (size_t i = 0; i < s.length(); ++i)
    {
        upper[i] = toupper(upper[i]);
    }
    return upper;
}

std::string lowerCase(const std::string & s)
{
    using namespace std;
    string lower(s);
    for (size_t i = 0; i < s.length(); ++i)
    {
        lower[i] = tolower(lower[i]);
    }
    return lower;
}

std::string trim(const std::string & s)
{
    using namespace std;
    if (s.length() == 0)
    {
        return s;
    }
    size_t begin = s.find_first_not_of(" \a\b\f\n\r\t\v");
    size_t end = s.find_last_not_of(" \a\b\f\n\r\t\v");
    if (begin == string::npos)
    {
        return "";
    }
    return string(s, begin, end - begin + 1);
}

