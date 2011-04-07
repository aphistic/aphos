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
