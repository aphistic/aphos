/*

term.h - Terminal functionality header

---

Copyright (c) 2011 Erik Davidson

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/

#ifndef TERM_H
#define TERM_H

#define VRAM 0xb8000

#define TERM_COUNT 7
#define TERM_COLS 80
#define TERM_ROWS 24

struct terminal
{
		int rows;
		int cols;
		int x;
		int y;
};
typedef struct terminal terminal_t;

terminal_t terms[TERM_COUNT];
//int term_current_idx = 0;

void term_init();
void term_cls();
void term_printchar(unsigned char c);
void term_printstr(char* msg);
void term_scrollbuffer(int lines);

#endif