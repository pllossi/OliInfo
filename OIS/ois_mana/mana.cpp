// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, K;
    cin >> N >> K;

    vector<int> C(N);
    for (int i = 0; i < N; ++i)
        cin >> C[i];

    long long M = 0;


    // INSERT YOUR CODE HERE


    cout << M << endl;

    return 0;
}
