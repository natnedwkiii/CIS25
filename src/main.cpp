#include <iostream>
#include "timer.h"
using namespace std;

int main() {
    int choice;

    do {
        cout << "\n=== DANCE PRACTICE TIMER ===\n";
        cout << "1. Warm-up\n";
        cout << "2. Practice\n";
        cout << "3. Break\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                warmupTimer();
                break;
            case 2:
                practiceTimer();
                break;
            case 3:
                breakTimer();
                break;
            case 4:
                cout << "Goodbye dancer!\n";
                break;
            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}
