#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int mangia(int N, int K, int P[]) {
    // Create a dynamic programming table
    // dp[i] will store the minimum total weight to get at least K grams
    vector<int> dp(K + 1, INT_MAX);
    dp[0] = 0;

    // Process each portion
    for (int i = 0; i < N; i++) {
        // Work backwards to avoid overwriting
        for (int j = K; j >= 0; j--) {
            // If current state can be reached
            if (dp[j] != INT_MAX) {
                // Calculate new total weight when adding current portion
                int newTotal = min(K, j + P[i]);
                
                // Update minimum total weight for the new state
                dp[newTotal] = min(dp[newTotal], dp[j] + P[i]);
            }
        }
    }

    // Find the minimum total weight that meets or exceeds K
    return dp[K];
}

int main() {
    // Read input file
    ifstream input("input.txt");
    int N, K;
    input >> N >> K;

    // Read portions weights
    int* P = new int[N];
    for (int i = 0; i < N; i++) {
        input >> P[i];
    }
    input.close();

    // Solve the problem
    int result = mangia(N, K, P);

    // Write output file
    ofstream output("output.txt");
    output << result;
    output.close();

    // Free allocated memory
    delete[] P;

    return 0;
}