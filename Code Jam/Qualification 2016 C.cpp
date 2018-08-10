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
int n, jj;
int mod[9] = { 3, 2, 3, 2, 7, 2, 3, 2, 11 };
char bin[33];

FILE *fp1, *fp2;

int to_base() {
	ll ret, r;
	int chk[9] = { 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	ll m[5] = { 2, 3, 5, 7, 11 }, flag;

	for (int i = 0; i < 9; i++) {
		ret = 0, r = 1, flag = 0;

		for (int k = 0; k < 5; k++) {
			ret = 0, r = chk[i];
			for (int j = 0; j < n; j++) {
				ret *= r;
				ret += bin[j];
				ret %= m[k];
			}

			if (!ret) {
				flag = 1, mod[r - 2] = m[k];
			}
		}

		if (!flag) return 0;
	}

	return 1;
}

void next2() {
	for (int b = 4; b < n - 1 && jj; b += 4) {
		bin[b] = 1;
		for (int a = 3; a < n - 1 && jj; a += 4) {
			bin[a] = 1;
			for (int i = 1; i < n - 1 && jj; i += 4) {
				bin[i] = 1;
				for (int j = 2; j < n - 1 && jj; j += 4) {
					bin[j] = 1;
					if (to_base()) {
						for (int k = 0; k < n; k++)
							fprintf(fp2, "%d", bin[k]);
						for (int k = 0; k < 9; k++)
							fprintf(fp2, " %d", mod[k]);
						fprintf(fp2, "\n");
						jj--;
					}

					bin[j] = 0;
				}
				bin[i] = 0;
			}
			bin[a] = 0;
		}
		bin[b] = 0;
	}
}

void next() {
	for (int i = 1; i < n - 1 && jj; i += 2) {
		bin[i] = 1;
		for (int j = 2; j < n - 1 && jj; j += 2) {
			bin[j] = 1;
			if (to_base()) {
				for (int k = 0; k < n; k++)
					fprintf(fp2, "%d", bin[k]);
				for (int k = 0; k < 9; k++)
					fprintf(fp2, " %d", mod[k]);
				fprintf(fp2, "\n");
				jj--;
			}

			bin[j] = 0;
		}
		bin[i] = 0;
	}

	next2();
}

int main() {
	fp1 = fopen("input.in", "r");
	fp2 = fopen("output.txt", "w");

	int tt;
	fscanf(fp1, "%d", &tt);

	for (int t = 1; t <= tt; t++) {
		fscanf(fp1, "%d %d", &n, &jj);
		bin[0] = bin[n - 1] = 1;
		bin[n] = '\0';

		fprintf(fp2, "Case #%d:\n", t);
		next();
		printf("%d", jj);
	}

	fclose(fp1);
	fclose(fp2);
}