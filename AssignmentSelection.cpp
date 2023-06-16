#include<iostream>
using namespace std;
struct as{
        char aid[5];
        int adif;
    };
void assignmentSelection(as a[], int n){
    int point=0, j=1;
    for(int i=0;i<n;i++){
        point = point + (a[i].adif*(n-j));
        j++;
    }
    cout<<"Maximum point = "<<point<<endl;
    cout<<"Assignment submission order: ";
    for(int i=0;i<n;i++){
        cout<<a[i].aid<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter the number of assignments:";
    cin>>n;
    as a[n],temp;

    cout<<"Enter the assignment id and difficulties:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<" assignment id and difficulty:";
        cin>> a[i].aid>>a[i].adif;
    }

    for(int i=0;i<n;i++){
        cout<<a[i].aid<<" "<<a[i].adif<<endl;
    }
    cout<<endl;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i].adif<a[j].adif){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i].aid<<" "<<a[i].adif<<endl;
    }
    cout<<endl;
    assignmentSelection(a,n);
return 0;
}
