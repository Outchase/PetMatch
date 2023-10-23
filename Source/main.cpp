#include <windows.h>
#include "../Header/Card.h"        // Include the Card class header
#include "../Header/GameBoard.h"    // Include the GameBoard class header
#include "../Header/Player.h"       // Include the Player class header
#include "../Header/AnimalLabels.h" // Include the AnimalLabels enum


int main() {
    int Tries = 0; //count how many tries it took
    Player* ptrPlayer= new Player; //Create a player
    GameBoard* ptrGameBoard = new GameBoard(4, 4); //Create a game board with 4 rows and 4 columns
    

    //*Debugging*
    // Print the initial state of the card vector
    printf("Initial Game Board:\n");
    ptrGameBoard->PrintVector();
    printf("\n\n");

    // Shuffle the cards
    ptrGameBoard->Shuffle();

    //*Cheats*
    // Print the shuffled card vector
    printf("Shuffled Game Board:\n");
    ptrGameBoard->PrintVector();
    printf("\n\n");

    // Game loop
    while (!ptrGameBoard->IsGameOver()) {
        //print flipped card
        ptrGameBoard->Print();

        // Player selects cards
        int row1 = ptrPlayer->SelectRow();
        int col1 = ptrPlayer->SelectColumn();
        int row2 = ptrPlayer->SelectRow();
        int col2 = ptrPlayer->SelectColumn();
        Tries++; //count each tries

        // Flip the cards (open)
        ptrGameBoard->GetCard(row1-1, col1-1)->FlipCard();
        ptrGameBoard->GetCard(row2-1, col2-1)->FlipCard();

        //Print open cards
        ptrGameBoard->Print();

        printf("\n");

        //check when selction was a match
        if (ptrGameBoard->IsMatch(row1, col1, row2, col2)) {
            printf("Match found!\n\n");
            //player.ConfirmInput();

        } else {
            printf("No match. Try again.\n\n");

            //player.ConfirmInput();
            
            //close the cards
            ptrGameBoard->GetCard(row1-1, col1-1)->FlipCard();
            ptrGameBoard->GetCard(row2-1, col2-1)->FlipCard();

        }
        Sleep(2000); // Sleep for 2 seconds (2000 milliseconds)
    }

    printf("It took you %d tries...", Tries);
    printf("\nGAME OVER.");

    // Clean up dynamic memory
    delete ptrPlayer;
    delete ptrGameBoard;

    return 0;
}


