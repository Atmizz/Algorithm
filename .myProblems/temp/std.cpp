#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define root 1,n,1
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
inline ll read() {
	ll x=0,w=1;char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar()) if(ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*w;
}
#define maxn 300100
const double eps=1e-8;
#define	int_INF 0x3f3f3f3f
#define ll_INF 0x3f3f3f3f3f3f3f3f
struct Node{
	int v;double w;
};
vector<Node>edge[maxn];
int n,m;
double dis[maxn];int vis[maxn];
struct heapnode{
	int u;double d;
	bool operator<(const heapnode &rhs) const {
		return d>rhs.d;
	}
};
void Dij(int S) {
	priority_queue<heapnode>q;
	for(int i=1;i<=3*n;i++) dis[i]=int_INF;
	dis[S]=0;
	q.push({S,0});
	while(!q.empty()) {
		heapnode f=q.top();q.pop();
		int u=f.u;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<edge[u].size();i++) {
			int v=edge[u][i].v;
			if(dis[v]>dis[u]+edge[u][i].w) {
				dis[v]=dis[u]+edge[u][i].w;
				q.push({v,dis[v]});
			}
		}
	}
}
int main() {
	freopen("10.in", "r", stdin);
	freopen("10.out", "w", stdout);
	n=read();m=read();
	for(int i=1;i<=m;i++) {
		int u=read(),v=read(),w=read();
		edge[u].push_back({v+n,(double)w});
		edge[v].push_back({u+n,(double)w});
		edge[u+n].push_back({v+2*n,1/((double)w-1)});
		edge[v+n].push_back({u+2*n,1/((double)w-1)});
		edge[u+2*n].push_back({v,((double)w-1)/(double)w});
		edge[v+2*n].push_back({u,((double)w-1)/(double)w});
	}
	Dij(1);
	double ans=int_INF;
	for(int i=0;i<=2;i++) ans=min(ans,dis[n+i*n]);
	if(ans==int_INF) printf("-1\n");
	else printf("%.3lf\n",ans);
	return 0;
}

