#include <stdio.h>
#include <math.h>

int main () {


  //Setting input values;
  float length;
  float width;
  //static values
  float curbl = 11.8;
  float curbw = 4.3;
  float curbCost = 2.48;
  float paverCost = 3.90;
  float PaverLandW = 7.75;

  //Getting Length of patio with restrictions
  printf( "Enter the length of your patio in feet: ");
  scanf("%f", &length ); //Taking the input value for length
  length = length*12;
  if(length*12 < 24){ //Checks to see if length is larger than 24 inches, if not ends the program
    printf("The patio length is not large enough\n");
    return 0;
  }

  //Getting width of patio with restrictions
  printf("Enter the width of your patio: ");
  scanf("%f", &width ); //Taking the input value for width
  width = width*12;
  if(width*12 < 24){ //Checks to see if width is larger than 24 inches, if not ends the program
    printf("The patio length is not large enough\n");
    return 0;
  }


  //Calculating
  float PaverL = length - curbw*2; //Subtracts 8.6 to take account the width of curbs on the outside.
  float PaverW = width - curbw*2; //Subtracts 8.6 to take account the width of curbs on the outside.

  float curbsL = length/curbl;
  float curbsW = (width-curbw*2)/curbl;

  float PaversL = PaverL/PaverLandW;
  float PaversW = PaverW/PaverLandW;


  //Getting the total number of curbs needed
  float wholeCurbsL = (ceil(curbsL))*2;
  float wholeCurbsW = (ceil(curbsW))*2;
  float TotalNeededCurbs = wholeCurbsL + wholeCurbsW;

  //Getting the total number of pavers needed
  float wholePaversL = (ceil(PaversL));
  float wholePaversW = (ceil(PaversW));
  float TotalNeededPavers = wholePaversL*wholePaversW;

  //Getting the Costs
  float TotalCostCurbs = TotalNeededCurbs*curbCost;
  float TotalCostPavers = TotalNeededPavers*paverCost;
  float TotalCost = TotalCostCurbs+TotalCostPavers;
  float HSTofTotalCost = TotalCost*.13;
  float TotalCostwithTax = TotalCost*1.13;

  printf("\nPatio cost and Requirements \n \nThe Curbs Needed:  %.0f\nThe Pavers Needed:   %.0f \nCost of Curbs:        %.2f $\nCost of Pavers:    %.2f $\nTotal Cost Without Tax:     %.2f $\nHST:   %.2f $\nTotal Cost With Tax:  %.2f $\n"
  ,TotalNeededCurbs,TotalNeededPavers,TotalCostCurbs,TotalCostPavers,TotalCost,HSTofTotalCost,TotalCostwithTax);





  return 0;

}
