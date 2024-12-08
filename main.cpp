#include <iostream>
#include <string>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <fstream> // for file operations

using namespace std;

// This number is based on the number of categories based on the text file.
const int max_Categories = 100;
int main()
{

    // Declaring Variables
    string team_A, team_B;
    int categoriesCount = 0;
    string categories[max_Categories];
    int team_ScoreA, team_ScoreB, selected_Number, totalGussess = 0;
    const int maxPoints = 20;
    const int rounds = 3;

    // Creating the Random Seed Generator
    srand(time(0));

    // Introduction / Instructions of the Game
    cout << "+----- Welcome to WaveLengt! -----+\n\n";
    cout << "CIT102 Project: Wavelength Project\n\n";
    cout << "Created By: Shervin Elibox\n\n";
    cout << "Instructions:\n\n";
    cout << "Two teams compete to guess a secret number between 1-10 based on clues." << endl;
    cout << "Each team selects a guesser while the other team picks the number and gives a clue from a random category." << endl;
    cout << "The guesser ranks the clue from 1 to 10, trying to match the team's chosen number." << endl;
    cout << "This happens for 3 clues, and the average guess is calculated." << endl;
    cout << endl;

    cout << "Press any Key to continue" << endl;
    cin.get();

    // Prompting team_A to Select their Guesser
    cout << "Team A select your Guesser to go Against Team B" << endl;
    cin >> team_A;

    // Place Code At Bottom
    // Prompting team_B to select their Guesser
    cout << "Team B select your Gusser to go Against Team A" << endl;
    cin >> team_B;

    // Reading the categories text file
    ifstream inFile("Categories.txt");
    if (inFile.is_open())
    {
        string line;
        while (getline(inFile, line) && categoriesCount < max_Categories)
        {

            categories[categoriesCount++] = line;
        }
        inFile.close();
    }
    else
    {
        cout << "Unable to Open the Categories.txt file " << endl;
        return 1;
    }

    // Clearing the Screen to commence game session
    system("CLS");

    // The Main Game Loop
    while (team_ScoreA < maxPoints && team_ScoreB < maxPoints)
    {

        totalGussess = 0;

        // Team B is now selecting a number for Team A
        cout << "Team B, Select a random number between (1-10): " << endl;
        cin >> selected_Number;

        // Validating the number chosen by Team

        while (selected_Number < 1 || selected_Number > 10)
        {
            cout << "Invalid number. Please select a number between 1 and 10: ";
            cin >> selected_Number;
        }

// Clearing the Screen to commence the game
#ifdef _WIN32
        system("CLS");
#else
        system("clear");
#endif
    }

    // Team A makes guesses based on the clues provided by Team B
    cout << "Team A, Its your turn to Guess" << endl;
    cout << endl;

    for (int i = 1; i < rounds; i++)
    {

        string category = categories[rand() % categoriesCount];
        cout << "Round" << i + 1 << ": Categories -" << category << endl;

        // Prompts Team B to provide a clue
        string clue;
        cout << "Team B, Please provide a clue based on the number " << selected_Number << endl;
        cin.ignore();
        getline(cin, clue);

        // Prompt Team A's Guesser to make a guess
        int Guess;
        cout << "Team A Member: " << team_A << ", based on the clue provided" << endl;
        cin >> Guess;

        // validate guess
        while (Guess < 1 || Guess > 10)
        {
            cout << "Invaild Guess. Please guess a number between (1-10)" << endl;
            cin >> Guess;
        }

        totalGussess += Guess;

        // Clearing the Screen
        system("CLS");

        // Caluclating the Average Guess for Team A
        int averageGuessA = totalGussess / rounds;
        cout << "Average guess for team a: " << averageGuessA << endl;

        // Calculate the difference for Team A's average guess
        int difference_TeamA = abs(averageGuessA - selected_Number);

        // Scoring Logic Based on the difference for Team A

        if (difference_TeamA == 0)
        {
            cout << "Exact match! Team A earns 2 points." << endl;
            team_ScoreA += 2; // Exact match, 2 points
        }
        else if (difference_TeamA == 1)
        {
            cout << "Exact match! Team A earns 2 points." << endl;
            team_ScoreA += 1; // Exact match, 2 points
        }
        else
        {
            cout << "No points earned this round." << endl;
        }

        // Team A's turn to select a number for Team B to guess
        totalGussess = 0;

        // Team A choses a Number for team B
        cout << "Team B, Select a random number between (1-10): " << endl;
        cin >> selected_Number;

        while (selected_Number < 1 || selected_Number > 10)
        {
            cout << "Invalid number. Please select a number between 1 and 10: ";
            cin >> selected_Number;
        }

        // Clearing the Screen 

        #ifdef _WIN32
        system("CLS");
        #else
        system("clear");
        #endif

        // Team B makes guesses based on the clues provided by Team A
        
    }
}
