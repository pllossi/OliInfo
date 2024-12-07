#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int tempo_massimo(int N, int a[], int b[])
{
    int maxtime = 0;
    int lastimetaken=0;
    int lastaken;//0 for a, 1 for b
    for (int i = 0; i < N; i++){
         if(a[i]>b[i]&&i==0){
            maxtime+=a[i];
            lastaken=0;
            lastimetaken=i;
         } else {
            maxtime+=b[i];
            lastaken=1;
            lastimetaken=i;
         }
         if(a[i]>b[i]){
            if(lastaken==0){
                maxtime+=a[i];
                lastimetaken=i;
            } else {
                if(lastimetaken==i-1)
                    maxtime+=a[i];
            }
         } else {
            if(lastaken==1){
                maxtime+=b[i];
                lastimetaken=i;
            } else {
                if(lastimetaken==i-1)
                    maxtime+=b[i];
                    lastimetaken=i;
            }
         }
    }
    return maxtime;
}


int main()
{
    int n;
    FILE *in = stdin, *out = stdout;
    assert(fscanf(in, "%d", &n) == 1);

    int *a = (int*)calloc(n, sizeof(int));
    int *b = (int*)calloc(n, sizeof(int));

    for(int i=0; i<n; i++){
      assert(fscanf(in, "%d", a + i) == 1);
      assert(fscanf(in, "%d", b + i) == 1);
    }

    int answ = tempo_massimo(n, a, b);
    fprintf(out, "%d\n", answ);

    free(a);
    free(b);

    fclose(in);
    fclose(out);

    return EXIT_SUCCESS;
}
