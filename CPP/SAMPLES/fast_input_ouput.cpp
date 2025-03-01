#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>
#include <limits>

using namespace std;

#ifdef _WIN32
    #define getchar_unlocked _getchar_nolock
#endif

const int N = 1'000'000; // 1 million numbers

// Fast input using getchar_unlocked()
inline int fastInput() {
    int n = 0;
    char ch = getchar_unlocked();
    while (ch < '0' || ch > '9') ch = getchar_unlocked();  // Skip non-numeric characters
    while (ch >= '0' && ch <= '9') {
        n = (n * 10) + (ch - '0');
        ch = getchar_unlocked();
    }
    return n;
}

int main() {
    vector<int> numbers(N);

    clock_t start, end;
    
    start = clock();
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    end = clock();
    cout << "cin: " << double(end - start) / CLOCKS_PER_SEC << " sec\n";

    cin.sync();

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    start = clock();
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    end = clock();
    cout << "cin (optimized): " << double(end - start) / CLOCKS_PER_SEC << " sec\n";

    cin.sync();

    start = clock();
    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }
    end = clock();
    cout << "scanf: " << double(end - start) / CLOCKS_PER_SEC << " sec\n";

    start = clock();
    for (int i = 0; i < N; i++) {
        numbers[i] = fastInput();
    }
    end = clock();
    cout << "getchar_unlocked(): " << double(end - start) / CLOCKS_PER_SEC << " sec\n";

    return 0;
}
