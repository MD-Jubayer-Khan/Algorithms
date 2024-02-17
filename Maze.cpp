#include <bits/stdc++.h>
using namespace std;

bool vis[1001][1001];
int dis[1001][1001];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
char a[1001][1001];    
pair<int, int> parent[1001][1001];

bool valid(int i, int j){
    if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] == '#') return false;    
    return true;
}

bool bfs(int sx, int sy, int ex, int ey) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    vis[sx][sy] = true;

    while (!q.empty()) {
        pair<int, int> par = q.front();
        q.pop();
        if (par.first == ex && par.second == ey){
            while (par.first != sx || par.second != sy){
                a[par.first][par.second] = 'X';
                par = parent[par.first][par.second];
                }
            a[sx][sy] = 'R';
            a[ex][ey] = 'D';
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int ci = par.first + d[i].first;
            int cj = par.second + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj]){
                q.push({ci, cj});
                vis[ci][cj] = true;
                parent[ci][cj] = par;
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    int sx,sy,ex,ey;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'R') sx = i, sy = j;
            if(a[i][j] == 'D') ex = i, ey = j;
        }
    }
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));

    bfs(sx, sy, ex, ey);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}