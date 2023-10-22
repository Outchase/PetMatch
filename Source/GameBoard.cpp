#include <vector>
#include <ctime>
#include "../Header/GameBoard.h"
#include "../Header/Card.h"

//Get selected card and returns a pointer/ memory address
Card* GameBoard::GetCard(int row, int col) {
        return cards[row * cols + col];
}

// create game board grid with rows and colums
GameBoard::GameBoard(int rows, int cols){
    this->rows=rows;
    this->cols = cols;

    //Initialize the game board
    for (int i = 0; i < rows*cols; i++)
    {
        //Initialize a card with a label and add it to the game board
        cards.push_back(new Card(static_cast<AnimalLabels>(i % lHappy + 1)));
    }
}

//Destructor 
//Frees memory by deleting allocated Card objects and clears cards containers
GameBoard::~GameBoard() {
    //clean up memory by deleting the card objects
    for (Card* card : cards) {
        delete card;
    }
    cards.clear();
}

void GameBoard::Shuffle(){
    srand(time(NULL)); //Seed the random number generator with current time

    for (int i = cards.size() - 1; i > 0; i--) {
        int j = rand() % (i + 1); //Generate a random index between 0 and i

        // Swap cards[i] and cards[j]
        Card* temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void GameBoard::Print(){
    for (int row = 0; row < rows; row++) {
        for (int i = 0; i < sizeof(arrCards[lFlippedCard + 1]) / sizeof(arrCards[lFlippedCard + 1][0]); i++) {
            for (int col = 0; col < cols; col++) {
                //Get the label of the card at (row, col)
                Card* card = GetCard(row, col);
                AnimalLabels label = card->GetLabel();

                if (card->IsFlipped()) {
                    //Print cards from arrCards
                    printf("%s ", arrCards[static_cast<int>(label)][i].c_str());
                } else {
                    // Print the back of the card
                    printf("%s ", arrCards[lFlippedCard][i].c_str());
                }
            }
            printf("\n");
        }
    }
}

bool GameBoard::IsMatch(int row1, int col1, int row2, int col2){
    //Get the cards at the specified positions
    Card* card1 = cards[(row1 - 1) * cols + (col1 - 1)];
    Card* card2 = cards[(row2 - 1) * cols + (col2 - 1)];

    // Check if both cards have the same label and return true or false
    return (card1->GetLabel() == card2->GetLabel());
}

bool GameBoard::IsGameOver(){
// Check if the game is over by examining the state of all cards
    for (Card* card : cards) {
        if (!card->IsFlipped()) {
            // If any card is not flipped, the game is not over
            return false;
        }
    }
    return true;
}

//*Cheats/Debugging*
// Print the card vector 
void GameBoard::PrintVector() {
    for (int i = 0; i < rows * cols; i++) {
        int label = cards[i]->GetLabel();
        printf("%d ", label);
    }
}