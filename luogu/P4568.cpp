#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > a[10020];
int n, m, l, r, t;
int d[10020];
int f[10020];
set<pair<int, int> > s;
void dijk() {
	for (int i = 0; i < n; i++) {
		s.insert(make_pair(d[i], i));
	}
	while (s.size()) {
		int u = s.begin()->second;
		s.erase(s.begin());
		for (pair<int, int> i: a[u]) {
			if (d[i.first] > d[u] + i.second) {
				s.erase(make_pair(d[i.first], i.first));
				d[i.first] = d[u] + i.second;
				s.insert(make_pair(d[i.first], i.first));
			}
		}
	}
}
int main() {
	scanf("%d%d%d%d%d", &n, &m, &l, &r, &t);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	memset(d, 0x3f, sizeof d);
	d[r] = 0;
	dijk();
	for (int k = 0; k < l; k++) {
		memcpy(f, d, sizeof f);
		for (int i = 0; i < n; i++) {
			for (pair<int, int> j: a[i]) {
				d[j.first] = min(d[j.first], f[i]);
			}
		}
		dijk();
	}
	printf("%d\n", d[t]);
	return 0;
}