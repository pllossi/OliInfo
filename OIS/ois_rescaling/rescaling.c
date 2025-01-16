#include <stdio.h>
#include <assert.h>

#define MAXN 5000

int erase(int N, int S[]) {
    // insert your code here
    return 42;
}


int S[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &S[i]));

    fprintf(fw, "%d\n", erase(N, S));
    fclose(fr);
    fclose(fw);
    return 0;
}
