#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)

{
    int change;
    int quarters;
    int dimes;
    int nickels;
    int pennies;
    do
    {
        float dollar = get_float("Change: ");
        change=round(dollar*100);
    }
    while (change <= 0 );
    quarters = change / 25;
    dimes = (change % 25) / 10;
    nickels = ((change % 25) % 10 / 5 );
    pennies = ((change % 25) % 10) % 5;
    printf("%d\n", quarters + dimes + nickels + pennies);
    
}