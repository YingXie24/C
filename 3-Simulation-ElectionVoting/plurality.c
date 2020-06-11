#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates.
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters to prompt for the candidate they want to vote for.
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    //  Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes = candidates[i].votes + 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{

    int i = 0;
    // Sort candidates array by votes. Bubble sort
    for (i = 0; i < candidate_count - 1 ; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (candidates[i].votes > candidates[j].votes)
            {
                candidate a = candidates[i];
                candidates[i] = candidates[j];
                candidates[j] = a;
            }
        }
    }

    // Print the name of candidate at the end of the array.
    printf("%s\n", candidates[candidate_count - 1].name);

    // Check for candidates with equal votes as the winner.
    int max_votes = candidates[candidate_count - 1].votes;

    for (int k = 0; k < candidate_count - 1; k++)
    {
        if (candidates[k].votes == max_votes)
        {
            printf("%s\n", candidates[k].name);
        }
    }
    return;
}