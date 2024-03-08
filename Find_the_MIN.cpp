#include <bits/stdc++.h>
using namespace std;

class cmp{
    public:
    bool operator()(const int& a, const int& b) const {
        return a > b;
    }
};

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin >> t;
    priority_queue<int, vector<int>, cmp> pq;
    set<int> s;     
    while (t--) {

        int command;
        cin >> command;
        if(command == 1){
            int num;
            cin >> num;
            if (s.find(num) == s.end()){
                pq.push(num);
                s.insert(num);
            }
        }
        else if(command == 2){
            if(!pq.empty()){
                int minVal = pq.top();
                cout << minVal << "\n";
                while (!pq.empty() && pq.top() == minVal) pq.pop();
                s.erase(minVal);  
            } 
            else cout << "empty" << "\n";
        }
    }
    return 0;
}