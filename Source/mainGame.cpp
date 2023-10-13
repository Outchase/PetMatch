#include <stdio.h>
#include <ctime>
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

int main(){
    Icons icons;

    // Define the size of the grid
    int rows = 4;
    int cols = 4;
    int targRow;
    int targCols;

    AnimalLabels animals[18];

    // Initialize the array with 16 elements, repeating the animal labels
    for (int i = 0; i < lFlippedCard; i++) {
        animals[i] = animals[i + 8] = (enum AnimalLabels)i;
    }

    icons.ShuffleArray(animals, 16); // Shuffle the array

    // Print the shuffled array
    /*for (int i = 0; i < 16; i++) {
        printf("%d ", animals[i]);
    }*/

    // Print the Cards
    icons.PrintCards(rows, cols, animals);

    /*printf("Enter the Target row: ");
    scanf("%d", &targRow);

    printf("Enter the Target row: ");
    scanf("%d", &targCols);*/

    printf("Enter the Target row: ");
    targRow= InputHandler(1,4);

    printf("Enter the Target collum: ");
    targCols= InputHandler(1,4);

    printf("Row : %d\nCols: %d", targRow, targCols);

    return 0;
}