#include<iostream>
#include<thread>
using namespace std;
void func1(void){
   cout<<"func1 working"<<endl;
}

int main(){
    std::thread t1(func1);
    t1.join();
    cout<<"thread had inplemented"<<endl;
    getchar();
    return 1;
}
