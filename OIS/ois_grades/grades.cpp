#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
    vector <int> G;
    int N,Num=-1;
    fin>>N;
    for(int i=0;i<N;i++)
    {
        int TMP;
        fin>>TMP;
        G.push_back(TMP);
    }
    for(int j=0;j<N;j++)
    {
        if(G[j]<6)
        {
            for(int k=N-1;k>j;k--)
            {
                if(G[k]>=6)
                {
                    Num=k-j+1;
                    fout<<Num;
                    return 0;
                }
            }
        }
    }
    fout<<Num;
    return 0;
}