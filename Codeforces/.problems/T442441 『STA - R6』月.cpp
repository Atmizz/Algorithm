#include <bits/stdc++.h>
using namespace std;
#define maxn 1000000
int a[maxn];
int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--) {
		int n;cin>>n;
		multiset<pair<int,int> >st;
		multiset<pair<int,int> >st2;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
			st.insert({a[i],i});
		}
		vector<pair<int,int> >ans;
		pair<int,int>kkk={0,0};
		while(!st.empty()) {
			if(kkk.first==0) {
				if(st2.size()==0) {
					auto num=*st.rbegin();
					st.erase(st.find(num));
					kkk=num;
				}
				else {
					auto num=*st2.rbegin();
					st2.erase(st2.find(num));
					kkk=num;
				}
			}
			auto num2=*st.rbegin();
			st.erase(st.find(num2));
			ans.push_back({kkk.second,num2.second});
			kkk.first--;
			num2.first--;
			if(num2.first!=0) {
				st2.insert(num2);
			}
		}
		for(auto [a,b]:ans) {
			cout<<a<<" "<<b<<endl;
		}
	}
	return 0;
}
