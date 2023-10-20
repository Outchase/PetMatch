#include <vector>
#include <ctime>
#include "../Header/GameBoard.h"
#include "../Header/Card.h"


Card& GameBoard::GetCard(int row, int col) {
        return cards[row * cols + col];
}

GameBoard::GameBoard(int rows, int cols){
    this->rows=rows;
    this->cols = cols;

    // Initialize the game board
    for (int i = 0; i < rows*cols; i++)
    {
        // Initialize a card with a label and add it to the game board
        cards.push_back(Card(static_cast<AnimalLabels>(i % lHappy + 1)));
    }
}

void GameBoard::Shuffle(){
    srand(time(NULL)); // Seed the random number generator with current time

    for (int i = cards.size() - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Generate a random index between 0 and i

        // Swap cards[i] and cards[j]
        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void GameBoard::Print(){
    for (int row = 0; row < rows; row++) {
        for (int i = 0; i < sizeof(arrCards[lFlippedCard + 1]) / sizeof(arrCards[lFlippedCard + 1][0]); i++) {
            for (int col = 0; col < cols; col++) {
                // Get the label of the card at (row, col)
                Card card = GetCard(row, col);
                AnimalLabels label = card.GetLabel();


                if (card.IsFlipped()) {
                    // Print the card's representation from arrCards
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
    // Get the cards at the specified positions
    Card& card1 = cards[(row1 - 1) * cols + (col1 - 1)];
    Card& card2 = cards[(row2 - 1) * cols + (col2 - 1)];

    // Flip the cards
    //card1.FlipCard();
    //card2.FlipCard();

    // Check if both cards have the same label
    return (card1.GetLabel() == card2.GetLabel());
}

bool GameBoard::IsGameOver(){
// Check if the game is over by examining the state of all cards
    for (const Card& card : cards) {
        if (!card.IsFlipped()) {
            // If any card is not flipped, the game is not over
            return false;
        }
    }

    return true;
}

void GameBoard::PrintVector(bool printShuffled) {
    for (int i = 0; i < rows * cols; i++) {
        int label = cards[i].GetLabel();

        if (printShuffled) {
            printf("%d ", label);
            //printf("%d: %d ", i, label);
        } else {
            printf("%d ", label);
            //printf("%d: %d ", i, label);
        }
    }
}