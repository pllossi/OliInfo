// NOTE: it is recommended to use this even if you don't understand the following code.

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000

int       N, i;
long long S[MAXN];
int       Q[4];
bool      ans = true;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    
    for (i = 0; i < N; ++i)
        assert(1 == scanf("%lld", &S[i]));
    
    
    
    // INSERT YOUR CODE HERE
    
    
    if (ans) {
        for (i = 0; i < 4; ++i)
            printf("%d ", Q[i]);
        printf("\n");
    } else {
        printf("-1\n");}

    return 0;
}
