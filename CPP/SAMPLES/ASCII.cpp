#include <iostream>

int main(){

    char ch1, ch2, ch3;

    ch1 = 65;
    ch2 = 97;
    ch3 = 48;

    std::cout << "ch1: "<<ch1<<std::endl;
    std::cout << "ch2: "<<ch2<<std::endl;
    std::cout << "ch3: "<<ch3<<std::endl;

    int myvariable = 97;
    char mychar = 'a';
    std::cout << "character value of myvariable: "<<char(myvariable)<<std::endl;
    std::cout << "ASCII value of mychar: "<<int(mychar)<<std::endl;
    return 0;
}