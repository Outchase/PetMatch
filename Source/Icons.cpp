#include <cstdlib>
#include <ctime>
#include <string>
#include "Icons.h"

// Function to shuffle an array of enum values
void Icons::ShuffleArray(enum AnimalLabels arr[], int size) {
    srand(time(NULL)); // Seed the random number generator with current time
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Generate a random index between 0 and i
        enum AnimalLabels temp = arr[i]; // Swap arr[i] and arr[j]
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void Icons::PrintCards(int rows, int cols, AnimalLabels arrAnimals[]){
    //int count =0;
    //printf(" %d %d ", rows, cols);
    for (int row = 0; row < rows; row++) {
        for (int i = 0; i < sizeof(arrCards[lFlippedCard+1]) / sizeof(arrCards[lFlippedCard+1][0]); i++) {
            for (int j = 0; j < cols; j++)
            {
                //print shuffled flipped cards
                //printf("%s ", arrCards[lFlippedCard][i].c_str());

                //print shuffled cards with icons
                printf("%s ", arrCards[arrAnimals[row * cols + j]][i].c_str());
            }
            printf("\n");
            
        }
    }

}

