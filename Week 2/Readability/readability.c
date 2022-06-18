#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
    // Initialise Variables
    string text = get_string("Text: ");
    int letters = 0;
    int words = 1;
    int sentence = 0;
    int len=strlen(text);
    for (int i = 0; i<len; i++) // Loop to determine letters, words and sentences
    {
       if ((text[i]>='a'&& text[i]<='z') || (text[i] >= 'A' && text[i]<='Z'))
       {
           letters++;
       }
       else if (text[i] == ' ')
       {
           words++;
       }
       else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
       {
           sentence++;
       }
    }
    float L = (100 * (float) letters / (float) words);
    float S = (100 * (float) sentence / (float) words);
    float grade = 0.0588 * L - 0.296 * S - 15.8; //Coleman-Liau Index Formula
    if (grade < 16 && grade >= 0) // If condition for grades 1 to 15
    {
        printf("Grade %i\n", (int) round(grade));
    }
    else if (grade >= 16) // For 16 and above
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n"); // For less than 1
    }

}