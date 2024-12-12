// NOTE: it is recommended to use this even if you don't understand the following code.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// constraints
#define MAXL 100

// input data
int T;
char S[MAXL];

int main() {
    // uncomment the following lines if you want to read/write from files
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &T));
    for (int i = 0; i < T; i++) {
    	assert(1 == scanf("%s", &S));
    
	    // insert your code here

	    printf("-1\n"); // print the result
    }
    return 0;
}
