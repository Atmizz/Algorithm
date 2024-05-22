#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000;
int p[maxn],n;
bool s[maxn];
int vis[maxn],prime[maxn],cnt=0;int mp[maxn];
void init(int limit=1e5) {
	for(int i=2;i<=limit;i++) {
		if(!vis[i]) prime[++cnt]=i,mp[i]=1;
		for(int j=1;j<=cnt;j++) {
			if(i*prime[j]>limit) break;
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}
void dfs(int u){//uä»£è¡¨çŽ°åœ¨è¦å¡«çš„ä½æ•°
	if(u>=n+1){
		int flag=0;

		for(int i=1;i<=n;i++){
//			cout<<p[i]<<" "<<p[i%n+1]<<endl;
			if(abs(p[i]-p[i%n+1])!=2&&abs(p[i]-p[i%n+1])!=3) {
//				cout<<p[i]<<" "<<p[i%]
				flag=1;
				break;
			}
//			cout<<p[i]<<" ";
		}
//		for(int i=1;i<=n;i++) {
//			cout<<p[i]<<" ";
//		}
//		cout<<flag<<endl;
		if(flag==0) {
			for(int i=1;i<=n;i++) {
				cout<<p[i]<<" ";
			}
			cout<<endl;
		}
		return ;
	}
	for(int i =1;i<=n;i++){
		if(s[i]==0){
			s[i]=1;
			p[u]=i;
			dfs(u+1);
			s[i]=0;
		}
	}
}
int main(){
	init();
	cin>>n;
	dfs(1);
	return 0;
}