#include<bits/stdc++.h>
using namespace std;

void maxheapify(vector <int> &v, int n, int i){

int l =2*i+1;
int r = 2*i+2;

int largest= i;

if(l<n && v[l]>v[largest]){
    largest = l;
}

 if(r<n && v[r]>v[largest]){
    largest = r;
}

if(largest!=i){

    swap(v[i], v[largest]);

    maxheapify(v, n, largest);      // maxheapify now to be applied on the child which was exchanged
}


}


void heapsort(vector<int> &v){

    int n = v.size();

    for (int i=(n/2)-1; i>=0; i--)            //as n/2 node has index n/2-1
    {
        maxheapify(v, n, i);                //n represents max-length till which we swap and i means the node on which we heapify
    }

    //now code for heap sort
    for (int j = n-1; j >0; j--)
    {
        swap(v[0], v[j]);

        maxheapify(v, j, 0);                // max-heapify on root element
    }
    
    
}


int main(){

    int n;
    cin>>n;

    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    heapsort(v);

    for(int i=0; i<n; i++){
            cout<<v[i]<<" ";
        }


return 0;
}