#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int,int> pii;

int main(){
    int n;
    cin>>n;
    vector<pii> vec;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        int fenzi=0,fenmu=0;
        int p=-1;
        bool flag=false;
        for(int i=0;i<str.size();i++){
            if(str[i]=='-'){
                flag=true;
                continue;
            }
            if(str[i]=='/'){
                p=i;
                break;
            }
            int num=str[i]-'0';
            fenzi=fenzi*10+num;
        }
        if(p==-1){
            if(flag){
                vec.push_back({fenzi*-1,1});
            }
            else vec.push_back({fenzi,1});
        }
        else {
            for(int i=p+1;i<str.size();i++){
                int num=str[i]-'0';
                fenmu=fenmu*10+num;
            }
            if(flag){
                vec.push_back({fenzi*-1,fenmu});
            }
            else vec.push_back({fenzi,fenmu});
        }
        
    }
    int cofenmu=1;
    int sum=0;
    for(int i=0;i<n;i++){
        cofenmu=(cofenmu*vec[i].second)/__gcd(cofenmu,vec[i].second);
    }
    for(int i=0;i<n;i++){
        int f=vec[i].first;
        f*=(cofenmu/vec[i].second);
        sum+=f;
    }
    if(sum%cofenmu==0){
        cout<<sum/cofenmu<<endl;
    }else {
        int yuefen=__gcd(sum,cofenmu);
        cout<<sum/yuefen<<"/"<<cofenmu/yuefen<< endl;
    }
}