#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define pr pair<int, int>
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;

const int N = 1e5 + 200;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;

void solve() {
	// std :: cout << "case : " << '\n';
	i64 n, k;
	std :: cin >> n >> k;
	std :: string str;
	std :: cin >> str;

	if(k == 0) {
		std :: cout << str;
		return ;
	}
	if(n == 1) {
		if(k & 1ll) std :: cout << 0;
		else std :: cout << 1;
		return ;
	}

	i64 num0 = 0, num1 = 0;
	std :: vector <int> f(n);
	for(int i = 1; i < n; ++ i)
		if(str[i] == '0') {
			f[i] = f[i-1] + 1;
			if(str[i+1] == '1' || i + 1 == n) num0 ++;
		}
	
	if(num0 >= k) {
		for(int i = 0; i < n; ++ i)
			if(str[i] == '0') {
				str[i] = '1';
				if(str[i+1] == '1') k --;
				if(k == 0) break;
			}
	}
	else {
		k -= num0;
		for(int i = 0; i < n; ++ i) str[i] = '1';
		if(num0 == 0 && k == 1) str[n-1] = '0';
	}

	std :: cout << str;
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T;
	while(T --) solve(), std :: cout << '\n';
	return 0;
}