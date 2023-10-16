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

void Icons::PrintCards(int rows, int cols, AnimalLabels arrAnimals[], int tarRow[], int tarCol[], int arrMatch[]){
    //printf("%d %d", tarRow[0], tarRow[1]);
    //printf("%d %d", tarCol[0], tarCol[1]);
    printf("\n");

    int count = 0;
    
    for (int row = 0; row < rows; row++) {
        for (int i = 0; i < sizeof(arrCards[lFlippedCard+1]) / sizeof(arrCards[lFlippedCard+1][0]); i++) {
            for (int j = 0; j < cols; j++)
            {
                //printf("TarRow: %d ", tarRow[count]);
                //printf("TarCol: %d ", tarCol[count]);
                //Print all IDs of Memo value
                //printf("ArrAnimals: %d ", arrAnimals[row * cols + j]);

                //ID of shuffled array
                //printf("%d ", arrAnimals[row * cols+j]);

                //print shuffled cards with icons
                /*if(row == tarRow[count]-1 && j==tarCol[count]-1 || row == tarRow[count+1]-1 && j==tarCol[count+1]-1){
                    printf("%s ", arrCards[arrAnimals[row * cols + j]][i].c_str());                  
                }else{
                   printf("%s ", arrCards[lFlippedCard][i].c_str());
                }*/
                
                //ERORRRR try to fix it
                /*if(FindInArray(arrMatch, sizeof(arrMatch) / sizeof(arrMatch[0]), arrAnimals[row * cols+j])){
                    printf("Match");
                   // printf("%s ", arrCards[arrAnimals[row * cols + j]][i].c_str());                  
                }else{
                   printf("%s ", arrCards[lFlippedCard][i].c_str());
                }*/
            }
            printf("\n");
            
        }
    }

}

bool Icons::FindInArray(int arrMatch[],int size, enum AnimalLabels value){
    for (int i = 0; i < size; i++) {
        if (arrMatch[i] == value) {
            return true; // Value found in the array
        }
    }
    return false;
}