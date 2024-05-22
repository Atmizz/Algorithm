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
struct Node {
	char num;
	int pos;
};
void solve() {
	std :: string str; std :: cin >> str;
	str = "0" + str; int n = str.length() - 1;
	std :: vector <Node> even, odd;
	std :: vector <char> ans;
	for(int i = 1; i <= n; ++ i)
		if(str[i] % 2 == 0) even.push_back({str[i], i});
		else odd.push_back({str[i], i});
		
	if(odd.empty() || even.empty()) {
		for(int i = 1; i <= n; ++ i)
			std :: cout << str[i];
		std :: cout << '\n';
		return ;
	}
	std :: vector <bool> vis(n+1, 0);
	int l = 0, r = 0, p = 1;
	for(int i = 1; i <= n; ++ i) {
		if(vis[i]) continue; p = i;
		while(l < odd.size() - 1 && odd[l].pos <= i) l ++;
		while(vis[odd[l].pos] == 1 && l < odd.size() - 1) l ++;
		while(r < even.size() - 1 && even[r].pos <= i) r ++;
		while(vis[even[r].pos] == 1 && r < even.size() - 1) r ++;
//		deb(i); deb(l); deb(r);
		if(str[i] % 2 == 0) {
		 	if(str[i] > odd[l].num && l < odd.size() && vis[odd[l].pos] == 0) {
		 		ans.push_back(odd[l].num);
		 		vis[odd[l].pos] = 1;
		 		i --;
		 	}
		} else {
		 	if(str[i] > even[r].num && r < even.size() && vis[even[r].pos] == 0) {
		 		ans.push_back(even[r].num);
		 		vis[even[r].pos] = 1;
		 		i --;
		 	}
		}
		if(p == i) ans.push_back(str[i]); vis[i] = 1;
	}
	for(auto x : ans)
		std :: cout << x;
	std :: cout << '\n';
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
