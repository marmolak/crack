/* Author: marmolak (dark side of me) */
/* Ubccre 3.3.7 */
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

    char jmp[2] = { 0x0f, 0x84  };
    char nops[6] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90};

    // 0x42e855
    fseek (fp, 0x0002e850 + 5, SEEK_SET);
    fwrite (nops, 6, 1, fp);

    // 0x42fa64
    fseek (fp, 0x0002fa60 + 2, SEEK_SET);
    fwrite (jmp, 2, 1, fp);

    // 0x42fb82
    fseek (fp, 0x0002fb80 + 2, SEEK_SET);
    fwrite (jmp, 2, 1, fp);

    fseek (fp, 0x0002fca0 + 2, SEEK_SET);
    fwrite (jmp, 2, 1, fp);


    fseek (fp, 0x000345a0, SEEK_SET);
    fwrite (nops, 2, 1, fp);
    fclose (fp);

    return EXIT_SUCCESS;
}
