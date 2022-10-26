//Blackjack
//Group 10 Final Project

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(){

    int lower = 1, upper = 52, count = 6, i = 0,j;
    int cards[52][4];
    int a,b,c,d;
    char cards1[100],input[100];
    FILE * fp;
    FILE * fp1;

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
        for (j = 0; j < 4; j++){
        fprintf(stdout,"%*d",3,cards[i][j]);
        }
        printf("\n");
        i++;
    }while(fgets(cards1,100,fp) != NULL);

    

    srand(time(0));

    printf("The random numbers are: ");
    for (int i = 0; i < count; i++) {
        int num = (rand() % (upper - lower + 1)) + lower;
        printf("%d ", num);
    }
    printf("\n");
    
 return 0;
}