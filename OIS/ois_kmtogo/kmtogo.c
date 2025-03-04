// NOTE: it is recommended to use this even if you don't understand the following code.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int N, i;
int D[10];

int main() {
    // uncomment the two following lines if you want to read/write from files
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));



    // INSERT YOUR CODE HERE


    for (i = 0; i < 10; ++i)
        printf("%d ", D[i]);
    printf("\n");

    return 0;
}
