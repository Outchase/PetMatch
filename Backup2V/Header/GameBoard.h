//Manages the game board, including shuffling, printing, and checking for matches.
#include <vector>
#include <string>
#include "Card.h"

class GameBoard{

    public:
        GameBoard(int rows, int cols);
        void Shuffle();
        void Print();
        bool IsMatch(int row1, int col1, int row2, int col2);
        bool IsGameOver();
        Card& GetCard(int row, int col);
        void PrintVector(bool printShuffled);
        /*bool FindInArray(int value);
        int arrMatch[8]{};*/

    private:
        int rows;
        int cols;
        std::string arrCards[lHappy+1][9]{
        {
            "#################",
            "#       ##      #",
            "#       ##      #",
            "#       ##      #",
            "# ############# #",
            "#       ##      #",
            "#       ##      #",
            "#       ##      #",
            "#################"
        },
        {
            "#################",
            "#               #",
            "#   ,-.___,-.   #",
            "#   \\_/_ _\\_/   #",
            "#     )O_O(     #",
            "#    { (_) }    #",
            "#     `-^-'     #",
            "#               #",
            "#################"
        },
        {
            "#################",
            "#               #",
            "#               #",
            "#    |\\---/|    #",
            "#    | o_o |    #",
            "#     \\_^_/     #",
            "#               #",
            "#               #",
            "#################"
        },
        {
            "#################",
            "#               #",
            "#   __     __   #",
            "#     \\._./     #",
            "#    ( o o )    #",
            "#     \\ Y /     #",
            "#      \\_/      #",
            "#               #",
            "#################"
        },
        {
            "#################",
            "#               #",
            "#     .=\"=.     #",
            "#   _/.-.-.\\_   #",
            "#  ( ( o o ) )  #",
            "#   |/  \"  \\|   #",
            "#    \\'---'/    #",
            "#               #",
            "#################"
        },
        {
            "#################",
            "# __         __ #",
            "#/  \\.-\"\"\"-./  \\#",
            "#\\    -   -    /#",
            "# |   o   o   | #",
            "# \\  .-'''-.  / #",
            "#  '-\\__Y__/-'  #",
            "#     `---`     #",
            "#################"
        },
        {
            "#################",
            "#               #",
            "#               #",
            "#     ^...^     #",
            "#    <_* *_>    #",
            "#      \\_/      #",
            "#               #",
            "#               #",
            "#################"
        },
        {
            "#################",
            "#               #",
            "#  ####   ####  #",
            "#  ####   ####  #",
            "#               #",
            "#    #######    #",
            "#  ##       ##  #",
            "#               #",
            "#################"
        },
        {
            "#################",
            "#               #",
            "#  ####   ####  #",
            "#  ####   ####  #",
            "#               #",
            "#  ##       ##  #",
            "#    #######    #",
            "#               #",
            "#################"
        }
    };
        std::vector<Card> cards;
};