#include <iostream>
#include <string>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <fstream> // for file operations
using namespace std;

const int MAX_CATEGORIES = 100; // Adjust this number based on your needs

int main()
{

    // Declaring Variables
    string team_A, team_B;
    int chosenNumber, guess, totalGuesses = 0;
    int scoreA = 0, scoreB = 0;
    const int rounds = 3;
    const int maxPoints = 20;
    string categories[MAX_CATEGORIES];
    int categoryCount = 0;

    // Initialize Random Seed
    srand(time(0));

    // Introduction/Instructions
    cout << "+----- Welcome to WaveLengt! -----+\n\n";
    cout << "CIT102 Project: Wavelength Project\n\n";
    cout << "Created By: Shervin Elibox\n\n";
    cout << "Instructions:\n\n";
    cout << "Two teams compete to guess a secret number between 1-10 based on clues." << endl;
    cout << "Each team selects a guesser while the other team picks the number and gives a clue from a random category." << endl;
    cout << "The guesser ranks the clue from 1 to 10, trying to match the team's chosen number." << endl;
    cout << "This happens for 3 clues, and the average guess is calculated." << endl;
    cout<<endl;

    cout << "Press Enter to Continue...";
    cin.get(); // Wait for the User to Press Enter

    // Clearing the screen
    system("CLS");


    // Prompt Team A to select their Guesser Name
    cout << "Notice only two teams can play at a time." << endl;
    cout<<endl;
    cout<<endl;
    cout << "Team A, select your guesser: ";
    cin >> team_A;

    // Prompt Team B to select their Guesser Name
    cout << "Team B, select your guesser: ";
    cin >> team_B;


    // Reading categories from file
    ifstream inFile("Categories.txt");
    if (inFile.is_open())
    {
        string line;
        while (getline(inFile, line) && categoryCount < MAX_CATEGORIES)
        {
            categories[categoryCount++] = line;
        }
        inFile.close();
    }
    else
    {
        cout << "Unable to open file Categories.txt" << endl;
        return 1;
    }
// Clear screen
    system("CLS");

    // Main game loop
    while (scoreA < maxPoints && scoreB < maxPoints)
    {
        // Team B's turn to select a number for Team A to guess
        totalGuesses = 0;

        // Team B chooses a number
        cout << "Team B, select a random number (1-10): ";
        cin >> chosenNumber;

        // Validate chosenNumber for Team B
        while (chosenNumber < 1 || chosenNumber > 10)
        {
            cout << "Invalid number. Please select a number between 1 and 10: ";
            cin >> chosenNumber;
        }

        // Clear the screen
#ifdef _WIN32
        system("CLS");
#else
        system("clear");
#endif

        // Team A makes guesses based on clues from Team B
        cout << "Team A, it's your turn to guess based on the clues provided by Team B." << endl;
        cout<<endl;
        for (int i = 0; i < rounds; i++)
        {
            // Display random category
            string category = categories[rand() % categoryCount];
            cout << "Round " << i + 1 << ": Category - " << category << endl;

            // Prompt Team B to provide a clue
            string clue;
            cout << "Team B, provide a clue based on the number " << chosenNumber << ": ";
            cin.ignore();
            getline(cin, clue);

            // Prompt Team A's guesser to make a guess
            int guess;
            cout << "Team A Member: " << team_A << ", based on the clue \"" << clue << "\", what is your guess (between 1 and 10)?: ";

            cin >> guess;

            // Validate guess
            while (guess < 1 || guess > 10)
            {
                cout << "Invalid guess. Please guess a number between 1 and 10: ";
                cin >> guess;
            }

            totalGuesses += guess;

            system("CLS");
        }

        // Calculate the average guess for Team A
        int averageGuessA = totalGuesses / rounds;
        cout << "Average guess: " << averageGuessA << endl;

        // Calculate the difference for Team A's average guess
        int differenceA = abs(averageGuessA - chosenNumber);

        // Scoring logic based on the difference for Team A
        if (differenceA == 0)
        {
            cout << "Exact match! Team A earns 2 points." << endl;
            scoreA += 2; // Exact match, 2 points
        }
        else if (differenceA == 1)
        {
            cout << "Close match! Team A earns 1 point." << endl;
            scoreA += 1; // Close match, 1 point
        }
        else
        {
            cout << "No points earned this round." << endl;
        }

        // Team A's turn to select a number for Team B to guess
        totalGuesses = 0;

        // Team A chooses a number
        cout << "Team A, select a random number (1-10): ";
        cin >> chosenNumber;

        // Validate chosenNumber for Team A
        while (chosenNumber < 1 || chosenNumber > 10)
        {
            cout << "Invalid number. Please select a number between 1 and 10: ";
            cin >> chosenNumber;
        }

        // Clear the screen
#ifdef _WIN32
        system("CLS");
#else
        system("clear");
#endif


        // Team B makes guesses based on clues from Team A
        cout << "Team B, it's your turn to guess based on the clues provided by Team A." << endl;
        for (int i = 0; i < rounds; i++)
        {
            // Display random category
            string category = categories[rand() % categoryCount];
            cout << "Round " << i + 1 << ": Category - " << category << endl;

            // Prompt Team A to provide a clue
            string clue;
            cout << "Team A, provide a clue based on the number " << chosenNumber << ": ";
            cin.ignore();
            getline(cin, clue);

            // Prompt Team B's guesser to make a guess
            int guess;
            cout << "Team A Member: " << team_B << ", based on the clue \"" << clue << "\", what is your guess (between 1 and 10)?: ";
            cin >> guess;

            // Validate guess
            while (guess < 1 || guess > 10)
            {
                cout << "Invalid guess. Please guess a number between 1 and 10: ";
                cin >> guess;
            }

            totalGuesses += guess;

              system("CLS");
        }

        // Calculate the average guess for Team B
        int averageGuessB = totalGuesses / rounds;
        cout << "Average guess: " << averageGuessB << endl;

        // Calculate the difference for Team B's average guess
        int differenceB = abs(averageGuessB - chosenNumber);

        // Scoring logic based on the difference for Team B
        if (differenceB == 0)
        {
            cout << "Exact match! Team B earns 2 points." << endl;
            scoreB += 2; // Exact match, 2 points
        }
        else if (differenceB == 1)
        {
            cout << "Close match! Team B earns 1 point." << endl;
            scoreB += 1; // Close match, 1 point
        }
        else
        {
            cout << "No points earned this round." << endl;
        }

        // Display current scores
        cout << "Team A score: " << scoreA << endl;
        cout << "Team B score: " << scoreB << endl;
    }

    // Declare the winner
    if (scoreA >= maxPoints)
    {
        cout << "Congratulations Team A, you won the game!" << endl;
    }
    else
    {
        cout << "Congratulations Team B, you won the game!" << endl;
    }

    return 0;
}
