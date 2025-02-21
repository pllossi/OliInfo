#include <bits/stdc++.h>

using namespace std;

bool isValidSequence(const vector<int>& sequence) {
    for (int i = 1; i < sequence.size(); i++) {
        bool curr_is_even = (sequence[i] % 2 == 0);
        bool prev_is_even = (sequence[i-1] % 2 == 0);
        if (curr_is_even == prev_is_even) {
            return false;
        }
    }
    return true;
}

int traffico(int N, vector<int> S) {
    if (N <= 1) return 0;

    vector<int> seq1 = S;
    vector<int> seq2 = S;
    if (seq2[0] % 2 == 0) seq2[0]++; else seq2[0]++;

    int changes1 = 0;
    int changes2 = 1;


    for (int i = 1; i < N; i++) {
        bool should_be_even1 = (seq1[i-1] % 2 == 1);
        bool should_be_even2 = (seq2[i-1] % 2 == 1);

        if ((seq1[i] % 2 == 0) != should_be_even1) {
            seq1[i] += (seq1[i] % 2 == 0) ? 1 : 1;
            changes1++;
        }

        if ((seq2[i] % 2 == 0) != should_be_even2) {
            seq2[i] += (seq2[i] % 2 == 0) ? 1 : 1;
            changes2++;
        }
    }

    if (!isValidSequence(seq1)) changes1 = N+1;
    if (!isValidSequence(seq2)) changes2 = N+1;

    return min(changes1, changes2);
}