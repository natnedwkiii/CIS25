#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

// Countdown function
void countdown(int seconds) {
    for (int i = seconds; i > 0; i--) {
        cout << i << " seconds remaining...\n";
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << "Time's up!\n";
}

void warmupTimer() {
    cout << "\nWarm-up: 10 seconds\n";
    countdown(10);
}

void practiceTimer() {
    cout << "\nPractice: 15 seconds\n";
    countdown(15);
}

void breakTimer() {
    cout << "\nBreak: 5 seconds\n";
    countdown(5);
}
