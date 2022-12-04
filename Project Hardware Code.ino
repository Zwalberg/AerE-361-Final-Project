int game(){
  int cards[52][4] = {
      {1,1,11,0},
      {2,2,2,0},
      {3,3,3,0},
      {4,4,4,0},
      {5,5,5,0},
      {6,6,6,0},
      {7,7,7,0},
      {8,8,8,0},
      {9,9,9,0},
      {10,10,10,0},
      {11,11,10,0},
      {12,12,10,0},
      {13,13,10,0},
      {14,1,11,0},
      {15,2,2,0},
      {16,3,3,0},
      {17,4,4,0},
      {18,5,5,0},
      {19,6,6,0},
      {20,7,7,0},
      {21,8,8,0},
      {22,9,9,0},
      {23,10,10,0},
      {24,11,10,0},
      {25,12,10,0},
      {26,13,10,0},
      {27,1,11,0},
      {28,2,2,0},
      {29,3,3,0},
      {30,4,4,0},
      {31,5,5,0},
      {32,6,6,0},
      {33,7,7,0},
      {34,8,8,0},
      {35,9,9,0},
      {36,10,10,0},
      {37,11,10,0},
      {38,12,10,0},
      {39,13,10,0},
      {40,1,11,0},
      {41,2,2,0},
      {42,3,3,0},
      {43,4,4,},
      {44,5,5,0},
      {45,6,6,0},
      {46,7,7,0},
      {47,8,8,0},
      {48,9,9,0},
      {49,10,10,0},
      {50,11,10,0},
      {51,12,10,0},
      {52,13,10,0},
    };
    short deal[4];
    short player_hand[6];
    short dealer_hand[6];
    short current_count;    
    short i,j,player_total,dealer_total,play = 1,new_card;
    int a,b,c,d,input;
    char cards1[100];
    //FILE * fp;
    /*
    fp = fopen("Card_List.csv","r");

    if (fp == NULL){
        fprintf(stderr,"Card list did not open correctly.\nEXITING PROGRAM\n");
        exit(3);
    }
    */
    /*
    do{
        fscanf(fp,"%d,%d,%d,%d",&a,&b,&c,&d);
        cards[i][0] = a;
        cards[i][1] = b;
        cards[i][2] = c;
        cards[i][3] = d;
        i++;
    }while(fgets(cards1,100,fp) != NULL);
    */

    printf("Welcome to Blackjack\n\n");
    for (i = 1; i <= 4; i++){
        int index = i-1;
        //printf("Card: %d\n",card_draw(i));
        deal[index] = card_draw(i) - 1;
        //printf("deal[%d] = %d\n",index,deal[index]);
        //printf("\t%d %d\n",cards[deal[index]][1],cards[deal[index]][2]);
        
    }
    
    //printf("Cards dealt: %hd\n",cards_dealt);

    player_hand[0] = cards[deal[0]-1][0];
    player_hand[1] = cards[deal[2]-1][0];
    dealer_hand[0] = cards[deal[1]-1][0];
    dealer_hand[1] = cards[deal[3]-1][0];

    //printf("Player hand: %d  %d\n",player_hand[0],player_hand[1]);

    for(i = 0; i < 2; i++){
      player_total += cards[player_hand[i]][2]; 
      current_count += checkVal(cards[player_hand[i]][2]);
      dealer_total += cards[dealer_hand[i]][2];
      current_count +=checkVal(cards[dealer_hand[i]][2]);
    }
    
    int player_cards = 2;
    int dealer_cards = 2;
    int dealer_loop=0;
    print_cards(player_total,player_cards,cards[dealer_hand[0]][1],1,play,dealer_hand,player_hand,cards);

    do{
      //stores button presses
       uint8_t buttons_pressed = arcada.readButtons();
      //if button B is pushed, display the card counter
      if (buttons_pressed & ARCADA_BUTTONMASK_B) {
        counterdisplay(current_count);
      }
      //if button a is pushed, remove the card counter
      if (buttons_pressed & ARCADA_BUTTONMASK_A) {
        arcada.displayBegin();
        arcada.setBacklight(255);
        arcada.display->fillScreen(ARCADA_BLACK);
        arcada.display->setTextColor(ARCADA_WHITE);
        print_cards(player_total,player_cards,cards[dealer_hand[0]][1],1,play,dealer_hand,player_hand,cards);        
      }
       uint8_t buttons = neokey.read();
        printf("\tEnter 1 to HIT or 0 to STAND: ");
        scanf(" %d",&input);
        if(buttons & (1<<0)){
            Serial.println("Button A");
            neokey.pixels.setPixelColor(0, 0xFF0000); // red
            new_card = card_draw(1) - 1;
            player_hand[player_cards] = cards[new_card][1];
            player_total += cards[player_hand[player_cards]][2];
            if(cards[new_card][2] == 11 && player_total > 21){
                player_total -= 10;
            }
            
            //printf("\tDEBUG: NEW_CARD is %d\t%d\n\n",new_card,player_hand[player_cards]);
            player_cards++;
            print_cards(player_total,player_cards,dealer_total,dealer_cards,play,dealer_hand,player_hand,cards);
            delay(2000);
            if(player_total > 21){
                red();
                printf("Player Busts!\nDEALER WINS\n");
                //losedisplay();
                //reset();
                exit(3);
            }
            else if(player_total == 21){
                printf("Player at 21!\n\tDEALER PLAYS OUT\n");
                break;
            }
        }
        else if(buttons & (1<<1)){
          Serial.println("Button B");
          neokey.pixels.setPixelColor(1, 0xFFFF00); // yellow
            printf("\e[1;1H\e[2J");
            printf("\tDEALER PLAYS OUT\n");
            play = 0;
        }
        else{
            printf("Not valid input! Try again!\n");
        }
          neokey.pixels.show();
    }while (play == 1);

    print_cards(player_total,player_cards,dealer_total,dealer_cards,play,dealer_hand,player_hand,cards);
    play = 1;
    
    do{
      //print_cards(player_total,player_cards,dealer_total,dealer_cards,play,dealer_hand,player_hand,cards);
        //red();
        //printf("\ndealer logic start\n");
        //reset();
        if(dealer_total == player_total){
            yellow();
            printf("Player has pushed with Dealer\n");
            play =0;
        }
        else if(player_total == 21 && player_cards<=2){
            green();
            printf("Player has hit a BlackJack!\n");
            //windisplay();            
            play = 0;
        }
	else if(dealer_total <= 21){
	    if(dealer_total == 21){
	        red();
	        printf("Dealer HIT 21!\n\tDEALER WINS\n");
          //losedisplay();
	        play = 0;
	    }
	    else if(dealer_total >= 17 && dealer_total >= player_total){
	        red();
		      printf("Dealer's total greater than player's!\n\tDealer WINS\n");
          //losedisplay();
		      play = 0;
	    }
	    else if(dealer_total >= 17 && dealer_total < player_total){
	        green();
	        printf("Player's total greater than dealer's!\n\tPlayer WINS\n");
          //windisplay();
		play = 0;
	    }
    }
        
        if(cards[new_card][2] == 11 && dealer_total > 21){
                dealer_total -= 10;
            }

        

	    else if(dealer_total < 17){
	      	new_card = card_draw(1) - 1;
		dealer_hand[dealer_cards] = cards[new_card][1];
		dealer_total += cards[dealer_hand[dealer_cards]][2];
                if(cards[new_card][2] == 11 && dealer_total > 21){
                    dealer_total -= 10;
		}
		dealer_cards++;
		print_cards(player_total,player_cards,dealer_total,dealer_cards,play,dealer_hand,player_hand,cards);
    delay(2000);
	  }

        else if(dealer_total > 21){
	    green();
	    printf("Dealer Bust!\n\tPlayer WINS\n");
      //windisplay();
	    play = 0;
	}


    if(dealer_loop>15){
        printf("Error: Dealer logic loop, exiting");
        exit(124);
    }
    dealer_loop++;





	}while (play == 1);
    

    //printf("Player total: %d\n",player);
    //printf("Dealer total: %d\n",dealer);

    return 0;
}

/* print_cards(player_total,player_cards,dealer_total,dealer_cards,play,dealer_hand,player_hand,cards);{

    int i;
    short card;
    
    printf("\e[1;1H\e[2J");

    printf("Dealer: ");
    for(i = 0; i < dealer_cards; i++){
        card = cards[dealer_hand[i]][1];
        if(card == 1 || card > 10){
            high_val_print(card);
        }
        else{
            printf("%d  ",cards[dealer_hand[i]][1]);
        }
        
    }
    printf("\nDealer Total: %d\n\n",dealer_total);

    printf("Player: ");
    for(i = 0; i < player_cards; i++){
        card = cards[player_hand[i]][1];
        if(card == 1 || card > 10){
            high_val_print(card);
        }
        else{
            printf("%d  ",cards[player_hand[i]][1]);
        }
        
    }
    printf("\nPlayer Total: %d\n",player_total);
} */