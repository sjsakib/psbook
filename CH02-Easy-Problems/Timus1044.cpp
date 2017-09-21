/**
 *    problem: Timus 1044 Lucky Tickets. Easy
 *    author: sjsakib
 *    approach: 
**/
#include <bits/stdc++.h>

using namespace std;

int pow(int a, int x) {
    int ret = 1;
    for (int i = 0; i < x; ++i) {
        ret *= a;
    }
    return ret;
}

int digitsum(int n) {
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int n;
int pos[38];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < pow(10, n/2); ++i) {
        int s = digitsum(i);
        pos[s]++;
    }
    int ans = 0;
    for (int i = 0; i < pow(10, n/2); ++i) {
        int s = digitsum(i);
        ans += pos[s];
    }
    printf("%d\n", ans);
    return 0;
}