#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <stack>
#include <cmath>
#include <bitset>
#include <complex>
#include <cstdlib>
#include <set>
#include <cstring>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
typedef long long i64;
const int INF = 0x3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e4 + 20;
int n, q;
std :: bitset <N> b[1010];
void solve() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) {
		int k;
		scanf("%d", &k);
		for(int j = 1; j <= k; ++ j) {
			int x;
			scanf("%d", &x);
			b[i].set(x, 1);
		}
	}
	scanf("%d", &q);
	while(q --) {
		int x, y;
		scanf("%d%d", &x, &y);
		bool ok = false;
		for(int i = 1; i <= n; ++ i) {
			if(b[i][x] && b[i][y]) {
				puts("Yes");
				ok = true;
				break;
			}
		}
		if(!ok) {
			puts("No");
		}
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	//scanf("%d", &T); 
	while(T --) solve();
	return 0;
}