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
const int MaxN = 1e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m;
bool vis[MaxN];
struct Node {
  int id;
  Node *left, *right;
}a[MaxN];
int main() {
  n = read(); Node *now = a + 1;
  for(int i = 1; i <= n; ++ i) vis[i] = 1, a[i].id = i, a[i].right = a[i].left = NULL;
  for(int i = 2; i <= n; ++ i) {
    int k = read(), p = read();
    if(p == 0) {
      if(a[k].left == NULL) {
        a[i].right = a + k; a[k].left = a + i;
        if(now->id == k) now = a + i;
      }
      else {
        a[i].left = a[k].left, a[k].left->right = a + i;
        a[i].right = a + k, a[k].left = a + i;
      }// std :: cout << i << " " << a[i].right->id << '\n';
    }else {
      if(a[k].right == NULL) {
        a[i].left = a + k; a[k].right = a + i;
      }
      else {
        a[i].right = a[k].right, a[k].right->left = a + i;
        a[i].left = a + k; a[k].right = a + i;
      }
    }
  }
  // for(int i = 1; i <= n; ++ i, puts("")) {  
  //   printf("id : %d ", a[i].id);
  //   if(a[i].left != NULL)
  //     printf("L : %d ", a[i].left->id);
  //   if(a[i].right != NULL)
  //     printf("R : %d", a[i].right->id);
  // }
  m = read();
  for(int i = 1; i <= m; ++ i) {
    int x = read();
    if(!vis[x]) continue;
    if(a[x].left == NULL && a[x].right == NULL) continue;
    vis[x] = 0;
    Node *resRight = a[x].right, *resLeft = a[x].left;
    if(a[x].left != NULL && a[x].right != NULL)
      resRight->left = resLeft, resLeft->right = resRight;
    else if(a[x].left != NULL && a[x].right == NULL)
      resLeft->right = NULL;
    else resRight->left = NULL;
  }
  while(now != NULL) printf("%d ", now->id), now = now->right;
  // printf("%d", now->id);
  return 0;
}
/*
2 3 4 1
*/