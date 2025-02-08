#include <bits/stdc++.h>

using namespace std;

#define MAXM 100000
#define mp make_pair
#define pr pair<int, int>

//si usa la dsu per trovare i nodi isolati e poi si costruisce un ponte per collrgarlo al resto

vector<int> dsu;
int find(int x) {
    if(dsu[x] == x) return x;
    int nuovo_capo = find(dsu[x]);
    dsu[x] = nuovo_capo;
    return nuovo_capo;
}

void unite(int x, int y) {
    int capo_x = find(x);
    int capo_y = find(y);
    dsu[capo_x] = capo_y;
}
//possono essere più di 1 ponte da costruire
int costruisci(int N,int M, int da[],int a[]){
    dsu.resize(N);
    for(int i=0; i<N; i++) dsu[i] = i;
    for(int i=0; i<M; i++) {
        unite(da[i], a[i]);
    }
    vector<int> isolati;
    for(int i=0; i<N; i++) {
        if(find(i) == i) isolati.push_back(i);
    }
    if(isolati.size() == 1) return 0;
    return isolati.size()-1;
}


int da[MAXM], a[MAXM];

int main() {
    FILE *fr, *fw;
    int N, M, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &M));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d%d", &da[i], &a[i]));

    fprintf(fw, "%d\n", costruisci(N, M, da, a));
    fclose(fr);
    fclose(fw);
    return 0;
}
