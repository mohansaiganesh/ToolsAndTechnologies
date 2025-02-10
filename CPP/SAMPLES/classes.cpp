#include <iostream>

using namespace std;


class Box {
    // private:
    int length=0, width=0;

    public:
    int getLength(){
        return length;
    }
    int getWidth(){
        return width;
    }

};

int main(){
    Box bObj;
    cout<<bObj.getLength()<<endl;
    return 0;
}