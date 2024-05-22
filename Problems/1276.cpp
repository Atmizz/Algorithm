#include <bits/stdc++.h>
#define gc getchar()
typedef unsigned long long ll;
inline int read() {
	int s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = - 1;
	for(; ch >= '0' && ch <= '9'; ch = gc) s = (s << 3) + (s << 1) + (ch ^ 48);
	return s * f;
}
inline int abs(int a) { return a < 0 ? -a : a;}
inline int max(int a, int b) { return a > b ? a : b;}
inline int min(int a, int b) { return a < b ? a : b;}
const int MaxN = 1e6 + 200;
const int mod = 1e9 + 7;
const int INF = 0x7fffffff;
struct Node {
	int Id, Grade;
	friend bool operator < (Node a, Node b) {
		if(a.Grade != b.Grade) return a.Grade < b.Grade;
		else return a.Id > b.Id;
	}
};
int main(){
	int n;
	while(~scanf("%d", &n)) {
		int k = 0, x; std :: priority_queue <Node> Q[4];
		for(int i = 1; i <= n; ++ i) {
			std :: string str;
			Node a;
			std :: cin >> str;
			if(str == "IN") k ++, x = read(), a.Grade = read(), a.Id = k, Q[x].push(a);
			else {
				x = read();
				if(!Q[x].empty()) printf("%d\n", Q[x].top()), Q[x].pop();
				else printf("EMPTY\n");
			}
		}
		/*
		Q[0].push(Node{2, 2});
		Q[0].push(Node{1, 2});
		Q[0].push(Node{3, 8});
		while(!Q[0].empty()) std :: cout << Q[0].top().Id << ' ', Q[0].pop(); 
		*/
	}
}