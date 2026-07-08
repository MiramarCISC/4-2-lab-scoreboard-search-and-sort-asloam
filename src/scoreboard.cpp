#include "scoreboard.hpp"
#include <iostream>

using namespace std;

int calculateTotal(const int scores[], int size) {
    // If the array is null or the size is invalid, return 0.
    // Otherwise, return the sum of all scores.

    if (scores == nullptr || !isValidSize(size)){
        return 0;
    }
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += scores [i];
    }
    return total;
}

double calculateAverage(const int scores[], int size) {
    // If the array is null or the size is invalid, return 0.0.
    // Otherwise, return the total divided by size.

    if (scores == nullptr || !isValidSize(size)) {
        return 0.0;
    }

    double total = calculateTotal (scores, size);
    return (total / size);
}

int findLowest(const int scores[], int size) {
    // If the array is null or the size is invalid, return 0.
    // Otherwise, return the smallest score.
    
    if (scores == nullptr || !isValidSize(size)) {
        return 0;
    }
    int lowest = scores[0];
    for (int i=1; i < size; i++) {
        if (scores[i] < lowest) {
            lowest = scores[i];}
        }
        return lowest;
}

int findHighest(const int scores[], int size) {
    // If the array is null or the size is invalid, return 0.
    // Otherwise, return the largest score.
    
    if (scores == nullptr || !isValidSize(size)) { 
        return 0;
    }

    int highest = scores[0];

    for (int i = 1; i < size; i++) {
        if (scores[i] > highest) {
            highest = scores[i];
        }
    }
    return highest;
}

int findScore(const int scores[], int size, int target) {
    // Search the array from left to right.
    // Return the index where target is found.
    // Return -1 when target is not found.

    if (scores == nullptr || !isValidSize(size)) {
        return -1;
    }

    for (int i = 0; i < size; i++) {
        if (scores[i] == target) {
            return i;
        }
    }

    return -1;
}

void sortScores(int scores[], int size) {
    // Sort the array from lowest to highest.
    // A selection sort works well for this lab.

    if (scores == nullptr || !isValidSize(size)) {
        return;
    }

    for (int start = 0; start < size -1; start++) {
        int minindex = start;

        for (int i = start + 1; i < size; i++) {
            if (scores[i] < scores[minindex]) {
                minindex = i;
            }
        }

        int temp = scores[start];
        scores[start] = scores[minindex];
        scores[minindex] = temp;
    }
}


void printScores(const int scores[], int size) {
    if (scores == nullptr || !isValidSize(size)) {
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


bool isValidSize(int size) {
    // Return true when size is greater than 0.
    return size > 0;
}
