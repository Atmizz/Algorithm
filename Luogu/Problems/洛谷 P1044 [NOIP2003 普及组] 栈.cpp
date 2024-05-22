#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,f[10001];
int main()
{
	f[0]=1;
	f[1]=1;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
		for(int j=0;j<i;j++)
			f[i]+=f[j]*f[i-1-j];
			//f[i]=f[i-1]*(4*i-2)/(i+1);
	printf("%d",f[n]);
	return 0;
}