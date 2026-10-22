#include <iostream>
#include <thread>
#include "partC.h"

template <typename T>
void display(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    int arr1[15] = {42, 7, 19, 3, 55, 12, 88, 24, 1, 33, 67, 14, 9, 50, 21};
    int arr2[15] = {99, 11, 45, 2, 78, 34, 13, 60, 5, 82, 18, 27, 51, 8, 36};

    std::thread T1(insertionSort<int>, arr1, 15);
    std::thread T2(insertionSort<int>, arr2, 15);

    T1.join();
    T2.join();

    display(arr1, 15);
    std::cout << std::endl;
    display(arr2, 15);
    std::cout << std::endl;

    return 0;
}