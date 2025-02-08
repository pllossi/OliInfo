// https://training.olinfo.it/task/ponti

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> città;
vector<int> dsu;
//dsu per trovare le città isolate per poi collegarle con una stada
int find(int a)
{
        if(dsu[a] == a)
                return a;
        return dsu[a] = find(dsu[a]);
}

void unite(int x,int y){
        x = find(x);
        y = find(y);
        dsu[x] = y;
}


int main()
{
        ifstream fin("input.txt");
        ofstream fout("output.txt");

        fin >> N >> M;

        for(int i =0;i<M;i++)
        {
                for(int l=0;l<N;l++)
                {
                        int a;
                        fin >> a;
                        città.push_back(a);
                }
        }
        //ora devo trovare le città isolate e collegarle con una strada
        dsu.resize(N);
        for(int i = 0;i<N;i++)
                dsu[i] = i;
        for(int i = 0;i<M;i++)
        {
                for(int l = 0;l<N;l++)
                {
                        if(città[i*N+l] == 1)
                                unite(i,l);
                }
        }
        int ans = 0;
        for(int i = 0;i<N;i++)
        {
                if(dsu[i] == i)
                        ans++;
        }
        fout << ans-1 << endl;
        return EXIT_SUCCESS;
}