#include<iostream>
using namespace std;
int MCM(int p[],int x){
    int mcm[x+1][x+1];
    for(int i=1;i<=x;i++){
        mcm[i][i]=0;
    }
    for(int l=2;l<=x;l++){
        for(int i=1;i<=x-l+1;i++){
            int j=i+l-1;
            int minn=100000;
            for(int k=i;k<=j-1;k++){
                minn=min(minn,(mcm[i][k]+mcm[k+1][j]+p[i-1]*p[j]*p[k]));
                mcm[i][j]=minn;
            }
        }
    }
    return mcm[1][x];
}
int main(){
    int n;
    cout<<"Enter number of matrix:"<<endl;
    cin>>n;
    int p[n+1];
    for(int i=0;i<=n;i++){
        cin>>p[i];
    }
    cout<<"Minimum number of matrix multiplication:"<<MCM(p,n);
}
