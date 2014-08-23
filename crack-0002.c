/* Author: m4rm0l4k (the dark side of my mind) */
/* Ubccre 3.4.1-1 (f20) */
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

    fseek (fp, 0x00030c25, SEEK_SET);
    fwrite (jmp, 2, 1, fp);

    fseek (fp, 0x00031e32, SEEK_SET);
    fwrite (jmp, 2, 1, fp);

    fseek (fp, 0x00031f52, SEEK_SET);
    fwrite (jmp, 2, 1, fp);

    fseek (fp, 0x00032072, SEEK_SET);
    fwrite (jmp, 2, 1, fp);

    fseek (fp, 0x00036970, SEEK_SET);
    fwrite (nops, 2, 1, fp);

    fseek (fp, 0x0003699d, SEEK_SET);
    fwrite (jmp, 2, 1, fp);

    fclose (fp);

    return EXIT_SUCCESS;
}
