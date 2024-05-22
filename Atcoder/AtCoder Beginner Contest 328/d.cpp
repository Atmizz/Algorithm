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
const int N = 2e5 + 20;
std :: string str;
void solve() {
	std :: cin >> str;
	int n = str.length();
	std :: stack <char> s;
	for(int i = 0; i < n; ++ i) {
		if(str[i] == 'A') {
			s.push('A');
			continue;
		} else if(str[i] == 'B') {
			s.push('B');
			continue;
		}
		if(s.size() < 2) {
			s.push('C');
			continue;
		}
		char ch1 = s.top(); s.pop();
		char ch2 = s.top(); s.pop();
		if(ch2 == 'A' && ch1 == 'B') continue;
		s.push(ch2); s.push(ch1); s.push('C');
	}
	std :: stack <char> ss;
	while(s.size()) ss.push(s.top()), s.pop();
	while(ss.size()) std :: cout << ss.top(), ss.pop();
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