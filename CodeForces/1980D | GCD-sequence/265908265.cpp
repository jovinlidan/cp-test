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

int gcdFunc(int a, int b) 
{ 
    // Everything divides 0 
    if (a == 0) 
        return b; 
    if (b == 0) 
        return a; 
  
    // base case 
    if (a == b) 
        return a; 
  
    // a is greater 
    if (a > b) 
        return gcd(a - b, b); 
    return gcd(a, b - a); 
} 

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int lastGcd = -1;
    int idx = -1;
    for(int i = 1; i < n; i++){
        int curGcd = gcdFunc(a[i], a[i - 1]);
        // cout << curGcd << " ";
        if(  curGcd < lastGcd){
            idx= --i;
            break;
        }
        lastGcd  = curGcd;
    }
    if(idx == -1){
        cout << "YES\n";
    }
    else{
        // cout << idx << "\n";
        vector<int> prefix;
        vector<int> middle;
        vector<int> suffix;
        for(int i = 0; i < n; i++){
            if(i != idx -1){
                prefix.push_back(a[i]);
            }
            if(i != idx){
                middle.push_back(a[i]);
            }
            if(i != idx + 1){
                suffix.push_back(a[i]);
            }
        }
        bool pf = true, md = true, sf = true;
        lastGcd = -1;
        for(int i = 1; i < prefix.size(); i++){
            int curGcd = gcdFunc(prefix[i], prefix[i - 1]);
            if(curGcd  < lastGcd){
                pf = false;
                break;
            }
            lastGcd = curGcd;
        }


        lastGcd = -1;
        for(int i = 1; i < middle.size(); i++){
            int curGcd = gcdFunc(middle[i], middle[i - 1]);
            if(curGcd  < lastGcd){
                md = false;
                break;
            }
            lastGcd = curGcd;
        }

        lastGcd = -1;
        for(int i = 1; i < suffix.size(); i++){
            int curGcd = gcdFunc(suffix[i], suffix[i - 1]);
            if(curGcd  < lastGcd){
                sf = false;
                break;
            }
            lastGcd = curGcd;
        }

        if(pf || md || sf)cout << "YES\n";
        else cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;

    while(tc--){
        solve();
    }
    
}
