//Blackjack
//Group 10 Final Project

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int card_draw();

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