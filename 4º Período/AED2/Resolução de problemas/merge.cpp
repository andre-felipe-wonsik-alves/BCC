#include <stdio.h>

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - left;

    int* E = new int[n1];
    int* D = new int[n2];

    for (int i = 0; i < n1; i++){
        E[i] = arr[left + i];
    }
    
    for (int i = 0; i < n2; i++)
    {
        D[i] = arr[mid+1+i];
    }

    int k = left;
    int i = 0, j = 0;

    while(i<n1 && j<n2){
        if(E[i] <= D[j]){
            arr[k] = E[i];
            i++; 
        } else {
            arr[k] = D[j];
            j++;
        }
        k++;
    }

    while (i<n1)
    {
        arr[k] = E[i];
        i++,k++;
    }
    
    while(j<n2){
        arr[k] = D[j];
        j++,k++;
    }
    

}

int main(){ 
    
    
    return 0;
}