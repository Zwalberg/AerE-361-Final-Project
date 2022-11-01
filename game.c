//Blackjack
//Group 10 Final Project

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"numgen.c"
#include<unistd.h>

int main(){
    int i=0,j,deal[4],player,dealer;
    int cards[52][4];
    int a,b,c,d;
    char cards1[100];
    FILE * fp;

    fp = fopen("Card_List.csv","r");

    if (fp == NULL){
        fprintf(stderr,"Card list did not open correctly.\nEXITING PROGRAM\n");
        exit(3);
    }

    do{
        fscanf(fp,"%d,%d,%d,%d",&a,&b,&c,&d);
        cards[i][0] = a;
        cards[i][1] = b;
        cards[i][2] = c;
        cards[i][3] = d;
        i++;
    }while(fgets(cards1,100,fp) != NULL);


    printf("Welcome to Blackjack\n\n");
    for (i = 1; i <= 4; i++){
        int index = i-1;
        deal[index] = card_draw(i);
       // printf("%d\n",deal[index]);
        //printf("\t%d %d\n",cards[deal[index]-1][1],cards[deal[index]-1][2]);
    }
    

    player = cards[deal[0]-1][2]+cards[deal[2]-1][2];
    dealer = cards[deal[1]-1][2]+cards[deal[3]-1][2];

    printf("Player total: %d\n",player);
    printf("Dealer total: %d\n",dealer);




    return 0;
}