#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("./test.txt","r",stdin);
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        map<int,int> mp;
        int ans=0;
        for(int i=0;i<n;i++){
            int t;
            cin>>t;
            mp[t%k]++;
            ans+=t/k;
        }
        for(auto [x,y]:mp){
            if(y<=0){
                continue;
            }
            for(auto [c,d]:mp){
                if(d<=0){
                    continue;
                }
                if(c+x>=k){
                    if(c!=x&&mp[c]>=1&&mp[x]>=1){
                        mp[c]--;
                        mp[x]--;
                        ans++;
                        break;
                    }else if(c==x&&mp[c]>=2){
                        mp[c]-=2;
                        ans++;
                        break;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}