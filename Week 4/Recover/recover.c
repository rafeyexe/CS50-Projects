#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 512
int main(int argc, char *argv[])
{
    FILE* input = fopen("card.raw", "r");
    if (input == NULL)
    {
        printf("Card.raw could not be opened\n");
        return 1;
    }
    if (argv[1]==NULL)
    {
        printf("Forsenic image not found.\n");
        return 1;
    }
    // Define buffer size, file counter, file pointer and boolean check
    unsigned char buffer[BUFFER_SIZE];
    int files = 0;
    FILE* picture = NULL;
    int foundjpg = 0;

    // itereate through blocks
    while (fread (buffer, BUFFER_SIZE, 1, input) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
        {
            if (foundjpg==1)
            {
                fclose(picture);
            }
            else
            {
                foundjpg=1;
            }
            char filename[8];
            sprintf(filename, "%03d.jpg", files);
            picture = fopen(filename, "a");
            files++;
        }
        if (foundjpg == 1)
        {
            // write 512 bytes to file once we start finding jpgs
            fwrite(&buffer, BUFFER_SIZE, 1, picture);
        }
    }
    fclose(input);
    fclose(picture);
    return 0;
}