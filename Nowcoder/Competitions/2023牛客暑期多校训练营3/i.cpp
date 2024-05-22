#include <bits/stdc++.h>
#define deb(x) std :: cout << #x << " = " << x << '\n';
using namespace std;
const int maxn = 5e5 + 10;
vector<int> ve[maxn];
int dep[maxn], f[21][maxn];
int jmp[21][maxn];
int col[60][maxn]; // 对于每个颜色能跳的最高的节点
long long a[maxn];
int Fa[maxn];
void dfs(int x, int fa)
{
    dep[x] = dep[fa] + 1;
    Fa[x] = fa;
    int up = -1; // 不管哪种颜色能跳到的高处。
    for (int i = 0; i < 60; i++)
    {
        col[i][x] = col[i][fa];
        if ((a[x] >> i & 1) && col[i][x] == -1)
            col[i][x] = x;
        if (~a[x] >> i & 1)
            col[i][x] = -1;
        if (up == -1 || (col[i][x] != -1 && dep[up] > dep[col[i][x]]))
            up = col[i][x];
    }
    jmp[0][x] = up; // 倍增
    if(x == 8) deb(jmp[0][8]);
    for (int i = 0; i <= 19; i++)
    {
        f[i + 1][x] = f[i][f[i][x]];
        if (jmp[i][x] != -1) {
            jmp[i + 1][x] = jmp[i][jmp[i][x]];
        }
    }
    for (auto it : ve[x])
    {
        if (it == fa)
            continue;
        f[0][it] = x;
        dfs(it, x);
    }
}
int lca(int x, int y)
{
    if (dep[x] < dep[y])
        swap(x, y);
    for (int i = 20; i >= 0; i--)
    {
        if (dep[f[i][x]] >= dep[y])
            x = f[i][x];
        if (x == y)
            return x;
    }
    for (int i = 20; i >= 0; i--)
        if (f[i][x] != f[i][y])
            x = f[i][x], y = f[i][y];
    return f[0][x];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    memset(col, -1, sizeof(col));
    memset(jmp, -1, sizeof(jmp));
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        ve[x].push_back(y);
        ve[y].push_back(x);
    }
    dfs(1, 0);deb(jmp[0][8]);
    function<int(int, int)> solve = [&](int x, int y)
    {
        int L = lca(x, y);
        deb(dep[L]);
        int ans = dep[x] + dep[y] - dep[L] * 2;
        if (x == L)
            swap(x, y);
        if (x == L)
            return 0;
        if (y == L)
        {
            for (int i = 20; i >= 0; i--)
                if (jmp[i][x] != -1 && dep[jmp[i][x]] > dep[L])
                {
                    deb(x); deb(jmp[i][x]); deb(dep[jmp[i][x]]); deb(i);
                    ans += 1 << i; x = jmp[i][x];
                    deb(x); deb(jmp[i-1][x]); deb(dep[jmp[i-1][x]]);
                }
            deb(ans);
            if (a[x] & a[Fa[x]])
                return ans;
            return -1;
        } std :: cout << "ans = " << ans << endl;
        for (int i = 20; i >= 0; i--)
            if (jmp[i][x] != -1 && dep[jmp[i][x]] > dep[L])
            {
                ans += 1 << i;
                x = jmp[i][x];
            }
        for (int i = 20; i >= 0; i--)
            if (jmp[i][y] != -1 && dep[jmp[i][y]] > dep[L])
            {
                ans += 1 << i;
                y = jmp[i][y];
            }
        if (jmp[0][x] == -1 || jmp[0][y] == -1)
            return -1;
        if (dep[jmp[0][x]] > dep[L] || dep[jmp[0][y]] > dep[L])
            return -1;
        bool flag = false;
        for (int i = 0; i < 60; i++)
            if (col[i][x] != -1 && col[i][y] != -1)
            {
                if (dep[col[i][x]] <= dep[L] && dep[col[i][y]] <= dep[L])
                    flag = true;
            }
        if (flag)
            return ans;
        else
            return ans + 1;
    };
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << solve(x, y) << "\n";
    }
    return 0;
}