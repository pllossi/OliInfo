// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// input data
int N, M, T;
vector<int> A, B, C, E;

int main() {
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");

    cin >> N >> M >> T;
    A.resize(M);
    B.resize(M);
    C.resize(M);
    E.resize(M);
    for (int i=0; i<M; i++)
        cin >> A[i] >> B[i] >> C[i] >> E[i];

    // insert your code here

    cout << 42 << endl; // print the result
    return 0;
}
