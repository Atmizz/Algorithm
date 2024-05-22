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
const int N = 1010;
struct ManacherAlgorithm {
	int radiuses[N<<1];
	std :: string exp;
	// index i in s
	// index i*2+1 in exp
	void init(std :: string &s) {
		exp = std :: string((int) s.size()*2+1, '#');
		int index = 0;
		for(int i = 1; i < (int) exp.size(); i += 2) {
			exp[i] = s[index++];
		}
	}
	void manacher() {
		int right_center = -1, right_radius = -1;
		for(int i = 0; i < (int) exp.size(); ++ i) {
			int radius = i < right_radius ? min(radiuses[right_center*2-i], right_radius - i) : 1;
			while(i - radius > -1 && i + radius < (int) exp.size()) {
				if(exp[i-radius] == exp[i+radius]) {
					radius ++;
				} else {
					break;
				}
			}
			radiuses[i] = radius;
			if(right_radius < i + radius) {
				right_radius = i + radius;
				right_center = i;
			}
		}
	}
	int getMaxRadius() {
		int maxx = 1;
		for(int i = 0; i < (int) exp.size(); ++ i) {
			maxx = max(maxx, radiuses[i]);
		}
		return maxx;
	}
	// Whether it is a palindrome string
	bool isPalindrome(int l, int r) {
		l --; r --;
		l = l * 2 + 1;
		r = r * 2 + 1;
		return radiuses[l+r>>1] >= (r - l) / 2 + 1;
	}
}Manacher;
void solve() {
	int n;
	std :: cin >> n;
	std :: string s;
	std :: cin >> s;
	Manacher.init(s);
	Manacher.manacher();
	int cnt = 0;
	for(auto &ch : s) {
		cnt += ch == '1';
	}
	if(Manacher.isPalindrome(1, n)) {
		if((n & 1) && cnt + 1 < n && s[n/2] == '0') {
			std :: cout << "ALICE\n";
			return ;
		}
		if(cnt == n) {
			std :: cout << "DRAW\n";
			return ;
		}
		std :: cout << "BOB\n";
		return ;
	}
	if((n & 1) && cnt + 2 ==  n && s[n/2] == '0') {
		std :: cout << "DRAW\n";
		return ;
	}
	std :: cout << "ALICE\n";
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	std :: cin >> _; 
	while(_ --) solve();
	return 0;
}