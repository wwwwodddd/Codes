#include <bits/stdc++.h>
using namespace std;
int n, m;
int c[100020];
void change(int x, int y) {
	for (int i = x; i <= n; i += i & -i) {
		c[i] += y;
	}
}
int query(int x) {
	int re = 0;
	for (int i = x; i > 0; i -= i & -i) {
		re += c[i];
	}
	return re;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		char o;
		int x, y;
		scanf(" %c%d%d", &o, &x, &y);
		if (o == 'x') {
			change(x, y);
		} else {
			printf("%d\n", query(y) - query(x - 1));
		}
	}
	return 0;
}