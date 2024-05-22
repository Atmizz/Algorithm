#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
int blk[N], block, n, q;
i64 cnt[N];
std :: map <char, int> mp[N];
std :: string str;
int query(int l, int r) {
	i64 res = 0, sum = 0;
	for(int i = l; i <= std :: min(r, blk[l] * block); ++ i)
		res |= (1ll << (str[i] - 'a'));
	if(blk[l] != blk[r])
		for(int i = (blk[r] - 1) * block + 1; i <= r; ++ i)
			res |= (1ll << (str[i] - 'a'));
	for(int i = blk[l] + 1; i <= blk[r] - 1; ++ i) {
//		deb(cnt[i]);
      res |= cnt[i];
    }
//    deb(res);
	while(res) sum += (res & 1ll), res >>= 1ll;
	return sum;
}
void solve() {
	std :: cin >> str;
	std :: cin >> q;
	n = str.size();
    str = '-' + str;
	block = std :: sqrt(n);
	for(int i = 1; i <= n; ++ i) {
		blk[i] = (i - 1) / block + 1;
		mp[blk[i]][str[i]] ++;
		if(mp[blk[i]][str[i]] == 1) cnt[blk[i]] += (1ll << (str[i] - 'a'));
	}
	while(q --) {
		int opt, l, r;
		char ch;
		std :: cin >> opt;
		if(opt == 1) {
			std :: cin >> l >> ch;
			mp[blk[l]][str[l]] --;
			if(mp[blk[l]][str[l]] == 0) cnt[blk[l]] -= (1ll << (str[l] - 'a'));
			mp[blk[l]][ch] ++;
			if(mp[blk[l]][ch] == 1) cnt[blk[l]] += (1ll << (ch - 'a'));
			str[l] = ch;
		} else {
			std :: cin >> l >> r;
			std :: cout << query(l, r) << endl;
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
