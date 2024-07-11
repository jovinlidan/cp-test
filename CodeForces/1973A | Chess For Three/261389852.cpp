#include <bits/stdc++.h>

using namespace std;

int tc;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   cin >> tc;
   int a, b , c;
   while(tc--){
    cin >> a >> b >> c;

    if((a + b + c) % 2 == 1){
        cout << -1 << '\n';
    }
    else{
        // 2 odd 1 even or 3 even
        int kur = b- a;
        b -= kur;
        c -= kur;
        int ans = kur;

        if(a + b <= c){
            cout << ans + a + b << '\n';
        }
        else{
            cout << ans + (a + b + c )/ 2 << '\n';
        }

    }
   


   }

    return 0;
}