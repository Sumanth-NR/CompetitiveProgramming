#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (auto &[e, s]: a) {
        cin >> s >> e;
    }
    sort(a.begin(), a.end());

    int ans = 0, r = 0;
    for (auto [e, s]: a) {
        if (s >= r) {
            ans++;
            r = e;
        }
    }

    cout << ans;

    return 0;
}
