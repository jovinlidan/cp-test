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


int check(ll xx){
    for(int i = 0; i < 31; i++){
        if(xx == (1ll << i))return i;
    }
    return -1;
}

vector<ll> bits;
vector<ll> ans;

vector<int> returnBit(ll xx){
    vector<int> ret;
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
    for(int i = 0; i < 31; i++){
        bits.push_back((1ll << i));
    }
    
    int tc ;
    cin >> tc;
    
    
    while(tc--){
        ll x;
        cin >> x;
        ans.clear();

        vector<int> byte = returnBit(x);

        // for(int i = 0; i < byte.size(); i++){
        //     cout << byte[i];
        // }
        // cout << '\n';

        for(int i = 0; i < byte.size()-1; i++){
            //check continuous 1
            if(byte[i] == 1 && byte[i+1] == 1){
                int start = i;
                int end = i;

                int j = i;
                start = i;
                while(j < byte.size() && byte[j] == 1){
                    byte[j] = 0;
                    j++;
                    // cout << "kena\n";
                }
                byte[start] = -1;
                byte[j] = 1;
                
                i = j-1;
            }
        }
        cout << byte.size() << '\n';
        for(int i = 0; i < byte.size(); i++){
            if(i != 0 )cout << " ";
            cout << byte[i];;
        }
        cout << '\n';


        
        
        
    }
}
