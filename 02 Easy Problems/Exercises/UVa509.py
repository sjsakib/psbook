#!/usr/bin/python3
"""
Problem: UVa - 509 RAID!
Status: WA :(
"""
case = 1
while True:
    try:
        d, s, b = map(int, input().strip().split())
    except ValueError:
        break
    p = (0 if input() == 'E' else 1)
    data = []
    for i in range(d):
        data.append(list(input().strip()))

    valid = True
    for i in range(s*b):
        k = 0
        lost = -1
        for j in range(d):
            c = data[j][i]
            if c == '1':
                k ^= 1
            if c == 'x':
                if lost != -1:
                    valid = False
                    break
                else:
                    lost = j
        if not valid or (lost == -1 and k != p):
            valid = False
            break
        if lost != -1:
            data[lost][i] = '0' if k == p else '1'

    if not valid:
        print("Disk set", case, "is invalid.")
    else:
        content = ''
        for i in range(b):
            for j in range(d):
                if j != i % d:
                    content += ''.join(data[j][i*s:(i+1)*s])
        if len(content) % 4:
            content += '0'*(4 - (len(content) % 4))
        print("Disk set", case, "is valid, contents are:", hex(int(content, 2))[2:].upper())
    case += 1
