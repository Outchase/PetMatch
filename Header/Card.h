//Represents a single card with a label and a state (flipped or not).
#ifndef CARD_H
#define CARD_H
#include "AnimalLabels.h"

class Card
{

    public:
        Card(AnimalLabels label);
        void FlipCard();
        bool IsFlipped() const;
        AnimalLabels GetLabel();

    private:
        bool flipped;
        AnimalLabels label;
};
#endif // CARD_H