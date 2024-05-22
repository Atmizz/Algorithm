#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 220;
std :: string str;
int s[N];
void solve() {
	std :: cin >> str;
	int n = str.length();
	for(int i = 0; i < n; ++ i)
		s[i+1] = str[i] - 'a' + 1;
	if(n == 1) {
		std :: cout << "YES\n";
		for(int i = 1; i <= 26; ++ i)
			std :: cout << char(i+'a'-1);
		std :: cout << endl;
		return ;
	}
	std :: set <int> adj[N];
	std :: vector <int> vis(30);
	adj[s[1]].insert(s[2]);
	adj[s[n]].insert(s[n-1]);
	for(int i = 2; i < n; ++ i) {
		adj[s[i]].insert(s[i-1]);
		adj[s[i]].insert(s[i+1]);
	}
	for(int i = 1; i <= 26; ++ i)
		if(adj[i].size() > 2) {
			std :: cout << "NO\n";
			return ;
		}
	std :: vector <int> ans;
	int cnt_1 = 0;
	for(int i = 1; i <= 26; ++ i)
		if(adj[i].size() == 1) {
			int x = i; cnt_1 ++;
			while(1) {
				if(vis[x]) {
					std :: cout << "NO\n";
					return ;
				}
				vis[x] = 1;
				ans.push_back(x);
				if(adj[x].size() == 0) break;
				for(auto y : adj[x])
					if(y != x) {
						adj[x].erase(y);
						adj[y].erase(x);
						x = y;
						break;
					}
			}
		}
	if(cnt_1 == 0) {
		std :: cout << "NO\n";
		return ;
	}
	std :: cout << "YES\n";
	for(auto x : ans)
		std :: cout << char(x+'a'-1);
	for(int i = 1; i <= 26; ++ i)
		if(!vis[i])
			std :: cout << char(i+'a'-1);
	std :: cout << endl;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}