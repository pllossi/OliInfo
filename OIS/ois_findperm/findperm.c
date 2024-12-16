// NOTE: it is recommended to use this even if you don't understand the following code.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// input data
int N;

int main() {
    // uncomment the following lines if you want to read/write from files
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));

    // SAMPLE INTERACTION, REPLACE WITH YOUR CODE
    printf("%d %d\n", 1, 2);
    fflush(stdout);

    int x;
    assert(1 == scanf("%d", &x));

    printf("! ");
    for (int i = 0; i < N; i++)
        printf("%d ", i + 1);
    printf("\n");
    fflush(stdout);
    
    return 0;
}
