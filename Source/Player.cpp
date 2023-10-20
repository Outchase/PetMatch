#include <stdio.h>
//#include <string>
#include "../Header/Player.h"

int Player::InputHandler(int min, int max){
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

/*void Player::ConfirmInput(){
    std::string userInput;
    printf("Press Y to continue...\n");
    while (true){ // Wait for the user to press Enter
        if (scanf("%s", &userInput) == 1 && userInput == "Y") {
            break;
        }
    }
}*/

int Player::SelectRow(){
    int row;
    printf("Enter the Target row (1-4): ");
    row=InputHandler(1,4);

    return row;
}

int Player::SelectColumn(){
    int col;

    printf("Enter the cloumn row (1-4): ");
    col=InputHandler(1,4);

    return col;
}