#ifndef SORTINGALGO_H
#define SORTINGALGO_H
#include <iostream>

template <typename T>
void bubbleSort(T arr[], int arrSize){
    for(int i = 0; i < arrSize; i++){
        for(int j = i+1; j < arrSize; j++){
            if(arr[j] < arr[i]){
                std::swap(arr[j], arr[i]);
            }
        }
    }
}

template <typename T>
void insertionSort(T arr[], int arrSize){
    int k = 1 , j;
    T temp;

    while(k < arrSize){
        temp = arr[k];
        j = k - 1;
        while(j >= 0 && temp <= arr[j]){
            arr[j+1]= arr[j];
            j--;
        }
        arr[j+1] = temp;
        k++;
    }
}

template<typename T>
int routine_smallest(T A[], int maxSize, int k){

    int position = k; 
    T smallestElem = A[k];

    for(int J = k+1; J < maxSize; J++){ 
        if(A[J] < smallestElem){
            smallestElem = A[J];
            position = J;
        }
    }

    return position;
}

template <typename T>
void selectionSort(T arr[], int arrSize){
    int POS;
    T temp; 

    for(int i = 0; i < arrSize; i++){

        POS = routine_smallest(arr, arrSize, i);

        temp = arr[i];
        arr[i] = arr[POS];
        arr[POS] = temp;
    }
}

#endif