#include<bits/stdc++.h>
using namespace std;


priority_queue<int, vector<int>, greater<int>> pqmin;
priority_queue<int, vector<int>> pqmax;

void insert(int n){

    if(pqmax.size() == pqmin.size())      //we always keep no. of elems in maxheap more when odd no. of elems
    {
        if(pqmax.size() == 0){
            pqmax.push(n);
            return;
        }

        /*if elem to be inserted is greater than top of max-heap(maximum),
         then add it in minheap*/

        if(pqmax.top() > n){
            pqmax.push(n);
        }

        else{
            pqmin.push(n);
        }
        
    }

    else{
        // Two cases possible
        // Case 1: size of maxHeap > size of minHeap
        // Case 2: size of minHeap > size of maxHeap

        if(pqmax.size() > pqmin.size()){
            if(n >= pqmax.top()){
                pqmin.push(n);
            }

            else{
                int temp = pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                //now equal elements in minheap and maxheap
                pqmax.push(n);
            }
        }

        // Case2:
        else{

            if(n <= pqmin.top()){
                pqmax.push(n);
            }

            else{
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                //now equal elements in minheap and maxheap
                pqmin.push(n);
            }

        }

    }
}

double findMedian(){

    if(pqmax.size() == pqmin.size()){
        return (pqmax.top()+pqmin.top())/2.0;
    }

    else if (pqmax.size() > pqmin.size())
    {
        return pqmax.top();
    }

    else{
        return pqmin.top();
    }
}


int main(){

    insert(3);
    // cout<<findMedian()<<endl;

    insert(1);
    // cout<<findMedian()<<endl;

    insert(5);
    cout<<findMedian()<<endl;

    return 0;
}