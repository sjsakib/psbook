/**
 * Problem: Timus 1005 - Stone Pile
 * Author: sjsakib
 * Approach: bitmask
 * Time: O(n * 2^n)
 * আমরা যদি 1 থেকে 2^n পর্যন্ত সবগুলো সংখ্যার বাইনারি নিই তাহলে n সংখ্যক ০ আর ১ এর যত রকম কম্বিনেশন হতে পারে সবগুলো পাব। তাহলে আমারা যদি i তম সংখ্যায় গিয়ে এর j তম বিট 1 হলে প্রদত্ত সংখ্যাগুলোর j তম সংখ্যা প্রথম গ্রুপে নিই তাহলে কিন্তু প্রথম গ্রুপের যত রকম যোগফল হতে পারে সেগুলো পাব। তাহলে ০ থেকে 2^n পর্যন্ত প্রতি
 * সংখ্যায় গিয়ে ঐ সংখ্যার বিট রিপ্রেজেন্টেশন অনুসারে যোগফল নিয়ে ans আপডেট করলে ফাইনাল ans পাওয়া যাবে। যদিও কম্প্লেক্সিটি _ডিপি_ থেকে বেশি, ব্যাপারটা ইন্টারেস্টিং
**/
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