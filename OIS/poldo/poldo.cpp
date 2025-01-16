// https://training.olinfo.it/task/poldo

#include <bits/stdc++.h>
using namespace std;
vector<int> panini(10000);
vector<int> memo(10000);
int N;
int double_penetration(int pos,int ultimoPeso){
        if(pos>=N){
                return 0;
        }
        int mangio=0;
        int nonMangio=0;
        if(panini[pos]<ultimoPeso){
                if(memo[pos]!=0){
                        mangio=memo[pos];
                } else 
                {
                        mangio=1+double_penetration(pos+1,panini[pos]);
                }
        }
        nonMangio=double_penetration(pos+1,ultimoPeso);
        memo[pos]=mangio;
        return max(mangio,nonMangio);
}

int main()
{
        ifstream in("input.txt");
        ofstream out("output.txt");
        in>>N;
        fill(memo.begin(),memo.end(),0);
        for(int i=0;i<N;i++){
                in>>panini[i];
        }
        double_penetration(0,10001);
        out<<*max_element(memo.begin(),memo.end());
        return 0;
}