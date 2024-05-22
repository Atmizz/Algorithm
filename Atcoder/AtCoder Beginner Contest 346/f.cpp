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
const int N = 1e5 + 20;
i64 n;
std :: string s, t;
int sum[N][26];
void solve() {
	std :: cin >> n >> s >> t;
	s = "0" + s;
	t = "0" + t;
	int len = s.length();
	std :: vector <int> p[26];
	for(int i = 1; i <= len; ++ i) {
		for(int j = 0; j < 26; ++ j) {
			sum[i][j] = sum[i-1][j];
		}
		sum[i][s[i]-'a'] ++;
		p[s[i]-'a'].push_back(i);
	}
	auto check = [=](i64 x) {
		// x -> the number that the string t repeats
		i64 cnt = 1, pos = 1;
		// cnt -> the number the string s has repeated
		// pos -> the position of the string s
		for(int i = 1; i <= (int) t.size(); ++ i) {
			int target = t[i] - 'a';
			if(x > sum[n][target] - sum[pos-1][target]) {
				i64 res = x - sum[n][target] + sum[pos-1][target];
				cnt += res / sum[n][target] + (res % sum[n][target] > 0);
				if(res % sum[n][target] == 0) {
					pos = 1;
				} else {
					pos = p[target][res%sum[n][target]];
				}
			} else {
				pos = p[target][pos+x];
			}
			
		}
		return true;
	};
	i64 l = 0, r = 1e17, ans;
	while(l <= r) {
		i64 mid = (l + r) >> 1LL;
		if(check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
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