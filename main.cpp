#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main() {
    const int N = 5;

    char names[N][20];
    int marks[N][3];
    int total[N];
    double average[N];

    // Input student names and marks
    for (int i = 0; i < N; i++) {
        cout << "\nEnter name of student " << i + 1 << ": ";
        cin >> ws;
        cin.getline(names[i], 20);

        total[i] = 0;

        for (int j = 0; j < 3; j++) {
            cout << "Enter mark " << j + 1 << ": ";
            cin >> marks[i][j];

            total[i] += marks[i][j];
        }

        average[i] = total[i] / 3.0;
    }

    // Find the top student
    int top = 0;

    for (int i = 1; i < N; i++) {
        if (total[i] > total[top]) {
            top = i;
        }
    }

    // Display the mark sheet
    cout << "\n\n";
    cout << "========== STUDENT MARK SHEET ==========\n";

    cout << left
         << setw(20) << "Name"
         << setw(8) << "M1"
         << setw(8) << "M2"
         << setw(8) << "M3"
         << setw(10) << "Total"
         << setw(10) << "Average" << endl;

    cout << string(64, '-') << endl;

    for (int i = 0; i < N; i++) {
        cout << left
             << setw(20) << names[i]
             << setw(8) << marks[i][0]
             << setw(8) << marks[i][1]
             << setw(8) << marks[i][2]
             << setw(10) << total[i]
             << fixed << setprecision(1)
             << average[i] << endl;
    }

    cout << "\nTop student: " << names[top] << endl;
    cout << "Highest total: " << total[top] << endl;

    return 0;
}