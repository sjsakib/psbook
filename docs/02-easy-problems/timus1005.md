# Timus 1005 - Stone Pile

### Bitmask

আমরা যদি 1 থেকে 2^n পর্যন্ত সবগুলো সংখ্যার বাইনারি নিই তাহলে n সংখ্যক ০ আর ১ এর যত রকম কম্বিনেশন হতে পারে সবগুলো পাব। তাহলে আমারা যদি i তম সংখ্যায় গিয়ে এর j তম বিট 1 হলে প্রদত্ত সংখ্যাগুলোর j তম সংখ্যা প্রথম গ্রুপে নিই তাহলে কিন্তু প্রথম গ্রুপের যত রকম যোগফল হতে পারে সেগুলো পাব। তাহলে ০ থেকে 2^n পর্যন্ত প্রতিসংখ্যায় গিয়ে ঐ সংখ্যার বিট রিপ্রেজেন্টেশন অনুসারে যোগফল নিয়ে ans আপডেট করলে ফাইনাল ans পাওয়া যাবে। যদিও কম্প্লেক্সিটি _ডিপি_ থেকে বেশি, ব্যাপারটা ইন্টারেস্টিং


---|---
Time | O(n * 2^n)
Commit Time | 15 Oct 2017 14:44

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

আগের এপ্রোচে প্রতি বিটে গিয়ে দেখতে হচ্ছে j তম সংখ্যা নেব কি না। এজন্য কম্প্লেক্সিটি হয়ে যাচ্ছে n * 2^n। এখান থেকে n বাদ দেয়া সম্ভব। প্রতি সংখ্যায় গিয়ে যদি আমরা তার একটি অন বিট অফ করে দেই তাহলে কিন্তু সংখ্যাটি আগের থেকে ছোট হয়ে যাচ্ছে। ঐ সংখ্যার জন্য কিন্তু যোগফল আমরা আগেও বের করেছি। এখন যদি আগেরটা কোন অ্যারেতে সেভ করে রাখতাম তাহলে ঐটার সাথে যততম বিটটি অফ করেছি প্রদত্ত সংখ্যার তততম সংখ্যাটি যোগ করে দিলেই কিন্তু বর্তমান সংখ্যার জন্য যোগফল পেয়ে যেতাম। এখন একটু খেয়াল করলে দেখা যাবে 2^i থেকে 2^i - 1 সংখ্যাগুলোর i তম বিট সব সময় অন থাকে। তাহলে এভাবে আমরা n * 2^n থেকে n বাদ দিতে পারি। কিন্তু তাহলে আবার2^n সাইজের অ্যারে লাগছে। সুতরাং মেমরি কম্প্লেক্সিটি বেড়ে যাচ্ছে।


---|---
Memory | O(2^n)
Time | O(2^n)
Commit Time | 15 Oct 2017 14:44

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
### Coin Change Dp

এখানে একটি গ্রুপের সর্বোচ্চ যোগফল হতে পারে সবগুলো সংখ্যার যোগফল পর্যন্ত। তাহলে আমরা ১ থেকে লুপ চালিয়ে প্রত্যেকটি সংখ্যায় গিয়ে দেখব প্রদত্তসংখ্যাগুলো একবার ব্যবহার করে সংখ্যাটি বানানো যায় কি না। এজন্য আমরা কয়েন চেন্জ ডিপি ব্যবহার করব। যদি যায় তাহলে ঐ সংখ্যাটিকে একটি গ্রুপের যোগফল ধরে ans আপডেট করব।


---|---
Time | O(total*n)
Commit Time | 15 Oct 2017 14:44

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

এইটাই মনে হয় সবার আগে মাথায় আসে। আইডিয়াটা হল প্রত্যেক সংখ্যায় গিয়ে ঐ সংখ্যা নিয়ে এবং না নিয়ে পরের সংখ্যায় যেতে হবে। এভাবে শেষ সংখ্যায় এসে দেখতে হবে যোগফল কত হয়। এটা যদি একটা গ্রুপের যোগফল হল তাহলে অন্য গ্রুপের যোগফলের জন্য মোট থেকে বাদ দিতে হবে। তারপর দুই গ্রুপের বিয়োগফল নিয়ে ans আপডেট করতে হবে।  


---|---
Time | O(2^n)
Commit Time | 15 Oct 2017 14:44

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
