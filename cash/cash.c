#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

// Digital camera FAT file block size: 512 Bytes
const int BLOCK_SIZE = 512;

bool has_JPEG_header(BYTE *buffer);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *inptr = fopen(argv[1], "rb");
    if (inptr == NULL)
    {
        printf("Could not read %s.\n", argv[1]);
        return 1;
    }

    BYTE *buffer = malloc(BLOCK_SIZE * sizeof (BYTE));
    if (buffer == NULL)
    {
        printf("Could not allocate memory.\n");
        return 1;
    }

    FILE *outptr = NULL;
    int img_count = 0;

    // Recover JPEGs from input file
    while (fread(buffer, 1, BLOCK_SIZE, inptr) == BLOCK_SIZE)
    {
        if (has_JPEG_header(buffer))
        {
            // Close previous file, if it exists
            if(outptr != NULL)
            {
                fclose(outptr);
            }

            // Create new file
            char filename[8]; // ###.jpg\0
            sprintf(filename, "%03i.jpg", img_count);

            outptr = fopen(filename, "wb");
            if (outptr == NULL)
            {
                printf("Could not create %s.\n", filename);
                fclose(inptr);
                free(buffer);
                return 1;
            }
            img_count++;
        }

        if (outptr != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, outptr);
        }
    }

    free(buffer);
    fclose(inptr);
    fclose(outptr);
    return 0;
}

// Check if the first 4 bytes of the buffer are the JPEG header
bool has_JPEG_header(BYTE *buffer)
{
    if (buffer[0] == 0xff &&
        buffer[1] == 0xd8 &&
        buffer[2] == 0xff &&
        (buffer[3] & 0xE0) == 0xE0)
    {
        return true;
    }
    return false;
}
