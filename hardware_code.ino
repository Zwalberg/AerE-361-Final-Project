/*Code Sources:
Arcada graphicstest (Display, Buttons)
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include "Adafruit_Arcada.h"
//#include "game.c" 
#include <Adafruit_NeoKey_1x4.h>   
#include <seesaw_neopixel.h>
Adafruit_Arcada arcada; 
Adafruit_NeoKey_1x4 neokey;


NeoKey1x4Callback blink(keyEvent evt) {
  uint8_t key = evt.bit.NUM;
  
  if (evt.bit.EDGE == SEESAW_KEYPAD_EDGE_RISING) {
    Serial.print("Key press ");
    Serial.println(key);
    neokey.pixels.setPixelColor(key, Wheel(map(key, 0, neokey.pixels.numPixels(), 0, 255)));
    
  } else if (evt.bit.EDGE == SEESAW_KEYPAD_EDGE_FALLING) {
    Serial.print("Key release ");
    Serial.println(key);

    neokey.pixels.setPixelColor(key, 0);
  }

  // Turn on/off the neopixels!
  neokey.pixels.show();
  return 0;
}

void setup(void) {
  Serial.begin(9600);
  Serial.begin(115200);
  arcada.arcadaBegin();
  arcada.displayBegin();
  arcada.setBacklight(255);
  arcada.display->fillScreen(ARCADA_BLACK);
  arcada.display->setTextColor(ARCADA_WHITE);
  //while (! Serial) delay(10);
  if (! neokey.begin(0x30)) {     // begin with I2C address, default is 0x30
    Serial.println("Could not start NeoKey, check wiring?");
    while(1) delay(10);
  }
  Serial.println("NeoKey started!");
  // Pulse all the LEDs on to show we're working
  for (uint16_t i=0; i<neokey.pixels.numPixels(); i++) {
    neokey.pixels.setPixelColor(i, 0x808080); // make each LED white
    neokey.pixels.show();
    delay(50);
  }
  for (uint16_t i=0; i<neokey.pixels.numPixels(); i++) {
    neokey.pixels.setPixelColor(i, 0x000000);
    neokey.pixels.show();
    delay(50);
  }
}

void loop() {

  game();  
}

uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return seesaw_NeoPixel::Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return seesaw_NeoPixel::Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return seesaw_NeoPixel::Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

void print_cards(int player_total,int player_cards,int dealer_total,int dealer_cards,int play,short dealer_hand[], short player_hand[],int cards[][4]) {
  arcada.displayBegin();
  arcada.setBacklight(255);
  arcada.display->fillScreen(ARCADA_BLACK);
  arcada.display->setTextColor(ARCADA_WHITE);
 arcada.display->setTextSize(2);
 arcada.display->setCursor(0,0); 
 arcada.display->println("Dealer:");
 for(int i = 0; i < dealer_cards; i++){   
 arcada.display->setCursor(30*(i),20);
 int card = cards[dealer_hand[i]][1];
 if(card == 1 || card > 10){
    high_val_print(card);
 }
 else {
 arcada.display->println(card);
 }
}
  arcada.display->println("------------");
  arcada.display->setCursor(0,50);
  arcada.display->println("Your Cards:");
  arcada.display->setCursor(170,50);
  arcada.display->println("Hit >");
  arcada.display->setCursor(150,100);
  arcada.display->println("Stand >");
  arcada.display->setCursor(130,140);
  arcada.display->println("Counter >");  
  for(int i = 0; i < player_cards; i++){
  arcada.display->setCursor(0,70+20*i);
  int card = cards[player_hand[i]][1];
  if(card == 1 || card > 10){
    high_val_print(card);
  }
  else {
    arcada.display->println(card);
  }
  arcada.display->setCursor(0,185);
  arcada.display->println("-------");
  arcada.display->setCursor(0,200);
  arcada.display->println("Pl:");
  arcada.display->setCursor(40,200);
  arcada.display->println(player_total);  
  arcada.display->setCursor(0,220);
  arcada.display->println("De:");
  arcada.display->setCursor(40,220);
  arcada.display->println(dealer_total);
}
}
void high_val_print(short face){
    char card_face[1] = {0};
    /*yellow();
    printf("\tDEBUG: face = %d\n",face);
    reset();*/
    switch (face){
        case 1: card_face[0] = 'A'; break;
        case 11: card_face[0] = 'J'; break;
        case 12: card_face[0] = 'Q'; break;
        case 13: card_face[0] = 'K'; break;
        default: card_face[0] = 'N'; break;
    }
    arcada.display->println(card_face[0]);  
    
}

//void carddisplay() {   
//size_t dealer_size = sizeof(dealer_hand)/sizeof(short);
//for(int i=0;i<dealer_size;i++) {  
//  arcada.display->setTextSize(2);
//  arcada.display->setCursor(0,0); 
//  arcada.display->println("Dealer:");
//  arcada.display->setCursor(0,15*i);
//  arcada.display->println(dealer_hand[i]);
//  arcada.display->println("------------");
//}
// size_t player_size = sizeof(player_hand)/sizeof(short);
// for(int i=0;i<player_size;i++) {
//   arcada.display->setCursor(0,50);
//   arcada.display->println("Your Cards:");
//   arcada.display->setCursor(0,60+15*i);
//   arcada.display->println(player_hand[i]);
//   arcada.display->setCursor(0,165);
//   arcada.display->println("---");
//   arcada.display->setCursor(0,180);
//   //arcada.display->println(player_total);
//   arcada.display->setCursor(160,165);
//   arcada.display->println("---");
//   arcada.display->setCursor(160,180);
//   //arcada.display->println(dealer_total);
// }
// }

void counterdisplay(int current_count) {
  arcada.display->setCursor(140,200);
  arcada.display->println("Counter:");
  arcada.display->setCursor(180,220);
  arcada.display->println(current_count);
}

void windisplay() {
    arcada.display->setTextColor(ARCADA_GREEN);
    arcada.display->setTextSize(5);
     arcada.display->setCursor(100,160);
    arcada.display->println("You Win!");  
    neokey.pixels.setPixelColor(0, 0x00FF00); // red
    neokey.pixels.setPixelColor(1, 0x00FF00); // red
    neokey.pixels.setPixelColor(2, 0x00FF00); // red
    neokey.pixels.setPixelColor(3, 0x00FF00); // 
    neokey.pixels.show();     
}

void losedisplay() {
    arcada.display->setTextColor(ARCADA_RED);
    arcada.display->setTextSize(5);
    arcada.display->setCursor(100,160);
    arcada.display->println("You Lose!");
    neokey.pixels.setPixelColor(0, 0xFF0000); // red
    neokey.pixels.setPixelColor(1, 0xFF0000); // red
    neokey.pixels.setPixelColor(2, 0xFF0000); // red
    neokey.pixels.setPixelColor(3, 0xFF0000); // 
    neokey.pixels.show();
}

int game(){
  int cards[53][4] = { {0,0,0,0},
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
    if(player_total > 21){
                dealer_total -= 10;
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
           // neokey.pixels.setPixelColor(0, 0xFF0000); // red
            new_card = card_draw(1) - 1;
            player_hand[player_cards] = cards[new_card][1];
            player_total += cards[new_card][2];
            if(cards[new_card][2] == 11 && player_total > 21){
                player_total -= 10;
            }
            
            //printf("\tDEBUG: NEW_CARD is %d\t%d\n\n",new_card,player_hand[player_cards]);
            player_cards++;
            print_cards(player_total,player_cards,dealer_total,dealer_cards,play,dealer_hand,player_hand,cards);
            //delay(2000);
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
         // neokey.pixels.setPixelColor(1, 0xFFFF00); // yellow
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


void red() {
  //printf("\033[1;31m");
    arcada.display->setTextColor(ARCADA_RED);
    arcada.display->setTextSize(2);
    arcada.display->setCursor(100,165);
    arcada.display->println("You Lose!");
    neokey.pixels.setPixelColor(0, 0xFF0000); // red
    neokey.pixels.setPixelColor(1, 0xFF0000); // red
    neokey.pixels.setPixelColor(2, 0xFF0000); // red
    neokey.pixels.setPixelColor(3, 0xFF0000); // 
    neokey.pixels.show();
}

void green(){
 // printf("\033[1;32m");
    arcada.display->setTextColor(ARCADA_GREEN);
    arcada.display->setTextSize(2);
     arcada.display->setCursor(100,165);
    arcada.display->println("You Win!"); 
    neokey.pixels.setPixelColor(0, 0x00FF00); // green
    neokey.pixels.setPixelColor(1, 0x00FF00); // green
    neokey.pixels.setPixelColor(2, 0x00FF00); // green
    neokey.pixels.setPixelColor(3, 0x00FF00); // 
    neokey.pixels.show();
}

void yellow(){
    //printf("\033[0;33m");
    arcada.display->setTextColor(ARCADA_YELLOW);
    arcada.display->setTextSize(5);
    arcada.display->setCursor(100,165);
    arcada.display->println("Tie!");
    neokey.pixels.setPixelColor(0, 0xFFFF00); // yellow
    neokey.pixels.setPixelColor(1, 0xFFFF00); // yellow
    neokey.pixels.setPixelColor(2, 0xFFFF00); // yellow
    neokey.pixels.setPixelColor(3, 0xFFFF00); // yellow
    neokey.pixels.show();
}

void reset() {
  printf("\033[0m");
}

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
