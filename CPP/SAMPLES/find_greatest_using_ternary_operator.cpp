#include <iostream>

int main()
{
    int a=3000, b=24000, c=4000, d=2000;
    
    int res = a>b ? (a>c?(a>d?a:d):(c>d?c:d)) : (b>c?(b>d?b:d):(c>d?c:d));
    
    std::cout<<"greater value is: "<<res<<std::endl;

    return 0;
}