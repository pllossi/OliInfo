// https://training.olinfo.it/task/viaggio

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

// Utility per il debug
#define DEBUG 1
#if DEBUG
template<typename T>
void debug(const T& x) {
    cout << "» " << x << endl;
}
template<typename T, typename... Args>
void debug(const T& x, const Args&... args) {
    cout << "» " << x << " | ";
    debug(args...);
}
#else
#define debug(...)
#endif

// Alias per tipi comuni
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvpi = vector<vpi>;
using vb = vector<bool>;

// Costanti comuni
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

// Macro utili
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define nl '\n'

// Funzioni di utilità
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
    // TODO: Implementa la soluzione qui
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // Per problemi con più test case
    int T = 1;
    // cin >> T;
    while(T--) solve();
    
    return 0;
}

