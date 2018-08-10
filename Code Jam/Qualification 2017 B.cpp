#include <cstdio>
#include <memory.h>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#define MAX(a, b) (a) > (b) ? (a) : (b)
#define MIN(a, b) (a) < (b) ? (a) : (b)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
	FILE *fp1 = fopen("input.in", "r");
	FILE *fp2 = fopen("output.txt", "w");

	int tt, len;
	fscanf(fp1, "%d", &tt);

	char s[21];

	for (int t = 1; t <= tt; t++) {
		fscanf(fp1, "%s", s);
		len = strlen(s);

		for (int i = 0; i < len - 1; i++)
			if (s[i] > s[i + 1]) {
				s[i]--;
				for (int j = i + 1; j < len; j++)
					s[j] = '9';

				i = -1;
			}
			
			if(s[0] == '0') fprintf(fp2, "Case #%d: %s\n", t, s + 1);
			else fprintf(fp2, "Case #%d: %s\n", t, s);
	}

	fclose(fp1);
	fclose(fp2);
}