#include "bits/stdc++.h"
using namespace std;

#define INF 1000000000000000003
#define PI 3.1415926535897932384626433832795
#define mod 1e9 + 7

#define F first
#define S second
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mkp make_pair
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set

#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define pob pop_back
#define eb emplace_back

#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
/*

3 4
(3+2x)^2 + (4+2x)^2 

*/

istream &operator>>(istream &in, __int128_t &value) {
    string s;
    in >> s;
    value = 0;
    for (char c : s) {
        value = value * 10 + (c - '0');
    }
    return in;
}

ostream &operator<<(ostream &out, __int128_t value) {
    if (value == 0) {
        out << '0';
        return out;
    }
    string s;
    while (value > 0) {
        s.push_back((value % 10) + '0');
        value /= 10;
    }
    reverse(s.begin(), s.end());
    out << s;
    return out;
}

void solve() {
    __int128_t n, c; cin >> n >> c;
    __int128_t a = 4 * n, b = 0, val = 0;
    for (int i = 0; i < n; ++i) {
        __int128_t x;
        cin >> x;
        b += x * 4;
        val += x * x;
    }
    c -= val;
    __int128_t l = 1, r = 1e18, ans = -1;
    while (l <= r) {
        __int128_t x = l + (r - l) / 2;
        if(x * x > c or a*x*x > c or b*x > c) {
            r = x-1;
            continue;
        }
        __int128_t value = a * x * x + b * x;
        if (value == c) {
            ans = x;
            break;
        } else if (value > c) {
            r = x - 1;
        } else {
            l = x + 1;
            ans = x;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int T = 1;
    cin >> T;
    while (T-- > 0) solve();

    return 0;
}
