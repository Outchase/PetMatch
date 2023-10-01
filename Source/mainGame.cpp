#include <stdio.h>
#include "mainGame.h"

int main(){

    Test mainTest;
    printf("Hello World!\n");
    printf("%s\n", mainTest.Dog.c_str());
    printf("%s\n", mainTest.Bear.c_str());
    printf("%s\n", mainTest.Cat.c_str());
    printf("%s\n", mainTest.Rabbit.c_str());
    printf("%s\n", mainTest.Monkey.c_str());
    printf("%s\n", mainTest.Fox.c_str());
    return 0;
}