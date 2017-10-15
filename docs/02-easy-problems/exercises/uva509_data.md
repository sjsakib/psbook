# uva509_data


---|---
Commit Time | 15 Oct 2017 14:44

```py
#!/usr/bin/python3
from random import randint

d = 6
s = 64
b = 100

data = [['' for i in range(b)] for j in range(d)]


def get_random(s):
    return ''.join([str(randint(0, 1)) for i in range(s)])


def fill():
    for i in range(b):
        parity = 0
        for j in range(d):
            if j != i % d:
                block = get_random(s)
                data[j][i] = block
                parity ^= int(block, 2)
        parity = bin(parity)[2:]
        if len(parity) < s:
            parity = '0'*(s-len(parity)) + parity
        data[i % d][i] = parity


def prnt():
    print(d, s, b)
    print('E')
    for disk in data:
        print(''.join(disk))
    print(0)


if __name__ == '__main__':
    fill()
    prnt()

```
