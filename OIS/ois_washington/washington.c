// NOTE: it is recommended to use this even if you don't understand the following code.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXS 128
#define MAXT 10000

int    L, T, i;
char   S[3][MAXS], D[3][MAXS];

int main() {
    // uncomment the two following lines if you want to read/write from files
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &T));

    for (i = 0; i < T; ++i) {
        assert(3 == scanf("%s %s %s", S[0], S[1], S[2]));
        assert(3 == scanf("%s %s %s", D[0], D[1], D[2]));

        L = 0;


        // INSERT YOUR CODE HERE


        printf("%d\n", L);
    }

    return 0;
}
