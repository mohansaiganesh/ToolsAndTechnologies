#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t hashValue = 0;
        for (const auto& element : v) {
            hashValue = hashValue * 31 + std::hash<int>{}(element);  // Better hash combining method
        }
        return hashValue;
    }
};


int main(){
    unordered_set<vector<int>, VectorHash> mySet;

    // Insert vectors into the set
    mySet.insert({1, 2, 3});
    mySet.insert({4, 5, 6});
    mySet.insert({2, 1, 3});  // Duplicate vector (will not be inserted)

    // Print the elements in the set
    for (const auto& vec : mySet) {
        cout << "{";
        for (int num : vec) {
            cout << num << " ";
        }
        cout << "}\n";
    }
    

    return 0;
}


