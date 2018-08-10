#include <cstdio>
typedef long long ll;

int vec[1000000];

int main() {
	int n, tt, t = 0;
	ll ans = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &vec[i]);

	for (int i = 0; i < n; i++) {
		scanf("%d", &tt);
		vec[i] -= tt;

		if (vec[i] > 0) {
			if (t <= 0) ans += vec[i];
			else if (vec[i] > t) ans += (ll)vec[i] - t;
		}
		if (vec[i] < 0) {
			if (t >= 0) ans -= vec[i];
			else if (vec[i] < t) ans += (ll)t - vec[i];
		}
		t = vec[i];
	}

	printf("%lld", ans);
}