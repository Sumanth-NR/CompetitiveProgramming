#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<array<int, 2>> a(n);
    for (auto &[x, y] : a) {
        cin >> x >> y;
    }

    for (int i = 0; i < n; ++i) {
        bool ok = true;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1]) > k) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << 1;
            return;
        }
    }

    cout << -1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
