#include <stdio.h>
#include "../Header/Card.h"

// Constructor Initializes a Card with label
//sets card state as not flipped
Card::Card(AnimalLabels label) : label(label), flipped(false) {}

//set value of state of card (open/close)
void Card::FlipCard(){
    if(flipped==true){
        flipped = false;
    }else{
        flipped = true;
    }
}

//get value of state of card
bool Card::IsFlipped() const{
    //safe to call, won't change the state of the card
    return flipped;
}

//get calue of label of card
AnimalLabels Card::GetLabel(){
    return label;
}