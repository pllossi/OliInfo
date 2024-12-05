#include <bits/stdc++.h>

#define MAXN 10000
#define MAXK 10000
#define MAXM 100000

using namespace std;

int compra(int N, int M, int K, int supermercati[], int da[], int a[]) {
    queue <int>q;
    vector<int>distance(N,-1);
    q.push(1);
    distance[1]=0;
    vector<vector<int>>G(N+1);
    for(int i =0;i<M;i++){
        G[a[i]].push_back(da[i]);
        G[da[i]].push_back(a[i]);
    }
    while(!q.empty()){
        int nodo=q.front();
        q.pop();
        for (int figlio : G[nodo])
        {
            if(!distance[figlio]==-1)
            {
                q.push(figlio);
                distance[figlio] = distance[nodo]+1;
            }
        }
    }
    

    return 42;
}


int supermercati[MAXK], da[MAXM], a[MAXM];

int main() {
    FILE *fr, *fw;
    int N, M, K, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(3 == fscanf(fr, "%d%d%d", &N, &M, &K));
    for(i=0; i<K; i++)
        assert(1 == fscanf(fr, "%d", &supermercati[i]));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d%d", &da[i], &a[i]));
    fprintf(fw, "%d\n", compra(N, M, K, supermercati, da, a));
    fclose(fr);
    fclose(fw);
    return 0;
}
