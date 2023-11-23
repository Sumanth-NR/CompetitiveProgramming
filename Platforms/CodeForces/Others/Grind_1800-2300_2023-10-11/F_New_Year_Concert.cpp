#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
class SparseTable {
public:
    using Merger = std::function<T(const T&, const T&)>;

    // A few examples of merge functions can be passed to the constructor
    static T min (const T &a, const T &b) { return std::min(a, b); }
    static T max (const T &a, const T &b) { return std::max(a, b); }
    static T gcd (const T &a, const T &b) { return std::gcd(a, b); }
    static T lcm (const T &a, const T &b) { return std::lcm(a, b); }
    static T bitAnd (const T &a, const T &b) { return a & b; }
    static T bitOr (const T &a, const T &b) { return a | b; }

private:
    int K;
    std::vector<std::vector<T>> st;
    Merger merge;

    T query(int l, int r, int k) {
        return merge(st[k][l], st[k][r - (1 << k) + 1]);
    }

public:
    SparseTable() = default;
    SparseTable(const SparseTable<T> &st) = default;
    template<class V>
    SparseTable(const std::vector<V> &a, Merger merge) { build(a, merge); }

    template<class V>
    void build(const std::vector<V> &a, Merger _merge) {
        merge = _merge;
        K = std::__lg(a.size());

        st.resize(K + 1);
        std::size_t n = a.size();
        st[0].resize(n);
        std::copy(a.begin(), a.end(), st[0].begin());

        for (int i = 1; i <= K; i++) {
            st[i].resize(n - (1 << i) + 1);
            for (int j = 0; j < static_cast<int>(n - (1 << i) + 1); j++) {
                st[i][j] = merge(
                    st[i - 1][j],
                    st[i - 1][j + (1 << (i - 1))]
                );
            }
        }
    }

    const std::vector<std::vector<T>>& operator () () const {
        return st;
    }

    T query(int l, int r) {
        if (l > r) {
            throw std::invalid_argument("l must be <= r");
        } else {
            int k = std::log2(r - l + 1);
            return merge(st[k][l], st[k][r - (1 << k) + 1]);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;

    SparseTable<int> st(a, SparseTable<int>::gcd);

    vector<bool> del(n + 1);
    for (int i = 0, j = 0; i < n; ) {
        // Notice that gcd[i, j] >= gcd[i, j+1] >= ... is a decreasing function
        // j is the maximum index s.t. gcd(a[i], ... a[j]) >= r - l + 1
        j = max(j, i);
        while (j+1 < n and st.query(i, j+1) >= j+1 - i + 1) {
            ++j;
        }
        if (st.query(i, j) == j - i + 1) {
            del[j] = true;
            i = ++j;
        } else {
            ++i;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (del[i]) ++ans;
        cout << ans << " \n"[i == n-1];
    }

    return 0;
}
