#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 5020;

int prime[N], cnt, num[N];
bool st[N];

void get_prime(int n) {
	for(int i = 2; i <= n; ++ i) {
		if(!st[i]) prime[++cnt] = i;
		for(int j = 1; j <= cnt && i * prime[j] <= n; ++ j) {
			st[i*prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
}

int get(int a, int p) {
	int sum = 0;
	while(a) {
		sum += a / p;
		a /= p;
	} return sum;
}

std :: vector <int> mul(std :: vector <int> a, int b) {
	std :: vector <int> c;
	int t = 0;
	for(int i = 0; i < a.size(); ++ i) {
		t += a[i] * b;
		c.push_back(t % 10);
		t /= 10;
	}
	while(t) c.push_back(t % 10), t /= 10;
	return c;
}

void solve() {
	int a, b;
	std :: cin >> a >> b;
	get_prime(a);
	for(int i = 1; i <= cnt; ++ i) num[i] = get(a, prime[i]) - get(b, prime[i]) - get(a - b, prime[i]);
	std :: vector <int> res;
	res.push_back(1);
	for(int i = 1; i <= cnt; ++ i)
		for(int j = 1; j <= num[i]; ++ j)
			res = mul(res, prime[i]);
	for(int i = res.size() - 1; i >= 0; -- i)
		std :: cout << res[i];
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}