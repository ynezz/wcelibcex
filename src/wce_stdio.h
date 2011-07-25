/* 
 * $Id: wce_stdio.h 62 2007-01-17 00:04:39Z mloskot $
 *
 * stdio.h - standard buffered input/output
 *
 * Created by Mateusz Loskot (mateusz@loskot.net)
 *
 * Copyright (c) 2006 Taxus SI Ltd.
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
 * Contact:
 * Taxus SI Ltd.
 * http://www.taxussi.com.pl
 *
 */

#include <windows.h>

#ifndef WCEEX_STDIO_H
#define WCEEX_STDIO_H    1

#if !defined(_WIN32_WCE)
# error "Only Windows CE target is supported!"
#endif


#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#ifndef BUFSIZ
#define BUFSIZ 512
#endif

#ifndef L_tmpnam
#define L_tmpnam MAX_PATH
#endif

/* Functions declarations */

int wceex_rename(const char *oldfile, const char *newfile);
int wceex_unlink(const char *filename);
int wceex_wunlink(const wchar_t *filename);
void wceex_rewind(FILE *stream);
FILE * wceex_freopen(const char *filename, const char *opentype, FILE *stream);
UINT wceex_GetTempFileNameA(LPCSTR lpPathName, LPCSTR lpPrefixString, UINT uUnique, LPSTR lpTempFileName);
DWORD wceex_GetTempPathA(DWORD ccBuffer, LPSTR lpszBuffer);
FILE * wceex_tmpfile(void);
char * wceex_tmpnam(char * result);
void wceex_perror(const char *msg);


#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* #ifndef WCEEX_STDIO_H */
