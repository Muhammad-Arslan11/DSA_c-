#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Heap{
    public:
    int arr[100];
    int index;
    int size;

    Heap(){
        arr[0] = -1;
        size = 0;
    }

    void print(){
        for(int i=1; i <= size; i++){
            cout<< arr[i]<< " ";
        }
        cout<<endl;
    }

    void insert(int val){
        size = size+1;
        index = size;
        arr[index] = val;

        while(index > 1){
           int parent  = index / 2;
           if(arr[parent] < arr[index]){
            // swap
            swap(arr[parent], arr[index]);
            index = parent;
           }
           else{
            return;
           }
        }
    }

    void deleteNode(){
       // if empty heap
       if(size == 0){
        // nothing to delete
        cout<<"nothing to delelte. Please insert an element!"<<endl;
        return;
       }

       arr[1] = arr[size]; // step 1: put first element at last node
       // step 2: remove last element
       size--;
      
        // step 3: take root to its correct position
        int i = 1;
       while(i < size){
        int leftIndex = 2*i;
        int rightIndex = 2*i +1;

        if(leftIndex <size && arr[i] < arr[leftIndex]){
            swap(arr[leftIndex], arr[i]);
            i = leftIndex;
        }
        else if(rightIndex <size && arr[i] < arr[rightIndex]){
            swap(arr[rightIndex], arr[i]);
            i = rightIndex;
        }
        else{
            // nothing to swap, everynode is at the right place
            return;
        }
       }
    }

    void heapify(int arr[], int n, int i){
        int largest = i;
        int left = 2*i;
        int right = 2*i + 1;

        if(largest <= n && arr[largest] < arr[left]){
            largest = left;
        }

        if(largest <= n && arr[largest] < arr[right]){
            largest = right;
        }

        if(largest != i){
           swap(arr[largest], arr[i]);
           heapify(arr,n,largest);
        }
    }

    void heapSort(int* arr, int n){
        int size = n;

        while(size > 1){
            // step1
            swap(arr[size], arr[1]);
            size--;
           // step 2
            heapify(arr,size, 1);
        }
    }

};

int main(){
    Heap h;
    // h.insert(60);
    // h.insert(50);
    // h.insert(40);
    // h.insert(30);
    // h.insert(20);
    // h.insert(10);

    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);
    // h.insert(10);
    // h.print();
    // h.deleteNode();
    // h.print();

    int arr[] = {-1,54,53,55,52,50};
    int n = 5;
    // heap creation
    for(int i=n/2; i >0; i--){
        h.heapify(arr, n, i );
    }
    // heapSort
    h.heapSort(arr, n);
    cout<<"printing the array after heapify: "<<endl;
    for(int i=1; i<=n; i++){
        cout<<" "<< arr[i];
    }
    cout<<endl;

       cout<<"printing sorted array: "<<endl;
    for(int i=1; i<=n; i++){
        cout<<" "<< arr[i];
    }
    cout<<endl;



    return 0;
}