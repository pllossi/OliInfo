#include <bits/stdc++.h>
#include <vector>

using namespace std;

#define MAXN 1000000

const int INF = 1e9+7;
[[nodiscart]]int receive(vector<int> &memo ,int N, int V[],int pos) {
    if(pos < 0) return 1;
    if(memo[pos] != -1) return memo[pos];
    int ans{};
    ans += receive(memo,N,V,pos-1-V[pos]);
    ans += receive(memo,N,V,pos-1);
    return memo[pos] = ans%INF;
}


int V[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &V[i]));
    vector<int> memo(N,-1);
    fprintf(fw, "%d\n", receive(memo,N, V, N-1));
    fclose(fr);
    fclose(fw);
    return 0;
}
