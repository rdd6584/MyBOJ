#include <cstdio>

int main() {
	FILE *fp1 = fopen("output.txt", "r");
	FILE *fp2 = fopen("output2.txt", "r");
	FILE *fp3 = fopen("result.txt", "w");

	int a1, a2;
	while (1) {
		if (fscanf(fp1, "%d", &a1) == EOF) break;
		if (fscanf(fp2, "%d", &a2) == EOF) break;

		if (a1 != a2) fprintf(fp3, "NO\n");
	}
	fprintf(fp3, "HELLO");

	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}