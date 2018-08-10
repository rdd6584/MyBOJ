#include <cstdio>
#include <cstring>
int main() {
	FILE *fp1 = fopen("input.in", "r");
	FILE *fp2 = fopen("output.txt", "w");

	int t, len, k, ans;
	char s[1001];
	fscanf(fp1, "%d", &t);

	for (int tt = 1; tt <= t; tt++) {
		fscanf(fp1, "%s %d", s, &k);
		len = strlen(s);
		ans = 0;
		for (int i = 0; i <= len - k; i++) {
			if (s[i] == '-') {
				for (int j = 0; j < k; j++)
					s[i + j] = s[i + j] == '-' ? '+' : '-';
				ans++;
			}
		}

		for (int i = len - k + 1; i < len; i++)
			if (s[i] == '-') ans = -1;

		if(ans == -1) fprintf(fp2, "Case #%d: IMPOSSIBLE\n", tt);
		else fprintf(fp2, "Case #%d: %d\n", tt, ans);
	}

	fclose(fp1);
	fclose(fp2);
}