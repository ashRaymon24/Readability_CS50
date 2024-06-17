#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int get_letters(string instring) //calculates the number of letters in a given string
{
    int length = strlen(instring);
    int temp = 0;
    int lcount = 0;
    for (int i = 0; i < length; i++) //validates each item in the string to check whether it is a letter or not using ASCII
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
    //counts the number of spaces within the string which is equal to the number of words + 1
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
    //counts the number of sentences by counting the number of full stops, exclamation marks and question marks
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
    l = ((float) letternum / (float) wordnum) * 100.0; //calculates the average number of letters per 100 words
    s = ((float) sentnum / (float) wordnum) * 100.0; //calculates the average number of sentences per 100 words
    index = (0.0588 * l) - (0.296 * s) - 15.8; //uses the Coleman-Liau index to calculate the reading level
    int grade = roundf(index); //rounds the value from the index to get a grade value
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
