#include<stdio.h>
#include<inttypes.h>
typedef unsigned __int128 uint128_t;
void main(){
//    uint64_t u = 1;
    uint64_t x = 1;
    uint64_t k = 1;
//    printf("%llu  %llu\n",x,k);
    uint128_t y = x*(uint128_t)k;
 //   printf("%llu   %llu\n",(uint64_t)(y>>64),(uint64_t) y);
    printf("OK\n");
}
