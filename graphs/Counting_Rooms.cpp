#include <bits/stdc++.h>
using namespace std;
#define ll long long

void bfs(ll i, ll j, vector<string>& roomMap, vector<vector<ll>>& vis, vector<pair<int, int>>& directions) {
    queue<pair<int, int>> q;
    int n = roomMap.size();
    int m = roomMap[0].size();

    q.push({i, j});
    vis[i][j] = 1;  // Mark as visited when adding to the queue

    while (!q.empty()) {
        ll _i = q.front().first;
        ll _j = q.front().second;
        q.pop();

        for (auto dir : directions) {
            ll x = _i + dir.first;
            ll y = _j + dir.second;
            if (x >= 0 && x < n && y >= 0 && y < m && roomMap[x][y] == '.' && !vis[x][y]) {
                vis[x][y] = 1;  // Mark as visited
                q.push({x, y});
            }
        }
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    cin.ignore();  // To consume the leftover newline character after `m`

    vector<string> roomMap(n);
    for (ll i = 0; i < n; i++) {
        getline(cin, roomMap[i]);
    }

    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<ll>> vis(n, vector<ll>(m, 0));

    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (!vis[i][j] && roomMap[i][j] == '.') {
                bfs(i, j, roomMap, vis, directions);
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
