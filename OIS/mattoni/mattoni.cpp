// https://training.olinfo.it/task/mattoni
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n, m;
    cin >> n >> m;
    
    vector<long long> diff(n + 1, 0);
    
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--; 
        diff[l]++; 
        diff[r]--;
    }
    
    vector<long long> heights(n);
    long long curr_height = 0;
    for (int i = 0; i < n; i++) {
        curr_height += diff[i];
        heights[i] = curr_height;
    }
    
    nth_element(heights.begin(), heights.begin() + n/2, heights.end());
    cout << heights[n/2] << endl;
    
    return 0;
}