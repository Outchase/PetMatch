#include <stdio.h>
#include <ctime>
#include "mainGame.h"
#include "Icons.h"

// ask nicolas <--------
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

int main(){

    mainGame mainGame;

    //Cards Cards;

    Icons icons;

    // Define the size of the grid
    const int rows = 4;
    const int cols = 4;

    enum AnimalLabels animals[18];

    // Initialize the array with 18 elements, repeating the animal labels
    for (int i = 0; i < 9; i++) {
        animals[i] = animals[i + 9] = (enum AnimalLabels)i;
    }

    icons.shuffleArray(animals, 18); // Shuffle the array

    // Print the shuffled array
    for (int i = 0; i < 18; i++) {
        printf("%d ", animals[i]);
    }

    //printf("%d", sizeof(Icons.arrCards[lFlippedCard+1]) / sizeof(Icons.arrCards[lFlippedCard+1][0]));

    /*for (int row = 0; row < rows; row++) {
        for (int i = 0; i < sizeof(Icons.arrCards[lFlippedCard+1]) / sizeof(Icons.arrCards[lFlippedCard+1][0]); i++) {
            for (int j = 0; j < cols; j++)
            {
                printf("%s ", Icons.arrCards[lFlippedCard][i].c_str());
            }
            printf("\n");
        }
    }*/

    return 0;
}