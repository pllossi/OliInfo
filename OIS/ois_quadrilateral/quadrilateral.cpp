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

    int N;
    cin >> N;
    
    vector<long long> S(N);
    for (int i = 0; i < N; ++i)
        cin >> S[i];
    
    bool ans = true;
    vector<int> Q(4);
    
    
    // INSERT YOUR CODE HERE
    
    
    if (ans) {
        for (int i = 0; i < 4; ++i)
            cout << Q[i] << " ";
        cout << endl;
    } else {
        cout << -1 << endl;
    }


    return 0;
}
