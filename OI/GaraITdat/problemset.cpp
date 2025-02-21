#include <bits/stdc++.h>

using namespace std;

vector<int> bilancia(int N, int M, vector<vector<int>> S) {
    vector<vector<bool>> mustBeBefore(M, vector<bool>(M, false));
    
    for (int i = 0; i < N; i++) {
        set<int> solved;
        for (int prob : S[i]) {
            solved.insert(prob);
        }
        
        for (int a : S[i]) {
            for (int b = 0; b < M; b++) {
                if (!solved.count(b)) {
                    mustBeBefore[b][a] = true;
                }
            }
        }
    }
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            if (mustBeBefore[i][j] && mustBeBefore[j][i]) {
                return vector<int>(); 
            }
        }
    }
    
    vector<int> result;
    vector<bool> used(M, false);
    
    while (result.size() < M) {
        int next = -1;
        for (int i = 0; i < M; i++) {
            if (!used[i]) {
                bool possible = true;
                for (int j = 0; j < M; j++) {
                    if (!used[j] && mustBeBefore[i][j]) {
                        possible = false;
                        break;
                    }
                }
                if (possible) {
                    next = i;
                    break;
                }
            }
        }
        
        if (next == -1) {
            return vector<int>();  
        }
        
        result.push_back(next);
        used[next] = true;
    }
    
    return result;
}