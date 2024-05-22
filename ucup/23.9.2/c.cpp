#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 256;
const int N = 1e5 + 20;
std :: string operation[N];
int a[N], back[N], change[N];
int n, r;
void solve() {
	r = 0;
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> operation[i] >> a[i];
		if(operation[i] != "add") std :: cin >> back[i];
		change[i] = -1;
	}
	for(int i = 1; i <= n; ++ i) {
		std :: string s = operation[i];
		if(s != "add") {
			if(s == "beq" && r != a[i]) continue;
			else if(s == "bne" && r == a[i]) continue;
			else if(s == "blt" && r >= a[i]) continue;
			else if(s == "bgt" && r <= a[i]) continue;
			int j = back[i], res = 0;
			while(j <= i) {
				s = operation[j];
				if(j == i) res ++;
				if(res == 256) {
					std :: cout << "No\n";
					return ;
				}
				if(s == "add") r = (r + a[j]) % Mod, ++ j;
				else {
					if(s == "beq" && r == a[j])
						j = back[j];
					else if(s == "bne" && r != a[j])
						j = back[j];
					else if(s == "blt" && r < a[j])
						j = back[j];
					else if(s == "bgt" && r > a[j])
						j = back[j];
					else j ++;
				}
			}
		} else r = (r + a[i]) % Mod;
	}
	std :: cout << "Yes\n";
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