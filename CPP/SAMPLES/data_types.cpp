#include <iostream>
#include<limits>

using namespace std;

void print_limits(){
   cout << "Int Min"<< std::numeric_limits<int>::min() << endl;
   return;
}

int main() {
   cout << "Size of char : " << sizeof(char) << endl;
   cout << "Size of int : " << sizeof(int) << endl;
   cout << "Size of short int : " << sizeof(short int) << endl;
   cout << "Size of long int : " << sizeof(long int) << endl;
   cout << "Size of long long int : " << sizeof(long long int) << endl;
   cout << "Size of float : " << sizeof(float) << endl;
   cout << "Size of double : " << sizeof(double) << endl;
   cout << "Size of long double : " << sizeof(long double) << endl;
   cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;

   cout<<endl;
   print_limits();
   
   return 0;
}