#include <iostream>
using namespace std;
#include<stack>
int bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    stack <int> newst;
     
    for(int j=0;j<n;j++){
        newst.push(arr[j]);
    
    for(int i=j;i<n;i++){
        if(newst.top()+arr[i]==0)
            return newst.top();
        
    }
     } 
     return -1;
}

int main() {
    int arr[] = {-1,10,6,7,-7,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = bubbleSort(arr, n);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl<<m<<endl;
    return 0;
}
