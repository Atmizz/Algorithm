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
	int l, r, sz, cnt, val, key;
}t[N];
int rt, n, idx;
void pushUp(int p) {
	t[p].sz = t[t[p].l].sz + t[t[p].r].sz + t[p].cnt;
}
int getNode(int key) {
	t[++idx].key = key;
	t[idx].sz = t[idx].cnt = 1;
	t[idx].val = rand();
	return idx;
}
void zig(int &p) {
	int q = t[p].l;
	t[p].l = t[q].r; t[q].r = p; p = q;
	pushUp(t[p].r); pushUp(p);
}
void zag(int &p) {
	int q = t[p].r;
	t[p].r = t[q].l; t[q].l = p; p = q;
	pushUp(t[p].l); pushUp(p);
}
void insert(int &p, int key) {
	if(!p) p = getNode(key);
	else if(t[p].key == key) t[p].cnt ++;
	else if(key < t[p].key) {
		insert(t[p].l, key);
		if(t[t[p].l].val > t[p].val) zig(p);
	} else {
		insert(t[p].r, key);
		if(t[t[p].r].val > t[p].val) zag(p);
	}
	pushUp(p);
}
void remove(int &p, int key) {
	if(!p) return ;
	if(t[p].key == key) {
		if(t[p].cnt > 1) t[p].cnt --;
		else if(t[p].l || t[p].r) {
			if(!t[p].r || t[t[p].l].val > t[t[p].r].val) {
				zig(p);
				remove(t[p].r, key);
			} else {
				zag(p);
				remove(t[p].l, key);
			}
		} else p = 0;
	} else if(key < t[p].key) remove(t[p].l, key);
	else remove(t[p].r, key);
	pushUp(p);
}
int getRankByKey(int p, int key) {
	if(!p) return 1;
	if(t[p].key == key) return t[t[p].l].sz + 1;
	else if(t[p].key > key) return getRankByKey(t[p].l, key);
	else return t[t[p].l].sz + t[p].cnt + getRankByKey(t[p].r, key);
}
int getKeyByRank(int p, int rank) {
	if(!p) return INF;
	if(t[t[p].l].sz >= rank) return getKeyByRank(t[p].l, rank);
	else if(t[t[p].l].sz + t[p].cnt >= rank) return t[p].key;
	else return getKeyByRank(t[p].r, rank - t[t[p].l].sz - t[p].cnt);
}
int getPrev(int p, int key) {
	if(!p) return -INF;
	if(t[p].key >= key) return getPrev(t[p].l, key);
	else return std :: max(t[p].key, getPrev(t[p].r, key));
}
int getNext(int p, int key) {
	if(!p) return INF;
	if(t[p].key <= key) return getNext(t[p].r, key);
	else return std :: min(t[p].key, getNext(t[p].l, key));
}
void solve() {
	std :: cin >> n;
	while(n --) {
		int opt, x;
		std :: cin >> opt >> x;
		if(opt == 1) insert(rt, x);
		else if(opt == 2) remove(rt, x);
		else if(opt == 3) std :: cout << getRankByKey(rt, x) << endl;
		else if(opt == 4) std :: cout << getKeyByRank(rt, x) << endl;
		else if(opt == 5) std :: cout << getPrev(rt, x) << endl;
		else if(opt == 6) std :: cout << getNext(rt, x) << endl;
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