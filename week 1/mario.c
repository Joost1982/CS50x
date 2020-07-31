// Joost1982's CS50x Problem Solution - Week 1 - Mario
// Program ask for an int and prints out a "pyramid" with the size of the int


#include <stdio.h>
#include <cs50.h>
void Pyramid(int seize);

int main()
{
    //Ask for input / seize

    int getal;
    do
    {
        getal = get_int("Height (min 1, max: 8): ");
    }
    while (getal < 1 || getal > 8);

    //Print Pyramid

    Pyramid(getal);
}

//Pyramid implementation
void Pyramid(int seize)
{
    for (int i = 0; i < seize; i++)         // number of lines
    {

        for (int x = seize - 1 ; x > i; x--)
        {
            printf(" ");                    // whitespace in front off blocks

        }
        for (int j = -1; j < i; j++)    // blocks left side
        {
            printf("#");
        }

        printf("  ");                    // whitespace between the blocks

        for (int j = -1; j < i; j++)    // blocks right side
        {
            printf("#");
        }

        printf("\n");
    }
}

