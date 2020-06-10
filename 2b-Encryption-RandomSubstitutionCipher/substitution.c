#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool repeating_letter(string s);

// Prompt for key in command line.
int main(int argc, string argv[])
{
    // Print error message if none, or more than one command-line argument.
    if (argc != 2)
    {
        printf("Please provide one command-line argument\n");
        return 1;
    }

    // Validate key. The key is argv[1].
    else
    {
        // Check if the key has 26 characters.
        if (strlen(argv[1]) == 26)
        {

        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

        // Check if the key contains only alphabets.
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isalpha(argv[1][i]))
            {

            }
            else
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }
        }

        // Check if there are repeating letters in the key.
        if ((int) repeating_letter(argv[1]) == 0)
        {

        }
        else
        {
            printf("Key must not contain repeated characters\n");
            return 1;
        }
    }

    // Hereon starts the process of processing the key.
    string input_key = argv[1];

    // Whether the characters in the key are uppercase or lowercase does not matter.
    // Build a full set of keys, of uppercase + lowercase. The number of letters in the key is 26, therefore double that is 52.
    char full_key[52];
    int f, k = 0;
    for (f = 0; f < 26; f++)
    {

        full_key[f] = toupper(input_key[k]);
        k = k + 1;
    }

    k = 0;
    for (f = 26; f < 52; f++)
    {
        full_key[f] = tolower(input_key[k]);
        k = k + 1;
    }

    // Prompt user for plaintext to encipher.
    string plaintext = get_string("plaintext: ");

    // Here on starts the process of encipher.
    // Calculate the length of plaintext.
    int length_plaintext = strlen(plaintext);

    // We want to preserve the case of the plaintext.
    // Create a full string (array) of english_alphabets, with the upper and lower case.
    string english_alphabets = "ABCDEFGHIJKLMNOP QRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    // Initialise the string (array) cyphertext. This will be the final output.
    char ciphertext[strlen(plaintext)];
    int c = 0;

    // Take each character in the plaintext. If the character is alphabetical, encipher. If not (space, number, punctuation), print as is.
    for (int p = 0; p < strlen(plaintext); p++)
    {

        if (isalpha(plaintext[p]))
        {
            // Compare the plaintext character with those in the english_alphabets.
            for (int e = 0; e < 52; e = e + 1)
            {
                // If matching, take the index at the english_alphabet, e.
                if (plaintext[p] == english_alphabets[e])
                {
                    // Output: Character in ciphertext. Input: Character in key, at the corresponding english_alphabet index.
                    ciphertext[c] = full_key[e];
                }
            }
        }
        else
        {
            ciphertext[c] = plaintext[p];
        }
        c = c + 1;
    }

    //Print ciphertext. Exit program.
    printf("ciphertext: ");
    for (c = 0; c < strlen(plaintext); c++)
    {
        printf("%c", ciphertext[c]);
    }
    printf("\n");
    // printf("ciphertext: %s\n", ciphertext);
    return 0;

}


// Function to determine if word contains repeating letter. True = 1, False = 0
bool repeating_letter(string s)
{
    for (int i = 0; i < strlen(s); i ++)
    {
        for (int j = i + 1; j < strlen(s); j ++)
        {
            if (s[i] == s[j])
            {
                return true;
            }
        }
    }

    return false;
}

