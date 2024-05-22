#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl '\n'
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 40;
int n, m;
std :: string str[N];
char joker;
// c d h s
bool cmp(std :: string a, std :: string b) {
  return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
}
void solve() {
  std :: cin >> n;
  m = n * 2;
  std :: cin >> joker;
  for(int i = 1; i <= m; ++ i) {
    std :: cin >> str[i];
  }
  std :: sort(str + 1, str + 1 + m, cmp);
  for(int i = 2; i <= m; ++ i) {
    if(str[i] == str[i-1]) {
      std :: cout << "IMPOSSIBLE\n";
      return ;
    }
  }
  std :: map <char, int> cnt;
  for(int i = 1; i <= m; ++ i) {
    cnt[str[i][1]] ++;
  }
  if((cnt['S'] & 1) + (cnt['C'] & 1) + (cnt['H'] & 1) + (cnt['D'] & 1) - (cnt[joker] & 1) > cnt[joker]) {
    std :: cout << "IMPOSSIBLE\n";
    return ;
  }
  std :: string waiter[60];
  int c = 0;
  for(int i = 1; i <= m; ++ i) {
    if(str[i][1] == joker) {
      waiter[c++] = str[i];
    }
  }
  int pos = 0;
  str[m+1] = "D0";
  for(int i = 1; i <= m; i ++) {
    if(str[i][1] == joker) continue;
    if(str[i][1] == str[i+1][1]) {
      std :: cout << str[i] << ' ' << str[i+1] << '\n';
      i ++;
    } else {
      std :: cout << str[i] << ' ' << waiter[pos++] << '\n';
    }
  }
  // deb(c);
  for(int i = pos; i < c; i += 2) {
    // deb(i);
    std :: cout << waiter[i] << ' ' << waiter[i+1] << '\n';
  }
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