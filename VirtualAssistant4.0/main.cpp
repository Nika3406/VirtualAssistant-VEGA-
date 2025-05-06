// Virtual Assistant V4.0 (VEGA)
// Nicholas Shvelidze, Mariami Shinjiashvili

#include <iostream>
#include <thread>
#include <chrono>
#include "basicMath.cpp"
#include "advancedMath.cpp"
#include "dataSets.cpp"
#include "converter.cpp"
#include "games.cpp"
#include "ascii_fps.cpp"
#include "arrayOperations.cpp"
#include "matrixOperations.cpp"
#include "kys.cpp"
#include "vocabQuestions.cpp"

using namespace std;

void displayTitle()
{
    cout << "\n";
    cout << " _    _   ______    ____     ____ \n";
    cout << "| |  | | |  ____| /  __  \\ /  __  \\ \n";
    cout << "| |  | | | |__    | |  |_| | |  | |\n";
    cout << "| |  | | |  __|   | |   __ | |__| |\n";
    cout << "| |__| | | |____  | |__| _||  __  |\n";
    cout << " \\____/  |______| |_____/  |_|  |_|\n";
    cout << "\n";
}

void virtualAssistant()
{
    int operation;
    do 
    {
        cout << "\nChoose an operation:\n";
        cout << "1. Basic Math Operations\n";
        cout << "2. Advanced Math Operations\n";
        cout << "3. Array Operations\n";
        cout << "4. Converter\n";
        cout << "5. Games\n";
        cout << "6. FPS Simulation\n";
        cout << "7. (Terry) Medical Assistant\n";
        cout << "8. Vocabulary Test\n";
        cout << "9. Exit to Main Menu\n";
        cout << "Enter your choice: ";

        while (!(cin >> operation) || operation < 1 || operation > 9) {
            cout << "Invalid input. Please enter a number between 1 and 9: ";
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        }

        switch (operation) 
        {
            case 1: basicMathOperations(); break;
            case 2: advancedMathOperations(); break;
            case 3:
            {
                int n;
                do {
                    cout << "\nChoose Array Operation Type" << endl;
                    cout << "1. Arithmatic Array Operations" << endl;
                    cout << "2. Matrix Array Operations" << endl;
                    cout << "3. Data Set Predictor" << endl;
                    cout << "4. Exit" << endl;
                    cout << "Enter your choice: ";

                    while (!(cin >> n) || n < 1 || n > 4) {
                        cout << "Invalid input. Please enter a number between 1 and 4: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    switch (n)
                    {
                        case 1: arrayVoid(); break;
                        case 2: matrixVoid(); break;
                        case 3: dataPredictor(); break;
                        case 4: cout << "Exiting" << endl; break;
                    }
                } while (n != 4);
                break;
            }
            case 4: converter(); break;
            case 5: games(); break;
            case 6:
            {
                cout << "Use W/A/S/D to move. Press SPACE to exit.\n";
                bool running = true;
                while (running) {
                    render();
                    this_thread::sleep_for(chrono::milliseconds(2));
                    running = update();
                }
                break;
            }
            case 7: runMentalHealthAssessment(); break;
            case 8: englishVocab(); break;
            case 9: cout << "Returning to main menu...\n"; break;
        }
    } while (operation != 9);
}

int main() 
{
    int choice;
    do 
    {
        displayTitle();
        cout << "\nHello, I am VEGA, your Virtual Assistant." << endl;
        cout << "Choose an option:\n";
        cout << "1. Start Virtual Assistant\n";
        cout << "2. Exit Program\n";
        cout << "Enter your choice: ";

        while (!(cin >> choice) || choice < 1 || choice > 2) {
            cout << "Invalid input. Please enter 1 or 2: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) 
        {
            case 1: virtualAssistant(); break;
            case 2: cout << "Exiting program. Goodbye!" << endl; break;
        }
    } while (choice != 2);

    return 0;
}

