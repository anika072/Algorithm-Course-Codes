#include<iostream>
using namespace std;
int main(){
int n,temp,count=1;
cout<<"Enter the number of activity:"<<endl;
cin>>n;
int start[n],finish[n];
cout<<"Enter the starting and finishing time of the activities:"<<endl;
for(int i=0;i<n;i++){
    cout<<"Enter the starting and finishing time of "<<i+1<<"activity:";
    cin>>start[i];
    cin>>finish[i];
    cout<<endl;
}
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(finish[i]>finish[j]){
            temp=finish[i];
            finish[i]=finish[j];
            finish[j]=temp;

            temp=start[i];
            start[i]=start[j];
            start[j]=temp;
        }
    }
}
for(int i=0;i<n;i++){
    cout<<start[i]<<" "<<finish[i]<<endl;
}
int j=0;
for(int i=1;i<n;i++){
    if(finish[j]<=start[i]){
        count++;
        j++;
    }
}
int p=0;
cout<<"Number of activities can be selected: "<<count<<endl;
cout<<"Activities are:"<<endl;
cout<<start[p]<<" - "<<finish[p]<<endl;
for(int i=1;i<n;i++){
    if(finish[p]<=start[i]){
        cout<<start[i]<<" - "<<finish[i]<<endl;
        p++;
    }
}
return 0;
}
