# Timus 1005 - Stone Pile

### Coin Change Dp

এখানে একটি গ্রুপের সর্বোচ্চ যোগফল হতে পারে সবগুলো সংখ্যার যোগফল পর্যন্ত। তাহলে আমরা ১ থেকে লুপ চালিয়ে প্রত্যেকটি সংখ্যায় গিয়ে দেখব প্রদত্তসংখ্যাগুলো একবার ব্যবহার করে সংখ্যাটি বানানো যায় কি না। এজন্য আমরা কয়েন চেন্জ ডিপি ব্যবহার করব। যদি যায় তাহলে ঐ সংখ্যাটিকে একটি গ্রুপের যোগফল ধরে ans আপডেট করব।


---|---
Time | O(total*n)
Commit Time | 15 Oct 2017 14:41

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
