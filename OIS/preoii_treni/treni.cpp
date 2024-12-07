int tempo_massimo(int N, int a[], int b[])
{
    int maxtime = 0;
    int lastaken=0;//0 for a, 1 for b
    for (int i = 0; i < N, i++){
         if(a[i]>b[i]){
            if(lastaken==0)
                maxtime+=a[i];
         } else {
            if(lastaken==1)
                maxtime+=b[i];
         }
    }
}
