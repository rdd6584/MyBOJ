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
vector<int> vec, vec2; queue<int> q; deque<int> dq;

char mat[101][101];
int hsum[101], vsum[101];

int main() {
	int tt, n, h, v, r, c, tsum = 0, ttt, tttt = 0, flag, ff = 0;
	scanf("%d", &tt);

	for (int t = 1; t <= tt; t++) {
		tttt = 0, tsum = 0, flag = 1, ff = 0;
		memset(hsum, 0, sizeof(hsum));
		memset(vsum, 0, sizeof(vsum));
		vec.clear();
		vec2.clear();
		scanf("%d %d %d %d", &r, &c, &h, &v);
		for (int i = 0; i < r; i++)
			scanf("%s", mat[i]);

		for(int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				if (mat[i][j] == '@') {
					hsum[i]++;
					vsum[j]++;
					tsum++;
				}
		printf("Case #%d: ", t);
		if (tsum % (h + 1) || tsum % (v + 1)) { printf("IMPOSSIBLE\n"); continue; }
		
		ttt = tsum / (h + 1);

		vec.push_back(-1);
		vec2.push_back(-1);

		for (int i = 0; i < r; i++) {
			tttt += hsum[i];
			if (tttt == ttt) { tttt = 0; vec.push_back(i); }
			else if (tttt > ttt) { flag = 0; break; }
		}

		ttt = tsum / (v + 1);
		tsum = 0;
		for (int i = 0; i < c; i++) {
			tttt += vsum[i];
			if (tttt == ttt) { tttt = 0; vec2.push_back(i); }
			else if (tttt > ttt) { flag = 0; break; }
		}

		for (int i = 1; i < sz(vec); i++) {
			for (int j = 1; j < sz(vec2); j++) {
				tsum = 0;
				for(int x = vec[i - 1] + 1; x <= vec[i]; x++)
					for (int y = vec2[j - 1] + 1; y <= vec2[j]; y++) {
						if (mat[x][y] == '@') tsum++;
					}
				if (!ff) ff = tsum;
				else {
					if (ff != tsum) flag = 0;
				}
			}
		}

		if (flag) printf("POSSIBLE\n");
		else printf("IMPOSSIBLE\n");
	}
}