#include <iostream>
#include <cstdio>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
double t;
int n;
int main() {
	cin >> t >> n;
	printf("%.3lf\n%d", t / n, n * 2);
	return 0;
}