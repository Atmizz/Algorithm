#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define gc getchar
#define ls k << 1
#define rs k << 1 | 1
#define double long double
#define pi std :: pair<double, double>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e4 + 20;
inline int read() {
   int s = 0, f = 1; char ch = gc();
   while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = gc();}
   while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = gc();
   return s * f;
}
double finddis(pi x, pi y) {
	return std :: sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
}
double findcos(pi a, pi b, pi c) {
	return (b.first - a.first) * (c.first - a.first) + (b.second - a.second) * (c.second - a.second);
}
double findsin(pi a, pi b, pi c) {
	return std :: fabs((b.first - a.first) * (c.second - a.second) + (c.first - a.first) * (b.second - a.second));
}
pi p[N], s[N];
double l[N];
void solve() {
	int n, m;
	n = read(); m = read();
	for(int i = 1; i <= n; ++ i)
		p[i].first = (double)read(), p[i].second = (double)read();
	for(int i = 1; i <= m; ++ i)
		s[i].first = (double)read(), s[i].second = (double)read();
	for(int i = 2; i <= n; ++ i)
		l[i] = finddis(p[i], p[i-1]);
	double r, dis_i_1, dis_i, cosA, cosB, sinA;
	for(int i = 1; i <= m; ++ i) {
		r = INF;
		for(int j = 2; j <= n; ++ j) {

			dis_i_1 = finddis(s[i], p[j-1]);
			dis_i = finddis(s[i], p[j]);
			cosA = findcos(p[j], p[j-1], s[i]);
			cosB = findcos(p[j-1], p[j], s[i]);
			if(std :: fabs(cosA / l[j] / dis_i - 1) < eps && std :: fabs(cosB / l[j] / dis_i_1 - 1) < eps) {
				r = 0;
				break;
			}
			if(cosA <= 0 || cosB <= 0) {
				r = std :: min(r, std :: min(dis_i, dis_i_1));
				continue;
			}
			sinA = findsin(p[j-1], s[i], p[j]) / dis_i_1 / l[j];
			r = std :: min(r, dis_i_1 * sinA);
		}
		printf("%.4Lf\n", r);
	}
}

int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}