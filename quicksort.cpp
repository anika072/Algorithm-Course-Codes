#include <iostream>
using namespace std;
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}
int partition(int arr[],int l,int h) {
  int pivot = arr[l];
  int i = l;
  int j=h;
  while(i<j){
    do{
        i++;
    }while(arr[i]<=pivot);
    do{
        j--;
    }while(arr[j]>pivot);
    if(i<j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
  }
  int temp=arr[l];
  arr[l]=arr[j];
  arr[j]=temp;

  return j;
}

void quickSort(int arr[],int l,int h) {
  if (l<h) {
    int pivot = partition(arr,l,h);
    quickSort(arr,l,pivot);
    quickSort(arr,pivot+1,h);
  }
}
int main() {
  int n;
  cout<<"How many numbers:"<<endl;
  cin>>n;
  int arr[n];
  cout<<"Enter numbers:"<<endl;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout << "Unsorted Array: \n";
  printArray(arr, n);
  quickSort(arr, 0, n);

  cout << "Sorted array in ascending order: \n";
  printArray(arr, n);
}
