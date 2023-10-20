#include <stdio.h>
#include "../Header/Card.h"

Card::Card(AnimalLabels label) : label(label), flipped(false) {
    
}

void Card::FlipCard(){
    if(flipped==true){
        flipped = false;
    }else{
        flipped = true;
    }
}

bool Card::IsFlipped() const{
    //safe to call: This function won't change the state of the card
    return flipped;
}

AnimalLabels Card::GetLabel(){
    return label;
}