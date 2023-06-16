#include<iostream>
using namespace std;
void knapsack(int k, int w[], int v[], int n){
    int best[n+1][k+1],p[n+1][k+1];
    for(int i=0;i<=k;i++){
        best[0][i]=0;
    }
    for(int i=0;i<=n;i++){
        best[i][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(j>=w[i-1]){
                if(best[i-1][j]>(best[i-1][j-w[i-1]] + v[i-1])){
                    best[i][j]=best[i-1][j];
                }
                else{
                    best[i][j]=best[i-1][j-w[i-1]] + v[i-1];
                }
            }
            else{
                 best[i][j]=best[i-1][j];
            }
        }
    }
    int res = best[n][k];
    cout<<"Profit: "<<res<<endl;
    int x=k;
    cout<<"Items selected: ";
    for (int i = n; i > 0 && res > 0; i--) {
        if (res == best[i - 1][x])
            continue;
        else {
            cout<<" "<<i ;
            res = res - v[i - 1];
            x = x - w[i - 1];
        }
}
}
int main(){
    int n,k;
    cout<<"Enter the number of Items:"<<endl;
    cin>>n;
    int w[n],v[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the weight and value of item "<<i+1<<" :";
        cin>>w[i];
        cin>>v[i];
    }
    cout<<"Enter the maximum weight :"<<endl;
    cin>>k;
    for(int i=0;i<n;i++){
        cout<<w[i]<<"  "<<v[i]<<endl;
    }
    knapsack(k,w,v,n);
return 0;
}

