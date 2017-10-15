# Timus 1044 - Lucky Tickets. Easy



---|---
Commit Time | 15 Oct 2017 13:56

```cpp
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
int mem[38];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < pow(10, n/2); ++i) {
        int s = digitsum(i);
        mem[s]++;
    }
    int ans = 0;
    for (int i = 0; i < pow(10, n/2); ++i) {
        int s = digitsum(i);
        ans += mem[s];
    }
    printf("%d\n", ans);
    return 0;
}
```


---|---
Commit Time | 15 Oct 2017 14:00

```cpp
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
int mem[38];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < pow(10, n/2); ++i) {
        int s = digitsum(i);
        mem[s]++;
    }
    int ans = 0;
    for (int i = 0; i < pow(10, n/2); ++i) {
        int s = digitsum(i);
        ans += mem[s];
    }
    printf("%d\n", ans);
    return 0;
}
```
