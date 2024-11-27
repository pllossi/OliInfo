// NOTE: it is recommended to use this even if you don't understand the following code.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// constraints
#define MAXM 100000

// input data
int N, M, T, i;
int A[MAXM], B[MAXM], C[MAXM], E[MAXM];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(3 == scanf("%d %d %d", &N, &M, &T));
    for(i=0; i<M; i++)
        assert(4 == scanf("%d %d %d %d", &A[i], &B[i], &C[i], &E[i]));

    // insert your code here
    
    printf("%d\n", 42); // print the result
    return 0;
}
