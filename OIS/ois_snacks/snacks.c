// NOTE: it is recommended to use this even if you don't understand the following code.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// constraints
#define MAXN 100000

// input data
int N, X;
int L[MAXN];

int main() {
    // uncomment the following lines if you want to read/write from files
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d%d", &N, &X));
    for (int i = 0; i < N; i++) {
        assert(1 == scanf("%d", &L[i]));
    }

    // insert your code here

    printf("%d\n", 42); // print the result
    return 0;
}
