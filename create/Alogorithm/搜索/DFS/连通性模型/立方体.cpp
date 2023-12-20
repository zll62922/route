#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 15;

int n, m, k;
char g[N][N][N];

int dx[] = {1, 0, 0, -1, 0, 0};
int dy[] = {0, 1, 0, 0, -1, 0};
int dz[] = {0, 0, 1, 0, 0, -1};

int dfs(int x, int y, int z)
{
    g[x][y][z] = '#';
    int res = 1;

    for (int i = 0; i < 6; i ++ )
    {
        int a = x + dx[i], b = y + dy[i], c = z + dz[i];
        if (a < 0 || a >= n || b < 0 || b >= m || c < 0 || c >= k)
            continue;
        if (g[a][b][c] == '#') continue;

        res += dfs(a, b, c);
    }

    return res;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            cin >> g[i][j];

    int y, z;
    cin >> y >> z;

    cout << dfs(0, y - 1, z - 1) << endl;

    return 0;
}


