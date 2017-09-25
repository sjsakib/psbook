/**
 *    problem: UVa 1592 Database
 *    author: sjsakib
 *    status: WA :(
**/
#include <bits/stdc++.h>

using namespace std;

string db[10007][12];
char buff[85];
int n,m;

bool read() {
    if(scanf("%d %d\n", &n,  &m) == EOF) return false;
    for (int i = 0; i < n; i++) {
        gets(buff); 
        int j=0,k=0;
        while(buff[j] != '\0') {
            if(buff[j] != ',') {
                db[i][k].push_back(buff[j]);
            } else k++;
            j++;
        }
    }
}

bool findDup(int c1, int c2) {
    map<pair<string, string>, int> mp;
    for (int r = 0; r < n; r++) {
        pair<string, string> p = make_pair(db[r][c1], db[r][c2]);
        //cout<<r<<' '<<db[r][c1]<<' '<<db[r][c2]<<endl;
        if(mp.find(p) == mp.end()) mp[p] = r;
        else {
            printf("NO\n%d %d\n%d %d\n", mp[p]+1, r+1, c1+1, c2+1);
            return true;
        }
    }
    return false;
}

void clear() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            db[i][j].clear();
        }
    }
}



int main() {
    while(read()) {
        bool found = false;
        for (int i = 0; i < m; i++) {
            for (int j = i+1; j < m; j++) {
                found = findDup(i,j);
                if(found) break;
            }
            if(found) break;
        }
        if(!found) printf("YES\n");
        clear();
    }
    return 0;
}