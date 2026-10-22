#ifndef SORTINGALGO_H
#define SORTINGALGO_H

#include <iostream>
#include <string>

template <typename T>
int routine_smallest(T A[], int maxSize, int k) {
    int position = k;
    T smallestElem = A[k];

    for (int J = k + 1; J < maxSize; J++) {
        if (A[J] < smallestElem) {
            smallestElem = A[J];
            position = J;
        }
    }
    return position;
}

template <typename T>
void selectionSort(T arr[], int arrSize) {
    int POS;
    T temp;

    for (int i = 0; i < arrSize; i++) {
        POS = routine_smallest(arr, arrSize, i);

        temp = arr[i];
        arr[i] = arr[POS];
        arr[POS] = temp;
    }
}

void processAndCountVotes(int arr[], int maxSize) {
    int voteCounts[6] = {0}; // Indices 1 to 5 store votes

    for (int i = 0; i < maxSize; i++) {
        voteCounts[arr[i]]++;
    }

    std::string names[6] = {
        "",
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustin",
        "Deja Jayla Banaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
    };

    int winningCandidate = 1;
    int highestVotes = voteCounts[1];

    std::cout << std::endl << "Votes Results: " << std::endl;
    for (int i = 1; i <= 5; i++) {
        std::cout << "Candidate " << i << " (" << names[i] << "): " << voteCounts[i] << " votes" << std::endl;
        if (voteCounts[i] > highestVotes) {
            highestVotes = voteCounts[i];
            winningCandidate = i;
        }
    }

    std::cout << std::endl << "Winner: Candidate " << winningCandidate << " with " << highestVotes << " votes!" << std::endl;
}

#endif