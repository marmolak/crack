/* Author: -=\ marm0lak /=-
 * Don't steal it! Buy it!
/* Ubccre 3.9.4.2-1 (f20) */
#include <stdio.h>
#include <stdlib.h>

/* I really want to play 8-bit music and show something very nice here... */
int main (int argc, char **argv)
{
    if ( argc < 2 ) {
        printf ("usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen (argv[1], "r+");

    if ( fp == NULL ) {
        printf ("can't open %s\n ", argv[1]);
        return EXIT_FAILURE;
    }

    /*
     * xor al, al
     * inc al
     */
    char magic_bytes[6] = {0x90, 0x90, 0x30, 0xc0, 0xfe, 0xc0};

    fseek (fp, 0x000fd1f1, SEEK_SET);
    fwrite (magic_bytes, 6, 1, fp);


    fclose (fp);

    return EXIT_SUCCESS;
}
