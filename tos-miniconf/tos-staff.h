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

#ifndef _TOS_STAFF_H
#define	_TOS_STAFF_H

#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include <fstream>

inline void assure(std::ifstream & in, const char * filename = "")
{
    using namespace std;
    if (!in)
    {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
}

inline void assure(std::ofstream & in, const char * filename = "")
{
    using namespace std;
    if (!in)
    {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
}

inline void requireArgs(int argc, int args,
                        const char * msg = "Must use %d arguments")
{
    using namespace std;
    if (argc != args + 1)
    {
        fprintf(stderr, msg, args);
        fputs("\n", stderr);
        exit(EXIT_FAILURE);
    }
}

inline void requireMinArgs(int argc, int minArgs,
                           const char * msg =
                           "Must use at least %d arguments")
{
    using namespace std;
    if (argc < minArgs + 1)
    {
        fprintf(stderr, msg, minArgs);
        fputs("\n", stderr);
        exit(EXIT_FAILURE);
    }
}

std::string & replaceAll(std::string & context, const std::string & from,
                         const std::string & to);

bool startsWith(const std::string & base, const std::string & key);

#endif	/* _TOS_STAFF_H */

