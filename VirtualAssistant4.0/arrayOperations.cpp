#include <iostream>
using namespace std;

int arr1[5];
int arr2[5];

void inputArrays() {
    cout << "Enter 5 elements for Array 1:\n";
    for (int i = 0; i < 5; i++) {
        cout << "arr1[" << i << "]: ";
        cin >> arr1[i];
    }

    cout << "Enter 5 elements for Array 2:\n";
    for (int i = 0; i < 5; i++) {
        cout << "arr2[" << i << "]: ";
        cin >> arr2[i];
    }
}

void addArrays() {
    cout << "Addition: ";
    for (int i = 0; i < 5; i++)
        cout << arr1[i] + arr2[i] << " ";
    cout << endl;
}

void subtractArrays() {
    cout << "Subtraction: ";
    for (int i = 0; i < 5; i++)
        cout << arr1[i] - arr2[i] << " ";
    cout << endl;
}

void multiplyArrays() {
    cout << "Multiplication: ";
    for (int i = 0; i < 5; i++)
        cout << arr1[i] * arr2[i] << " ";
    cout << endl;
}

void divideArrays() {
    cout << "Division: ";
    for (int i = 0; i < 5; i++) {
        if (arr2[i] != 0)
            cout << (float)arr1[i] / arr2[i] << " ";
        else
            cout << "INF ";
    }
    cout << endl;
}

void arrayVoid() {
    inputArrays();  // <- run this FIRST before the menu

    int choice;
    do {
        cout << "\nArithmetic Array Operations Menu\n";
        cout << "0. Enter Arrays\n";
        cout << "1. Add Arrays\n2. Subtract Arrays\n3. Multiply Arrays\n4. Divide Arrays\n5. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 0: inputArrays(); break;
            case 1: addArrays(); break;
            case 2: subtractArrays(); break;
            case 3: multiplyArrays(); break;
            case 4: divideArrays(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);
}
