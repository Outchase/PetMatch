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
    std::string confirmInput;
    printf("Press Y to continue...\n");
        while (1) {
            if (scanf("%s", &confirmInput) != 1 && confirmInput != "Y") {
                while (getchar() != '\n'); // Clear the input buffer
                printf("Invalid input. Please enter Y to continue.. ");
            } else {
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