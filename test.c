#include<stdio.h>
int test(int x){
    int y = x;
    y=2*y+x;
    return y;
}
int main(){
    int x = 0;
    int y=test(x);
    return 1;
}
