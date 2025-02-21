int compila(int D, int X, int N, int S){
    int spazUtilizz=N*S;
    int count=0;
     while((D-spazUtilizz)<X){
        count++;
        spazUtilizz-=S;
    }
    return count;
}
