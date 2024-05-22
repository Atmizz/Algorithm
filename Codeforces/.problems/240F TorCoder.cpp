#include <bits/stdc++.h>
//#pragma GCC optimize(2)
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
struct Node {
	int l, r, sum, lz;
}t[26][N<<2];
int n, m;
std :: string str;
void pushUp(int k, int ch) {
	t[ch][k].sum = t[ch][ls].sum + t[ch][rs].sum;
}
void pushDown(int k, int ch) {
	t[ch][ls].lz = t[ch][rs].lz = t[ch][k].lz;
	t[ch][ls].sum = (t[ch][ls].r - t[ch][ls].l + 1) * t[ch][k].lz;
	t[ch][rs].sum = (t[ch][rs].r - t[ch][rs].l + 1) * t[ch][k].lz;
	t[ch][k].lz = -1;
}
void build(int l, int r, int k, int ch) {
	t[ch][k].l = l; t[ch][k].r = r; t[ch][k].lz = -1;
	if(l == r) {
		t[ch][k].sum = (str[l] - 'a') == ch;
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls, ch); build(mid+1, r, rs, ch);
	pushUp(k, ch);
}
void modify(int l, int r, int k, int x, int ch) {
	if(t[ch][k].l >= l && t[ch][k].r <= r) {
		t[ch][k].lz = x;
		t[ch][k].sum = (t[ch][k].r - t[ch][k].l + 1) * x;
		return ;
	}
	if(t[ch][k].lz != -1) pushDown(k, ch);
	int mid = (t[ch][k].l + t[ch][k].r) >> 1;
	if(l <= mid) modify(l, r, ls, x, ch);
	if(r > mid) modify(l, r, rs, x, ch);
	pushUp(k, ch);
}
int query(int l, int r, int k, int ch) {
	if(t[ch][k].l >= l && t[ch][k].r <= r) return t[ch][k].sum;
	if(t[ch][k].lz != -1) pushDown(k, ch);
	int mid = (t[ch][k].l + t[ch][k].r) >> 1, sum = 0;
	if(l <= mid) sum += query(l, r, ls, ch);
	if(r > mid) sum += query(l, r, rs, ch);
	return sum;
}
void solve() {
	std :: cin >> n >> m;
	std :: cin >> str;
	str = ')' + str;
	for(int i = 0; i < 26; ++ i)
		build(1, n, 1, i);
	for(int i = 1; i <= m; ++ i) {
		int l, r, oddCnt = 0, odd = 0, cnt[26];
		std :: cin >> l >> r;
		for(int j = 0; j < 26; ++ j) {
			cnt[j] = query(l, r, 1, j);
			if(cnt[j] & 1) odd = j, oddCnt ++;
		}
		if(oddCnt > 1) continue;
		if(oddCnt == 1 && (r - l + 1) % 2 == 0) continue;
		for(int j = 0; j < 26; ++ j)
			if(cnt[j]) modify(l, r, 1, 0, j);
		if(oddCnt == 1) {
			cnt[odd] --;
			modify((l+r)>>1, (l+r)>>1, 1, 1, odd);
		}
		for(int j = 0; j < 26; ++ j) 
			if(cnt[j]) {
				modify(l, l + cnt[j] / 2 - 1, 1, 1, j);
				modify(r - cnt[j] / 2 + 1, r, 1, 1, j);
				l += cnt[j] / 2;
				r -= cnt[j] / 2;
			}
	}
	for(int i = 1; i <= n; ++ i)
		for(int j = 0; j < 26; ++ j)
			if(query(i, i, 1, j)) {
				std :: cout << char(j + 'a');
				break;
			}
}
int main() {
	freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}