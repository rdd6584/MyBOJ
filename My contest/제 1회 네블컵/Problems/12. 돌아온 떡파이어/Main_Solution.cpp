#include <cstdio>
#define ff 97
#define ss 1031
typedef long long ll;

int lucas(int n, int k, int fac[], int inv[], int p) {
	int t1, t2, sum = 1;

	while (n || k) {
		t1 = n % p; t2 = k % p;
		if (t1 < t2) return 0;
		sum = sum * ((fac[t1] * inv[t2] % p) * inv[t1 - t2] % p) % p;
		n /= p, k /= p;
	}

	return sum;
}

int uclid(int r1, int r2) {
	int r, t, s, q, p = r1;
	int s1 = 1, s2 = 0;
	int t1 = 0, t2 = 1;

	while (r2) {
		q = r1 / r2;
		r = r1 - q * r2;
		r1 = r2; r2 = r;

		s = s1 - q * s2;
		s1 = s2; s2 = s;

		t = t1 - q * t2;
		t1 = t2; t2 = t;
	}

	if (t1 < 0) t1 += p;
	return t1;
}

void init(int fac[], int inv[], int p) {
	for (ll i = 1; i < p; i++)
		fac[i] = fac[i - 1] * i % p;

	inv[p - 1] = uclid(p, fac[p - 1]);
	for (ll i = p - 1; i >= 1; i--)
		inv[i - 1] = inv[i] * i % p;
}

int china(int a, int b, int ap, int bp, int MOD) {
	int sum = 0, t1 = MOD / ap, t2 = MOD / bp;

	sum = (sum + (ll)t1 * uclid(ap, t1 % ap) % MOD * a % MOD) % MOD;
	sum = (sum + (ll)t2 * uclid(bp, t2 % bp) % MOD * b % MOD) % MOD;

	return sum;
}

int main() {
	int t, n, k, a1, a2;
	scanf("%d", &t);

	int fac1[ff] = { 1 }, fac2[ss] = { 1 };
	int inv1[ff], inv2[ss];

	init(fac1, inv1, ff);
	init(fac2, inv2, ss);

	while (t--) {
		scanf("%d %d", &n, &k);

		if (n == 0 && k == 1) { printf("1\n"); continue; }
		n--; k -= 2;
		if (k == -1) { printf("0\n"); continue; }

		a1 = lucas(n, k, fac1, inv1, ff);
		a2 = lucas(n, k, fac2, inv2, ss);

		printf("%d\n", china(a1, a2, ff, ss, ff * ss));
	}
}