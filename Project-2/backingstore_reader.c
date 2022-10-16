/*
 * Project 5: backingstore_reader.c
 *
 * This program demonstrates how to read and print the bytes in the backing store.
 *
 * by Xiao Qin.
 */
#include <stdio.h>
#define DEBUG

/* There is no byte data type in C */
typedef unsigned char byte;

int main ( int argc, char *argv[] ) {
    const char backingstore[] = "BACKING_STORE";
  
    FILE *file;
    int i;
    int seek_position;
    fpos_t pos;
    int num_bytes_read;
    byte one_byte; 
    
    /* argc should be 3 for correct execution */
    if ( argc != 3 ) {
        /* We print argv[0] assuming it is the program name */
        printf( "usage: %s, <seek position>, <number of bytes to read>\n", argv[0]);
        return 0;
    }

    /* 
     * Convert strings into seek_position and num_bytes_read 
     * We assume argv[1] is seek_position and argv[2] is num_bytes_read
     */ 
    seek_position = atoi(argv[1]);
    num_bytes_read = atoi(argv[2]);

#ifdef DEBUG
    printf("seek_position =%d, num_bytes_read =%d\n", seek_position, num_bytes_read);
#endif
        
    file = fopen(backingstore, "r" );
        
    /* fopen returns 0, the NULL pointer, on failure */
    if ( file == 0 ) {
         printf( "Could not open file: %s.\n", backingstore);
    }
    else {
        /* SEEK_SET: reference position is the beginning of file */
        fseek(file, seek_position, SEEK_SET);
        fgetpos(file, &pos);
        printf("Reading from position: %d.\n", pos);

        /* Read and print data from backingstore */
        for (i = 0; i < num_bytes_read; i++) {
           fread(&one_byte, 1, 1, file);
           /* printf prints one byte as hex */ 
           printf("0x%x, %d", one_byte, one_byte); 
           /* 
            * Note: If one_byte's data type is int, 
            * then we have to use a bit mask: one_byte&0xFF
            */ 
        }
        printf("\n");
  
        fclose( file );
    }
}
