#include <iostream>
using namespace std;
void merge(int arr[], int l, int mid, int h) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int m = mid - l + 1;
  int n = h - mid;

  int A[m], B[n];

  for (int i=0;i<m;i++)
    A[i] = arr[l+i];
  for (int j=0;j<n;j++)
    B[j] = arr[mid+1+j];
  int i, j, k;
  i = 0;
  j = 0;
  k = l;
  while (i < m && j < n) {
    if (A[i]<=B[j]) {
      arr[k]=A[i];
      i++;
    }
    else {
      arr[k]=B[j];
      j++;
    }
    k++;
  }
  while (i<m) {
    arr[k]=A[i];
    i++;
    k++;
  }

  while (j<n) {
    arr[k]=B[j];
    j++;
    k++;
  }
}
void mergeSort(int arr[], int l, int h) {
  if (l < h) {
    int mid = l + (h - l) / 2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, h);

    merge(arr, l, mid, h);
  }
}

int main() {
    cout<<"How many numbers:"<<endl;
    int n;
    cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  mergeSort(arr,0,n-1);

  cout << "Sorted array:";
  for(int i=0;i<n;i++){
    cout<<arr[i]<<"  ";
  }
  return 0;
}

