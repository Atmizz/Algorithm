#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;

using namespace std;
map<int,pair<int,int>> minn;//点的序号->位置,最小值 

inline int read() {
	int s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = gc)
		s = (s << 1) + (s << 3) + (ch ^ 48);
	return s * f;
}
inline int abs(int a) {return a < 0 ? -a : a;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 3e3 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, head[MaxN<<1], cnt, num, dep[MaxN], fa[MaxN], f[MaxN][22];
int List[5][MaxN<<2], sum[5];
struct Edge {
	int to, net;
}e[MaxN << 1];
struct Ans {
	int u, v, w;
}a[MaxN * MaxN * 4];
void Insert(int u, int v) {
	e[++cnt] = {v, head[u]};
	head[u] = cnt;
}
void dfs(int u, int pa) {
	f[u][0] = pa; dep[u] = dep[pa] + 1; fa[u] = pa;
	for(int i = 1; dep[u] - (1 << i) >= 0; ++ i)
		f[u][i] = f[f[u][i-1]][i-1];
	for(int i = head[u]; i; i = e[i].net)
		if(e[i].to != pa) dfs(e[i].to, u);
}
int LCA(int x, int y) {
	if(dep[x] < dep[y]) std :: swap(x, y);
	for(int i = 21; i >= 0; -- i)
		if(dep[f[x][i]] >= dep[y]) x = f[x][i];
	if(x == y) return x;
	for(int i = 21; i >= 0; -- i)
		if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}

void dfs11(int u, int lca) {
	List[1][++sum[1]] = u;
	if(u == lca) return ;
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(v == fa[u]) return dfs11(v, lca);
	}
}
void dfs12(int u, int lca) {
	List[2][++sum[2]] = u;
	if(u == lca) return ;
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(v == fa[u]) return dfs12(v, lca);
	}
}
void dfs21(int u, int lca) {
	List[3][++sum[3]] = u; 
//	std :: cout << "dfs21 : " << List[3][sum[3]] << '\n';
	if(u == lca) return ;
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(v == fa[u]) return dfs21(v, lca);
	}
}
void dfs22(int u, int lca) {
	List[4][++sum[4]] = u;
	if(u == lca) return ;
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(v == fa[u]) return dfs22(v, lca);
	}
}
bool st[MaxN][MaxN*2];

void calc(int x,int y){//数字,位置  计算一个的答案 
	int N=max(sum[1],sum[3]),M=min(sum[1],sum[3]);//长序列长度,短序列长度
	int dx=N%M;//偏移量
	int add=(y-1)/M;
//	cout<<sum[1]<<endl;
//	cout<<sum[3]<<endl;
	for(int i=0;y%M+i*dx<=M;i++){//偏移次数 
		//看短序列中是否存在相同位置,存在则结束 
		int loc = y%M+i*dx;
		if(st[x][loc]){//短序列中存在数字相同且位置相同
			//cout<<loc<<endl;
			int last_v=minn[x].second; 
			int last_l=minn[x].first;
			if(i<last_v||(i==last_v&&loc<last_l)||last_l==0){
				minn[x] ={loc,i};
			}
			break;
		}
		if(dx==0)break; 
	} 
}
void solve() {
	n = read(); m = read();
	for(int i = 1; i < n; ++ i) {
		int u = read(), v = read();
		Insert(u, v); Insert(v, u);
	} dfs(1, 1);
	while(m --) {
		for(int j = 1; j <= 4; ++ j) sum[j] = 0; num = 0;
		int s1 = read(), t1 = read(), s2 = read(), t2 = read();
		int lca = LCA(s1, t1), S1, S3;
		dfs11(s1, lca); dfs12(t1, lca); S1 = sum[1];
		for(int i = sum[2] - 1; i >= 1; -- i) List[1][++sum[1]] = List[2][i];
		for(int i = 2; i <= sum[2]; ++ i) List[1][++sum[1]] = List[2][i];
		for(int i = S1 - 1; i >= 2; -- i) List[1][++sum[1]] = List[1][i];
		if(List[1][1] == List[1][sum[1]]) sum[1] --;
		
		lca = LCA(s2, t2);
		dfs21(s2, lca); dfs22(t2, lca); S3 = sum[3];
		
		for(int i = sum[4] - 1; i >= 1; -- i) List[3][++sum[3]] = List[4][i];
		for(int i = 2; i <= sum[4]; ++ i) List[3][++sum[3]] = List[4][i];
		for(int i = S3 - 1; i >= 2; -- i) List[3][++sum[3]] = List[3][i];
		if(List[3][1] == List[3][sum[3]]) sum[3] --;
		
		for(int j = 1; j <= sum[1]; ++ j)
			for(int k = 1; k <= sum[3]; ++ k)
				if(List[1][j] == List[3][k])
					if(sum[1]>=sum[3])a[++num] = {j, k, List[1][j]};
		else a[++num] = {k, j, List[1][j]};
		
		memset(st,0,sizeof(st));
		minn.clear();
		
		for(int j = 1; j <= num; ++ j){
			//u,v,w   第一个序列里的位置,第二个,对应数字
			st[a[j].w][a[j].v]=1; 
			//cout<<a[j].w<<":"<<a[j].v<<endl;
		}
		for(int j = 1; j <= num; ++ j){
			calc(a[j].w,a[j].u);
		}
		int ans =-1;
		int minp=MaxN+1;
		int minc=MaxN+1;
		
		for(auto it:minn){
			int k=it.first;//序号 
			pair<int,int> pii=it.second;//位置,最小值 
			int loc=pii.first;
			int minn2=pii.second;
			if(minn2<=minc&&loc<=minp){
				minp=loc;
				minc=minn2;
				ans=k;
			}
		}
//			cout<<"ans="<<ans<<endl;       
		cout<<ans<<endl;       
	}
}
int main() {
	int T = 1;
	std :: cin >> T;
	while (T--) solve();
	return 0;
}

