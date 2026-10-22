#include <iostream>
#include <thread>
#include <chrono>

int integer;

void addInteger(int i) {
    integer += i;
}

void display() {
    std::cout << "integer: " << integer << "\n";
}

int main() {
    std::thread T1(addInteger, 1);
    std::thread T2(addInteger, 2);
    std::thread T3(addInteger, 3);

    display();
    T1.join();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    display();
    T2.join();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    display();
    T3.join();

    return 0;
}