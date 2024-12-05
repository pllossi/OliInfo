// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;

    int K;
    cin >> K;

    int S;
    cin >> S;

    string R = "";


    int post=N*K;
    if (post<S) {
        R = "NO";
    } else {
        R = "YES";
    }


    cout << R << endl;

    return 0;
}
