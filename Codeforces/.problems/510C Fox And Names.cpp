#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
std :: string st = "abcdefghijklmnopqrstuvwxyz";
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <std :: string> str(n);
	std :: vector <int> deg(27), adj[27];
	for(int i = 0; i < n; ++ i)
		std :: cin >> str[i];
	for(int i = 0; i < n - 1; ++ i) {
		int idx = 0;
		while(str[i][idx] == str[i+1][idx]) idx ++;
		if(idx == str[i].size()) continue;
		if(idx == str[i+1].size()) {
			std :: cout << "Impossible";
			return ;
		}
		int x = (int)str[i][idx]-'a'+1, y = (int)str[i+1][idx]-'a'+1;
		// std :: cout << str[i][idx] << ' ' << str[i+1][idx] << endl;
		adj[x].push_back(y); deg[y] ++;
	}
	std :: vector <int> res;
	for(int i = 1; i <= 26; ++ i)
		if(!deg[i]) res.push_back(i);
	for(int i = 0; i < res.size(); ++ i) {
		// deb(res[i]);
		for(auto v : adj[res[i]]) {
			deg[v] --;
			if(deg[v] == 0) res.push_back(v);
		}
	}
	if(res.size() < 26) std :: cout << "Impossible";
	else
		for(auto x : res)
			std :: cout << (char)(x + 'a' - 1);
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