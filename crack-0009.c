/* Author: *-= m4rMolek3 =-*
 * Don't steal it! Buy it!
 * Ubccre 4.5.19 (fedora rpm)
 * TEST IN PROGRESS
 * */
#include <stdio.h>
#include <stdlib.h>

/* I really want to play 8-bit music and show something very nice here...
 * Sega rulez.
 * */
int main (int argc, char **argv)
{
    if ( argc < 2 ) {
        puts ("usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen (argv[1], "r+");

    if ( fp == NULL ) {
        puts ("can't open %s\n ", argv[1]);
        return EXIT_FAILURE;
    }

    /*
     * xor al, al
     * inc al
     */
    const char magic_bytes[6] = {0x90, 0x90, 0x30, 0xc0, 0xfe, 0xc0};

    fseek (fp, 0x1054e3 + 4, SEEK_SET);
    fwrite (magic_bytes, 6, 1, fp);

    const char not_magic_bytes[13] = "            ";
    fseek (fp, 0x27ff50, SEEK_SET);
    fwrite (not_magic_bytes, 12, 1, fp);

    fclose (fp);

    return EXIT_SUCCESS;
}
