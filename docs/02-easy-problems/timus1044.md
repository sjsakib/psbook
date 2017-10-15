# Timus 1044 - Lucky Tickets. Easy

দেখতে ঝামেলার মনে হতে পারে। কিন্তু আসলে সিম্পল। n = 8 বিবেচনা করা যাক। অর্ধেকগুলা ডিজিটের সর্বোচ্চ যোগফল হতে পারে ৩৬। প্রিতিটি যোগফল কতভাবে হতে পারে তা রাখার জন্য mem‌[3‌] নেব। একটা  এখন ০ থেকে ৯৯৯৯ পর্যন্ত লুপ চালিয়ে প্রতিটি সংখ্যার ডিজিট সাম s বের করতে হবে এবং mem‌[s‌] বাড়াতে হবে। তাহলে আমরা পেয়ে যাচ্ছি কতভাবে কোন একটি যোগফল সম্ভব।


---|---
Commit Time | 15 Oct 2017 14:44

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
