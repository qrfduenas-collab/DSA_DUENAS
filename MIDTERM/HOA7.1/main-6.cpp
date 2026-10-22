#include <iostream>
#include "sortingAlgo.h"

const int maxSize = 100;

int val = 12345;

int myRand() {
    val = (1103515245 * val + 12345) % 2147483648;
    if (val < 0) {
        val = -val;
    }
    return val;
}

void displayArr(int arr[]);

int main(){

    //creates an array with unsorted list with 100 maximum size
    int unsortedArr[maxSize];

    //populates the array with random values
    for(int i = 0; i < maxSize; i++){
        unsortedArr[i] = (myRand() % 5) + 1;
    }
    displayArr(unsortedArr);

    std::cout << "Sorted Array: " << std::endl;
    selectionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

    processAndCountVotes(unsortedArr, maxSize);

    return 0;
}

void displayArr(int arr[]){
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}