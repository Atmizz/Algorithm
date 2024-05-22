#include <bits/stdc++.h>
using namespace std;
#define int long long
int uni[200005],n,m,d[200005];
void init(){for(int i=1;i<=n;i++){uni[i]=i;d[i]=0;}}
int fin(int x){
	if(uni[x]==x) return x;
	int a=uni[x];uni[x]=fin(uni[x]);d[x]+=d[a];
	return uni[x];
}
void con(int x,int y,int v){int a=fin(x),b=fin(y);uni[a]=b;d[a]=d[y]+v-d[x];}
void solve(){
	cin>>n>>m;int x,y,v;int f=1;init();
	for(int i=1;i<=m;i++){
        cin>>x>>y>>v;if(!f){continue;}
        if(fin(x)==fin(y)){
        	if(d[x]-d[y]!=v){
        		f=0;
        	}
        }
        con(x,y,v);
	}
    if(f){cout<<"YES"<<endl;}
    else{cout<<"NO"<<endl;}
}
signed main(){
	cin.tie(nullptr);cout.tie(nullptr);
	int t;cin>>t;
	while(t--){solve();}
}