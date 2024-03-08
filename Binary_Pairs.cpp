#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        string st;
        cin >> st;
        int countBinaryPair = 0;
        for (int i = 0; i < n; i++){
            if (st[i] == '0' && st[i + 1] == '1') countBinaryPair++;
            else if (st[i] == '1' && st[i + 1] == '0') countBinaryPair++;
        }
        cout << countBinaryPair << endl;       
    }
    
    return 0;
}