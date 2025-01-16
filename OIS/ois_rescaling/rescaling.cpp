#include <bits/stdc++.h>
#include <vector>

#define MAXN 5000
#define MAXS 1000000

vector<int> mem(N); 

int erase(int N, int S[]) {
    
    return 0;
}


int S[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &S[i]));

    fprintf(fw, "%d\n", erase(N, S));
    fclose(fr);
    fclose(fw);
    return 0;
}
