/*
* Copyright 2021 Rochus Keller <mailto:me@rochus-keller.ch>
*
* This file is part of the Oberon+ parser/compiler library.
*
* The following is the license that applies to this copy of the
* library. For a license to use the library under conditions
* other than those described here, please email to me@rochus-keller.ch.
*
* GNU General Public License Usage
* This file may be used under the terms of the GNU General Public
* License (GPL) versions 2.0 or 3.0 as published by the Free Software
* Foundation and appearing in the file LICENSE.GPL included in
* the packaging of this file. Please review the following information
* to ensure GNU General Public Licensing requirements will be met:
* http://www.fsf.org/licensing/licenses/info/GPLv2.html and
* http://www.gnu.org/copyleft/gpl.html.
*/

#include "Out.h"

void Out$Int(int64_t i, int32_t n)
{
    printf("%*lld", n, i);
}

void Out$Real(float x, int32_t n)
{
    printf("%*e", n, x);
}

void Out$LongReal(double x, int32_t n)
{
    printf("%*e", n, x);
}

void Out$Ln()
{
	printf("\n");
}

void Out$Char(char c)
{
	printf("%c", c );
}

void Out$String(const struct OBX$Array$1 str)
{
	OBX$PrintA(0,(const char*)str.$a);
}

void Out$init$()
{
}

void Out$Open()
{
}

OBX$Cmd Out$cmd$(const char* name)
{
	if(name==0) return Out$init$;
	return 0;
}
