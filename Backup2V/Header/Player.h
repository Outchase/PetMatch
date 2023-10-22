//Represents the player's actions, like selecting cards and tracking progress.

class Player
{

    public:
        int InputHandler(int min, int max);
        int SelectRow();    // Function to select a row.
        int SelectColumn(); // Function to select a column.
        void ConfirmInput();
};
