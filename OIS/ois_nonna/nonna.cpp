#include <bits/stdc++.h>

using namespace std;

#define MAXN 5000
#define MAXK 5000
#define MAXP 1000000

const int INF = 1e9;
vector<vector<int>> dp(MAXN, vector<int>(MAXK, -1));
int mangia(int N, int K, int P[],int pos,int rim) {

}


int P[MAXN];

int main() {
    FILE *fr, *fw;
    int N, K, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &K));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &P[i]));
    fprintf(fw, "%d\n", mangia(N, K, P,0,N));
    fclose(fr);
    fclose(fw);
    return 0;
}
