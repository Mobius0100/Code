/* CSP202012-2 期末预测之最佳阈值 */

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int M = 100000;
pair<int, int> a[M + 1];
int prefix[M + 2], suffix[M + 2], p[M + 2];

int main()
{
    int m, i;

    scanf("%d", &m);
    for(i = 1; i <= m; i++)
        scanf("%d%d", &a[i].first, &a[i].second);

    sort(a + 1, a + 1 + m);

    // 前缀和
    prefix[0] = 0;
    for(i = 1; i <= m; i++)
        prefix[i] = prefix[i - 1] + (a[i].second == 0 ? 1 : 0);
    // 后缀和
    suffix[m + 1] = 0;
    for(i = m; i >= 1; i--)
        suffix[i] = suffix[i + 1] + (a[i].second == 1 ? 1 : 0);

    int pos = 1;
    p[1] = 1;
    for(i = 1; i <= m; i++)
        if(a[i].first == a[i - 1].first)
            p[i] = pos;
        else
            p[i] = (pos = i);

    int ans = 0, mx = 0;
    for(i = 1; i <= m; i++) {
        int cur = prefix[p[i] - 1] + suffix[i];
        if(cur >= mx)
            mx = cur, ans = a[i].first;
    }

    printf("%d\n", ans);

    return 0;
}
