#include <iostream>
#include <cstring>
using namespace std;

const int N = 2010;
int n, m, S, T;
double g[N][N];
double dist[N];
bool st[N];

void dijkstra() {
    dist[S] = 1;
    for (int i = 1; i <= n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] < dist[j]))
                t = j;
        
        // 搜到终点了就可以直接返回了
        if (t == T) return;

        st[t] = true;
        for (int j = 1; j <= n; j++)
            if (!st[j] && dist[j] < dist[t] * g[t][j])
                dist[j] = dist[t] * g[t][j];
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        double z = (100.0 - c) / 100;
        g[a][b] = g[b][a] = max(g[a][b], z);
    }
    
    cin >> S >> T;

    dijkstra();

    printf("%.8lf\n", 100 / dist[T]);

    return 0;
}