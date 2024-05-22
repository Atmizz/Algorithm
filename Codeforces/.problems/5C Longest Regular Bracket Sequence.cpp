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
std :: string str;
int a[N], n;
void solve() {
	std :: cin >> str; n = str.length();
	std :: stack <int> s;
	for(int i = 0; i < n; ++ i)
		if(str[i] == '(') s.push(i+1);
		else {
			if(s.empty()) continue;
			a[i+1] = 1; a[s.top()] = 1; s.pop();
		}
	std :: vector <int> f(n+1);
	for(int i = 1; i <= n; ++ i)
		if(a[i] == 1) f[i] = f[i-1] + 1;
		else f[i] = 0;
	int maxx = 0, cnt = 0;
	for(int i = 1; i <= n; ++ i)
		if(f[i] > maxx && f[i] > 1) maxx = f[i], cnt = 1;
		else if(f[i] == maxx) cnt ++;
	if(maxx == 0)
		std :: cout << "0 1";
	else std :: cout << maxx << ' ' << cnt;
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