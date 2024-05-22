#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
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
const int MaxN = 15;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int arr[MaxN], Index[MaxN], len;
std :: vector <int> ans;
std :: string str;
int main() {
  std :: cin >> str; len = str.length();
  for(int i = 0; i < len; ++ i) {
    int x = str[i] - 48;
    if(!arr[x]) arr[x] = 1, ans.push_back(x);
  }
  std :: sort(ans.begin(), ans.end());
  std :: reverse(ans.begin(), ans.end());
  for(int i = 0; i < ans.size(); ++ i)
    arr[ans[i]] = i;
  for(int i = 0; i < len; ++ i)
    Index[i] = arr[str[i]-48];
  printf("int[] arr = new int[]{");
  for(int i = 0; i < ans.size() - 1; ++ i) printf("%d,", ans[i]);
  if(!ans.size()) printf("%d};\n", ans[ans.size()-1]);
  else printf("%d};\n", ans[ans.size()-1]);
  printf("int[] index = new int[]{");
  for(int i = 0; i < len - 1; ++ i)
    printf("%d,", Index[i]);
  printf("%d};", Index[len-1]);
  return 0;
}