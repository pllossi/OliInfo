#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    // Read array and create prefix sums
    vector<long long> prefix(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        prefix[i] = prefix[i-1] + x;
    }
    
    // Process queries
    while(q--) {
        int a, b;
        cin >> a >> b;
        // Since array is 1-indexed in the problem
        cout << prefix[b] - prefix[a-1] << '\n';
    }
    
    return 0;
}