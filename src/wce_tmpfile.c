/*
 * $Id$
 *
 * Defines tmpfile() function.
 *
 * Copyright (c) 2009 Petr Stetiar <ynezz@true.cz>, Gaben Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation 
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom 
 * the Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH
 * THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * MIT License:
 * http://opensource.org/licenses/mit-license.php
 *
 */

#include <windows.h>
#include <wce_stdio.h>
#include <wce_stdlib.h>

/*******************************************************************************
* wceex_tmpfile - Create a temporary binary file
*
* Description:
*
*   This function creates a temporary binary file for update mode, as if by
*   calling fopen with mode "wb+". The file is deleted automatically when it
*   is closed or when the program terminates. (On some other ISO C systems the
*   file may fail to be deleted if the program terminates abnormally).
*
*
* Reference:
*
*   The GNU C Library Manual
* 
*******************************************************************************/
FILE * wceex_tmpfile(void)
{
	char *filename = NULL;
	wchar_t wpath[MAX_PATH+1] = {0};
	wchar_t wfilename[MAX_PATH+1] = {0};
	static char buf[L_tmpnam+1] = {0};
	FILE *ret;

	GetTempPath(MAX_PATH, wpath);
	GetTempFileName(wpath, L"_", 0, wfilename);
	filename = wceex_wcstombs(wfilename);

	ret = fopen(filename, "wb+");
	free(filename);
	return ret;
}
