#include <cstdio>
typedef long long ll;

ll modulo(ll a, ll b, ll mod) {
	ll sum = 1;

	while (b) {
		if (b % 2) sum = sum * a % mod;
		a = a * a % mod;
		b /= 2;
	}

	return sum;
}

int main() {
	ll n;
	scanf("%lld", &n);
	if(n == 0) {printf("1"); return 0;}
	printf("%lld", modulo(2, n - 1, 1000000007));
}