#include<iostream>
using namespace std;
void knapsack(int n, float weight[], float profit[], int capacity){
    int u = capacity;
    float x[n],total_profit=0;
    for(int i=0;i<n;i++){
        x[i]=0;
    }
    int i;
    for( i=0;i<n;i++){
        if(weight[i]>u)
            break;
        else{
            x[i]=1;
            total_profit = total_profit + profit[i];
            u = u-weight[i];
        }
    }
    if(i<n){
        x[i]=u/weight[i];
        total_profit = total_profit + (x[i]*profit[i]);
    }
    cout<<"Maximum benefit is: "<<total_profit<<endl;
    cout<<"By taking these items: ";
    for(int i=0;i<n;i++){
        cout<<x[i]<<" ";
    }
}
int main(){
    int n,capacity;
    cout<<"Enter the number of objects: "<<endl;
    cin>>n;

    float weight[n],profit[n],rat[n],temp;
    cout<<"Enter the weights and profits of the objects :"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter the weight and profit of "<<i+1<<"th object :";
        cin>>weight[i];
        cin>>profit[i];
        cout<<endl;
    }
    cout<<"Enter the capacity of the knapsack: "<<endl;
    cin>>capacity;

    for(int i=0;i<n;i++){
        rat[i]=profit[i]/weight[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(rat[i]<rat[j]){
                temp=rat[i];
                rat[i]=rat[j];
                rat[j]=temp;

                temp=weight[i];
                weight[i]=weight[j];
                weight[j]=temp;

                temp=profit[i];
                profit[i]=profit[j];
                profit[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<weight[i]<<" "<<profit[i]<<" "<<rat[i]<<endl;
    }
    knapsack(n,weight,profit,capacity);
return 0;
}
