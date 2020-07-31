#include <stdio.h>
#include <cs50.h>

// Joost1982's CS50x Problem Set Solution - week 1
// Program asks for a name and prints a greeting with that name

int main(void)
{
    string naam = get_string("What's your name?\n");
    printf("hello, %s\n", naam);
}