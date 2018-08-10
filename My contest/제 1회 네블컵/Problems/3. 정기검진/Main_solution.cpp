#include <cstdio>
#include <memory.h>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>
#define sz(x) (int)(x).size()
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
vector<pli> v[20101];
ll dist[100][20101];
priority_queue<pli, vector<pli>, greater<pli> > pq;

int main() {
	int n, m, b, k, q, a, bb;
	ll c, mv;
	pli tv;
	scanf("%d %d %d %d %d", &n, &m, &b, &k, &q);

	for (int i = 0; i < b; i++)
		for (int j = 0; j < n + m + b; j++)
			dist[i][j] = 1e18;

	while (k--) {
		scanf("%d %d %lld", &a, &bb, &c);
		a--, bb--;
		v[a].push_back({ c, bb });
		v[bb].push_back({ c, a });
	}

	for (int k = n + m; k < n + m + b; k++) {
		pq.push({ 0, k });

		while (!pq.empty()) {
			tv = pq.top();
			pq.pop();

			if (dist[k - n - m][tv.second] < 1e17 && dist[k - n - m][tv.second] != tv.first) continue;

			for (int i = 0; i < sz(v[tv.second]); i++)
				if (dist[k - n - m][v[tv.second][i].second] > tv.first + v[tv.second][i].first) {
					dist[k - n - m][v[tv.second][i].second] = tv.first + v[tv.second][i].first;
					pq.push({ tv.first + v[tv.second][i].first, v[tv.second][i].second });
				}
		}
	}

	while (q--) {
		scanf("%d %d", &a, &bb);
		a--, bb--;
		mv = 1e18;
		for (int k = n + m; k < n + m + b; k++)
			mv = min(mv, dist[k - n - m][a] + dist[k - n - m][bb]);
		if (mv >= 1e17) printf("-1\n");
		else printf("%lld\n", mv);
	}
}