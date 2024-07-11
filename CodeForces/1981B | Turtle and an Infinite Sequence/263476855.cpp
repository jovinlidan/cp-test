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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;

    while(tc--){
        ll n, m;
        cin >> n >> m;
        vector<ll> bitMid = returnBit(n);
        vector<ll> bitRight = returnBit(n + m);
        vector<ll> bitLeft = returnBit(max(int(n - m), 0));

        
         // CALC RIGHT

        for(int i = 30; i >= 0; i--){
            if(bitMid[i] == 0 && bitRight[i] == 1){
                // here
                for(int j = i; j >=0; j--){
                    bitRight[j] = 1;
                    
                }
                break;
            }
        }
         // turn bit into number
        ll numRight = 0;
        for(int i = 0; i < 31; i++){
            if(bitRight[i] == 1){
                numRight += (1ll << i);
            }
        }
        
         // CALC LEFT
        bitMid = returnBit(n);

        int leftFirstBitIdx = -1;
        for(int i = 0 ; i < 30; i++){
            if(bitLeft[i] == 1){
                leftFirstBitIdx = i;
                break;
            }
        }

        for(int i = 30; i >= 0; i--){
            if(bitMid[i] == 1){
                // here
                for(int j = i; j >=leftFirstBitIdx; j--){
                    bitLeft[i] = 1;
                }
                break;
                
            }
        }

       

        // turn bit into number
        ll numLeft = 0;
        for(int i = 0; i < 31; i++){
            if(bitLeft[i] == 1){
                numLeft += (1ll << i);
            }
        }
        
        // cout << (n | (numRight)) << '\n';
        cout << (n | (numRight) | (numLeft)) << '\n';
    }
    
}