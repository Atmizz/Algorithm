#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
#define ll long long
inline int read() {
  int s = 0, f = 1; char ch = gc;
  for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
  for(; ch >= '0' && ch <= '9'; ch = gc)
    s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * f;
}
inline int abs(int a) {return a < 0 ? -a : a;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 1e6+200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, a[MaxN];
struct SegmentTree {
  struct Node {
    int l, r, Max_, Max_l, Max_r, sum;
    Node() {Max_ = Max_l = Max_r = sum = 0;}
  }t[MaxN << 1];
  void Push_Up(int k) {
    t[k].Max_l = max(t[ls].Max_l, t[ls].sum + t[rs].Max_l);
    t[k].Max_r = max(t[rs].Max_r, t[ls].Max_r + t[rs].sum);
    t[k].Max_ = max(max(t[ls].Max_, t[rs].Max_), t[ls].Max_r + t[rs].Max_l);
    t[k].sum = t[ls].sum + t[rs].sum;
  }
  void Build_A_Nice_SegmentTree(int l, int r, int k) {
    t[k].l = l; t[k].r = r;
    if(l == r) {
      t[k].Max_ = t[k].Max_l = t[k].Max_r = t[k].sum =a[l];
      return ;
    }
    int mid = (l + r) >> 1;
    Build_A_Nice_SegmentTree(l, mid, ls);
    Build_A_Nice_SegmentTree(mid+1, r, rs);
    Push_Up(k);
  }
  Node Query(int l, int r, int k) {
    if(l <= t[k].l && t[k].r <= r) return t[k];
    int mid = (t[k].l + t[k].r) >> 1, opt = 0;
    Node ans_L, ans_R, ans;
    if(l <= mid) opt += 1, ans_L = Query(l, r, ls);
    if(r > mid) opt += 2, ans_R = Query(l, r, rs);
    if(opt == 1) return ans_L;
    else if(opt == 2) return ans_R;
    ans.Max_l = max(ans_L.Max_l, ans_R.Max_l + ans_L.sum);
    ans.Max_r = max(ans_R.Max_r, ans_R.sum + ans_L.Max_r);
    ans.Max_ = max(max(ans_L.Max_, ans_R.Max_), ans_L.Max_r + ans_R.Max_l);
    ans.sum = ans_L.sum + ans_R.sum;
    return ans;
  }
  void Modify(int l, int r, int z, int k) {
    if(t[k].l == t[k].r) {
      t[k].Max_ = t[k].Max_l = t[k].Max_r = t[k].sum = z;
      return ;
    }
    int mid = (t[k].l + t[k].r) >> 1;
    if(l <= mid) Modify(l, r, z, ls);
    if(r > mid) Modify(l, r, z, rs);
    Push_Up(k);
  }
}T;     
int main() {
//  freopen("P4513_2.in", "r", stdin); freopen("ans.out", "w", stdout);
  n = read(); m = read();  
  for(int i = 1; i <= n; ++ i) a[i] = read();
  T.Build_A_Nice_SegmentTree(1, n, 1);
  for(int i = 1; i <= m; ++ i) {
    int opt = read(), l = read(), r = read();
    if(opt == 1) {
      if(l > r) std :: swap(l, r);
      printf("%d\n", T.Query(l, r, 1).Max_);
    }
    else T.Modify(l, l, r, 1);
  }
  return 0;
}