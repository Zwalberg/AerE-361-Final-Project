#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void card_gen(){
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
}

int card_type(int )