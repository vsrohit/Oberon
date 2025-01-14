#ifndef _OBX_IN_
#define _OBX_IN_

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

#include "OBX.Runtime.h"

extern int In$Done;

//PROCEDURE Open;
extern void In$Open();

//PROCEDURE Char (VAR ch: CHAR);
extern void In$Char(char* ch);
//PROCEDURE Int (VAR i: INTEGER);
extern void In$Int(int32_t* i);
extern void In$LongInt(int64_t* i);
//PROCEDURE Real (VAR x: REAL);
extern void In$Real(float* x);
extern void In$LongReal(double* x);
//PROCEDURE String (VAR str: ARRAY OF CHAR);
extern void In$String(struct OBX$Array$1 str);
//PROCEDURE Name (VAR name: ARRAY OF CHAR);
extern void In$Name(struct OBX$Array$1 name);

extern void In$init$();
extern OBX$Cmd In$cmd$(const char*);

#endif
