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
const int N = 400;
const i64 M = 1e18;
std :: mt19937 rd(114514);
char g[11][N];
int pos;
i64 quickPow(i64 a, i64 b) {
	i64 fac = 1LL;
	while(b) {
		if(b & 1LL) {
			fac = fac * a;
		}
		b /= 2; a = a * a;
		// std :: cout << a << ' ' << fac << '\n';
	}
	return fac;
}
void print5(int st, int num) {
	if(num == 1) {
		for(int i = 1; i <= 5; ++ i) {
			g[i][st+4] = '1';
		}
	}
	else if(num == 2) {
		for(int i = st; i <= st + 4; ++ i) {
			g[1][i] = g[3][i] = g[5][i] = '2';
		}
		g[2][st+4] = g[4][st] = '2';
	}
	else if(num == 3) {
		for(int i = st; i <= st + 4; ++ i) {
			g[1][i] = g[3][i] = g[5][i] = '3';
		}
		g[2][st+4] = g[4][st+4] = '3';
	}
	else if(num == 4) {
		for(int i = 1; i <= 5; ++ i) {
			g[i][st+4] = '4';
		}
		for(int i = st; i <= st + 4; ++ i) {
			g[3][i] = '4';
		}
		for(int i = 1; i <= 3; ++ i) {
			g[i][st] = '4';
		}
	}
	else if(num == 5) {
		for(int i = st; i <= st + 4; ++ i) {
			g[1][i] = g[3][i] = g[5][i] = '5';
		}
		g[4][st+4] = g[2][st] = '5';
	}
	else if(num == 6) {
		for(int i = st; i <= st + 4; ++ i) {
			g[1][i] = g[3][i] = g[5][i] = '6';
		}
		g[2][st] = g[4][st+4] = g[4][st] = '6';
	}
	else if(num == 7) {
		for(int i = 1; i <= 5; ++ i) {
			g[i][st+4] = '7';
		}
		for(int i = st; i <= st + 3; ++ i) {
			g[1][i] = '7';
		}
	}
	else if(num == 8) {
		for(int i = st; i <= st + 4; ++ i) {
			g[1][i] = g[3][i] = g[5][i] = '8';
		}
		g[4][st+4] = g[2][st] = g[2][st+4] = g[4][st] = '8';
	}
	else if(num == 9) {
		for(int i = st; i <= st + 4; ++ i) {
			g[1][i] = g[3][i] = g[5][i] = '9';
		}
		g[4][st+4] = g[2][st] = g[2][st+4] = '9';
	}
	else {
		for(int i = st; i <= st + 4; ++ i) {
			g[1][i] = g[5][i] = '0';
		}
		for(int i = 1; i <= 5; ++ i) {
			g[i][st+4] = g[i][st] = '0';
		}
	}
}
void print7(int st, int num) {
	if(num == 1) {
		for(int i = 2; i <= 8; ++ i) {
			g[i][st+6] = '1';
		}
	}
	else if(num == 2) {
		for(int i = st; i <= st + 6; ++ i) {
			g[2][i] = g[5][i] = g[8][i] = '2';
		}
		g[3][st+6] = g[4][st+6] = g[6][st] = g[7][st] = '2';
	}
	else if(num == 3) {
		for(int i = st; i <= st + 6; ++ i) {
			g[2][i] = g[5][i] = g[8][i] = '3';
		}
		g[3][st+6] = g[4][st+6] = g[6][st+6] = g[7][st+6] = '3';
	}
	else if(num == 4) {
		for(int i = st; i <= st + 6; ++ i) {
			g[5][i] = '4';
		}
		for(int i = 2; i <= 8; ++ i) {
			g[i][st+6] = '4';
		}
		for(int i = 2; i <= 5; ++ i) {
			g[i][st] = '4';
		}
	}
	else if(num == 5) {
		for(int i = st; i <= st + 6; ++ i) {
			g[2][i] = g[5][i] = g[8][i] = '5';
		}
		g[3][st] = g[4][st] = g[6][st+6] = g[7][st+6] = '5';
	}
	else if(num == 6) {
		for(int i = st; i <= st + 6; ++ i) {
			g[2][i] = g[5][i] = g[8][i] = '6';
		}
		g[6][st+6] = g[7][st+6] = '6';
		for(int i = 2; i <= 8; ++ i) {
			g[i][st] = '6';
		}
	}
	else if(num == 7) {
		for(int i = 2; i <= 8; ++ i) {
			g[i][st+6] = '7';
		}
		for(int i = st; i <= st + 6; ++ i) {
			g[2][i] = '7';
		}
	}
	else if(num == 8) {
		for(int i = st; i <= st + 6; ++ i) {
			g[2][i] = g[5][i] = g[8][i] = '8';
		}
		for(int i = 2; i <= 8; ++ i) {
			g[i][st] = g[i][st+6] = '8';
		}
	}
	else if(num == 9) {
		for(int i = st; i <= st + 6; ++ i) {
			g[2][i] = g[5][i] = g[8][i] = '9';
		}
		for(int i = 2; i <= 8; ++ i) {
			g[i][st+6] = '9';
		}
		for(int i = 2; i <= 5; ++ i) {
			g[i][st] = '9';
		}
	}
	else {
		for(int i = st; i <= st + 6; ++ i) {
			g[2][i] = g[8][i] = '0';
		}
		for(int i = 2; i <= 8; ++ i) {
			g[i][st+6] = g[i][st] = '0';
		}
	}
}
void print_(int st) {
	for(int i = st; i <= st + 6; ++ i) {
		g[4][i] = g[6][i] = '=';
	}
}
void printINF(int st) {
	for(int i = st; i <= st + 6; ++ i) {
		g[2][i] = g[8][i] = 'I';
	}
	for(int i = 2; i <= 8; ++ i) {
		g[i][st+3] = 'I';
	}
	st += 8;
	for(int i = 2; i <= 8; ++ i) {
		g[i][st] = g[i][st+6] = 'N';
	}
	for(int i = 1; i <= 7; ++ i) {
		g[1+i][st+i-1] = 'N';
	}
	st += 8;
	for(int i = st; i <= st + 6; ++ i) {
		g[2][i] = g[5][i] = 'F';
	}
	for(int i = 2; i <= 8; ++ i) {
		g[i][st] = 'F';
	}
}
void mk(i64 x, int sz) {
	if(x == 0) {
		if(sz == 5) {
			print5(pos, 0);
			pos += 6;
		} else {
			print7(pos, 0);
			pos += 8;
		}
	}
	i64 y = x;
	std :: stack <int> st;
	while(y) {
		st.push(y % 10);
		y /= 10;
	}
	for(; (int) st.size();) {
		y = st.top(); st.pop();
		if(sz == 7) {
			print7(pos, y);
		} else {
			print5(pos, y);
		}
		pos += sz + 1;
	}
}
void solve() {
	std :: string str;
	std :: cin >> str;
	memset(g, '.', sizeof g);
	i64 a = 0, b = 0; pos = 1;
	int n = (int) str.size();
	str = '(' + str;
	for(int i = 1; i <= n; ++ i) {
		if(str[i] >= '0' && str[i] <= '9') {
			int j = i;
			if(i == 1) {
				while(j <= n && str[j] >= '0' && str[j] <= '9') {
					a = a * 10 + str[j] - 48;
					j ++;
				}
			} else {
				while(j <= n && str[j] >= '0' && str[j] <= '9') {
					b = b * 10 + str[j] - 48;
					j ++;
				}
			}
			i = j - 1;
		}
	}
	 
	// std :: cout << quickPow(a, b) << '\n';
	
	i64 c = (a == 1 ? 1 : -1);

	i64 num = 0, res = 1e18;
	while(a != 1 && a != 0 && res) {
		res /= a;
		num ++;
	}
//	std :: cout << a << ' ' << b << ' ' << num << '\n';
	if(num > b) {
		c = quickPow(a, b);
	}
	if(a == 0 || a == 1) {
		c = a;
	}
	if(a == 0 && b == 0) {
		c = 1;
	}
//	 deb(num);
//	 deb(a);
//	 deb(b)
//	 deb(c)
	mk(a, 7); mk(b, 5); print_(pos); pos += 8;
	if(c == -1) {
		printINF(pos);
		pos += 24;
	} else {
		mk(c, 7);
	}

	for(int i = 0; i < 10; ++ i) {
		for(int j = 0; j < pos; ++ j) {
			std :: cout << g[i][j];
		}
		std :: cout << '\n';
	}
	std :: cout << '\n';
}
int main() {
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}
