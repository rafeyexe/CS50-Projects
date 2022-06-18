#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    int key;
    if (argc != 2)
    {
        printf("Incorrect key. Rerun prorgam and enter a single value key.\n");
        return 1;
    }
    else
    {
        //Turn key into an integer
        key = atoi(argv[1]);
        printf("Your selected shift key is: %i\n", key);
    }

    //Input text to encrypt
    string plaintext = get_string("plaintext: ");

    //Encrypt while preserving cases and numbers
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (islower(plaintext[i]))
            {
                //For preserving case and numbers
                printf("%c", (((plaintext[i] + key) - 97) % 26) + 97);
            }
            if (isupper(plaintext[i]))
            {
                printf("%c", (((plaintext[i] + key) - 65) % 26) + 65);
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }

    }
    printf("\n");

    return 0;
}