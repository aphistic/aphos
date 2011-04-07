void kmain(void* mbd, unsigned int magic)
{
	if (magic != 0x2BADB002)
	{
		/* Something very bad happened */
		return;
	}

	//char * boot_loader_name = (char*) ((long*) mbd)[16];

	unsigned char *videoram = (unsigned char *) 0xb8000;
	videoram[0] = 65;
	videoram[1] = 0x07;
}
