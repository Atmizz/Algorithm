#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string s1,s2;
void f(int l1,int r1,int l2,int r2)
{
	int m=s1.find(s2[r2]);
	cout<<s2[r2];
	if(m>l1) f(l1,m-1,l2,l2+(m-1-l1+1)-1);
	if(m<r1) f(m+1,r1,l2+(m-1-l1+1)-1+1,r2-1);
}
int main()
{
	cin>>s1>>s2;
	f(0,s1.length()-1,0,s2.length()-1);
	return 0;
}