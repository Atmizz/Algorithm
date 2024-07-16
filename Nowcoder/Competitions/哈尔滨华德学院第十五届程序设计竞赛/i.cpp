#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define sz(x) (int)x.size()
#define mk std :: make_pair
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << '\n';
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
typedef unsigned long long ull;
template <class T>
T max(T a, T b) {
	return a > b ? a : b;
}
template <class T>
T min(T a, T b) {
	return a < b ? a : b;
}
template <class T>
T abs(T a) {
	return a < 0 ? -a : a;
}
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <int> a(n+1), c(n+1);
	i64 sum = 0;
	std :: vector <int> b(n+1);
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		c[i] = a[i] - a[i-1];
		b[i] = c[i];
		if(i >= 2) {
			sum += c[i];
		}
	}
	if(n <= 2) {
		std :: cout << 0;
		return ;
	}
	int avg = sum / (n - 1);
	sum %= (n - 1);
	if(sum < 0) {
		sum += n - 1;
	}
	int ans = INT_MAX, cnt = 0;
	if(sum == 1) {
		if(avg <= 0) {
			avg --;
		}
	} else if(sum == n - 2) {
		if(avg >= 0) {
			avg ++;
		}
	} else if(sum != 0) {
		std :: cout << -1 << '\n';
		return ;
	}
//////////////////////////////////////////
	

	for(int i = 2; i < n; ++ i) {
		if(c[i] > avg) {
			c[i] --;
			c[i+1] ++;
			cnt ++;
		} else if(c[i] < avg) {
			c[i] ++;
			c[i+1] --;
			cnt ++;
		}
	}
	
	if(abs(c[2] - avg) == 1) {
		cnt ++;
		c[2] = avg;
	} 
	if(abs(c[n] - avg) == 1) {
		c[n] = avg;
		cnt ++;
	}

	for(int i = 2; i <= n; ++ i) {
		// std :: cout << c[i] << " ";
		if(c[i] != avg) {
			cnt = INT_MAX;
			break;
		}
	}
	// deb(cnt);
	ans = min(ans, cnt);
	cnt = 0;

	for(int i = 2; i <= n; ++ i) {
		c[i] = b[i];
		// std :: cout << c[i] << " \n"[i == n];
	}


	if(c[2] < avg) {
		c[2] ++;
		cnt ++;
	} else if(c[2] > avg) {
		c[2] --;
		cnt ++;
	}
	for(int i = 2; i < n; ++ i) {
		if(c[i] > avg) {
			c[i] --;
			c[i+1] ++;
			cnt ++;
		} else if(c[i] < avg) {
			c[i] ++;
			c[i+1] --;
			cnt ++;
		}
	}
	if(abs(c[n] - avg) == 1) {
		c[n] = avg;
		cnt ++;
	}
	for(int i = 2; i <= n; ++ i) {
		if(c[i] != avg) {
			cnt = INT_MAX;
			break;
		}
	}
	// deb(cnt);
	ans = min(ans, cnt);
	std :: cout << (ans == INT_MAX ? -1 : ans);
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	//std :: cin >> _; 
	while(_ --) solve();
	return 0;
}