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

priority_queue<int, vector<int>, greater<int> > pq;
vector<int> v; queue<int> q; deque<int> dq;

ll vec[1000][3];
ll roro[5];
char visit[5];
int ro, b, c;

ll go2(int cc, int tnfid, ll tlrks) {
	if (cc == c) {
		if (tnfid) return 1e18;
		else return tlrks;
	}

	ll mv = 1e18;
	for (int i = 0; i < ro; i++) {
		if (!visit[i]) {
			visit[i]++;
			mv = min(mv, go2(cc + 1, tnfid - min(roro[i], vec[cc][0]), max(tlrks, min(roro[i], vec[cc][0]) * vec[cc][1] + vec[cc][2])));
			visit[i]--;
		}
	}

	mv = min(mv, go2(cc + 1, tnfid, tlrks));
	return mv;
}

ll go(int o, int bits, int pre) {
	if (o == ro) {
		if (bits) return 1e18;
		else return go2(0, b, 0);
	}

	ll mv = 1e18;
	for (int i = pre; i <= bits; i++) {
		roro[o] = i;
		mv = min(mv, go(o + 1, bits - i, i));
	}

	return mv;
}

int main() {
	int tt;
	scanf("%d", &tt);

	for (int t = 1; t <= tt; t++) {
		printf("Case #%d: ", t);
		scanf("%d %d %d", &ro, &b, &c);

		for (int i = 0; i < c; i++)
			scanf("%lld %lld %lld", &vec[i][0], &vec[i][1], &vec[i][2]);

		printf("%lld\n", go(0, b, 0));
	}
}