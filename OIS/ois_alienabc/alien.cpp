#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool backtrack(const string& S, int index, vector<string>& current, unordered_set<string>& used) {
    // If we've processed the entire string, we're done
    if (index == S.length()) {
        return true;
    }
    
    // Try single letter
    if (index < S.length()) {
        string single_letter(1, S[index]);
        if (used.count(single_letter) == 0) {
            current.push_back(single_letter);
            used.insert(single_letter);
            
            if (backtrack(S, index + 1, current, used)) {
                return true;
            }
            
            // Backtrack
            current.pop_back();
            used.erase(single_letter);
        }
    }
    
    // Try double letter
    if (index + 1 < S.length() && S[index] == S[index+1]) {
        string double_letter(2, S[index]);
        if (used.count(double_letter) == 0) {
            current.push_back(double_letter);
            used.insert(double_letter);
            
            if (backtrack(S, index + 2, current, used)) {
                return true;
            }
            
            // Backtrack
            current.pop_back();
            used.erase(double_letter);
        }
    }
    
    return false;
}

string solve_alienabc(const string& S) {
    vector<string> result;
    unordered_set<string> used;
    
    if (backtrack(S, 0, result, used)) {
        // Construct output string
        string output;
        for (size_t i = 0; i < result.size(); i++) {
            output += result[i];
            if (i < result.size() - 1) {
                output += " ";
            }
        }
        return output;
    }
    
    return "-1";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    for (int ii = 0; ii < T; ii++) {
        string S;
        cin >> S;
        
        // Solve each test case
        cout << solve_alienabc(S) << '\n';
    }
    
    return 0;
}