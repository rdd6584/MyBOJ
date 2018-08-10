#include <cstdio>
#include <vector>
#define MM 2000001
using namespace std;
typedef long long ll;

vector <int> v;
char sieve[MM];

bool isPrime(ll a){
	for(int i = 0; i < (int)v.size() && (ll)v[i] * v[i] <= a; i++)
		if(a % v[i] == 0) return 0;
	return 1;
}

int main() {
	int t;
	scanf("%d", &t);
	
	sieve[1] = 1;
	for(int i = 2; i * i < MM; i++) {
		if (!sieve[i])
			for(int j = i * i; j < MM; j += i)
				sieve[j]++;
	}
	for(int i = 2; i < MM; i++)
		if(!sieve[i]) v.push_back(i);
	
	ll a, b;
	while (t--) {
		scanf("%lld %lld", &a, &b);

		a += b;
		if (a < 4) { printf("NO\n"); continue; }
		if (a % 2 == 0) { printf("YES\n"); continue; }
		a -= 2;

		if (isPrime(a)) printf("YES\n");
		else printf("NO\n");
	}
}