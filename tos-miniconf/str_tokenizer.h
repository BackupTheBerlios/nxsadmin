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


// Simple string tokenizer class, that allows an application to break a
// string into tokens.
          
#ifndef _STR_TOKENIZER_H
#define	_STR_TOKENIZER_H

#include <string>

class StringTokenizer
{
public:

    StringTokenizer(const std::string & aString, const std::string & aDelim = " ");

    ~StringTokenizer()
    {
    };

    int countTokens() const;
    bool hasMoreElements() const;
    bool hasMoreTokens() const;
    std::string nextElement();
    std::string nextToken();
    std::string nextElement(const std::string & aDelim);
    std::string nextToken(const std::string & aDelim);

protected:

    StringTokenizer();

private:

    std::string theTokenStr;
    std::string theDelim;
};

#endif	/* _STR_TOKENIZER_H */

