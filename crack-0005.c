/* Author: -=\ M4rm0l4K /=-
 * (where is my mind? WHERE IS MY OPEN MIIIIIND!) Check this bitch.. cheeeck this bitcheeees! */
/* Ubccre 3.7.3 (f20) - extended release */
#include <stdio.h>
#include <stdlib.h>

/* Yeah some multicracker will be better than copy these */
int main (int argc, char **argv)
{
    if ( argc < 2 ) {
        printf ("usage: %s executable library\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen (argv[1], "r+");

    if (fp == NULL) {
        printf ("can't open %s\n ", argv[1]);
        return EXIT_FAILURE;
    }

    FILE *fp_lib = fopen (argv[2], "r+");
    if (fp_lib == NULL) {
	fclose(fp);
        printf ("can't library open %s\n ", argv[1]);
        return EXIT_FAILURE;
    }

    /*
     * xor al, al
     * inc al
     */
    char magic_bytes[6] = {0x90, 0x90, 0x30, 0xc0, 0xfe, 0xc0};


    fseek (fp, 0x000f40dc, SEEK_SET);
    fwrite (magic_bytes, 6, 1, fp);
    fclose (fp);

    /* This allows disassembling of "protected" binaries - and yes...
     * This is not finished because author is very funny person ... */
    /* 
     * nop
     * jmp <address>
     */
    char allow_disassembling[6] = { 0x90, 0xe9, 0x8f, 0x00, 0x00, 0x00 };
    fseek (fp_lib, 0x507478, SEEK_SET);
    fwrite (allow_disassembling, 6, 1, fp_lib);
    fclose (fp_lib);

    return EXIT_SUCCESS;
}
