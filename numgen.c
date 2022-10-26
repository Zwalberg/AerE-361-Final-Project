//Blackjack
//Group 10 Final Project

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(){

    int lower = 1, upper = 52, count = 6;
    FILE * fp;

    fp = fopen("Card_List.csv","r");

    if (fp == NULL){
        fprintf(stderr,"Card list did not open correctly.\nEXITING PROGRAM\n");
    }

    srand(time(0));

    printf("The random numbers are: ");
    for (int i = 0; i < count; i++) {
        int num = (rand() % (upper - lower + 1)) + lower;
        printf("%d ", num);
    }
    printf("\n");
    
 return 0;
}