#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX_N = 1e6 + 14;

string s;
int f[MAX_N];
// f[i] = largest j where s[:j] = s[i - j:j]

int main() {
	cin >> s;
	f[0] = 0;
	f[1] = 0;
	for (int i = 2; i <= s.size(); ++i) {
		int cur_match = f[i - 1];
		while (s[cur_match] != s[i] && cur_match)
			cur_match = f[cur_match];
		if (s[cur_match] == s[i])
			f[i] = cur_match + 1;
		else
			f[i] = 0;
	}
}
