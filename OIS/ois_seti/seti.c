#include <stdio.h>
#include <assert.h>

#define MAXN 1000000

int receive(int N, int V[]) {
    // insert your code here
    return 42;
}


int V[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &V[i]));

    fprintf(fw, "%d\n", receive(N, V));
    fclose(fr);
    fclose(fw);
    return 0;
}
