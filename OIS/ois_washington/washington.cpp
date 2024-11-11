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

    int T;
    cin >> T;

    vector<string> S(3), D(3);
    for (int i = 0; i < T; ++i) {
        cin >> S[0] >> S[1] >> S[2];
        cin >> D[0] >> D[1] >> D[2];

        int L = 0;


        // INSERT YOUR CODE HERE


        cout << L << endl;
    }

    return 0;
}
