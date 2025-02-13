#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    map<ll, int> mp;
    ll s = 0;
    mp[0] = 1;
    ll ans = 0;
    for (auto x: a) {
        s += x;
        if (mp.find(s - k) != mp.end()) {
            ans += mp.at(s - k);
        }
        mp[s]++;
    }

    cout << ans << '\n';

    return 0;
}
