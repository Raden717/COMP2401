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
  Fish *bucket[bucket_size];
  unsigned char numFish;
} Fisher;

//Pond Structure
typedef struct {
  Fish *fish[pond_size];
  unsigned char numFish;
} Pond;

//Adds fish to pond
//Returns 0 if didn't add, otherwise returns 1;
int addFish(Pond *p, unsigned char size, char *species){
  if(p->numFish == pond_size){ //Checks for full pond
    return 0;
  } else {
    p->fish[p->numFish] = malloc(sizeof(Fish)); //Allocate the pointer to prevent overwriting
    p->fish[p->numFish]->species = species; //Can change species and size since i allocated this pointer
    p->fish[p->numFish]->size = size;

    p->numFish = p->numFish + 1;
  }

}


//Prints out all the fish in a fish array
void listFish(Fish **arrayOfFish, int n){
  for(int i = 0; i < n; i++){ //Loops through array and prints fish
    printf("%d cm || %s \n",arrayOfFish[i]->size, arrayOfFish[i]->species);
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
      fisher->bucket[fisher->numFish] = malloc(sizeof(Fish)); //Allocate the pointer to prevent overwrites
      fisher->bucket[fisher->numFish]->species = f->species; //Allocate the fish species/size to this pointer
      fisher->bucket[fisher->numFish]->size = f->size;
      fisher->numFish++;
      return 1;
    } else {
      return 0;
    }
  }
}

int castLine(Fisher *fisher, Pond *p){
  if(p->numFish == 0){ //Checks if pond is empty
    return 0;
  }

  if(fisher->numFish == bucket_size){ //Checks if bucket is full
    return 0;
  }

  unsigned char upper = p->numFish; //placeholder value for numfish
  int num  = (rand() % upper); //Random index for a fish in the pond

  if(likes(fisher,p->fish[num]) == 1){ //Checks likes
    keep(fisher,p->fish[num]);  //Keeps it since it checks if fishers bucket is full earlier
    free(p->fish[num]); //Frees the added fish as it is no longer needed
    p->fish[num] = p->fish[p->numFish-1]; //Sets the pointer of previous fish to another pointer thats allocated
    upper--;

    p->numFish = upper;
    return 1;
  } else {
    return 0;
  }
}

void giveAwayFish(Fisher *fisher1, Fisher *fisher2, Pond *p){
  while(fisher1->numFish > 0){ //Loops through fisher1's bucket until empty
    if(likes(fisher2,fisher1->bucket[fisher1->numFish-1]) && fisher2->numFish != bucket_size){ //Checks if fisher2 has space in bucket and if they like
      keep(fisher2,fisher1->bucket[fisher1->numFish-1]); //Keeps it since thy have space and they like
      free(fisher1->bucket[fisher1->numFish-1]); //Frees memory in this bucket since its no longer needed
      fisher1->numFish--;
    } else {
      addFish(p, fisher1->bucket[fisher1->numFish-1]->size,fisher1->bucket[fisher1->numFish-1]->species); //Adds fish to the pond
      free(fisher1->bucket[fisher1->numFish-1]); //Frees memory from the bucket as addfish creates memory with malloc
      fisher1->numFish--;
    }
  }
}

int main(){
  srand(time(NULL)); //Initializes once to get random integers

  Pond p;
  p.numFish = 0;
  //Adding Fish
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
  listFish(p.fish, pond_size);

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
  printf("Fred's Bucket after attempting to catch fish\n");
  listFish(Fred.bucket, Fred.numFish);
  printf("-------------------\n");
  printf("Suzy's Bucket after attempting to catch fish\n");
  listFish(Suzy.bucket, Suzy.numFish);
  printf("-------------------\n");
  printf("Left in pond\n");
  listFish(p.fish, p.numFish);


  //Giving away fish

  printf("-------------------\n");
  printf("Suzy gives Fred some fish\n");
  giveAwayFish(&Suzy, &Fred, &p);

  printf("-------------------\n");
  printf("Freds fish\n");
  listFish(Fred.bucket, Fred.numFish);
  printf("-------------------\n");
  printf("Suzys fish\n");
  listFish(Suzy.bucket, Suzy.numFish);
  printf("-------------------\n");
  printf("Pond after everything\n");
  listFish(p.fish, p.numFish);

  //Freeing up all the memory after printing
  for(int i = 0; i < 15; i++){
    if(i < p.numFish){
      free(p.fish[i]);
    }
    if(i < Fred.numFish){
      free(Fred.bucket[i]);
    }
    if(i < Suzy.numFish){
      free(Suzy.bucket[i]);
    }
  }
  return 0;
}
