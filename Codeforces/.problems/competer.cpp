#include<bits/stdc++.h>
#define int long long
using namespace std;

int read() {
	char ch=getchar();
	int f=1,x=0;
	while(ch<'0'||ch>'9') {
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}

const int maxn=1e5+10,mod=1e9+7;

int n,m;
int p[maxn],a[maxn],h[maxn],cnt,w[maxn],sz[maxn],con[maxn],tot;

struct edge {
	int v,next;
}e[maxn<<1];

void addedge(int u,int v) {
	e[++cnt].v=v;
	e[cnt].next=h[u];
	h[u]=cnt;
}
void insert(int u,int v) {
	addedge(u,v);
	addedge(v,u);
}

void dfs(int u,int fa) {
	sz[u]=1;
	for(int i=h[u];i;i=e[i].next) {
		int v=e[i].v;
		
		if(v!=fa) {
			dfs(v,u);
			sz[u]+=sz[v];
		}
	}
	if(fa!=0) {
		con[++tot]=sz[u]*(n-sz[u]);//不着急取模
	}
}

signed main() {
	int T=read();
	while(T--) {
		n=read();
		fill(h+1,h+n+1,0);
		cnt=0;
		for(int i=1;i<n;i++) {
			insert(read(),read());
		}
		m=read();
		fill(w,w+n+1,0);
		for(int i=1;i<=m;i++) {
			p[i]=read();
		}
		sort(p+1,p+m+1);//这里要先排序
		
		if(n-1<m) {//第一种
			for(int i=1;i<n-1;i++) {
				w[i]=p[i];
			}
			w[n-1]=p[n-1];
			for(int i=n;i<=m;i++) {
				w[n-1]=w[n-1]*p[i]%mod;
			}
		}
		else {//第二种
			for(int i=1;i<=m;i++) {
				w[i]=p[i];
			}
			for(int i=m+1;i<n;i++) {
				w[i]=1;
			}
			sort(w+1,w+n);
		}
		
		tot=0;
		dfs(1,0);//维护con
		
		int ans=0;
		
		sort(con+1,con+n);
		for(int i=1;i<n;i++) {
			// std :: cout << "con[i] = " << con[i] << '\n';
			// std :: cout << "w[i] = " << w[i] << '\n';
			ans+=con[i]%mod*w[i]%mod;//贪心
			ans%=mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}