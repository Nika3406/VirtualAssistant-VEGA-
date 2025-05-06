#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void englishVocab() {
    const int totalQuestions = 15;
    int score = 0;
    char answer;

    cout << "Enhance your vocabulary\n\n";

    auto ask = [&](const string& question, char correctAnswer) {
        while (true) {
            cout << question;
            cout << "Your answer: ";
            cin >> answer;
            answer = tolower(answer);

            if (answer == correctAnswer) {
                score++;
                break;
            } else if (answer >= 'a' && answer <= 'd') {
                // Valid but incorrect answer
                break;
            } else {
                cout << "Invalid input. Please enter A, B, C, or D.\n";
            }
        }
    };

    ask("1. Which word best describes something ridiculously absurd or unreasonable?\nA) Adamant\nB) Ludicrous\nC) Deliberation\nD) Spontaneity\n", 'b');
    ask("\n2. After hearing the good news, she was filled with pure ___ .\nA) Malice\nB) Elation\nC) Predicament\nD) Exasperation\n", 'b');
    ask("\n3. A 'predicament' is:\nA) A pleasant surprise\nB) A difficult or tricky situation\nC) A type of goal\nD) A feeling of joy\n", 'b');
    ask("\n4. Which word means hatred or the desire to harm?\nA) Malice\nB) Cunning\nC) Ludicrous\nD) Wager\n", 'a');
    ask("\n5. If someone is described as 'idle', they are:\nA) Extremely busy\nB) Clever and sneaky\nC) Not doing anything\nD) Loud and energetic\n", 'c');
    ask("\n6. The fox in the story used its ___ to trick the hunters.\nA) Spontaneity\nB) Elation\nC) Cunning\nD) Malice\n", 'c');
    ask("\n7. A 'wager' is most similar to:\nA) A wish\nB) A bet\nC) A punishment\nD) A prize\n", 'b');
    ask("\n8. Which word refers to doing something on impulse or without planning?\nA) Meticulous\nB) Spontaneity\nC) Deliberation\nD) Adamant\n", 'b');
    ask("\n9. She was ___ that the decision was final and refused to change her mind.\nA) Elated\nB) Dreanged\nC) Adamant\nD) Idle\n", 'c');
    ask("\n10. What does 'meticulous' mean?\nA) Careless and clumsy\nB) Lazy and uninterested\nC) Extremely careful and detail-oriented\nD) Fast and reckless\n", 'c');
    ask("\n11. His constant questions led to the teacher’s ___ .\nA) Exasperation\nB) Elation\nC) Predicament\nD) Malice\n", 'a');
    ask("\n12. A 'dreanged' person is:\nA) Calm and collected\nB) Sad and lonely\nC) Mentally disturbed or insane\nD) Intelligent and charming\n", 'c');
    ask("\n13. The jury made a careful ___ before reaching a verdict.\nA) Wager\nB) Elation\nC) Deliberation\nD) Malice\n", 'c');
    ask("\n14. To 'abase' someone means to:\nA) Praise them highly\nB) Lower or degrade them\nC) Confuse them\nD) Defend them fiercely\n", 'b');
    ask("\n15. Which word means 'feeling or showing tiredness, especially as a result of excessive exertion'?\nA) Weary\nB) Adamant\nC) Meticulous\nD) Spontaneity\n", 'a');

    // Final score
    cout << "\nQuiz Completed! Your score: " << score << " out of " << totalQuestions << ".\n";

    if (score == totalQuestions)
        cout << "Perfect score! You know your vocab!";
    else if (score >= 12)
        cout << "Great job!";
    else if (score >= 8)
        cout << "Not bad! Keep practicing!";
    else
        cout << "Keep studying, you're getting there!";
}
