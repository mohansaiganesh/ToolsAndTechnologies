#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>
#include<cstdlib>

using namespace std;
using namespace std::chrono;

//generate large vector of random numbers
vector<int> generate_vector(size_t n){
    vector<int> v(n);
    for(size_t i=0;i<n;++i){
        v[i] = rand() % 10000;
    }
    return v;
}


//naive loop with erase
void test_naive(vector<int> v){

    auto start = high_resolution_clock::now();
    for(auto it=v.begin(); it!=v.end();){
        if(*it % 2 == 0){
            it = v.erase(it);
        }
        else{
            ++it;
        }
    }

    auto end = high_resolution_clock::now();

    cout<<"Naive erase time: "<<duration_cast<milliseconds>(end-start).count()<<" ms\n";
}


// smart erase-remove idiom
void test_smart(vector<int> v){
    auto start = high_resolution_clock::now();
    v.erase(remove_if(v.begin(), v.end(), [](int x){
            return x%2==0;
        }), 
        v.end()
    );

    auto end = high_resolution_clock::now();

    cout<<"Smart erase time: "<< duration_cast<milliseconds>(end-start).count()<<" ms\n";
}


int main(){
    size_t n = 100000;

    vector<int> v = generate_vector(n);

    test_naive(v);
    test_smart(v);


    return 0;
}