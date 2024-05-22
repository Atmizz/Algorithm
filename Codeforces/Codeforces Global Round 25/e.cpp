#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
void solve() {
	std :: string str;
	std :: cin >> str;
	int n = str.size();
	std :: string s = '0' + str;
	bool ok = true;
	for(int i = 1; i <= n / 2; ++ i) {
		if(s[i] != s[n-i+1]) {
			ok = false;
			break;
		}
	}
	if(!ok) {
		std :: cout << "YES\n1\n" << str << '\n';
		return ;
	}
	std :: string exp_str(str.length()*2+1, '#');
	std :: vector <int> radiuses(n*2+2);
	int index = 0;
	for(int i = 1; i < exp_str.length(); i += 2) {
	    exp_str[i] = str[index++];
	}
	int max_center = -1;
	int right_radius = -1, right_center = -1;
	for(int i = 0; i < exp_str.size(); ++ i) {
    int radius = i < right_radius ? std :: min(radiuses[right_center*2-i], right_radius - i) : 1;
    while(i + radius < exp_str.length() && i - radius > -1) {
      if(exp_str[i+radius] == exp_str[i-radius]) {
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
	for(int i = 4; i < n * 2; i += 2) {
		// std :: cout << i << ' ';
		// std :: cout << i+(n*2-i+1)/2 << ' ' << (n*2-i+1)/2 << '\n';
		if(radiuses[i/2] != i / 2 + 1 && radiuses[i+(n*2-i)/2] != (n*2-i)/2+1) {
			std :: cout << "YES\n2\n";
			for(int j = 1; j <= i; ++ j) {
				if(exp_str[j] != '#') {
					std :: cout << exp_str[j];
				}
			}
			std :: cout << ' ';
			for(int j = i + 1; j <= n * 2; ++ j) {
				if(exp_str[j] != '#') {
					std :: cout << exp_str[j];
				}
			}
			std :: cout << '\n';
			return ;
		}
	}

	std :: cout << "NO\n";
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