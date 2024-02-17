#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N = 1e5 + 5;
ll parent[N];
ll group_size[N];
ll countCycle = 0;

void dsu_initialize(ll n)
{
    for (ll i = 1; i <= n; i++){
        parent[i] = -1;
        group_size[i] = 1;
    }
}

ll dsu_find(ll node)
{
    if (parent[node] == -1) return node;
    ll leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}

void dsu_union_by_size(ll node1, ll node2)
{
    ll leaderA = dsu_find(node1);
    ll leaderB = dsu_find(node2);
    if (group_size[leaderA] > group_size[leaderB]) parent[leaderB] = leaderA, group_size[leaderA] += group_size[leaderB];
    else parent[leaderA] = leaderB, group_size[leaderB] += group_size[leaderA];
}

int main()
{
    ll n, e;
    cin >> n >> e;
    dsu_initialize(n);

    while (e--)
    {
        ll a, b;
        cin >> a >> b;

        ll leaderA = dsu_find(a);
        ll leaderB = dsu_find(b);

        if (leaderA == leaderB) countCycle++;
        else dsu_union_by_size(a, b);
    }
    
    cout << countCycle;

    return 0;
}