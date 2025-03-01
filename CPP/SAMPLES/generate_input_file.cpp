#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 1000000; // 1 million numbers

int main() {
    ofstream outFile("input.txt"); // Open file for writing
    if (!outFile) {
        cerr << "Error opening file!\n";
        return 1;
    }

    srand(time(0)); // Seed for randomness

    for (int i = 0; i < N; i++) {
        outFile << (rand() % 1000000 + 1) << "\n"; // Generate a random number between 1 and 1,000,000
    }

    outFile.close(); // Close file
    cout << "input.txt generated successfully!\n";

    return 0;
}
