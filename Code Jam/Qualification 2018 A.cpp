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

char s[32];

int main() {
	int tt, n, d, sum, p, c;
	scanf("%d", &tt);

	for (int t = 1; t <= tt; t++) {
		scanf("%d", &d);
		scanf("%s", s);
		n = strlen(s);
		c = 0, sum = 0, p = 1;
		
		for(int i =  0; i < n; i++){
			if(s[i] == 'S') {sum += p; c++;}
			else p <<= 1;
		}
		printf("Case #%d: ", t);
		if(c > d) { printf("IMPOSSIBLE\n"); continue; }
		c = 0;
		
		for(int i = n - 2; i >= 0 && d < sum; i--) {
			if(s[i] == 'C' && s[i + 1] == 'S') {
				swap(s[i], s[i + 1]);
				c++;
				i += 2;
			}
			
			sum = 0, p = 1;
			for(int i =  0; i < n; i++){
				if(s[i] == 'S') sum += p;
				else p <<= 1;
			}
		}
		
		printf("%d\n", c);
	}
}