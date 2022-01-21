#include <stdio.h>
#include <string.h>
#define MAX 1000

//Setting global char Arrays
char rank[] = "23456789TJQKA";
char suit[] = "HDSC";

//Setting char with value of 1 and 0;
char ValueOf1 = 'b' - 'a';
char ValueOf0 = 'a' - 'a';

//Determines if given character is a valid Rank
  char isValidRank (char c) {
    for(int i = 0; i < 13; i++){
      char a = rank[i];
      if(a == c)
        return ValueOf1;
    }
    return ValueOf0;
  }
//Determines if given character is a valid Suit
  char isValidSuit (char c) {
    for(int i = 0; i < 4; i++){
      char a = suit[i];
      if(a==c ){
        return ValueOf1;
      }
    }
    return ValueOf0;
  }
//Determines what the Trump Card will bex
  char getTrump () {
    char Trump[MAX];
    printf("Choose a Trump Suit : 'H', 'D', 'S', 'C'\n");
    while(1){ //Infinite Loop if the card input is invalid
      fgets(Trump,MAX,stdin);
      if(Trump[1] == '\n' && isValidSuit(Trump[0]) == ValueOf1){
        return Trump[0];
      }
        printf("That is not a valid suit, please try again choosing from 'H', 'D', 'S', 'C' \n");
    }
  }


int main () {
  while(1){
  //Trump function runs first
  char TrumpCard = getTrump();
  printf("The Trump Card for this round is %c\n",TrumpCard);
  //Infinite Loop Starts
  //while(1){ Original While but makes it easier to run by putting loop outside
  //Player 1-4 Chooses their cards
    char p1[MAX];
    printf("Player 1: Please enter a card rank and suit (Ex. 5S, 4H, TC)\n");

    while(1){
      fgets(p1,MAX,stdin);
      if(isValidRank(p1[0]) && isValidSuit(p1[1]) && p1[2] == '\n'){
        break;
      } else if (p1[0] == '.' && isValidSuit(p1[1])) { //Allows rank to be '.' to break the code
        break;
      } else {
        printf("That is an invalid card. \nPlayer 1: Please enter a card rank and suit (Ex. 5S, 4H, TC)\n");
      }
    }

    //Used to break
    if(p1[0] == '.'){
      break;
    }

    char p2[MAX];
    printf("Player 2: Please enter a card rank and suit (Ex. 5S, 4H, TC)\n");

    while(1){
      fgets(p2,MAX,stdin);
      if(isValidRank(p2[0]) && isValidSuit(p2[1]) && p2[2] == '\n'){
        break;
      } else if (p2[0] == '.' && isValidSuit(p2[1])) { //Allows rank to be '.' to break the code
        break;
      } else {
        printf("That is an invalid card. \nPlayer 2: Please enter a card rank and suit (Ex. 5S, 4H, TC)\n");
      }
    }

    //Used to break
    if(p2[0] == '.'){
      break;
    }

    char p3[MAX];
    printf("Player 3: Please enter a card rank and suit (Ex. 5S, 4H, TC)\n");

    while(1){
      fgets(p3,MAX,stdin);
      if(isValidRank(p3[0]) && isValidSuit(p3[1]) && p3[2] == '\n'){
        break;
      } else if (p3[0] == '.' && isValidSuit(p3[1])) { //Allows rank to be '.' to break the code
        break;
      } else {
        printf("That is an invalid card. \nPlayer 3: Please enter a card rank and suit (Ex. 5S, 4H, TC)\n");
      }
    }

    //Used to break
    if(p3[0] == '.'){
      break;
    }

    char p4[MAX];
    printf("Player 4: Please enter a card rank and suit (Ex. 5S, 4H, TC)\n");

    while(1){
      fgets(p4,MAX,stdin);
      if(isValidRank(p4[0]) && isValidSuit(p4[1]) && p4[2] == '\n'){
        break;
      } else if (p4[0] == '.' && isValidSuit(p4[1])) { //Allows rank to be '.' to break the code
        break;
      } else {
        printf("That is an invalid card. \nPlayer 4: Please enter a card rank and suit (Ex. 5S, 4H, TC)\n");
      }
    }

    //Used to break
    if(p4[0] == '.'){
      break;
    }

    //Printing all the cards, excluding the P[3] since it stores \n which skips a line
    printf("Cards are: %c%c, %c%c, %c%c, %c%c \n",p1[0],p1[1],p2[0],p2[1],p3[0],p3[1],p4[0],p4[1]);
    char players[4][MAX];

    //Creating player list to easily iterate over with for loops
    strcpy(players[0],p1);
    strcpy(players[1],p2);
    strcpy(players[2],p3);
    strcpy(players[3],p4);


    //Player list used for printing later
    char player[4][MAX];

    strcpy(player[0],"Player1");
    strcpy(player[1],"Player2");
    strcpy(player[2],"Player3");
    strcpy(player[3],"Player4");



    //Creating integers of rank index for ranks to easily compare later since 0 < 1 < 2....
    int index1;
    int index2;
    int index3;
    int index4;

    //Finding the index
    index1 = (int)((strchr(rank, p1[0]))- rank);
    index2 = (int)((strchr(rank, p2[0]))- rank);
    index3 = (int)((strchr(rank, p3[0]))- rank);
    index4 = (int)((strchr(rank, p4[0]))- rank);

    int indexes[4] = {index1,index2,index3,index4};



    int CardWinningIndex = -1; //Set to negative 1 so the first card with trump suit automatically is set as winner
    int PlayerwinnerIndex;

    if(p1[1] != TrumpCard && p2[1] != TrumpCard && p3[1] != TrumpCard && p4[1] != TrumpCard){ //Game without Trump
      char LeadingSuit = p1[1];
      int PlayerwinnerIndex = 0;
      int CardWinningIndex = index1;

      if(p2[1] != LeadingSuit && p3[1] != LeadingSuit && p4[1] != LeadingSuit){ //If leading suit wins
        printf("The winner is %s who has card %s\n",player[PlayerwinnerIndex],players[PlayerwinnerIndex]);

      } else {
        char haveLeadingSuit[4][MAX];
        int haveLeadingSuitIndex[4]; //

        for(int i = 0; i<4 ;i++){ //Creates char array with players which have leading suit
          if(players[i][1] == LeadingSuit){
            strcpy(haveLeadingSuit[i],players[i]);  //Adds into both arrays with same i, so the index of the card can be easily accessed
            haveLeadingSuitIndex[i] = indexes[i];
          }
        }

        for(int i = 0; i<4 ; i++){ //Compares all cards with LeadingSuits to find which has ihighest index
          if(haveLeadingSuitIndex[i] > CardWinningIndex){
            CardWinningIndex = indexes[i];
            PlayerwinnerIndex = i;
          }
        }

        printf("The winner is %s who has card %s\n",player[PlayerwinnerIndex],players[PlayerwinnerIndex]);

      }

    } else { //Game with Trump Card
      char haveTrumpSuit[4][MAX];
      int haveTrumpCardIndex[4];

      for(int i = 0; i<4 ;i++){ //Creates char array with players which have Trump suit
        if(players[i][1] == TrumpCard){
          strcpy(haveTrumpSuit[i],players[i]);  //Adds into both arrays with same i, so the index of the card can be easily accessed
          haveTrumpCardIndex[i] = indexes[i];
        }
      }

      for(int i = 0; i < 4 ; i++){
        if(haveTrumpCardIndex[i] > CardWinningIndex){
          CardWinningIndex = indexes[i];
            PlayerwinnerIndex = i;
        }
      }
        printf("The winner is %s who has card %s\n",player[PlayerwinnerIndex],players[PlayerwinnerIndex]);
    }

    printf("Time to play again!, if you would like to exit. Please enter ',' as the rank and a valid suit\n");

    //LOOP AGAIN

  }

  return 0;

}
