/// kuding testcase(.out) maker
/// Author : ky15534
/// Date : 2018-04-06
/// ���� : ���� �ȿ� .in ���ϵ� �ְ� ���� �ڵ� ���� �����Ͻø� �˴ϴ�.
/// ���� �������
#include <io.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

/*------------------------------------------------------------------------------*/
// ���� �ڵ�
#include <cstdio>
#include <memory.h>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <cmath>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
const ll MOD = 1e9 + 7;

priority_queue<int> pq;
vector<int> v; queue<int> q; deque<int> dq;

int _main() {
	int n, t, p, tt, c = 0, miv = 0, cc = 0;
	scanf("%d %d %d", &n, &t, &p);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tt);
		sum += tt;
		c++;
		pq.push(tt);

		while (sum > t - (ll)p * i && c) {
			if (t - (ll)p * i < 0) { sum = c = 0; break; }
			c--;
			sum -= pq.top();
			pq.pop();
		}

		miv = max(miv, c);
	}
	printf("%d", miv);

	return 0;
}

/*------------------------------------------------------------------------------*/

/// �������� �ʱ�ȭ�� �ʿ��� �� ���
void _____() {
	while (!pq.empty()) pq.pop();
}

/// ���ι� �ǵ��� ������
int main() {
	_finddata_t c_file;
	intptr_t hFile;
	char f_name[FILENAME_MAX] = "";
	char f_in[FILENAME_MAX] = "";
	char f_out[FILENAME_MAX] = "";
	assert(~(hFile = _findfirst("*.in", &c_file)));
	do {
		sscanf(c_file.name, "%[^(.in)]", f_name);
		strcpy(f_in, f_name);
		strcpy(f_out, f_name);
		freopen(strcat(f_in, ".in"), "r", stdin);
		freopen(strcat(f_out, ".out"), "w", stdout);
		_____();
		_main();
	} while (_findnext(hFile, &c_file) == 0);
	_findclose(hFile);
	return 0;
}