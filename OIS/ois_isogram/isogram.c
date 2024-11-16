// NOTE: it is recommended to use this even if you don't understand the following code.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// constraints
#define MAXC 100

// input data
int N, i;
char S[MAXC + 1];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d\n", &N));
    for(i=0; i<N; i++) {
        assert(gets(S));

        // insert your code here

    }

    printf("%d\n", 42); // print the result
    return 0;
}
