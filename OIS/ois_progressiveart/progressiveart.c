// NOTE: it is recommended to use this even if you don't understand the following code.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000
#define MAXS 1000

int K, L, M, N, i;
char A[MAXN][MAXS];

int main() {
    // uncomment the two following lines if you want to read/write from files
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    assert(4 == scanf("%d%d%d%d", &N, &M, &L, &K));

    // INSERT YOUR CODE HERE

    if (1) {
        printf("YES\n");
        for (i = 0; i < N; ++i)
            printf("%s\n", A[i]);
    } else {
        printf("NO\n");
    }

    return 0;
}
