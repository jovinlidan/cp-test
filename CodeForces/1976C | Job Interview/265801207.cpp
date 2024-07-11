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
vector<ll> prefixSum(200005) ,ans(200005);
vector<char> choice(200005);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;

    while(tc--){
       int n, m;
       cin >> n >> m;
       for(int i = 0;i < n+m+1; i++){
            cin >> a[i];
       }

       int nn = n , mm = m;
       
       for(int i = 0;i < n+m+1; i++){
            cin >> b[i];

            if(i == 0){
                if(nn > 0 && mm > 0){
                    if(a[i] > b[i]){
                        prefixSum[i] = a[i];
                        nn--;
                        choice[i] = 'a';
                    }
                    else{
                        prefixSum[i] = b[i];
                        mm--;
                        choice[i] = 'b';
                    }
                }
                else if(nn > 0){
                    prefixSum[i] = a[i];
                    nn--;
                    choice[i] = 'a';
                }
                else if(mm > 0){
                    prefixSum[i] = b[i];
                    mm--;
                    choice[i] = 'b';
                }

            }
            else{
                if(nn > 0 && mm > 0){
                    if(a[i] > b[i]){
                        prefixSum[i] = prefixSum[i-1] + a[i];
                        nn--;
                        choice[i] = 'a';

                    }
                    else{
                        prefixSum[i] = prefixSum[i-1] + b[i];
                        mm--;
                        choice[i] = 'b';
                    }
                }
                else if(nn > 0){
                    prefixSum[i] = prefixSum[i-1] + a[i];
                    nn--;
                    choice[i] = 'a';

                }
                else if(mm > 0){
                    prefixSum[i] = prefixSum[i-1] + b[i];
                    mm--;
                    choice[i] = 'b';
                }
            }
       }
      

       nn = 0, mm = 0;

       ll latestBigA = -1, latestBigB = -1;
       for(int i = n+m ; i >= 0; i--){
            if(i == n+m){
                ans[i] = prefixSum[i-1];
            }else{
                ll totalSum = ans[n+m];
                if(choice[i] == 'a'){
                    ll withoutThis = totalSum - a[i];
                    // cout << i << "-" << withoutThis << " -- " << latestBigB << '\n';
                    if(latestBigA != -1 ){
                        // take the latest bigA and remove the b
                        withoutThis += a[latestBigA];


                        // because remove b, now need to take b from end 
                        if(latestBigA != n+m){
                            withoutThis -= b[latestBigA];
                            withoutThis += b[n+m];
                        }
                    }
                    else{
                        withoutThis += a[n+m];
                    }
                    ans[i] = withoutThis;
                }
                else{
                    ll withoutThis = totalSum - b[i];

                    if(latestBigB != -1){
                        withoutThis += b[latestBigB];

                        if(latestBigB != n+m){
                            withoutThis -= a[latestBigB];
                            withoutThis += a[n+m];
                        }
                    }
                    else{
                        withoutThis += b[n+m];
                    }
                    ans[i] = withoutThis;
                }
            }

            if(a[i] > b[i] && choice[i] != 'a' ){
                latestBigA = i;
            }
            else if(a[i] < b[i] && choice[i] != 'b'){
                latestBigB = i;
            }
       }

       for(int i = 0; i < n+m+1; i++){
        cout << ans[i] << " ";
       }
       cout << '\n';
    }
    
}
