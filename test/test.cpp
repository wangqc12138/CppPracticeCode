#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int> arr;
    int positive=0,negative=0,zero=0;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(x<0){negative++;}
        else if(x>0){positive++;}
        else{zero++;}
        if(x!=0||zero>1){arr.emplace_back(x);}
    }
    if(negative>2||positive>2){cout<<"no\n";return;}
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            for(int k=j+1;k<arr.size();k++){
                bool flag=false;
                for(int l=0;l<arr.size();l++){
                    if(arr[i]+arr[j]+arr[k]==arr[l]){
                        flag=true;
                        break;
                    }
                }
                if(!flag){cout<<"no\n";return;}
            }
        }
    }
    cout<<"yes\n";
}
int main(){
    string s1,s2,s3,s4;
    int i=100;
    char buf[40]={'2','0','2'};
    s1="wanggf.wgf_task_10.10.10.183/data03_ktgrp_wanggf3_xferTest";
    s2="sun01.txt";
    s3=buf;
    s4="";
    char szContent[1024] = {0};
	printf("m_strPrefixKey====%s\n",s1.c_str());
	printf("m_strFileName====%s\n",s2.c_str());
	puts(s3.c_str());
	printf("fileDupInfo.m_iRedo====%d\n",i);
	printf("fileDupInfo.m_strExtraInfo=====[%s]\n",s4.c_str());
	snprintf(szContent,sizeof(szContent),"%s|%s|%s|%d|%s",s1.c_str(),s2.c_str(),s3.c_str(),i,s4.c_str());   
	puts(szContent);
    cout<<sizeof(szContent)<<endl;
    printf("%s\n",szContent);   
	cout<<szContent<<endl;
    return 0;
}
