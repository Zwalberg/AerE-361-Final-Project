//Blackjack
//Group 10 Final Project

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"numgen.c"
#include<unistd.h>



int cards[52][4];
short deal[4];
short player_hand[6];
short dealer_hand[6];
short current_count;

void print_cards(int player_total,int player_cards,int dealer_total,int dealer_cards,int play,short dealer_hand[], short player_hand[]);
void red();
void green();
void yellow();
void reset();
void print_menu();
void high_val_print(short face);


// int main(){
//     short i,j,player_total,dealer_total,play = 1,new_card;
//     int a,b,c,d,input;
//     char cards1[100];
//     FILE * fp;

//     fp = fopen("Card_List.csv","r");

//     if (fp == NULL){
//         fprintf(stderr,"Card list did not open correctly.\nEXITING PROGRAM\n");
//         exit(3);
//     }

//     do{
//         fscanf(fp,"%d,%d,%d,%d",&a,&b,&c,&d);
//         cards[i][0] = a;
//         cards[i][1] = b;
//         cards[i][2] = c;
//         cards[i][3] = d;
//         i++;
//     }while(fgets(cards1,100,fp) != NULL);


//     printf("Welcome to Blackjack\n\n");
//     for (i = 1; i <= 4; i++){
//         int index = i-1;
//         //printf("Card: %d\n",card_draw(i));
//         deal[index] = card_draw(i) - 1;
//         //printf("deal[%d] = %d\n",index,deal[index]);
//         //printf("\t%d %d\n",cards[deal[index]][1],cards[deal[index]][2]);
        
//     }
    
//     //printf("Cards dealt: %hd\n",cards_dealt);

//     player_hand[0] = cards[deal[0]-1][0];
//     player_hand[1] = cards[deal[2]-1][0];
//     dealer_hand[0] = cards[deal[1]-1][0];
//     dealer_hand[1] = cards[deal[3]-1][0];

//     //printf("Player hand: %d  %d\n",player_hand[0],player_hand[1]);

//     for(i = 0; i < 2; i++){
//       player_total += cards[player_hand[i]][2];
//       dealer_total += cards[dealer_hand[i]][2];
//     }
    
//     int player_cards = 2;
//     int dealer_cards = 2;
    
//     print_cards(player_total,player_cards,dealer_total,dealer_cards,play,dealer_hand,player_hand);

//     do{
//         printf("\tEnter 1 to HIT or 0 to STAND: ");
//         scanf(" %d",&input);
//         if(input == 1){
//             new_card = card_draw(1) - 1;
//             player_hand[player_cards] = cards[new_card][1];
//             player_total += cards[new_card][2];
//             if(cards[new_card][2] == 11 && player_total > 21){
//                 player_total -= 10;
//             }
            
//             //printf("\tDEBUG: NEW_CARD is %d\t%d\n\n",new_card,player_hand[player_cards]);
//             player_cards++;
//             print_cards(player_total,player_cards,dealer_total,dealer_cards,play,dealer_hand,player_hand);
//             if(player_total > 21){
//                 red();
//                 printf("Player Busts!\nDEALER WINS\n");
//                 reset();
//                 exit(3);
//             }
//             else if(player_total == 21){
//                 printf("Player at 21!\n\tDEALER PLAYS OUT\n");
//                 break;
//             }
//         }
//         else if(input == 0){
//             printf("\e[1;1H\e[2J");
//             printf("\tDEALER PLAYS OUT\n");
//             play = 0;
//         }
//         else{
//             printf("Not valid input! Try again!\n");
//         }
//     }while (play == 1);

//     print_cards(player_total,player_cards,dealer_total,dealer_cards,play,dealer_hand,player_hand);
//     play = 1;
    
//     do{
//       //print_cards(player_total,player_cards,dealer_total,dealer_cards,play,dealer_hand,player_hand);
//         if(dealer_total > 21){
// 	    green();
// 	    printf("Dealer Bust!\n\tPlayer WINS\n");
// 	    play = 0;
// 	}
// 	else if(dealer_total <= 21){
// 	    if(dealer_total == 21){
// 	        red();
// 	        printf("Dealer HIT 21!\n\tDEALER WINS\n");
// 	        play = 0;
// 	    }
// 	    else if(dealer_total >= 17 && dealer_total >= player_total){
// 	        red();
// 		printf("Dealer's total greater than player's!\n\tDealer WINS\n");
// 		play = 0;
// 	    }
// 	    else if(dealer_total >= 17 && dealer_total < player_total){
// 	        green();
// 	        printf("Player's total greater than dealer's!\n\tPlayer WINS\n");
// 		play = 0;
// 	    }
// 	    else if(dealer_total < 17){
// 	      	new_card = card_draw(1) - 1;
// 		dealer_hand[dealer_cards] = cards[new_card][1];
// 		dealer_total += cards[new_card][2];
//                 if(cards[new_card][2] == 11 && dealer_total > 21){
//                     dealer_total -= 10;
// 		}
// 		dealer_cards++;
// 		print_cards(player_total,player_cards,dealer_total,dealer_cards,play,dealer_hand,player_hand);
// 	    }
// 	}
//     }while (play == 1);
    

//     //printf("Player total: %d\n",player);
//     //printf("Dealer total: %d\n",dealer);

//     return 0;
// }

// /* print_cards(player_total,player_cards,dealer_total,dealer_cards,play,dealer_hand,player_hand);{

//     int i;
//     short card;
    
//     printf("\e[1;1H\e[2J");

//     printf("Dealer: ");
//     for(i = 0; i < dealer_cards; i++){
//         card = cards[dealer_hand[i]][1];
//         if(card == 1 || card > 10){
//             high_val_print(card);
//         }
//         else{
//             printf("%d  ",cards[dealer_hand[i]][1]);
//         }
        
//     }
//     printf("\nDealer Total: %d\n\n",dealer_total);

//     printf("Player: ");
//     for(i = 0; i < player_cards; i++){
//         card = cards[player_hand[i]][1];
//         if(card == 1 || card > 10){
//             high_val_print(card);
//         }
//         else{
//             printf("%d  ",cards[player_hand[i]][1]);
//         }
        
//     }
//     printf("\nPlayer Total: %d\n",player_total);
// } */


// void red() {
//   printf("\033[1;31m");
// }

// void green(){
//   printf("\033[1;32m");
// }

// void yellow(){
//     printf("\033[0;33m");
// }

// void reset() {
//   printf("\033[0m");
// }

// // void high_val_print(short face){
// //     char card_face[1] = {0};
// //     /*yellow();
// //     printf("\tDEBUG: face = %d\n",face);
// //     reset();*/
// //     switch (face){
// //         case 1: card_face[0] = 'A'; break;
// //         case 11: card_face[0] = 'J'; break;
// //         case 12: card_face[0] = 'Q'; break;
// //         case 13: card_face[0] = 'K'; break;
// //         default: card_face[0] = 'N'; break;
// //     }
// //     arcada.display->println(cardface);
   
// // }
