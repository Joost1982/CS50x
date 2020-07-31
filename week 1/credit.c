// Joost1982's CS50x Problem Solution - Week 1 - Credit
//
// - Prompt for input
// - Calculate checksum
// - Check for card length and starting digits
// - Print AMEX, MASTERCARD, VISA or INVALID.


#include <stdio.h>
#include <cs50.h>
void CheckNumber(long number, int length);

string OUTCOME = "INVALID\n";

int main()
{

    long kaartnummer = 0;
    int LENGTH = 0;

//input
    do
    {
        kaartnummer = get_long("Number: ");
    }
    while (kaartnummer < 0);

    //check length: only 13, 15 and 16 are OK!
    if (kaartnummer > 1000000000000 && kaartnummer < 10000000000000)
    {
        LENGTH = 13;
    }
    else if (kaartnummer > 100000000000000 && kaartnummer < 1000000000000000)
    {
        LENGTH = 15;
    }
    else if (kaartnummer > 1000000000000000 && kaartnummer < 10000000000000000)
    {
        LENGTH = 16;
    }

    if (LENGTH == 13 || LENGTH == 15 || LENGTH == 16)
    {
        CheckNumber(kaartnummer, LENGTH);
    }
    else
    {
        printf("%s", OUTCOME);
    }

}

void CheckNumber(long number, int length)
{
    long j = 1;
    long getal;
    int secondnumber = 0;
    long checksum_part1 = 0;
    long checksum_part2 = 0;

    for (int i = 0; i < length; i++)
    {
        getal = (number / j) % 10;
        j *= 10;

        // checksum
        if (i % 2 != 0)
        {

            if ((getal * 2) > 9)    // max = 18 (2 * 9)
            {
                int getalA = (getal * 2) % 10;
                int getalB = ((getal * 2) / 10) % 10;
                checksum_part1 = checksum_part1 + getalA + getalB;
            }
            else
            {
                checksum_part1 = checksum_part1 + (getal * 2);
            }
        }
        else
        {
            checksum_part2 = checksum_part2 + getal;
        }
        // check required starting numbers

        //Visa 13 or 16 digits and starts with a 4
        //Mastercard always 16 digits and start with 51, 52, 53, 54 or 55
        if (length == 13)
        {
            if (i == 12 && getal == 4)
            {
                if ((checksum_part1 + checksum_part2) % 10 == 0)
                {
                    OUTCOME = "VISA\n";
                }
            }
        }

        if (length == 16)
        {
            if (i == 14)
            {
                secondnumber = getal;
            }

            if (i == 15 && getal == 4)
            {
                if ((checksum_part1 + checksum_part2) % 10 == 0)
                {
                    OUTCOME = "VISA\n";
                }
            }

            if (i == 15 && getal == 5 && (secondnumber > 0 && secondnumber < 6))
            {
                if ((checksum_part1 + checksum_part2) % 10 == 0)
                {
                    OUTCOME = "MASTERCARD\n";
                }
            }
        }
        //American Express (always 15 digits and starts with 34 or 37)
        if (length == 15)
        {
            if (i == 13)
            {
                secondnumber = getal;
            }

            if (i == 14 && (getal == 3 && (secondnumber == 4 || secondnumber == 7)))
            {
                if ((checksum_part1 + checksum_part2) % 10 == 0)
                {
                    OUTCOME = "AMEX\n";
                }
            }
        }
    }
    printf("%s", OUTCOME);
}