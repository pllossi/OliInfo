// NOTE: it is recommended to use this even if you don't understand the following code.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// constraints
#define MAXN 10000

// input data
int N;
int V[MAXN];

int main() {
    // uncomment the following lines if you want to read/write from files
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for (int i = 0; i < N; i++) {
        assert(1 == scanf("%d", &V[i]));
    }

    // insert your code here

    printf("%d\n", 42); // print the result
    
    return 0;
}
