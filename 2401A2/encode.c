#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define DATA_BITS    8
#define PARITY_BITS  4
#define CHAR_LIMIT   100


// Encode the given character c into a bitSequence of size (DATA_BITS + PARITY_BITS).
// Each character in bitSequence must be a '1' or '0' character corresponding to one of the
// proper hamming code data bits or parity bits.  For example, if c='A', then the
// resulting string "100010010001" should be stored in bitSequence.
void encode(unsigned char c, char bitSequence[]) {

  //Placed value to read the bits backwords
  int placed = 7;

  //placeholder values for parity sums
  int p1 = 0;
  int p2 = 0;
  int p4 = 0;
  int p8 = 0;

  for(int i = 0; i < 12; i++){
    if(i != 0 && i != 1 && i != 3&& i != 7){ //Checks if i is index of parities (We don't want that)
      char place = '2';
      if(((c & (1 << placed))>>placed) > 0 ){ //Finding out if bit is 1 or 0
        place = '1';
        placed--;
      } else {
        place = '0';
        placed--;
      }

      switch(i){ //Switch case to add sums of parities and to set bitsequence values
        case 2:
        bitSequence[2] = place;
        if(place == '1'){
          p1++;
          p2++;
        }
        break;
        case 4:
        bitSequence[4] = place;
        if(place == '1'){
          p1++;
          p4++;
        }
        break;
        case 5:
        bitSequence[5] = place;
        if(place == '1'){
          p2++;
          p4++;
        }
        break;
        case 6:
      //  printf("?");
    //    printf("%c\n",place);
        bitSequence[6] = place;
        if(place == '1'){
          p1++;
          p2++;
          p4++;
        }
        break;
        case 8:
        bitSequence[8] = place;
        if(place == '1'){
          p1++;
          p8++;
        }
        break;
        case 9:
        bitSequence[9] = place;
        if(place == '1'){
          p2++;
          p8++;
        }
        break;
        case 10:
        bitSequence[10] = place;
        if(place == '1'){
          p1++;
          p2++;
          p8++;
        }
        break;
        case 11:
        bitSequence[11] = place;
        if(place == '1'){
          p4++;
          p8++;
        }
        break;

      }

    } else {
      bitSequence[i] = '5'; //placeholder
    }
  }
  bitSequence[12] = '\0'; //Null terminating

  //Setting the parity values based off even/odd
  if((p1%2) == 0){
    bitSequence[0] = '0';
  } else {
    bitSequence[0] = '1';
  }
  if((p2%2) == 0){
    bitSequence[1] = '0';
  } else {
    bitSequence[1] = '1';
  }
  if((p4%2) == 0){
    bitSequence[3] = '0';
  } else {
    bitSequence[3] = '1';
  }
  if((p8%2) == 0){
    bitSequence[7] = '0';
  } else {
    bitSequence[7] = '1';
  }



  // ...

}


// This program gets a string of ASCII characters from the user and then encodes each character
// using a 12-bit hamming code scheme, which uses 4 parity bits.  The output is displayed as a single
// string that represents a sequence of bits which has length of 12 times the number of characters
// entered.  The resulting string output consists solely of '1' and '0' characters.
int main() {
  unsigned char   transmitString[CHAR_LIMIT+1];
  unsigned char   encodedCharacters[(12+1)*(CHAR_LIMIT+1)];
  int             charCount;

  // Get the string to encode
  char formatString[10];
  sprintf(formatString, "%%%ds", CHAR_LIMIT);
  scanf(formatString, (char *)transmitString);
  charCount = strlen(transmitString);

  // Encode each character in the string by using a 12-bit hamming code
  for (int i=0; i<charCount; i++) {
    encode(transmitString[i], &encodedCharacters[i]);
    printf("%s", &encodedCharacters[i]);
  }
  printf("\n");
}
