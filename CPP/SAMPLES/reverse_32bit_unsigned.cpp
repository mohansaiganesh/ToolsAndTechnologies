#include<iostream>
#include<string>
#include<cstdint>
#include<algorithm>

std::string printBinary(unsigned int n){
    std::string res="";
    while(n>0){
        res+= std::to_string(n&1);
        n/=2;
    }
    std::reverse(res.begin(), res.end());

    if(res.length()<8)
    res.insert(0,8-res.length(),'0');

    return res;

}

uint32_t reverse(uint32_t n, int bits){
    
    if(bits==1)
    return n;

    uint32_t left = n >> (bits/2);
    uint32_t right = n << (bits/2);

    std::cout<<"left: "<<printBinary(left)<<std::endl;
    std::cout<<"right: "<<printBinary(right)<<std::endl;

    return left | right;
    // return reverse(left,bits/2)|reverse(right,bits/2);

}

int main(){

    uint32_t n = 170;
    std::cout<<printBinary(n)<<std::endl;

    uint32_t res = reverse(n,8);

    std::cout<<"reversed value is: "<<int(res)<<std::endl;

    std::cout<<printBinary(res)<<std::endl;

    ;

    return 0;
}