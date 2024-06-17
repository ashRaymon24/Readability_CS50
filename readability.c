#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int get_letters(string instring)
{
    int length = strlen(instring);
    int temp = 0;
    int lcount = 0;
    for (int i = 0; i < length; i++)
    {
        temp = toupper(instring[i]);
        if ((temp >= 65) && (temp <= 90))
        {
            lcount += 1;
        }
    }
    return lcount;
}

int get_words(string istring)
{
    int length = strlen(istring);
    int temp = 0;
    int wcount = 1;
    for (int i = 0; i < length; i++)
    {
        temp = istring[i];
        if (temp == 32)
        {
            wcount += 1;
        }
    }
    return wcount;
}

int get_sent(string istring)
{
    int length = strlen(istring);
    int temp = 0;
    int scount = 0;
    for (int i = 0; i < length; i++)
    {
        temp = istring[i];
        if ((temp == 46) || (temp == 33) || (temp == 63))
        {
            scount += 1;
        }
    }
    return scount;
}

int main(void)
{
    string input = get_string("Text: ");
    float index = 0;
    float l = 0;
    float s = 0;
    int letternum = get_letters(input);
    int wordnum = get_words(input);
    int sentnum = get_sent(input);
    l = ((float) letternum / (float) wordnum) * 100.0;
    s = ((float) sentnum / (float) wordnum) * 100.0;
    index = (0.0588 * l) - (0.296 * s) - 15.8;
    int grade = roundf(index);
    if ((grade >= 1) && (grade <= 16))
    {
        printf("Grade %d\n", grade);
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}
