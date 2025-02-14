#include<iostream>
#include<ctime>
#include<typeinfo>



int main(){
    //get the current time 
    std::time_t now = std::time(0);
    std::cout << "Current time: "<<now<<std::endl;



    //convert to local time
    std::tm* localTime = std::localtime(&now);

    //print local time
    std::cout<<"local time is: " << std::asctime(localTime) <<std::endl;

    std::cout << "Type of localTime: " << typeid(localTime).name() << std::endl;

    std::cout<<localTime<<std::endl;



    return 0;
}