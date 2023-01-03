#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define endl '\n'
 
using namespace std;
 
const int INF = 1e9+7;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;
const int MOD = 1000000007;
const int MAX = 1e5+7;
 
struct segMin {
 
    int size;
    vector<pii> minimum;
 
    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        minimum.assign(2 * size, {INF, INF});
    }
 
    void build(vector<int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < a.size()) {
                minimum[x] = {a[lx], lx};
            }
 
            return;
        }
 
        int m = (rx + lx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
 
        minimum[x] = min(minimum[2 * x + 1], minimum[2 * x + 2]);
    }
 
    void build(vector<int> &a) {
        build(a, 0, 0, size);
    }
 
    pii qmin(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return {INF, -1};
        if (lx >= l && rx <= r) return minimum[x];
 
        int m = (lx + rx) / 2;
        pii min1 = qmin(l, r, 2 * x + 1, lx, m);
        pii min2 = qmin(l, r, 2 * x + 2, m, rx);
 
        return min(min1, min2);
    }
 
    pii qmin(int l, int r) {
        return qmin(l, r, 0, 0, size);
    }
 
};
 
struct segMax {
 
    int size;
    vector<pii> minimum;
 
    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        minimum.assign(2 * size, {-INF, -INF});
    }
 
    void build(vector<int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < a.size()) {
                minimum[x] = {a[lx], lx};
            }
 
            return;
        }
 
        int m = (rx + lx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
 
        minimum[x] = max(minimum[2 * x + 1], minimum[2 * x + 2]);
    }
 
    void build(vector<int> &a) {
        build(a, 0, 0, size);
    }
 
    pii qmin(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return {-INF, -1};
        if (lx >= l && rx <= r) return minimum[x];
 
        int m = (lx + rx) / 2;
        pii min1 = qmin(l, r, 2 * x + 1, lx, m);
        pii min2 = qmin(l, r, 2 * x + 2, m, rx);
 
        return max(min1, min2);
    }
 
    pii qmin(int l, int r) {
        return qmin(l, r, 0, 0, size);
    }
 
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    segMin st;
    st.init(n);
    st.build(arr);
    
    segMax st2;
    st2.init(n);
    st2.build(arr);
    
    int l, r, x;
    while (m--) {
        cin >> l >> r >> x;
        
        pii menor = st.qmin(l-1, r);
        pii maior = st2.qmin(l-1, r);
        
        if (menor.ff != x) {
            cout << menor.ss+1 << endl;
        } else if (maior.ff != x) {
            cout << maior.ss+1 << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
 
    return 0;
}