// NOTE: it is recommended to use this even if you don't understand the following code.
#include <bits/stdc++.h>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;

    vector<int> D(10);

    for(int i = 1; i<=N;i++){
        string s = to_string(i);
        for(int j = 0; j<s.size();j++){
            D[s[j]-'0']++;
        }
    }

    for (int i = 0; i < 10; ++i)
        cout << D[i] << " ";
    cout << endl;

    return 0;
}
