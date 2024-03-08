#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(),v.end(),cmp);

    int firstMin = v.back();
    v.pop_back();
    int secondMin = v.back();

    cout << firstMin + secondMin << endl;
    
    return 0;
}