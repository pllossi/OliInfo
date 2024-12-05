// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>

using namespace std;

int f(int i,vector<int> &meno, vector<int> &T){
    int ris_a;
    int ris_b;
    if(i==T.size()){
        return 0;
    }
    if(meno[i]!=-1){
        return meno[i];
    }
    ris_a=T[i]+f(i+1,meno,T);
    ris_b=T[i]+f(i+2,meno,T);
    meno[i]=min(ris_a,ris_b);
    return min(ris_a,ris_b);
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");
    
    int N;
    cin >> N;
    vector<int> T(N);
    for (int i=0; i<N; i++)
        cin >> T[i];
    vector<int>l (N,-1);
    int sola=f(0,l,T);
    int solb=f(1,l,T);
    cout << min(sola,solb) << endl;
    return 0;
}
