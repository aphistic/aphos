/*

term.c - Terminal functionality

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

#include <term.h>
#include <strlib.h>

int term_current_idx = 0;

void term_init()
{
	int idx;
	for (idx = 0; idx < TERM_COUNT; idx++)
	{
		terminal_t term = terms[idx];
		term.x = 0;
		term.y = 0;
		term.rows = TERM_ROWS;
		term.cols = TERM_COLS;
	}
}

void term_cls()
{
	unsigned char * vram = (unsigned char *) VRAM;

	int idx;
	for (idx = 0; idx < TERM_COLS * TERM_ROWS * 2; idx++)
	{
		*(vram + idx) = 0;
	}

	terminal_t term = terms[term_current_idx];
	term.x = 0;
	term.y = 0;
}

void term_printchar(unsigned char c)
{
	unsigned char * vram = (unsigned char *) VRAM;

	terminal_t *term = &terms[term_current_idx];

	if (c == '\n')
	{
		term->x = 0;
		term->y++;
		return;
	}
	else if (c == '\t')
	{
		term->x += 4;
		return;
	}
	else
	{
		long offset = (term->x * 2) + (term->y * TERM_COLS * 2);
		vram[offset] = c;
		vram[offset + 1] = 0x07;

		term->x++;
	}

	if (term->x > TERM_COLS)
	{
		term->x = 0;
		term->y++;
	}
}

void term_printstr(char* msg)
{
	int len = strlen(msg);

	int idx;
	for (idx = 0; idx < len; idx++)
	{
		term_printchar(msg[idx]);
	}
}