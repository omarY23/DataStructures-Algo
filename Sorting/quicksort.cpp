partitition(A,p,r){
    x=A[r];
    j=p;
    i=p-1;

    for(j=p to r-1){
        if(A[j]<=x){
            i++;
            swap(A[j] with A[i])
        }
    }
    swap(A[i+1] with x)
    return i+1;
}