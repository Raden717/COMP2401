#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define pond_size     15
#define bucket_size   10


//Fish Strucutre
typedef struct {
  unsigned char size;
  char *species;
} Fish;

//Fisher Structure
typedef struct {
  char *name;
  unsigned char keepSize;
  Fish bucket[bucket_size];
  unsigned char numFish;
} Fisher;

//Pond Structure
typedef struct {
  Fish fish[pond_size];
  unsigned char numFish;
} Pond;

//Adds fish to pond
//Returns 0 if didn't add, otherwise returns 1;
int addFish(Pond *p, unsigned char size, char *species){
  if(p->numFish == pond_size){ //Checks for full pond
    return 0;
  } else {

    Fish addFish = {size,species}; //Creates the added fish
    p->fish[p->numFish] = addFish; //Adds the fish
    p->numFish = p->numFish + 1;
  }

}


//Prints out all the fish in a fish array
void listFish(Fish *arrayOfFish, int n){
  for(int i = 0; i < n; i++,arrayOfFish++){ //Loops through array and prints fish
    printf("%d cm || %s \n",arrayOfFish->size, arrayOfFish->species);
  }
}

//Sees if a fisher likes a fish
char likes (Fisher *fisher, Fish *f){
  if(fisher->keepSize <= f->size && (strcmp(f->species,"Sunfish")) != 0 ){
    return 1;
  } else {
    return 0;
  }
}


//Sees if a fisher likes a fish and whether or not they will keep it
int keep (Fisher *fisher, Fish *f){
  if(fisher->numFish == bucket_size){ //Checks if bucket is full
    return 0;
  } else {
    if(fisher->keepSize <= f->size){ //Checks if fisher likes it
      fisher->bucket[fisher->numFish] = *f; //Keeps it
      fisher->numFish = fisher->numFish+1;
      return 1;
    } else {
      return 0;
    }
  }
}

//Causes the fisher to cast into a pond and checks whether or not it will take the fish
int castLine(Fisher *fisher, Pond *p){
  if(p->numFish == 0){ //Checks if pond is empty
    return 0;
  }

  if(fisher->numFish == bucket_size){ //Checks if bucket is full
    return 0;
  }
  Fish nullFish = {0,0}; //Nullfish to replace fish being taken from pond
  unsigned char upper = p->numFish; //placeholder value for numfish
  int num  = (rand() % upper); //Random index for a fish in the pond


  if(likes(fisher,& p->fish[num]) == 1){
    keep(fisher,&p->fish[num]); //Since  the fisher likes it, and the fishsers bucket isnt full, it keeps it

    p->fish[num] = p->fish[upper-1]; //Changing the value for the fish that was just taken
    p->fish[upper-1] = nullFish; //Creating a nullfish for other spots in array
    upper--;
    p->numFish = upper;
    return 1;
  } else {
    return 0;
  }
}

void giveAwayFish(Fisher *fisher1, Fisher *fisher2, Pond *p){
  Fish nullFish = {0,0};
  while(fisher1->numFish > 0){ //Keeps looping through fisher1's bucket until its empty
    if(likes(fisher2,&fisher1->bucket[fisher1->numFish-1]) && fisher2->numFish != pond_size){ //Checks if fisher2 likes the fish and has space
      fisher2->bucket[fisher2->numFish] = fisher1->bucket[fisher1->numFish-1]; //Takes the fish
      fisher2->numFish++;
      fisher1->bucket[fisher1->numFish-1] = nullFish; //Replaces fish with nullfish
      fisher1->numFish--;
    } else { //Adds to pond
      addFish(p, fisher1->bucket[fisher1->numFish-1].size,fisher1->bucket[fisher1->numFish-1].species);
      fisher1->bucket[fisher1->numFish-1] = nullFish;
      fisher1->numFish--;
    }
  }
}

int main(){
  srand(time(NULL)); //Initializes once in main to get random integers

  Pond p;
  p.numFish = 0;
  //Adding  fish
  addFish(&p, 4, "Sunfish");             // 0
  addFish(&p, 25, "Pike");            // 1
  addFish(&p, 20, "Bass");            // 2
  addFish(&p, 30, "Perch");            // 3
  addFish(&p, 14, "Sunfish");            // 4
  addFish(&p, 15, "Pike");         // 5
  addFish(&p, 9, "Pike");        // 6
  addFish(&p, 12, "Bass");        // 7
  addFish(&p, 5, "Sunfish");        // 8
  addFish(&p, 12, "Sunfish");        // 9
  addFish(&p, 10, "Bass");             // 10
  addFish(&p, 2, "Bass");            // 11
  addFish(&p, 16, "Perch");            // 12
  addFish(&p, 30, "Sunfish");            // 13
  addFish(&p, 7, "Perch");            // 14

  printf("-------------------\n");
  printf("Pond\n");
  listFish(p.fish, 15);

  Fisher Fred;
  Fred.numFish = 0;
  Fred.name = "Fred";
  Fred.keepSize = 15;

  Fisher Suzy;
  Suzy.numFish = 0;
  Suzy.name = "Suzy";
  Suzy.keepSize = 10;
  //Casting Lines
  castLine(&Fred, &p);
  castLine(&Fred, &p);
  castLine(&Fred, &p);
  castLine(&Fred, &p);
  castLine(&Fred, &p);
  castLine(&Fred, &p);
  castLine(&Fred, &p);
  castLine(&Fred, &p);
  castLine(&Fred, &p);
  castLine(&Fred, &p);

  castLine(&Suzy, &p);
  castLine(&Suzy, &p);
  castLine(&Suzy, &p);
  castLine(&Suzy, &p);
  castLine(&Suzy, &p);
  castLine(&Suzy, &p);
  castLine(&Suzy, &p);
  castLine(&Suzy, &p);
  castLine(&Suzy, &p);
  castLine(&Suzy, &p);

  printf("-------------------\n");
  printf("Fred's Bucket after attempting to catch fish: \n");
  listFish(Fred.bucket, Fred.numFish);
  printf("-------------------\n");
  printf("Suzy's Bucket after attempting to catch fish: \n");
  listFish(Suzy.bucket, Suzy.numFish);
  printf("-------------------\n");
  printf("Fishes Left in pond\n");
  listFish(p.fish, p.numFish);

  //Giving away Fish

  printf("-------------------\n");
  printf("Suzy gives Fred some fish\n");
  giveAwayFish(&Suzy, &Fred, &p);

  printf("-------------------\n");
  printf("Freds fish: \n");
  listFish(Fred.bucket, Fred.numFish);
  printf("-------------------\n");
  printf("Suzys fish: \n");
  listFish(Suzy.bucket, Suzy.numFish);
  printf("-------------------\n");
  printf("Pond after everything\n");
  listFish(p.fish, p.numFish);


  return 0;
}
