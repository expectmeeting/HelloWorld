#include<stdio.h>
#include<iostream>
int main(){
    int x = 0;
    int *y = new int[1];
    y[0]=1;
    x=y[0];
    delete [] y;
    y=NULL;
    return 1;
}

