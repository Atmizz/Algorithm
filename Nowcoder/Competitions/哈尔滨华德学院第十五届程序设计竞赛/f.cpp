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
const int N = 2e5 + 20;
struct Node {
	i64 sno;
	int grade, rank;
	friend bool operator < (Node a, Node b) {
		return a.grade == b.grade ? a.sno < b.sno : a.grade > b.grade;
	}
};
struct Mode {
	i64 cno;
	int grade, rank;
	friend bool operator < (Mode a, Mode b) {
		return a.cno < b.cno;
	}
};
void solve() {
	std :: map <i64, std :: vector <Node> > v;
	std :: map <i64, std :: vector <Mode> > u;
	std :: map <i64, std :: map <i64, int> > gd, rk;
	int n;
	std :: cin >> n;
	while(n --) {
		i64 sno, cno;
		int grade;
		std :: cin >> sno >> cno >> grade;
		v[cno].pb({sno, grade, 1});
		gd[cno][sno] = grade;
	}
	for(auto &[cno, a] : v) {
		std :: sort(a.begin(), a.end());
		rk[cno][a[0].sno] = 1;
		u[a[0].sno].pb({cno, a[0].grade, 1});
		for(int i = 1; i < sz(a); ++ i) {
			if(a[i].grade != a[i-1].grade) {
				a[i].rank = a[i-1].rank + 1;
			} else {
				a[i].rank = a[i-1].rank;
			}
			rk[cno][a[i].sno] = a[i].rank;
			u[a[i].sno].pb({cno, a[i].grade, a[i].rank});
		}
	}
	while(1) {
		std :: string s;
		std :: cin >> s;
		if(s == "END") {
			std :: cout << "OK";
			break;
		}
		i64 cno, sno;
		int grade;
		if(s == "query1") {
			std :: cin >> sno >> cno;
			std :: cout << gd[cno][sno] << nl;
		} else if(s == "query2") {
			std :: cin >> sno >> cno;
			std :: cout << rk[cno][sno] << nl;
		} else if(s == "query3") {
			std :: cin >> cno;
			for(auto &a : v[cno]) {
				std :: cout << a.sno << ' ' << a.grade << ' ' << a.rank << nl;
			}
		} else {
			std :: cin >> sno;
			for(auto &a : u[sno]) {
				std :: cout << a.cno << ' ' << a.grade << ' ' << a.rank << nl;
			}
		}
	}
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