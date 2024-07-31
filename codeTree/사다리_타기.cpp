#include <iostream>
using namespace std;
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 987654321

int n, m;
vector<pair<int, int>> edges; // y, x-(x+1)
bool edge[16][16];
bool v[16];      // back tracking visit check
bool v1[16][16]; // dfs visit check
int res[16];
vector<int> temp;
int ans = MAX;

void setRes(int cur, int y, int x, int prev_y, int prev_x)
{
    if (y == 16)
    {
        res[cur] = x;
        return;
    }

    if (x <= n && edge[y][x] && x+1 != prev_x)
        setRes(cur, y, x + 1, y, x);
    else if (x > 1 && edge[y][x - 1] && x-1 != prev_x)
        setRes(cur, y, x - 1, y, x);
    else
        setRes(cur, y + 1, x, y, x);
}

bool dfs(int cur, int y, int x, int prev_y, int prev_x)
{
    if (y == 16)
    {
        if (x == res[cur])
            return true;
        else
            return false;
    }

    if (x <= n && v1[y][x] && x+1 != prev_x)
        return dfs(cur, y, x + 1, y, x);
    else if (x > 1 && v1[y][x - 1] && x-1 != prev_x)
        return dfs(cur, y, x - 1, y, x);
    else
        return dfs(cur, y + 1, x, y, x);
}

void f(int idx, int cnt, int cnt_bound)
{
    if (cnt >= cnt_bound)
    {
        memset(v1, false, sizeof(v1));
        for (auto e : temp)
        {
            pair<int, int> tmp = edges[e];
            v1[tmp.first][tmp.second] = true;
        }
        bool isAllTrue = true;
        for (int i = 1; i <= n; i++)
        {
            if (!dfs(i, 1, i, -1, -1))
            {
                isAllTrue = false;
                break;
            }
        }
        if (isAllTrue)
            ans = min(ans, cnt_bound);

        return;
    }

    for (int i = idx; i < m; i++)
    {
        if (v[i])
            continue;
        v[i] = true;
        temp.push_back(i);
        f(i + 1, cnt + 1, cnt_bound);
        v[i] = false;
        temp.pop_back();
    }
}

int main()
{
    FIO;

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int e, j; // (e)ㅡ(e+1), j번째 줄
        cin >> e >> j;
        edges.push_back(make_pair(j, e));
        edge[j][e] = true;
    }

    for (int i = 1; i <= n; i++)
        setRes(i, 1, i, -1, -1);

    for (int cnt = 0; cnt <= m; cnt++)
    {
        f(0, 0, cnt);
        if(ans != MAX) break;
    }

    cout << ans << "\n";
}