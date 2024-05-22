#include <stdio.h>
int main() {
  int n;
  double a[102], ave = 0;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++ i)
    scanf("%lf", &a[i]), ave += a[i];
  ave /= n;
  for(int i = 1; i <= n; ++ i)
    if(a[i] > ave) printf("%.0lf ", a[i]);
  return 0;
}