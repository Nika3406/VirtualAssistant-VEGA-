#include <iostream>
#include <cmath>
#include <limits>  // For input validation

using namespace std;

void safeInputDouble(const string& prompt, double& num) {
    while (true) {
        cout << prompt;
        if (cin >> num) break;
        cout << "Invalid input. Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void safeInputInt(const string& prompt, int& num) {
    while (true) {
        cout << prompt;
        if (cin >> num) break;
        cout << "Invalid input. Please enter an integer.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void add() {
    double num1, num2;
    safeInputDouble("Enter first number: ", num1);
    safeInputDouble("Enter second number: ", num2);
    cout << "Addition: " << num1 + num2 << endl;
}

void subtract() {
    double num1, num2;
    safeInputDouble("Enter first number: ", num1);
    safeInputDouble("Enter second number: ", num2);
    cout << "Subtraction: " << num1 - num2 << endl;
}

void multiply() {
    double num1, num2;
    safeInputDouble("Enter first number: ", num1);
    safeInputDouble("Enter second number: ", num2);
    cout << "Multiplication: " << num1 * num2 << endl;
}

void divide() {
    double num1, num2;
    safeInputDouble("Enter numerator: ", num1);
    while (true) {
        safeInputDouble("Enter denominator: ", num2);
        if (num2 != 0) break;
        cout << "Division by zero is not allowed.\n";
    }
    cout << "Division: " << num1 / num2 << endl;
}

void average() {
    double num1, num2;
    safeInputDouble("Enter first number: ", num1);
    safeInputDouble("Enter second number: ", num2);
    cout << "Average: " << (num1 + num2) / 2 << endl;
}

void checkEvenOdd() {
    double num;
    safeInputDouble("Enter a number: ", num);
    cout << "Number is " << ((static_cast<int>(num) % 2 == 0) ? "Even" : "Odd") << endl;
}

void checkSign() {
    double num;
    safeInputDouble("Enter a number: ", num);
    cout << "Number is " << (num > 0 ? "Positive" : (num < 0 ? "Negative" : "Zero")) << endl;
}

void squareRoot() {
    double num;
    while (true) {
        safeInputDouble("Enter a number: ", num);
        if (num >= 0) break;
        cout << "Cannot compute square root of a negative number.\n";
    }
    cout << "Square root: " << sqrt(num) << endl;
}

void absoluteValue() {
    double num;
    safeInputDouble("Enter a number: ", num);
    cout << "Absolute Value: " << fabs(num) << endl;
}

void switchnums() {
    double num1, num2;
    safeInputDouble("Enter first number: ", num1);
    safeInputDouble("Enter second number: ", num2);

    double temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "After swapping:\n";
    cout << "First number: " << num1 << endl;
    cout << "Second number: " << num2 << endl;
}

void minMaxNums() {
    double a, b, c;
    safeInputDouble("Enter first number: ", a);
    safeInputDouble("Enter second number: ", b);
    safeInputDouble("Enter third number: ", c);
    cout << "The min value is " << min(a, min(b, c)) << endl;
    cout << "The max value is " << max(a, max(b, c)) << endl;
}

void basicMathOperations() {
    int operation;
    do {
        cout << "\nChoose an operation:\n"
             << "1. Addition\n"
             << "2. Subtraction\n"
             << "3. Multiplication\n"
             << "4. Division\n"
             << "5. Average\n"
             << "6. Check Even or Odd\n"
             << "7. Check Sign (Positive/Negative)\n"
             << "8. Square Root\n"
             << "9. Absolute Value\n"
             << "10. Switch Numbers\n"
             << "11. Minimum/Maximum Number\n"
             << "12. Exit\n";

        safeInputInt("Enter your choice: ", operation);

        switch (operation) {
            case 1: add(); break;
            case 2: subtract(); break;
            case 3: multiply(); break;
            case 4: divide(); break;
            case 5: average(); break;
            case 6: checkEvenOdd(); break;
            case 7: checkSign(); break;
            case 8: squareRoot(); break;
            case 9: absoluteValue(); break;
            case 10: switchnums(); break;
            case 11: minMaxNums(); break;
            case 12: cout << "Exiting Program\n"; break;
            default: cout << "Invalid choice. Please try again.\n"; break;
        }
    } while (operation != 12);
}
