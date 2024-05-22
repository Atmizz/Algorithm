#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
void solve() {
	int n;
	std :: cin >> n;
	std :: string str[n];
	for(int i = 0; i < n; ++ i) {
		std :: cin >> str[i];
	}
	std :: vector <int> adj[26], in(26), vis(26);
	for(int i = 0; i < n; ++ i) {
		for(int j = i + 1; j < n; ++ j) {
			int flag = 0;
			for(int _ = 0; _ < std :: min((int) str[i].size(), (int) str[j].size()); ++ _) {
				if(str[i][_] != str[j][_]) {
					int x = str[i][_] - 'a';
					int y = str[j][_] - 'a';
					adj[x].push_back(y);
					in[y] ++;
					flag = 1;
					break;
				}
			}
			if(!flag && str[i].size() > str[j].size()) {
				std :: cout << "Impossible";
				return ;
			}
		}
	}
	std :: queue <int> q;
	for(int i = 0; i < 26; ++ i) {
		if(!vis[i] && !in[i]) {
			vis[i] = 1;
			q.push(i);
		}
	}
	if(q.size() == 0) {
		std :: cout << "Impossible";
		return ;
	}
	std :: vector <char> ans;
	while((int) q.size()) {
		int x = q.front(); q.pop();
		ans.push_back(x + 'a');
		for(auto y : adj[x]) {
			in[y] --;
			if(in[y] == 0) {
				if(vis[y]) {
					std :: cout << "Impossible";
					return ;
				}
				vis[y] = 1;
				q.push(y);
			}
		}
	}
	for(int i = 0; i < 26; ++ i) {
		if(in[i] > 0) {
			std :: cout << "Impossible";
			return ;
		}
	}
	for(auto x : ans) {
		std :: cout << x;
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}