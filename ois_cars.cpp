#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000;
#define MAXP MAXN-1;
int res = 0;
int n;
vector<int> a;
vector<int> p;
int main(){
    for(int i = 0; i < n; i++){
        int l;
        cin >> l;
        p.push_back(l);
    }
    a=p;
    sort(p.begin(),p.end());
    for (int i = 0; i < a.size(); i++)
    {
        if(p[i]!=a[i]){
           res++; 
        }
    }
    cout<<res;    
}