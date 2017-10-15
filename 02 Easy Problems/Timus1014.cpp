/**
 * Problem: Timus 1014 - Product of Digits
 * Author: sjsakib
 * Approach: Greedy
 * Time: O(n)
 * গ্রীডি টেকনিকে খুবই সহজে সমাধান করা সম্ভব। ৯ থেকে ২ পর্যন্ত সংখ্যাগুলো দিয়ে যতবার ভাগ যায় ভাগ দিতে থাকব আর সংখ্যাগুলো লিখে রাখব। যদি শেষে ১ থাকে তাহলে সমাধান আছে।
 * লিখে রাখা সংখ্যাগুলো উল্টা অর্ডারে প্রিন্ট করব।
**/
#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    scanf("%d", &n);
    vector<int> ans;
    if(n == 1) {
        printf("1\n");
        return 0;
    } else if(n == 0) {
        printf("10\n");
        return 0;
    }
    for(int i = 9;i >= 2;--i) {
        while(n % i == 0) {
            n /= i;
            ans.push_back(i);
        }
    }
    if(n == 1) {
        for (int i = ans.size()-1; i >= 0; --i) {
            printf("%d", ans[i]);
        }
        printf("\n");
    } else {
        printf("-1\n");
    }
    return 0;
}