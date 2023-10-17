#include <stdio.h>
#include "Icons.h"

// g++ *.cpp -o maingame.exe

int InputHandler(int min, int max){   
    int userInput;
    while (1) {
        if (scanf("%d", &userInput) != 1 || userInput < min || userInput > max) {
            while (getchar() != '\n'); // Clear the input buffer
            printf("Invalid input. Please enter a valid number between 1 and 4: ");
        } else {
            break;
        }
    }
    return userInput;
}

void SelectCards(int targRow[], int targCols[]){
    for (int i = 0; i < 2; i++)
    {
        printf("Enter the Target row: ");
        targRow[i]= InputHandler(1,4);

        printf("Enter the Target collum: ");
        targCols[i]= InputHandler(1,4);
    }
}

void MatchChecker(AnimalLabels animals[], int targRow[], int rows, int targCols[],  int arrMatch[], int &arrMatchIndex){
    //check when the card match that the player selected
    if(animals[((targRow[0]-1)*rows+targCols[0]-1)] == animals[((targRow[1]-1)*rows+targCols[1]-1)]){
        //printf("\n%d ", animals[((targRow[0]-1)*rows+targCols[0]-1)]); 
        //printf("\n%d ", animals[((targRow[1]-1)*rows+targCols[1]-1)]); 
        printf("\nMatch!\n");
        arrMatch[arrMatchIndex] = animals[((targRow[0]-1)*rows+targCols[0]-1)];
        arrMatchIndex++;
    }
}

int main(){
    Icons icons;
    

    // Define the size of the grid
    int rows = 4;
    int cols = 4;
    int targRow[2];
    int targCols[2];
    int Tries=0;
    int arrMatchIndex = 0; // Initialize an index to keep track of the position in arrMatch
    AnimalLabels animals[18];

    //<Add it to function>
    // Initialize the array with 16 elements, repeating the animal labels
    for (int i = 0; i < lHappy; i++) {
        animals[i] = animals[i+8] = (enum AnimalLabels)(i+1);
    }
    
    // Print the array For Debugging
    /*for (int i = 0; i < 16; i++) {
        printf("%d ", animals[i]);
    }*/

    icons.ShuffleArray(animals, 16); // Shuffle the array

    //see the shuffled array values, cheats
    printf("\nShuffled array: ");    
    for (int i = 0; i < 16; i++) {
        printf("%d ", animals[i]);
    }
    
    // Print the Cards, keep it to the End
    //icons.PrintCards(rows, cols, animals, targRow, targCols);

    //<Make a function>
    //loop trough gameplay until you win
    while (arrMatchIndex < 8){
        icons.PrintCards(rows, cols, animals, targRow, targCols);

        SelectCards(targRow, targCols);

        MatchChecker(animals, targRow, rows, targCols, icons.arrMatch, arrMatchIndex);

        Tries++;
    }

    icons.PrintCards(rows, cols, animals, targRow, targCols);

    printf("\nGAME OVER.");

    printf("\nIt took you %d tries...", Tries);

    //Print matched arrays. For Debugging
    /*printf("\nMatch array: ");
    for (int i = 0; i < sizeof(icons.arrMatch) / sizeof(icons.arrMatch[0]); i++) {
        printf("%d ", icons.arrMatch[i]);
    }*/
}