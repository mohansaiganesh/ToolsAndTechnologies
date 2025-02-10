#include <iostream>
#include <typeinfo>

using namespace std;

int main(){
    cout << typeid(0255).name() <<" value " << 0255 <<endl ;

    cout << typeid(314159E-5L).name() <<" value " << 314159E-5L <<endl ;

    return 0;
}