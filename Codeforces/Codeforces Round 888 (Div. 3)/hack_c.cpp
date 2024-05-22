#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define root 1,n,1
#define ls rt<<1
#define rs rt<<1|1
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
inline ll read() {
    ll x=0,w=1;char ch=getchar();
    for(;ch>'9'||ch<'0';ch=getchar()) if(ch=='-') w=-1;
    for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x*w;
}
inline void print(__int128 x){
    if(x<0) {putchar('-');x=-x;}
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
#define maxn 1000000
const double eps=1e-8;
#define int_INF 0x3f3f3f3f
#define ll_INF 0x3f3f3f3f3f3f3f3f
int c[maxn];
int main() {
    int T=read();
    while(T--) {
        int n=read();int k=read();
        map<int,int>mp;
        for(int i=1;i<=n;i++) {
            c[i]=read();
            mp[c[i]]++;
        }
        if(c[1]==c[n]) {
            if(mp[c[1]]>=k) {
                cout<<"YES"<<endl;
            }
            else {
                cout<<"NO"<<endl;
            }
        }
        else {
            int sum1=0,sum2=0;
            int flag=0;
            for(int i=1;i<=n;i++) {
                if(c[i]==c[1]) sum1++;
                if(c[i]==c[n]) sum2++;
                if(sum1==k&&mp[c[n]]-sum2>=k) {
                    flag=1;break;
                }
            }
            if(flag) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}