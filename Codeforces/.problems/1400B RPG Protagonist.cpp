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
const int N = 2e5 + 20;
i64 p, f, cnts, cntw, s, w;
void solve() {
	std :: cin >> p >> f;
	std :: cin >> cnts >> cntw;
	std :: cin >> s >> w;
	if(s > w) {
		std :: swap(s, w);
		std :: swap(cnts, cntw);
	}
	i64 ans = 0;
	for(i64 i = 0; i <= cnts; ++ i) {
		if(i * s > p) {
			break;
		}
		i64 cnt = i, resp = p - i * s;
		i64 ress = cnts - i, resw = cntw;
		if(w * resw > resp) {
			cnt += resp / w;
			resw -= resp / w;
		} else {
			resw = 0;
			cnt += cntw;
		}
		i64 resf = f;
		if(ress) {
			if(ress * s > f) {
				cnt += f / s;
				resf -= f / s * s;
			} else {
				cnt += ress;
				resf -= ress * s;
			}
		}
		if(resw) {
			if(resw * w > resf) {
				cnt += resf / w;
			} else {
				cnt += resw;
			}
		}
		ans = std :: max(ans, cnt);
	}
	std :: cout << ans << '\n';
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