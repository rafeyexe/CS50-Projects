#include<stdio.h>
#include<cs50.h>

int main (void)

{
    int height;
    
    do
    {
        height = get_int("Height: "); //getting input
    }
    while (height < 1 || height > 8) ;  //input parameters
    
    for (int i = 0; i < height; i++)   //nested loops for spaces and hashes
    {
        int space = (height - 1) - i;
        int hash = (i + 1) ;
        for (int s = 0; s < space; s++) //print spaces
        {
            printf(" ");
        }
        for (int h = 0; h < hash; h++) //print space
        {
            printf("#");
        }
        printf("\n");
    }

}

