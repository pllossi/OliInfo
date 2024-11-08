#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");

    int N, X;
    input >> N >> X;

    vector<int> loudness(N);

    for (int i = 0; i < N; i++) {
        input >> loudness[i];
    }

    sort(loudness.begin(), loudness.end());

    int time = 0;

    int i;
    for(i = 1; i<N; i=i+2)
    {
        if(loudness[i]+loudness[i-1]<=X)
        {
           
           time = time+1;
        }
        else
        {
            
            time = time+2;
        }
    }
    if(i==N)
        time=time+1;


    output << time;


    return 0;
}
