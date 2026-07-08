#ifndef SCOREBOARD_HPP
#define SCOREBOARD_HPP

const int DEFAULT_SCORE_COUNT = 5;

// Required array processing functions
bool isValidSize(int size);
bool isBadInput(const int arr[], int size);
int calculateTotal(const int scores[], int size);
double calculateAverage(const int scores[], int size);
int findLowest(const int scores[], int size);
int findHighest(const int scores[], int size);
int findScore(const int scores[], int size, int target);
void sortScores(int scores[], int size);
void printScores(const int scores[], int size);

#endif
