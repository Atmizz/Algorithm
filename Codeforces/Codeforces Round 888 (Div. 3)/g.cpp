#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;

int pa[200010];

int find(int x) {
    return x == pa[x] ? x : pa[x] = find(pa[x]);
}

void merge(int u, int v) {
    u = find(u); v = find(v);
    pa[u] = v;
}

void solve() {
    int n, m;
    std :: cin >> n >> m;
    for(int i = 1; i <= n; ++ i) pa[i] = i;

    std :: vector <int> h(n+1);
    for(int i = 1; i <= n; ++ i) std :: cin >> h[i];

    std :: vector <std :: array<int, 3> > edge(m);
    for(auto & [w, x, y] : edge)
        std :: cin >> x >> y, w = std :: max(h[x], h[y]);
    std :: sort(edge.begin(), edge.end());

    int q; std :: cin >> q;
    std :: vector <std :: array <int, 4> > Q(q);
    for(int i = 0; i < q; ++ i) {
        int u, v, e;
        std :: cin >> u >> v >> e;
        Q[i] = {h[u]+e, u, v, i};
    }
    std :: sort(Q.begin(), Q.end());

    std :: vector <bool> st(q);
    int t = 0;
    for(const auto & [e, u, v, id] : Q) {
        while(t < m && edge[t][0] <= e) {
            merge(edge[t][1], edge[t][2]);
            t ++;
        }
        int x = find(pa[u]), y = find(pa[v]);
        st[id] = (x == y);
    }
    for(auto x : st)
        std :: cout << (x ? "YES\n" : "NO\n");
    std :: cout << endl; 
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