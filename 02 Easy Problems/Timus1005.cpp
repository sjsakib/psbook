/**
 * Problem: Timus 1005 - Stone Pile
 * Author: sjsakib
 * Approach: backtracking
 * Time: O(2^n)
 * এইটাই মনে হয় সবার আগে মাথায় আসে। আইডিয়াটা হল প্রত্যেক সংখ্যায় গিয়ে ঐ সংখ্যা নিয়ে এবং না নিয়ে পরের সংখ্যায় যেতে হবে। এভাবে শেষ সংখ্যায় এসে দেখতে হবে যোগফল কত হয়। এটা যদি একটা গ্রুপের যোগফল হল তাহলে অন্য গ্রুপের যোগফলের জন্য মোট থেকে বাদ দিতে হবে। তারপর দুই গ্রুপের বিয়োগফল নিয়ে ans আপডেট করতে হবে।  
**/
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