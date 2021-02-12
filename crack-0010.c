/* Author: *-= m4rMolek3 =-*
 * Don't steal it! Buy it!
 * Ubccre 4.7.1 (fedora rpm)
 * */
#include <stdio.h>
#include <stdlib.h>

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
    const char magic_bytes[6] = {0x90, 0x90, 0x30, 0xc0, 0xfe, 0xc0};

    fseek (fp, 0x105038 + 16, SEEK_SET);
    fwrite (magic_bytes, 6, 1, fp);

    const char not_magic_bytes[13] = "            ";
    fseek (fp,0x25A988, SEEK_SET);
    fwrite (not_magic_bytes, 12, 1, fp);

    fclose (fp);

    return EXIT_SUCCESS;
}
