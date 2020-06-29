#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 2100
using namespace std;

int level[MAX];
vector<int> graph[MAX];
int c[MAX][MAX], f[MAX][MAX];
int work[MAX];
int S, E;
bool bfs() {
    for (int i = 0; i < MAX; i++) level[i] = -1;
    level[S] = 0;
    queue<int> que;
    que.push(0);
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];
            if (level[next] == -1 && c[now][next] - f[now][next] > 0) {
                level[next] = level[now] + 1;
                que.push(next);
            }
        }
    }
    return level[E] != -1;
}

int dfs(int now, int dest, int flow) {
    if (now == dest) return flow;
    for (int& i = work[now]; i < graph[now].size(); i++) {
        int next = graph[now][i];
        if (level[next] == level[now] + 1 && c[now][next] - f[now][next] > 0) {
            int re = dfs(next, dest, min(c[now][next] - f[now][next], flow));
            if (re > 0) {
                f[now][next] += re;
                f[next][now] -= re;
                //cout << "flow " << now <<" to " << next << ":" << re<<endl;
                return re;
            }
        }
    }
    return 0;
}


int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    S = 0;
    E = n + m + 1;
    vector<int> u, d;
    for (int i = 1; i <= n; i++) {
        int t;
        scanf("%d", &t);
        u.push_back(t);
        c[S][i] = 1;
        c[i][S] = 1;
        graph[i].push_back(S);
        graph[S].push_back(i);
    }
    for (int i = n + 1; i <= m + n; i++) {
        int t;
        scanf("%d", &t);
        d.push_back(t);
        c[i][E] = 1;
        c[E][i] = 1;
        graph[i].push_back(E);
        graph[E].push_back(i);
    }
    for (int i = 0; i < u.size(); i++) {
        for (int j = 0; j < d.size(); j++) {
            if (u[i] <= 2 * d[j] && 4 * d[j] <= 3 * u[i]) {
                c[i + 1][j + 1 + n] = 1;
                graph[i + 1].push_back(j + 1 + n);
                graph[j + 1 + n].push_back(i + 1);
            }
            if (u[i] <= d[j] && 4 * d[j] <= 5 * u[i]) {
                c[i + 1][j + 1 + n] = 1;
                graph[i + 1].push_back(j + 1 + n);
                graph[j + 1 + n].push_back(i + 1);
            }
        }
    }
    int ans = 0;
    while (bfs()) {
        for (int i = 0; i < MAX; i++) work[i] = 0;
        while (1) {
            int flow = dfs(S, E, 10000);
            if (!flow) break;
            ans += flow;
        }
    }
    printf("%d\n", ans);
}
