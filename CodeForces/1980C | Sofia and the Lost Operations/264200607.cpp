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
    vector<int> a;
    vector<int> b;
    vector<int> d;

    a.resize(200005);
    b.resize(200005);
    d.resize(200005);

    while(tc--){
        map<int, bool> bHas;
        map<int, int> bChanged;
        
        int n , m;
        cin >> n;

        bHas.clear();
        bChanged.clear();

        int totalChanged = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
            if(a[i] != b[i]){
                totalChanged++;
                bChanged[b[i]]++;
            }
            bHas[b[i]] = true;
        }

        cin >> m;
        for(int i = 0; i < m; i++){
            cin >> d[i];
        }
        vector<bool> suffixIgnore;
        bool alltrue = false;
        for(int i = m-1 ; i>= 0; i--){
            if(i == m-1){
                if(bHas[d[i]]){
                    suffixIgnore.push_back(true);
                    alltrue = true;
                }
                else{
                    suffixIgnore.push_back(false);
                }
            }
            else{
                if(bHas[d[i]] || alltrue){
                    suffixIgnore.push_back(true);
                    alltrue = true;
                }
                else{
                    suffixIgnore.push_back(false);
                }
            }
        }
        reverse(suffixIgnore.begin(), suffixIgnore.end());

        // bool ignore = false;
        // if(bHas[d[m-1]]) ignore = true;


        if(totalChanged > m){
            cout << "NO\n";
            continue;
        }else{
            bool forceNo = false;
            for(int i = 0; i < m; i++){
                if(bChanged[d[i]]){
                    bChanged[d[i]]--;
                    totalChanged--;
                }
                else{  
                    // cout << i << " --  " << suffixIgnore[i] << '\n';
                    if(!suffixIgnore[i]){
                        forceNo = true;
                        break;
                    }
                  
                
                }
            }

            // cout << totalChanged << " " << forceNo << '\n';
            if(totalChanged == 0  && !forceNo){
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }

        }




    }
    
}
