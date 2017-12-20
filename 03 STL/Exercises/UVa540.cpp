/**
 * Problem: UVa 540 - Team Queue
 * Author: sjsakib
 * Approach: map + queue
**/
#include <cstdio>
#include <map>
#include <queue>

using namespace std;

map<int, int> team;
bool queued[1010];
queue<int> team_queue;
queue<int> teams[1010];

int main() {
    int t,n,x;
    int s = 1;
    while(scanf("%d", &t) && t != 0) {
        printf("Scenario #%d\n", s++);
        for (int i = 0; i < t; i++) {
            scanf("%d", &n);
            for (int j = 0; j < n; j++) {
                scanf("%d", &x);
                team[x] = i;
            }
        }
        char cmd[10];
        while (scanf("%s", cmd) && cmd[0] != 'S') {
            if (cmd[0] == 'E') {
                scanf("%d", &x);
                int tm = team[x];
                if(!queued[tm]) {
                    queued[tm] = true;
                    team_queue.push(tm);
                }
                teams[tm].push(x);
            } else {
                int tm = team_queue.front();
                printf("%d\n", teams[tm].front());
                teams[tm].pop();
                if(teams[tm].empty()) {
                    team_queue.pop();
                    queued[tm] = false;
                }
            }
        }
        puts("");
        team_queue = queue<int>();
        team.clear();
        for (int k = 0; k < t; k++) {
            teams[k] = queue<int>();
            queued[k] = false;
        }
    }
    return 0;
}