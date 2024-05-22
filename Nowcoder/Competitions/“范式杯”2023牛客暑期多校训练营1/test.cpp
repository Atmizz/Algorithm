#include<bits/stdc++.h>
using namespace std;

long long a[1000001];
long long b[1000001];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long sum=0;
	long long maxn=-0x3f3f3f3f3f;
	long long minn=0x3f3f3f3f3f;
	int maxp,minp;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		long long diff=a[i]-b[i];
		sum+=abs(diff);
		if(maxn<diff){
			maxn=diff;
			maxp=i;
		}
		if(minn>diff){
			minn=diff;
			minp=i;
		}
	}
	long long ans=sum;
	sum-=abs(a[maxp]-b[maxp]);
	sum-=abs(a[minp]-b[minp]);
	sum+=abs(a[maxp]-b[minp]);
	sum+=abs(a[minp]-b[maxp]);
	cout<<min(ans,sum);
}
