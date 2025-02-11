#include <iostream>
#include <iomanip>

int main(){
    double k = 1.1234567;

    std::cout<<"k without precision: "<<k<<std::endl;

    //setting precision upto 10 significant digits(including before and after the decimal point)
    std::cout<<"k with precision: "<<std::setprecision(10)<<k<<std::endl; 

    return 0;
}