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

    int N, M, L, K;
    cin >> N >> M >> L >> K;

    vector<string> A(N);


    // INSERT YOUR CODE HERE


    if(1){
        cout << "YES" << endl;
        for (int i = 0; i < N; ++i)
            cout << A[i] << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
