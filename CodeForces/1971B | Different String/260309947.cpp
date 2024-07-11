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
   cin >> tc;
   while(tc--){
    string s;
    cin >> s;
    set<char> st;
    for(int i = 0; i < s.length() ; i++){
        st.insert(s[i]);
        
 
    }
    if(st.size() == 1){
        cout << "NO\n";
    }
    else {
        for(int i = 0 ; i< s.length()-1; i++){
            if(s[i] != s[i+1]){
                swap(s[i], s[i+1]);
                break;
            }
        }
        cout << "YES\n";
        cout << s << '\n';
    }
    // cout << st.size() == 1 ? "" << '\n';
   }

    return 0;
}