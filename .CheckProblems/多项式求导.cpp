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
// const int N = ;
void solve() {
	std :: string str;
	std :: cin >> str;
	std :: cout << "f'(x)=";
	int n = str.length(), cnt = 0;
	for(int i = 4; i < n; ++ i) {
		if(str[i] == 'x') {
			cnt ++;
			int f = 1;
			int pos = i;
			for(; pos >= 4; -- pos) {
				if(str[pos] == '=' || str[pos] == '-' || str[pos] == '+') {
					break;
				}
			}
			if(str[pos] == '-') {
				f = -1;
			} else if(str[pos] == '=') {
				f = 2;
			}
			pos ++;
			int A = 0;
			while(str[pos] >= '0' && str[pos] <= '9') {
				A = A * 10 + (str[pos] - 48);
				pos ++;
			}
			if(A == 0) {
				A = 1;
			}
			int I = 0;
			if(str[i+1] != '^') {
				I = 1;
			} else {
				pos += 2;
				while(str[pos] >= '0' && str[pos] <= '9') {
					I = I * 10 + str[pos] - 48;
					pos ++;
				}
			}
			if(f == 1) {
				std :: cout << "+";
			} else if(f == -1) {
				std :: cout << '-';
			}
			std :: cout << A * I;
			if(I - 1 > 1) {
				std :: cout << "x^" << I - 1;
			} else if(I - 1 == 1) {
				std :: cout << "x";
			}
		}
	}
	if(cnt == 0) {
		std :: cout << 0;
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