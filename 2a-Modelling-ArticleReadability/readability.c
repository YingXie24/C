// Takes a text and determines the (U.S.) grade level needed to understand the text.
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

// Declare functions
int count_letters(string user_input);
int count_words(string user_input);
int count_sentences(string user_input);

// Main function
int main(void)
{
    // Prompt for user-input string
    string s = get_string("Text: ");

    // Initialise and calculate the number of letters, words and sentences in user-input string.
    int letters = count_letters(s);
    int words = count_words(s);
    int sentences = count_sentences(s);

    // Calculate Coleman-Liau index.
    // First, calculate L. L is the average number of letters per 100 words in the text.
    float L = 100 / (float) words * letters;

    // Second, calculate S. S is the average number of sentences per 100 words in the text.
    float S = 100 / (float) words * sentences;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    //Print grade
    int grade = round(index);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}



// Function to count number of letters, not including spaces and punctuations.
int count_letters(string user_input)
{

    int input_length = strlen(user_input);
    int letter_counter = 0;
    for (int i = 0; i < input_length; i++)
    {
        if isalnum(user_input[i])
        {
            letter_counter++;
        }
    }
    return letter_counter;
}

// Function to count the number of words.
int count_words(string user_input)
{
    int space_counter = 0;
    int input_length = strlen(user_input);
    for (int i = 0; i < input_length; i++)
    {
        if isspace(user_input[i])
        {
            space_counter++;
        }
    }
    return space_counter + 1;
}

// Function to count the number of sentences
int count_sentences(string user_input)
{
    int sentence_counter = 0;
    int input_length = strlen(user_input);
    for (int i = 0; i < input_length; i++)
    {
        if (user_input[i] == '.' || user_input[i] == '?' || user_input[i] == '!')
        {
            sentence_counter++;
        }
    }
    return sentence_counter;
}