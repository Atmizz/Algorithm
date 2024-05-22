#include <cstdio>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
typedef long long i64;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
int n, m, w[110], v[110], tot, c[3010];
bool f[N];
void solve() {
	while(1) {
		scanf("%d %d", &n, &m);
		if(n == 0) return ; f[0] = 1; tot = 0;
		for(int i = 1; i <= n; ++ i)
			scanf("%d", &v[i]);
		for(int i = 1; i <= n; ++ i)
			scanf("%d", &w[i]);
		for(int i = 1; i <= n; ++ i) {
			if((i64)w[i] * v[i] >= m) {
				for(int j = v[i]; j <= m; ++ j)
					f[j] |= f[j-v[i]];
				continue;
			}
			int k = 1;
			while(w[i] >= k) {
				c[++tot] = v[i] * k;
				w[i] -= k; k <<= 1;
			}
			if(w[i]) c[++tot] = v[i] * w[i];
		}
		for(int i = 1; i <= tot; ++ i)
			for(int j = m; j >= c[i]; -- j)
				f[j] |= f[j-c[i]];
		int ans = 0;
		for(int i = 1; i <= m; ++ i)
			ans += f[i], f[i] = 0;
		printf("%d\n", ans);
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