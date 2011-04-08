/*

loader.s - Kernel multiboot and bootloader entry point

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

.global loader				# entry point for linker

# setting up the Multiboot header
.set ALIGN,	1<<0		# align loaded modules on page boundaries
.set MEMINFO,	1<<1		# provide the memory map
.set FLAGS,	ALIGN | MEMINFO	# this is the multiboot 'flag' field
.set MAGIC,	0x1BADB002	# 'magic number' lets bootloader find the header
.set CHECKSUM,	-(MAGIC + FLAGS)# checksum required

.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# reserve initial kernel stack space
.set STACKSIZE, 0x4000		# 16k
.comm stack, STACKSIZE, 32	# reserve 16k stack on a quadword boundary

loader:
	mov $(stack + STACKSIZE), %esp	# set up the stack
	push %eax				# Multiboot magic number
	push %ebx				# Multiboot data structure

	call 	kmain				# call kernel proper

	cli
hang:
	hlt				# halt machine should kernel return
	jmp 	hang
