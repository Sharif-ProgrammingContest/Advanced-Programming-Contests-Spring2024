#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX_N = 1e6 + 14, BASE = 777, MOD = 1e9 + 7;

string s, p;
int h[MAX_N], po[MAX_N];

// h[i] = hash of s[:i]

/// @return hash of s[l:r]
int get(int l, int r) {
	return (h[r] - (ll) h[l] * po[r - l] % MOD + MOD) % MOD;
	// h[r] = s[r - 1] * base ^ 0 + s[r - 2] * base ^ 1 + ... + s[l] * base ^ (r - l + 1) + s[l - 1] * base ^ (r - l) + s[l - 2] * base ^ (r - l - 1) + ...
	// h[l] = s[l - 1] * base ^ 0 + s[l - 2] * base ^ 1 + s[l - 3] * base ^ 2 + s[l - 4] * base ^ 3 + ...
	// h[l] * po[r - l] = s[l - 1] * base ^ (r - l) + s[l - 2] * base ^ (r - l + 1) + s[l - 3] * base ^ (r - l + 2) + s[l - 4] * base ^ (r - l + 3) + ...
	// => h[r] - h[l] * po[r - l] = s[r - 1] * base ^ 0 + s[r - 2] * base ^ 1 + ... + s[l] * base ^ (r - l + 1)
}

int main() {
	cin >> s;
	po[0] = 1;
	for (int i = 0; i < s.size(); ++i)
		po[i + 1] = (ll) po[i] * BASE % MOD;
	for (int i = 0; i < s.size(); ++i)
		h[i + 1] = ((ll) h[i] * BASE + s[i]) % MOD;
	cin >> p;
	int hash_p = 0;
	for (auto c: p)
		hash_p = (hash_p * BASE + c) % MOD;
	int ans = 0;
	for (int i = 0; i <= s.size() - p.size(); ++i)
		ans += get(i, i + p.size()) == hash_p;
	cout << ans << '\n';
}
