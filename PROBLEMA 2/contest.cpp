#include<bits/stdc++.h>
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
#define MAX 1000000
 
int n;
int k1, k2, k3;
vector<int> v(MAX);
int tb[MAX][3];
 
int DC(int idx, int vez = 0) {
    if(idx >= n) return 0;
 
    if(tb[idx][vez] != -1) return tb[idx][vez]; 
 
    int troca = 1e8, ntroca, tres = 1e8;
    if(vez == 0) {
        troca = (v[idx] != 2) + DC(idx+1, 1);
        tres = (v[idx] != 3) + DC(idx+1, 2);
        ntroca = (v[idx] != 1) + DC(idx+1);
    }else if(vez == 1) {
        troca = (v[idx] != 3) + DC(idx+1, 2);
        ntroca = (v[idx] != 2) + DC(idx+1, vez);
    }else {
        ntroca = (v[idx] != 3) + DC(idx+1, 2);
    }
 
    return tb[idx][vez] = min({troca, ntroca, tres});
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    memset(tb, -1, sizeof tb);
    cin >> k1 >> k2 >> k3;
    n = k1+k2+k3;
 
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        if(i < k1) {
            v[a-1] = 1;
        }else if(i < k1+k2) {
            v[a-1] = 2;
        }else {
            v[a-1] = 3;
        }   
    }
    
    cout << DC(0);
 
    return 0;
}
