#include <bits/stdc++.h>
using namespace std;

// Data Types
typedef long long int ll;
typedef long double ld;

// Constants
const int MOD = 1000000007;
const double PI = 3.1415926535;
const int INF = INT_MAX;
const ll LINF = LONG_MAX;
const char NL = '\n';

// Some misc Macros
#define pb push_back
#define prec fixed << setprecision
#define tempT template <class _T>
#define all(v) (v).begin(), (v).end()
#define F first
#define S second
#define Sort(v) sort(all(v))

// For loops
#define For(n) for(int i=0; i<n; i++)
#define ForRev(n) for (int i=n-1; i>=0; i--)
#define Trav(_iterable) for(auto &i: _iterable)
#define FOR(i, start, end) for(auto i=start; i<end; i++)
#define FORRev(i, start, end) for(auto i=end-1; i>=start; i--)
#define TRAV(i, _iterable) for(auto &i: _iterable)

// Data Structures
tempT struct V: vector<_T> {
    using vector<_T>::vector;
    void sort() { std::sort(all(*this)); }
    friend ostream& operator << (ostream &outFunc, const V<_T> &v)
    { Trav(v) outFunc << i << ' '; outFunc << ' '; return outFunc; }
    friend istream& operator >> (istream &inFunc, V<_T> &v)
    { Trav(v) inFunc >> i; return inFunc; }
};
template<class _T1, class _T2> struct P: pair<_T1, _T2> {
    using pair<_T1, _T2>::pair;
    friend ostream& operator << (ostream &outFunc, const P<_T1, _T2> &p)
    { outFunc << p.F << ' ' << p.S << ' '; return outFunc; }
    friend istream& operator >> (istream &inFunc, P<_T1, _T2> &p)
    { inFunc >> p.F >> p.S; return inFunc; }
};

#define M map
typedef V<int> vi;
typedef V<bool> vb;
typedef V<vi> vvi;
typedef P<int, int> pii;
typedef M<int, int> mii;
typedef V<long long int> vl;
typedef V<vl> vvl;


// Yes or No and return Macros
#define pY { cout << "YES"; return; }
#define pN { cout << "NO"; return; }

// Input Macros
#define Get(_T, x) _T x; cin >> x
#define GetV(_T, x, n) V<_T> x(n); cin >> x

// Debugging
bool debug = false;

/* ------------------------------------------------------------------------- */
// Some Functions

void _fast() { ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); }

tempT _T Min(int n, _T a[]) {_T mn = a[0];For(n) mn = min(mn, a[i]); return mn;}
tempT _T Max(int n, _T a[]) {_T mx = a[0];For(n) mx = max(mx, a[i]); return mx;}
tempT _T Min(V<_T> a) { _T mn = a[0]; Trav(a) mn = min(mn, i); return mn; }
tempT _T Max(V<_T> a) { _T mx = a[0]; Trav(a) mx = max(mx, i); return mx; }

tempT ll Sum(int n, _T a[]) { ll s = 0; For(n) s += a[i]; return s; }
tempT ll Sum(V<_T> a) { ll s = 0; Trav(a) s += i; return s; }

tempT M<_T, int> freq(V<_T> a) {M<_T, int> m; Trav(a) m[i]++; return m; }

/* ------------------------------------------------------------------------- */

// Global Variables
int D = 30;

// const int N = 1e5 + 3;
string giv30digit(int n) {
    string _ans; For(D) _ans += '0';
    for (int i=0; n > 0; i++, n/=2) if (n%2) _ans[i] = '1';
    return _ans;
}


void solve() {
    Get(int, n);
    GetV(int, a, n);
    Get(int, x);

    // auto f = [&] () -> void {};
    V<string> b; 
    Trav(a) {
        b.pb(giv30digit(i));
    }

    string xS = giv30digit(x);
    for(int i=0, j=1; i<xS.size(); i++, j*=2) {
        if (xS[i] == '1') continue;
        TRAV(k, a) {
            if (k&j) k -= j;
        }
    }

    mii m = freq(a);

    ll ans = 0;
    Trav(m) {
        ans += (ll)i.S * i.S;
    }

    cout << ans;
}


int main() {
    _fast();

    int t = 1;
    cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve();
        cout << NL;
    }

    return 0;
}
