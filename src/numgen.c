//Blackjack
//Group 10 Final Project

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int card_draw(int count){
    int upper,lower,draw,i;
    time_t t;

    upper = 52;
    lower = 1;

    srand(time(NULL));

    for(i = 0; i < count; i++){
        draw = (rand() % (upper - lower + 1)) + lower;
        //printf(" %d",draw);
    }
    //printf("\n");

    return draw;
}

int checkVal(int card){
    // function to return the value of a card in the High-Lo method of card counting
    // card int must be the number value of the card (column 3)
    
    int val=0;
    if (card > 1 && card < 7)
    {
        val= 1;
    }
    else if (card >= 7 && card < 10)
    {
        val= 0;
    }
    else if (card == 10 || card == 1)
    {
        val= -1;
    }
    else
    //debug
        printf("Invalid Range (cardval check)\n");
    return val;
}