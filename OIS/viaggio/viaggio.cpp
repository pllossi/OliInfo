// https://training.olinfo.it/task/viaggio

#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

int main()
{
    int min;
    int N,M;
    cin >> N >> M;
    vector<vector<pair<int,int>>> viaggi(N+1);
    for(int i=0;i<M;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        viaggi[a].push_back(mp(b,c));
        viaggi[b].push_back(mp(a,c));
    }
    vector<int> distanze(N+1,INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distanze[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        int nodo = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > distanze[nodo]) continue;
        for (auto &viaggio : viaggi[nodo])
        {
            int vicino = viaggio.first;
            int peso = viaggio.second;
            if (distanze[vicino] > distanze[nodo] + peso)
            {
                distanze[vicino] = distanze[nodo] + peso;
                pq.push({distanze[vicino], vicino});
            }
        }
    }
    cout << min << endl;

}