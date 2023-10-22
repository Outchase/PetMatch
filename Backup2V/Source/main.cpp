#include <windows.h>
#include "../Header/Card.h"        // Include the Card class header
#include "../Header/GameBoard.h"    // Include the GameBoard class header
#include "../Header/Player.h"       // Include the Player class header
#include "../Header/AnimalLabels.h" // Include the AnimalLabels enum


int main() {
    //
    int Tries = 0; //count how many tries it took
    Player player; //Create a player
    GameBoard gameBoard(4, 4); //Create a game board with 4 rows and 4 columns
    

    //*For Debugging*
    // Print the initial state of the game board
    /*printf("Initial Game Board:\n");
    gameBoard.PrintVector(false);
    printf("\n\n");*/

    // Shuffle the cards
    gameBoard.Shuffle();

    //*Cheats*
    // Print the shuffled card 
    printf("Shuffled Game Board:\n");
    gameBoard.PrintVector(true);
    printf("\n\n");

     // Game loop
    while (!gameBoard.IsGameOver()) {
        //print flipped card
        gameBoard.Print();

        // Player selects cards
        int row1 = player.SelectRow();
        int col1 = player.SelectColumn();
        int row2 = player.SelectRow();
        int col2 = player.SelectColumn();
        Tries++;

        // Flip the cards
        gameBoard.GetCard(row1-1, col1-1).FlipCard();
        gameBoard.GetCard(row2-1, col2-1).FlipCard();

        //Print open cards
        gameBoard.Print();

        printf("\n");

        if (gameBoard.IsMatch(row1, col1, row2, col2)) {
            printf("Match found!\n\n");
            //player.ConfirmInput();

        } else {
            printf("No match. Try again.\n\n");

            Sleep(2000); // Sleep for 2 seconds (2000 milliseconds)
            //player.ConfirmInput();
            
            //close the cards
            gameBoard.GetCard(row1-1, col1-1).FlipCard();
            gameBoard.GetCard(row2-1, col2-1).FlipCard();

        }
    }

    printf("It took you %d tries...", Tries);

    printf("\nGAME OVER.");
    return 0;
}


