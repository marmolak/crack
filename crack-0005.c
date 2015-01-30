/* Author: -=\ M4rm0l4K /=-
 * (where is my mind? WHERE IS MY OPEN MIIIIIND!) */
/* Ubccre 3.7.3 (f20) */
#include <stdio.h>
#include <stdlib.h>

/* Yeah some multicracker will be better than copy these */
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

    fseek (fp, 0x000f40dc, SEEK_SET);
    fwrite (magic_bytes, 6, 1, fp);


    fclose (fp);

    return EXIT_SUCCESS;
}
