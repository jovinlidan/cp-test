#include <bits/stdc++.h>

using namespace std;

bool isEdge(int i, int j, int x, int y)
{
    if (i == 0 || j == 0 || i == x - 1 || j == y - 1)
        return true;
    return false;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   

   int tc;
   int a , b, c , d;
   cin >> tc;
   while(tc--){
   cin >> a >> b >> c >> d;

    if(a > b){
        swap(a, b);
    }
    if( c > d ){
        swap(c , d);
    }
    int ans = 0;
    for( int i = a; i <= b; i++){
        if( i == c){
            ans++;
        }
        else if ( i == d){
            ans++;
        }
    }
    if( ans == 1)cout << "YES\n";
    else cout << "NO\n";

   }

    return 0;
}