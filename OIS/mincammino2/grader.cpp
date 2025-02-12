    #include <bits/stdc++.h>
    using namespace std;

    void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<long long>& D) {
        vector<vector<pair<int, long long>>> adj(N + 1);
        for(int i = 0; i < M; i++) {
            adj[X[i]].push_back({Y[i], (long long)P[i]});
        }

        fill(D.begin(), D.end(), LLONG_MAX);
        D[1] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 1});

        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if(d > D[u]) continue;

            for(auto [v, w] : adj[u]) {
                if(D[u] + w < D[v]) {
                    D[v] = D[u] + w;
                    pq.push({D[v], v});
                }
            }
        }
    }

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> X(M), Y(M), P(M);
    vector<long long> D(N + 1);

    for (int i = 0; i < M; i++) {
        cin >> X[i] >> Y[i] >> P[i];
        X[i]++; Y[i]++;
    }

    mincammino(N, M, X, Y, P, D);

    for (int i = 1; i <= N; i++) {
        cout << D[i] << ' ';
    }
    cout << '\n';
}
