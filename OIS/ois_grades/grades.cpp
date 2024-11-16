/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>

// constraints
#define MAXN 1000000

// input data
int N, i,res=0;
int G[MAXN];

int main() {
    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &G[i]));

    for(i=0; i<N; i++){
        if(G[i]>6){
            res++;
        }
    }
    if(res==0){
        res=-1;
    }
    printf("%d\n", res); // print the result
    return 0;
}
