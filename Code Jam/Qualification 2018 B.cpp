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
vector<int> even, odd, v; queue<int> q; deque<int> dq;

int main() {
	int tt, n, temp, flag;
	int a, b;
	scanf("%d", &tt);

	for (int t = 1; t <= tt; t++) {
		scanf("%d", &n);
		a = 0, b = 0, flag = 0;
		even.clear(), odd.clear(), v.clear();

		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			if (i % 2 == 0) even.push_back(temp);
			else odd.push_back(temp);
		}
		sort(all(even));
		sort(all(odd));
		printf("Case #%d: ", t);

		while (a + b < n) {
			v.push_back(even[a++]);
			if (a + b < n)
				v.push_back(odd[b++]);
		}

		for (int i = 1; i < sz(v); i++)
			if (v[i] < v[i - 1]) {
				flag = i;
				break;
			}
		if (flag) printf("%d\n", flag - 1);
		else printf("OK\n");
	}
}