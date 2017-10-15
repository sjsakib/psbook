# Timus 1005 - Stone Pile

### Bitmask



---|---
Time | O(n * 2^n)
Commit Time | 15 Oct 2017 13:56

```cpp
#include <bits/stdc++.h>

using namespace std;

int n, num[22], sum=0, ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
        sum += num[i];
    }
    ans = sum;
    for (int mask = 0; mask < (1<<n); mask++) {
        int s = 0;
        for (int j = 0; j < n; ++j) {
            if((1<<j)&mask) s += num[j];
        }
        ans = min(ans, abs(sum-s*2));
    }
    printf("%d\n",ans);
    return 0;
}
```
### Bitmask With Memorization



---|---
Time | O(2^n)
Memory | O(2^n)
Commit Time | 15 Oct 2017 13:56

```cpp
#include <bits/stdc++.h>

using namespace std;

int n, num[22], sum=0, ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
        sum += num[i];
    }
    ans = sum;
    int mem[(1<<n) + 10];
    mem[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int mask = 1<<i; mask < (1<<(i+1)); mask++) {
            mem[mask] = mem[mask ^ (1<<i)] + num[i];
            ans = min(ans, abs((sum - mem[mask]*2)));
        }
    }
    printf("%d\n",ans);
    return 0;
}
```
### Coin Change Dp Time



---|---
Commit Time | 15 Oct 2017 13:56

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int arr[22];
    int sum = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    int ans = sum;
    bool dp[sum+1];
    memset(dp, 0, sum);
    dp[0] = 1;
    for (int j = 1; j < n; j++) {
        for (int i = sum; i >= 1; i--) {
            if(i >= arr[j] && dp[i - arr[j]]) {
                dp[i] = 1;
                ans = min(ans, abs(sum- i*2));
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
```
### Backtracking



---|---
Time | O(2^n)
Commit Time | 15 Oct 2017 13:56

```cpp
#include <bits/stdc++.h>

using namespace std;

int n;
int arr[22];
int sum = 0;
int ans;

void backtrack(int i, int s) {
    if(i == n) {
        ans = min(ans, abs(sum - s*2));
        return;
    }
    backtrack(i+1, s);
    backtrack(i+1, s+arr[i]);
}


int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    ans = sum;
    backtrack(0, 0);
    printf("%d\n",ans);
    return 0;
}
```
### Bitmask



---|---
Time | O(n * 2^n)
Commit Time | 15 Oct 2017 14:00

```cpp
#include <bits/stdc++.h>

using namespace std;

int n, num[22], sum=0, ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
        sum += num[i];
    }
    ans = sum;
    for (int mask = 0; mask < (1<<n); mask++) {
        int s = 0;
        for (int j = 0; j < n; ++j) {
            if((1<<j)&mask) s += num[j];
        }
        ans = min(ans, abs(sum-s*2));
    }
    printf("%d\n",ans);
    return 0;
}
```
### Bitmask With Memorization



---|---
Memory | O(2^n)
Time | O(2^n)
Commit Time | 15 Oct 2017 14:00

```cpp
#include <bits/stdc++.h>

using namespace std;

int n, num[22], sum=0, ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
        sum += num[i];
    }
    ans = sum;
    int mem[(1<<n) + 10];
    mem[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int mask = 1<<i; mask < (1<<(i+1)); mask++) {
            mem[mask] = mem[mask ^ (1<<i)] + num[i];
            ans = min(ans, abs((sum - mem[mask]*2)));
        }
    }
    printf("%d\n",ans);
    return 0;
}
```
### Coin Change Dp Time



---|---
Commit Time | 15 Oct 2017 14:00

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int arr[22];
    int sum = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    int ans = sum;
    bool dp[sum+1];
    memset(dp, 0, sum);
    dp[0] = 1;
    for (int j = 1; j < n; j++) {
        for (int i = sum; i >= 1; i--) {
            if(i >= arr[j] && dp[i - arr[j]]) {
                dp[i] = 1;
                ans = min(ans, abs(sum- i*2));
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
```
### Backtracking



---|---
Time | O(2^n)
Commit Time | 15 Oct 2017 14:00

```cpp
#include <bits/stdc++.h>

using namespace std;

int n;
int arr[22];
int sum = 0;
int ans;

void backtrack(int i, int s) {
    if(i == n) {
        ans = min(ans, abs(sum - s*2));
        return;
    }
    backtrack(i+1, s);
    backtrack(i+1, s+arr[i]);
}


int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    ans = sum;
    backtrack(0, 0);
    printf("%d\n",ans);
    return 0;
}
```
