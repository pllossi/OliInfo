#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    for (int i = 0; i < T; ++i) {
        vector<string> S(3), D(3); 
        for (int j = 0; j < 3; ++j) {
            if (!(cin >> S[j])) {
                cout << "Invalid input for source strings" << endl;
                return 1;
            }
        }
        
        // Read destination strings
        for (int j = 0; j < 3; ++j) {
            if (!(cin >> D[j])) {
                cout << "Invalid input for destination strings" << endl;
                return 1;
            }
        }

        int L = 0;
        for (int j = 0; j < 3; ++j) {
            if (S[j] == D[j]) {
                L++;
            }
        }

        cout << L << endl;
    }

    return 0;
}