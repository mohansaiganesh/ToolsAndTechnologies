#include<iostream>
#include<string>

std::string reverse(std::string mystr){
    std::string res = "";
    

    int length = mystr.length();

    if(length==1)
    return mystr;

    
    std::string left = mystr.substr(length/2);
    std::string right = mystr.substr(0,length/2);

    std::cout<<left<<" "<<right<<std::endl;

    return reverse(left)+reverse(right);
}

int main(){

std::cout<<reverse("12345678")<<std::endl;

return 0;
}