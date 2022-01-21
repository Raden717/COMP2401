#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define DATA_BITS    8
#define PARITY_BITS  4
#define CHAR_LIMIT   100




// Given a brokenSequence of bits representing a corrupted 12-bit (i.e., DATA_BITS + PARITY_BITS)
// hamming code sequence, determine which bit had been flipped and then flip it back and store
// the repaired sequence in fixedSequence.    Note that both bit sequences may be very large,
// but this function should only examine the first 12 bits of the sequence (i.e., the first
// 12 characters in the incoming and outgoing char array).
void fix(char brokenSequence[], char fixedSequence[]) {
  // ...
  // Replace the code below with your own code
  // ...
  int brokenSeqInt[13];
  //Converting string into array of ints to easily add;
  for(int i = 0 ; i < 13; i++){
    if(brokenSequence[i] == '1'){
      brokenSeqInt[i] = 1;
    } else {
      brokenSeqInt[i] = 0;
    }
    fixedSequence[i] = brokenSequence[i]; //Copying the array
  }



  //Index arrays for parity/real bits to easily loop through
  int parityBits[4] = {0,1,3,7};
  int realBits[8] = {2,4,5,6,8,9,10,11};

  //Array for checking parity sums
  int checkp[4];
  //Adding to find if parity is even/odd
  checkp[0] = (brokenSeqInt[2] + brokenSeqInt[4] + brokenSeqInt[6] + brokenSeqInt[8] + brokenSeqInt[10]) % 2;
  checkp[1] = (brokenSeqInt[2] + brokenSeqInt[5] + brokenSeqInt[6] + brokenSeqInt[9] + brokenSeqInt[10]) % 2;
  checkp[2] = (brokenSeqInt[4] + brokenSeqInt[5] + brokenSeqInt[6] + brokenSeqInt[11]) % 2;
  checkp[3] = (brokenSeqInt[8] + brokenSeqInt[9] + brokenSeqInt[10] + brokenSeqInt[11]) % 2;


  //Array for checking whether or not the parity is correct based off sums
  int truep[4];
  //Sees if there are more than one parity that is incorrect which implies that all parity bits are correct and that a bit is wrong
  int truepsum = 0;

  for(int i = 0; i < 4; i++){
    if(checkp[i] == 0 && brokenSeqInt[parityBits[i]] == 0){
      truep[i] = 0;
    } else if (checkp[i] == 1 && brokenSeqInt[parityBits[i]] == 1){
      truep[i] = 0;
    } else {
      truep[i] = 1; //This parity is incorrect "supposedly"
    }
    truepsum += truep[i];
  }


  //Placeholder for the broken bit/ parity bit to use to fix for later

  int brokenbitindex = 0;

  if(truepsum == 1){ //Checks if only one parity is incorrect which implies that its the incorrect bit

    for(int i = 0; i<4; i++){
      if(truep[i] == 1){
        brokenbitindex = parityBits[i];
      }
    }
    if(fixedSequence[brokenbitindex] == '1'){
      fixedSequence[brokenbitindex] = '0';
    } else {
      fixedSequence[brokenbitindex] = '1';
    }

  } else {


    //Placeholders to see if non parity bits are broken under conditions
    int brokenbit[8] = {0,0,0,0,0,0,0,0};


    //Luckily for us, each bit effects different parities. No 2 have the same combination
    brokenbit[0] = truep[0] + truep[1];
    brokenbit[1] = truep[0] + truep[2];
    brokenbit[2] = truep[1] + truep[2];
    brokenbit[3] = truep[0] + truep[1] + truep[2];
    brokenbit[4] = truep[0] + truep[3];
    brokenbit[5] = truep[1] + truep[3];
    brokenbit[6] = truep[0] + truep[1] + truep[3];
    brokenbit[7] = truep[2] + truep[3];

    //Checking all the cases
    for(int i = 0 ; i < 8 ; i++){

      if(i == 3 || i == 6){ //These bits effect 3 parities so we know if its these if the broken bit affected 3 parities
        if(brokenbit[i] == 3){
          brokenbitindex = realBits[i]; //Getting the index value of broken bit

        }
      } else {
        if(brokenbit[i] == 2){ //Bits affecting only 2 parities
          brokenbitindex = realBits[i];
        }
      }
    }

    //Fixing the broken bit
    if(fixedSequence[brokenbitindex] == '1'){
      fixedSequence[brokenbitindex] = '0';
    } else {
      fixedSequence[brokenbitindex] = '1';
    }



  }

  //BitCase

  }





// This program takes in a corrupted 12-bit hamming code sequence from the user and then
// attempts to correct the corrupted bits.   It is assumed that exactly one bit in each
// of the 12-bit sequences has been flipped.   The input is a large array of characters
// which are all 1's or 0's.   The incoming sequence MUST be a multiple of 12 characters.
// For example, if a data string was entered originally as "ABCD" ... then each character
// in the string would be encoded as 12-bits.  So we would need 48 bits to represent the
// input string.   These 48 bits would be coded as 48 characters consisiting of 1's or
// 0's.   So, the expected input to this program would be a large 48 character string of
// '1' and '0' chars.
int main() {
  unsigned char   brokenString[12*CHAR_LIMIT+1];
  unsigned char   fixedString[12*CHAR_LIMIT+1];
  int             charCount;

  // Get the string to decode
  char formatString[10];
  sprintf(formatString, "%%%ds", 12*CHAR_LIMIT);
  scanf(formatString, (char *)brokenString);
  charCount = strlen(brokenString);

  // Make sure that the string size is a multiple of 12 characters, otherwise something is wrong
  if (charCount%12 != 0) {
    printf("The entered bit sequence must have a multiple of 12 bits.\nThis sequence has %d bits left over.\n", charCount%12);
    exit(-1);
  }

  // Fix the bits in the brokenString by identifying the single flipped bit in each of
  // the sequential sets of 12 bits
  for (int i=0; i<charCount/12; i++)
    fix(&brokenString[i*12], &fixedString[i*12]);
  fixedString[12*(charCount/12)] = '\0';
  printf("%s\n", fixedString);
}
