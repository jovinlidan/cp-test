#include <bits/stdc++.h>
using namespace std;
#define INF -1e9
typedef long long int ll;
typedef pair <int,int> pii;
typedef pair <pii,int> piii;
const ll MOD = 1e9+7;
const int mxN = 1000005;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int kx[8] = { 2, 1, -1, -2, -2, -1, 1, 2};
int ky[8] = { 1, 2, 2, 1, -1, -2, -2, -1};
ll qpow(unsigned long long x , int y , int p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y % 2 == 1) res = (res * x) % p;
        y = y / 2;
        x = (x * x) % p;
    }
    return res;
}
ll modInverse(unsigned long long x , int p)
{
    return qpow(x, p - 2 , p);
}
double calc (ll t1 , ll t2 , ll y1 , ll y2)
{
    return (t1 * y1 + t2 * y2) * 1.0 /(y1 + y2);
}

string getBit(int n){
    string s = "";
    while(n){
        s += (n % 2) + '0';
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

vector<ll> returnBit(ll xx){
    vector<ll> ret;
    for(int i = 0; i < 31; i++){
        if(xx & (1ll << i)){
            ret.push_back(1);
        }
        else{
            ret.push_back(0);
        }
    }
    return ret;
}

vector<int>prefixSum;
vector<int>suffixSum;
int total = 0;
// 14 - 
// 1 2 3 4 5
// string temp;
void solve(int n){
    int l = 1, r = n; 
    while (l < r) {
        int mid = (r-l) / 2 + l;
        // l - mid
        int leftSum = (total - prefixSum[l-1]) - suffixSum[mid+1];
        // int rightSum = (total - prefixSum[mid]) - suffixSum[r+1];

        // ask left
        cout << "? ";
        cout << mid- l + 1 << " ";
        for(int i = l; i <= mid; i++){
            if( i != l)cout << " ";
            cout << i;
        } 
        cout << '\n';
        cout.flush();


        int resLeft,resRight;
        cin >> resLeft;

        if(resLeft != leftSum){
            r = mid;
        }
        else{
            l = mid+1;
        }
    
    }

    cout << "! " << l << '\n'; 
    cout.flush();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;

    while(tc--){
        int n, sum = 0 ;
        total = 0;
        cin >> n;
        vector<int> v(n+5);
        prefixSum.resize(n+5);
        suffixSum.resize(n+5);
        for(int i = 1; i <= n; i++){
            cin >> v[i];
            sum += v[i];
            total += v[i];
            prefixSum[i] = sum;
        }

        sum = 0;
        for(int i = n; i >= 1; i--){
            sum += v[i];
            suffixSum[i] = sum;
        }
        

        solve(n);
        cout.flush();
    }
    cout << '\n';
    
}

// 19 19 18 11 19 6 20 8