#include<iostream>
using namespace std;
struct job{
        char jid[6];
        int deadline;
        int profit;
    };
void jobsequencing(job j[],int n){
    int dmax=0,count=0;
    for(int i=0;i<n;i++){
        if(j[i].deadline>dmax)
            dmax=j[i].deadline;
    }
    cout<<dmax<<endl;
    int timeslot[dmax];
    for(int i=1;i<=dmax;i++){
        timeslot[i]=-1;
    }
    int k;
    for(int i=1;i<=n;i++){
            k = min(dmax,j[i-1].deadline);
            while(k>=1){
                if(timeslot[k]==-1){
                    timeslot[k]=i-1;
                    count++;
                    break;
                }
                k--;
            }
            if(count==dmax)
                break;
        }
/*for(int i=0;i<dmax;i++){
    cout<<timeslot[i]<<endl;
}
*/
cout<<count<<endl;
cout<<"Following is maximum profit sequence of jobs:"<<endl;
for(int i=1;i<=dmax;i++){
    cout<<j[timeslot[i]].jid<<endl;
}
cout<<endl;
}
int main(){
    int n;
    cout<<"Enter the number of jobs: "<<endl;
    cin>>n;
    job j[n],temp;
    cout<<"Enter job id, deadline and profit :"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter "<<i+1<<" job id, deadline and profit :";
        cin>>j[i].jid>>j[i].deadline>>j[i].profit;
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        cout<<j[i].jid<<" "<<j[i].deadline<<" "<<j[i].profit<<endl;
    }

    for(int i=0;i<n;i++){
        for(int p=i+1;p<n;p++){
            if(j[i].profit<j[p].profit){
                temp=j[i];
                j[i]=j[p];
                j[p]=temp;
            }
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<j[i].jid<<" "<<j[i].deadline<<" "<<j[i].profit<<endl;
    }
    cout<<endl;
    jobsequencing(j,n);
return 0;
}
