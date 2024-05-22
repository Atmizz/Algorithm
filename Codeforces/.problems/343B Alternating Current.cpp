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
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e6 + 20;
char str[N];
void solve() {
	scanf("%s", str);
	int n = strlen(str);
	std :: stack <char> s;
	for(int i = 0; i < n; ++ i) {
		if(s.empty()) s.push(str[i]);
		else {
			char temp = s.top();
			if(temp == str[i]) s.pop();
			else s.push(str[i]);
		}
	}
	std :: cout << (s.size() ? "No" : "Yes");
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