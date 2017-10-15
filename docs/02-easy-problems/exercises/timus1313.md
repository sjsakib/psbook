# Timus 1313 - Some Words about Sports





---|---
Commit Time | 15 Oct 2017 13:56

```py

from sys import stdin

n = int(input())

arr = []

for line in stdin:
    arr.append(line.split())

for i in range(n*2):
    j = max(i-n+1, 0)
    i = min(i, n-1)
    while i >= 0 and j < n:
        end = '\n' if (i == n-1 and j == n-1) else ' '
        print(arr[i][j], end=end)
        i -= 1
        j += 1

```




---|---
Commit Time | 15 Oct 2017 14:00

```py

from sys import stdin

n = int(input())

arr = []

for line in stdin:
    arr.append(line.split())

for i in range(n*2):
    j = max(i-n+1, 0)
    i = min(i, n-1)
    while i >= 0 and j < n:
        end = '\n' if (i == n-1 and j == n-1) else ' '
        print(arr[i][j], end=end)
        i -= 1
        j += 1

```
