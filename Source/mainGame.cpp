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

int main(){
    Icons icons;

    // Define the size of the grid
    int rows = 4;
    int cols = 4;
    int targRow[2];
    int targCols[2];
    int arrMatch[16];

    AnimalLabels animals[18];

    //Add it to function
    // Initialize the array with 16 elements, repeating the animal labels
    for (int i = 0; i < lFlippedCard; i++) {
        animals[i] = animals[i + 8] = (enum AnimalLabels)i;
    }

    icons.ShuffleArray(animals, 16); // Shuffle the array

    // Print the shuffled array For Debugging
    /*for (int i = 0; i < 16; i++) {
        printf("%d ", animals[i]);
    }*/

    // Print the Cards
    //icons.PrintCards(rows, cols, animals, targRow, targCols);

    // Add While when game is over
    //system("cls");
    /*for (int i = 0; i < 2; i++)
    {
        printf("Enter the Target row: ");
        targRow[i]= InputHandler(1,4);

        printf("Enter the Target collum: ");
        targCols[i]= InputHandler(1,4);
    }*/

    printf("\nShuffled array: ");    
    for (int i = 0; i < 16; i++) {
        printf("%d ", animals[i]);
    }

    SelectCards(targRow, targCols);

    //Print the Cards
    //icons.PrintCards(rows, cols, animals, targRow, targCols);

    /*printf("Row: ");
    for (int i = 0; i < sizeof(targRow) / sizeof(targRow[0]); i++) {
        printf("%d ", targRow[i]);
    }

    printf("\nCols: ");
    for (int i = 0; i < sizeof(targCols) / sizeof(targCols[0]); i++) {
        printf("%d ", targCols[i]);
    }*/

    printf("\nShuffled array: ");    
    for (int i = 0; i < 16; i++) {
        printf("%d ", animals[i]);
    }

    printf("\n");

    if(animals[((targRow[0]-1)*rows+targCols[0]-1)] == animals[((targRow[1]-1)*rows+targCols[1]-1)]){
        
        printf("\n%d ", animals[((targRow[0]-1)*rows+targCols[0]-1)]); 
        printf("\n%d ", animals[((targRow[1]-1)*rows+targCols[1]-1)]); 
        printf("\nMatch\n");
        animals[0] = animals[((targRow[0]-1)*rows+targCols[0]-1)];
        //animals[1] = animals[((targRow[1]-1)*rows+targCols[1]-1)];
    }



    for (int i = 0; i < 2; i++) {
        printf("%d ", arrMatch[i]);
    }

    //printf("\n(%d-1) * %d + %d - 1 = %d", targRow[0], rows, targCols[0], ((targRow[0]-1)*rows+targCols[0]-1));

    //printf("\n%d ", animals[((targRow[0]-1)*rows+targCols[0]-1)])



}