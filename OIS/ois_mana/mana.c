// NOTE: it is recommended to use this even if you don't understand the following code.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 100000

int       K, N, i;
int       C[MAXN];
long long M;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d%d", &N, &K));

    for (i = 0; i < N; ++i)
        assert(1 == scanf("%d", &C[i]));

    M = 0;


    // INSERT YOUR CODE HERE


    printf("%lld\n", M);

    return 0;
}
