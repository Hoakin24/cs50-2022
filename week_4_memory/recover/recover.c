#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;
    const int BLOCK_SIZE = 512;
    BYTE buffer[BLOCK_SIZE];
    FILE *image_file = NULL;
    int jpgs = 0;
    char *filename = malloc(8 * sizeof(char));

    // checks if app is used correctly
    if (argc != 2)
    {
        printf("Usage: ./recover infile\n");
        return 1;
    }

    FILE *raw_file = fopen(argv[1], "r");

    // checks if file exist
    if (argv[1] == NULL || access(argv[1], F_OK))
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // read file until end
    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        // checks if jpg is found
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // checks if jpg was found before
            if (image_file != NULL)
            {
                fclose(image_file);
            }

            sprintf(filename, "%03i.jpg", jpgs);

            // increments the numbers of jpgs
            jpgs++;

            // opens a new image file for a new jpg
            image_file = fopen(filename, "w");
        }

        // write until new jpg is found
        if (image_file != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, image_file);
        }
    }

    // close files
    if (image_file != NULL)
    {
        fclose(image_file);
    }

    fclose(raw_file);

    free(filename);

}