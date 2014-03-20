/*

kernel.c - Main kernel entry point

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

#include <multiboot.h>
#include <stdlib.h>
#include <term.h>

void kmain(void* mbd, unsigned int magic)
{
	if (magic != 0x2BADB002)
	{
		/* Something very bad happened */
		return;
	}

	multiboot_info_t *mbi = mbd;

	term_init();
	term_cls();

	printk("12345678901234567890123456789012345678901234567890123456789012345678901234567890a");
	printk("a\np\nh\no\ns\n");
	//printk("a\np\nh\no\ns\n");
	//printk("a\np\nh\no\ns\n");
	//printk("a\np\nh\no\ns\n");
	//printk("a\np\nh\no\ns\n");
	//printk("a\np\nh\no\ns\n");
	//printk("a\np\nh\no\ns\n");
	//printk("a\np\nh\no\ns\n");
	//term_scrollbuffer(1);

	/*term_printchar('T');
	term_printchar('e');
	term_printchar('s');
	term_printchar('t');
	term_printchar('!');

	term_printstr("test\ntest2\ttest3");*/
}
