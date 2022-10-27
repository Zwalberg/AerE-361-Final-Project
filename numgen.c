//Blackjack
//Group 10 Final Project

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(){

    int lower = 1, upper = 52, count = 6, i = 0;
    char cards[52][4],input[100];
    int a,b,c,d;
    char cards1[100];
    FILE * fp;
    FILE * fp1;

    fp = fopen("Card_List.csv","r");

    do{
    fscanf(fp,"%d,%d,%d,%d",&a,&b,&c,&d);
    cards[i][0] = a;
    cards[i][1] = b;
    cards[i][2] = c;
    cards[i][3] = d;
    i++;
    }while(fgets(cards1,100,fp) != NULL);

    for(i = 0; i < 52; i++){
    printf("%d  %d  %d  %d\n",cards[i][0],cards[i][1],cards[i][2],cards[i][3]);
    }

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