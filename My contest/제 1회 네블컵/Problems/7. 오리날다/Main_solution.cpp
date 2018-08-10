#include <cstdio>
#include <memory.h>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <cmath>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
const ll MOD = 1e9 + 7;

priority_queue<pli, vector<pli>, greater<pli> > pq;
vector<int> v; queue<int> q; deque<int> dq;

pii vec[100001];
char visit[100001];

int main() {
	int n, k, l, r, mid, goh, t;
	pli tv;
	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < n; i++)
		scanf("%d %d", &vec[i].first, &vec[i].second);
	sort(vec, vec + n);

	for (t = 0; t < n && !vec[t].first; t++);
	if (!t) { printf("Ducks can't fly"); return 0; }
	pq.push({0, t - 1});

	while (!pq.empty()) {
		tv = pq.top();
		pq.pop();

		if (tv.second == 123456) { printf("%lld", tv.first); return 0; }
		if (!visit[tv.second]) visit[tv.second]++;
		else continue;
		goh = vec[tv.second].first + vec[tv.second].second;
		if (goh >= k) { pq.push({ tv.first + k - vec[tv.second].first, 123456 }); continue; }

		l = tv.second, r = n - 1;
		while (l <= r) {
			mid = (l + r) / 2;
			if (goh >= vec[mid].first) l = mid + 1;
			else r = mid - 1;
		}

		if (r > tv.second && !visit[r]) pq.push({ tv.first + vec[tv.second].second + goh - vec[r].first, r});
		if (tv.second && !visit[tv.second - 1]) pq.push({tv.first + vec[tv.second].first - vec[tv.second - 1].first, tv.second - 1});
	}

	printf("Ducks can't fly");
}