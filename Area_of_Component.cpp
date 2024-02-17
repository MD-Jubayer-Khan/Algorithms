#include <bits/stdc++.h>

using namespace std;
const int N = 1001;

int n, m;
int mat[N][N];
int visited[N][N];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool isValid(int x, int y){
    return !visited[x][y] && mat[x][y] != -1 && x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int i, int j,int &countRoom){
    queue<pair<int, int>> q;

    q.push({i,j});
    visited[i][j] = true;

    while(!q.empty()){
        auto par = q.front();
        q.pop();
        int x = par.first;
        int y = par.second;

        for(int i = 0; i < 4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(isValid(new_x, new_y))
            {
                q.push({new_x, new_y});
                visited[new_x][new_y] = true;
                countRoom++;        
            }
        }
    }
}

int main () {
    pair<int, int> dest;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++)
        {
            if(s[j] == '-') mat[i][j] = -1;
            else mat[i][j] = 0; 
            visited[i][j] = false;
        }
    }

    int countArea;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && mat[i][j] == 0) {
                int countRoom = 1;
                bfs(i, j,countRoom);
                flag = true;
                countArea = min(countArea,countRoom);
            }
        }     
    }
    
    if(flag) cout << countArea;
    else cout << -1;

    return 0;
}