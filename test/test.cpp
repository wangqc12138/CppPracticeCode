#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("./test.txt","r",stdin);
    int M;
    cin>>M;
    while(M--){
       string str;
       cin>>str;
       int N=str.size();
       int a[N][2],b[N][2];
       int m=0;
       int n=0;
       for(int i=0;i<N;i++){
           if(str[i]=='1'){
               m++;
           }else{
               n++;
           }
       }
       int c=0;
       int d=0;
       int ans=n;
       for(int i=0;i<N;i++){
           if(str[i]=='1'){
               c++;
           }else{
               d++;
           }
           a[i][0]=d;
           a[i][1]=c;
           ans=min(ans,max(c,n-d));
       }
       c=0,d=0;
       for(int i=N-1;i>=0;i--){
           if(str[i]=='1'){
               c++;
           }else{
               d++;
           }
           b[i][0]=d;
           b[i][1]=c;
           ans=min(ans,max(c,n-d));
       }
       for(int i=0;i<N;i++){
           for(int j=i+1;j<N;j++){
               ans=min(ans,max(a[i][1]+b[j][1],n-a[i][0]-b[j][0]));
           }
       }
       cout<<ans<<endl;
    }
    return 0;
}