#include <cstdio>
#include <cstdlib>
#include <time.h>
typedef long long ll;

// (((ll)rand() << 16) | rand())
int main() {
	FILE *fp1 = fopen("tc8.in", "w");
	srand(time(NULL));
	int n = 100000, t = (((ll)rand() << 16) | rand()) % 100000001 + 900000000, p = (((ll)rand() << 16) | rand()) % 100000 + 1;
	fprintf(fp1, "%d %d %d\n", n, t, p);

	for (int i = 0; i < n; i++)
		fprintf(fp1, "%lld ", (((ll)rand() << 16) | rand()) % 100000 + 1);

	fclose(fp1);
}