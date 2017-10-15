# Timus 1025 - Democracy in Danger






---|---
Commit Time | 15 Oct 2017 14:44

```py


n = int(input())

print(sum(sorted(map(lambda x: int(x)//2 + 1, input().split()))[:n//2 + 1]))

```
