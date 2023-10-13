#include <cstdlib>
#include <ctime>
#include "Icons.h"

// Function to shuffle an array of enum values
void Icons::shuffleArray(enum AnimalLabels arr[], int size) {
    srand(time(NULL)); // Seed the random number generator with current time
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Generate a random index between 0 and i
        enum AnimalLabels temp = arr[i]; // Swap arr[i] and arr[j]
        arr[i] = arr[j];
        arr[j] = temp;
    }
}