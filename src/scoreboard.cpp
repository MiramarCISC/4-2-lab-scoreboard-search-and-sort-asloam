#include "scoreboard.hpp"
#include <iostream>

using namespace std;

// If the size is greater than 0, returns True
bool isValidSize(int size) {
    return size > 0;
}

// If the array is null or the size is invalid, returns True
bool isBadInput(const int arr[], int size) {
    return arr == nullptr || !isValidSize(size);
}

// If the array is null or the size is invalid, returns 0
// Otherwise, returns the sum of all scores
int calculateTotal(const int scores[], int size) {
    if (isBadInput(scores, size)) return 0;
    
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += scores[i];
    }

    return total;
}

// If the array is null or the size is invalid, returns 0.0
// Otherwise, returns the total divided by the size
double calculateAverage(const int scores[], int size) {
    if (isBadInput(scores, size)) return 0.0;

    double total = calculateTotal(scores, size);
    
    return (total / size);
}

// If the array is null or the size is invalid, returns 0
// Otherwise, returns the smallest score
int findLowest(const int scores[], int size) {
    if (isBadInput(scores, size)) return 0;

    int lowest = scores[0];
    for (int i = 1; i < size; i++) {
        if(scores[i] < lowest) lowest = scores[i];
    }

    return lowest;
}

// If the array is null or the size is invalid, returns 0
// Otherwise, returns the largest score
int findHighest(const int scores[], int size) {
    if (isBadInput(scores, size)) return 0;

    int highest = scores[0];
    for (int i = 1; i < size; i++) {
        if(scores[i] > highest) highest = scores[i];
    }

    return highest;
}

// Searches the array from left to right
// Returns the index where target is found
// Returns -1 if the target is not found
int findScore(const int scores[], int size, int target) {
    if (isBadInput(scores, size)) return -1;

    for (int i = 0; i < size; i++) {
        if(scores[i] == target) return i;
    }
    
    return -1;
}

// Sorts the array from lowest to highest
void sortScores(int scores[], int size) {
    // Selection Sort
    for(int i = 0; i < (size - 1); i++) {
        int indexLowest = i;

        for(int j = (i + 1); j < size; j++) {
            if (scores[j] < scores[indexLowest]) {
                indexLowest = j;
            }
        }

        int temp = scores[i];
        scores[i] = scores[indexLowest];
        scores[indexLowest] = temp;
    }
}

// Prints the scoreboard in the terminal if valid
void printScores(const int scores[], int size) {
    if (isBadInput(scores, size)) {
        cout << "No scores to print." << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << scores[i];

        if (i < size - 1) {
            cout << " ";
        }
    }

    cout << endl;
}