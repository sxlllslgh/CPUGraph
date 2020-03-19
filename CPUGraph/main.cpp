#include <chrono>
#include <cmath>
#include <iostream>
#include <thread>

bool flag = true;

void drawGraph(long nsecInterval) {
    std::chrono::nanoseconds inter(nsecInterval);
    double i = 0;
    while (flag) {
        auto start = std::chrono::steady_clock::now();
        double rate = 0.5 * sin(i) + 1.0;
        long workDuration = long(nsecInterval * rate);
        while (std::chrono::steady_clock::now() - start < std::chrono::nanoseconds(workDuration));
        std::this_thread::sleep_for(std::chrono::nanoseconds(nsecInterval - workDuration));
        i += 0.2;
    }
}

int main() {
    std::thread t(drawGraph, 500000000);
    char input;
    while (true) {
        std::cin.get(input);
        if (input == 10) {
            flag = false;
            break;
        }
    }
    return 0;
}