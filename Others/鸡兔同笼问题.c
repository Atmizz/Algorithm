#include <stdio.h>
int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i ++)
    if(i * 2 + (n - i) * 4 == m)
      printf("鸡的数量：%d 兔的数量：%d", i, n - i);
}