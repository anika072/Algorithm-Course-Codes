#include<iostream>
using namespace std;
void lcs(char x[],char y[],int m,int n){
    int arr[m+1][n+1];
    for(int i=0;i<=m;i++){
        arr[i][0]=0;
    }
    for(int i=0;i<=n;i++){
        arr[0][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]==y[j-1])
                arr[i][j]=arr[i-1][j-1]+1;
            else
                arr[i][j]=max(arr[i][j-1],arr[i-1][j]);
        }
    }
    int res=arr[m][n];
    int i=m,j=n,k=res;
    char str1[res],str2[res];
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            str1[k-1]=x[i-1];
            i--;
            j--;
            k--;
        }
        else if(arr[i][j-1]>arr[i-1][j])
            j--;
        else
            i--;
    }
     int p=m,q=n,r=res;
     while(p>0 && q>0){
        if(x[p-1]==y[q-1]){
            str2[r-1]=x[p-1];
            p--;
            q--;
            r--;
        }
        else if(arr[p][q-1]>=arr[p-1][q])
            q--;
        else
            p--;
    }
    cout<<arr[m][n]<<endl;
    for(int i=0;i<res;i++)
        cout<<str1[i];
    cout<<endl;
    for(int i=0;i<res;i++)
        cout<<str2[i];
}
int main(){
    int m,n;
    cout<<"Enter the length os the strings:"<<endl;
    cin>>m>>n;
    char x[m],y[n];
    cout<<"Enter first string:"<<endl;
    for(int i=0;i<m;i++){
        cin>>x[i];
    }
    cout<<"Enter second string:"<<endl;
    for(int i=0;i<n;i++){
        cin>>y[i];
    }
    lcs(x,y,m,n);
    return 0;
}
