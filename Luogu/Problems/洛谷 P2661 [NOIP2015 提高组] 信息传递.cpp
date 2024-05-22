#include <cstdio>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#define Max 200120
#define re register
struct information {
	int net,to;
}t[Max];
int n,head[Max],cnt,dfn[Max],Index,num,low[Max],id[Max],ans = 1e9;
inline void insert(int u,int v) {
	t[++cnt].net = head[u];
	t[cnt].to = v;
	head[u] = cnt;
}
std :: stack<int>s;
void tarjan(int u) {
	low[u] = dfn[u] = ++ Index;
	s.push(u); int v;
	for(re int i = head[u] ; i ; i = t[i].net) {
		v = t[i].to;
		if(!dfn[v]) tarjan(v), low[u] = std :: min(low[u],low[v]);
		else if(!id[v]) low[u] = std :: min(low[u],dfn[v]);
	}
	if(low[u] == dfn[u]) {
		num ++; int sum = 0;
		while(!s.empty()) {
			v = s.top(), s.pop();
			id[v] = num;
			sum ++ ;
			if(u == v) break;
		}
		if(sum != 1) ans = std :: min(ans,sum);
	}
}
inline void init() {
	scanf("%d",&n); int x;
	for(re int i = 1 ; i <= n ; ++ i) scanf("%d",&x),insert(i,x);
}
void work() {
	for(re int i = 1 ; i <= n ; ++ i)
		if(!dfn[i]) tarjan(i);
}
void print() {printf("%d",ans);}
int main() {
	init();
	work();
	print();
	return 0;
}