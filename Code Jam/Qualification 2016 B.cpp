#include <cstdio>
#include <cstring>

char s[101];

int main() {
	int t, len, c;
	scanf("%d", &t);

	for (int tt = 1; tt <= t; tt++) {
		scanf("%s", s);
		len = strlen(s), c = 0;

		for (int i = 1; i < len; i++) {
			if (s[i] != s[i - 1]) {
				for (int j = 0; j < i; j++)
					s[j] = s[j] == '+' ? '-' : '+';
				c++;
			}
		}
		if (s[0] == '-') c++;

		printf("Case #%d: %d\n", tt, c);
	}
}