#include <bits/stdc++.h>
using namespace std;
char a[1010][1010];
int main() {
	cin.sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	int maxx=-1;int maxx2=-1;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(a[i][j]=='#') continue;
			if(a[i][j]-'0'>maxx) {
				maxx2=-1;
			}
			maxx=max(maxx,a[i][j]-'0');
			if(maxx==a[i][j]-'0') {
				if(a[i-1][j]!='#'&&i-1>=1)
					maxx2=max(maxx2,a[i-1][j]-'0');
				if(a[i+1][j]!='#'&&i+1<=n)
					maxx2=max(maxx2,a[i+1][j]-'0');
				if(a[i][j-1]!='#'&&j-1>=0)
					maxx2=max(maxx2,a[i][j-1]-'0');
				if(a[i][j+1]!='#'&&j+1<=m)
					maxx2=max(maxx2,a[i][j+1]-'0');
			}
		}
	}
//	cout<<maxx<<" "<<maxx2<<endl;
	if(maxx==maxx2||maxx2==-1) {
		cout<<char(maxx+'0')<<'\n';
	}
	else {
		cout<<char(maxx+'0')<<char(maxx2+'0')<<'\n';
	}
	return 0;
}
