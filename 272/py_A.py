# -*- coding: utf-8 -*-

n = int(input())

line = input().strip().split()

ans = 0
for i in range(n):
    ans += int(line[i])

print(ans)
