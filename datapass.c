#include<stdio.h>
void main(){
   char cN = 1;
   int iN = cN;
   int iN1 = 10;
   int temp = 0;
   temp = iN;
   iN = iN1;
   iN1 = temp;
   temp = iN + 6*iN;
}
