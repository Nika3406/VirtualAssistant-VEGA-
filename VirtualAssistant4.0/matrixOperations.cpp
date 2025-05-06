#include <iostream>
using namespace std;

int A[2][2];
int B[2][2];

void inputMatrices() {
    cout << "Enter values for Matrix A (2x2):\n";
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }

    cout << "Enter values for Matrix B (2x2):\n";
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            cout << "B[" << i << "][" << j << "]: ";
            cin >> B[i][j];
        }
}

void addMatrices() {
    cout << "Matrix Addition:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << A[i][j] + B[i][j] << " ";
        cout << endl;
    }
}

void subtractMatrices() {
    cout << "Matrix Subtraction:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << A[i][j] - B[i][j] << " ";
        cout << endl;
    }
}

void multiplyMatrices() {
    int product[2][2] = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                product[i][j] += A[i][k] * B[k][j];

    cout << "Matrix Multiplication:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << product[i][j] << " ";
        cout << endl;
    }
}

void matrixVoid() {
    inputMatrices();  // <- run this FIRST before the menu

    int choice;
    do {
        cout << "\nMatrix Array Operations Menu\n";
        cout << "0. Enter Matrices\n";
        cout << "1. Add Matrices\n2. Subtract Matrices\n3. Multiply Matrices\n4. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 0: inputMatrices(); break;
            case 1: addMatrices(); break;
            case 2: subtractMatrices(); break;
            case 3: multiplyMatrices(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);
}
