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

ll calc(ll midTime, ll h, ll n, vector<ll> &d, vector<ll> &c){
    ll cur = 0;
    for(int i = 0; i < n; i++){
        ll damage = ((midTime / c[i]) * d[i]);
        cur+=damage;
    }
    return cur;
}

vector<int> a(200005), b(200005);
vector<ll> ans(200005);
vector<char> choice(200005);

void solve(){
    int n;
        string s, ans = "";
        cin >> n >> s;

        int x = 0, y = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'N') y++;
            else if(s[i] == 'S') y--;
            else if(s[i] == 'E') x++;
            else x--;
        }
        // cout << x << " " << y << '\n';
        if(x % 2 != 0 || y % 2 != 0){
            cout << "NO\n";
            return;
        }

        if(x == 0 && y == 0){
            if(n == 2){
                cout << "NO\n";
                return;
            }
            char next = '0';
            
            for(int i = 0; i< n; i++){
                if(i == 0){
                    if(s[i] == 'N') next = 'S';
                    else if(s[i] == 'S') next = 'N';
                    else if(s[i] == 'E') next = 'W';
                    else next = 'E';
                    ans += 'R';
                }
                else if(next == s[i]){
                    ans += 'R';
                    next = '0';
                }
                else {
                    ans += 'H';
                }
            }
            cout << ans << '\n';
            return;
        }
        else {
            // cout << x << " " << y << '\n';
            for(int i = 0; i < n; i++){
                if(s[i] == 'N' && y > 0){
                    y-=2;
                    ans += 'R';
                }
                else if(s[i] == 'S' && y < 0){
                    y+=2;
                    ans += 'R';
                }
                else if(s[i] == 'E' && x > 0){
                    x-=2;
                    ans += 'R';
                }
                else if(s[i] == 'W' && x < 0){
                    x+=2;
                    ans += 'R';
                }
                else{
                    ans += 'H';
                }
            }
            cout << ans << '\n';
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
