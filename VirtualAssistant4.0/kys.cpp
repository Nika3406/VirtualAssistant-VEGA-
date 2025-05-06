#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int askQuestion(const string& question) {
    char response;
    int score = 0;

    cout << question << endl;
    cout << "   a. Rarely or Never\n   b. Sometimes\n   c. Often or Always\nYour answer (a/b/c): ";
    
    while (true) {
        cin >> response;
        response = tolower(response);

        if (response == 'a') {
            score = 1;
            break;
        } else if (response == 'b') {
            score = 2;
            break;
        } else if (response == 'c') {
            score = 3;
            break;
        } else {
            cout << "Invalid input. Please enter 'a', 'b', or 'c': ";
        }
    }

    return score;
}

void runMentalHealthAssessment() {
    cout << "Welcome to the Mental Health Assistant I am Terry - Suicide Prevention Support\n";
    cout << "This assistant will help you reflect on your emotional well-being.\n";
    cout << "Please answer the following 10 questions honestly.\n\n";

    string questions[10] = {
        "1. I feel overwhelmed by hopelessness or sadness.",
        "2. I have lost interest in activities I used to enjoy.",
        "3. I feel isolated or disconnected from others.",
        "4. I struggle to find purpose or meaning in life.",
        "5. I feel like a burden to others.",
        "6. I have trouble sleeping or sleep too much.",
        "7. I experience sudden mood changes or irritability.",
        "8. I think about hurting myself or ending my life.",
        "9. I avoid friends, family, or social situations.",
        "10. I find it hard to concentrate or make decisions."
    };

    int totalScore = 0;

    for (int i = 0; i < 10; i++) {
        int score = askQuestion(questions[i]);
        totalScore += score;
        cout << endl;
    }

    cout << "\nYour Total Score: " << totalScore << "\n";

    if (totalScore <= 16) {
        cout << "Level A - Low Risk: You show signs of good emotional health.\n";
        cout << "Recommendations:\n- Stay connected with loved ones.\n- Keep journaling and self-reflecting.\n- Maintain healthy routines.\n";
    } else if (totalScore <= 23) {
        cout << "Level B - Moderate Risk: There are some concerning signs.\n";
        cout << "Recommendations:\n- Talk to someone you trust.\n- Practice mindfulness and self-care.\n- Consider support groups or therapy.\n";
    } else {
        cout << "Level C - High Risk: Please consider reaching out for help right away.\n";
        cout << "Recommendations:\n- Contact a mental health professional or hotline.\n- You are not alone, support is available.\n";
        cout << "In the U.S., you can call or text 988 for 24/7 support.\n";
    }
}
