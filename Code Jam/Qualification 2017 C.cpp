#include <cstdio>
#include <memory.h>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>
#define MAX(a, b) (a) > (b) ? (a) : (b)
#define MIN(a, b) (a) < (b) ? (a) : (b)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

deque <pll> q;

int main() {
	int tt;
	ll n, k;
	pll v;
	scanf("%d", &tt);

	for (int t = 1; t <= tt; t++) {
		scanf("%lld %lld", &n, &k);
		q.clear();
		
		q.push_back({n, 1});

		while (1) {
			v = q.front();
			q.pop_front();

			k -= v.second;
			if (k <= 0) {
				printf("Case #%d: ", t);
				if (v.first % 2) printf("%lld %lld\n", v.first / 2, v.first / 2);
				else printf("%lld %lld\n", v.first / 2, (v.first - 1) / 2);
				break;
			}

			if (v.first % 2) {
				if (!q.empty() && (*(q.end() - 1)).first == v.first / 2)
					(*(q.end() - 1)).second += v.second * 2;
				else q.push_back({ v.first / 2, v.second * 2 });
			}
			else {
				if (!q.empty() && (*(q.end() - 1)).first == v.first / 2)
					(*(q.end() - 1)).second += v.second;
				else q.push_back({ v.first / 2, v.second});
				q.push_back({ (v.first - 1) / 2, v.second });
			}
		}


	}
}