#include <stdio.h>
#include "mainGame.h"
#include "Cards.h"
#include "Icons.h"

int main(){

    mainGame mainGame;

    //Cards Cards;

    Icons Icons;

    for (int i = 0; i < 4; i++)
    {
        for (int i = 0; i < 4; i++)
        {
           /*for (int k = 0; k <= 9; k++)
            {
            printf(" %s \n", Icons.arrTest[k].c_str());
            }*/
            printf(" %s \n", Icons.arrTest[0].c_str());
            printf(" %s ", Icons.arrTest[1].c_str());

            printf("O");
        }
            printf("\n");
        
    }
    
    
     /*for (int k = 0; k <= 9; k++)
     {
        printf(" %s ", Icons.arrTest[k].c_str());
            //printf(" %s ", Icons.arrTest[0][j].c_str());
    }*/
    return 0;
}