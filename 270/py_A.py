# -*- coding: utf-8 -*-


a, b = map(int, input().split())

# a += 8
# b += 8
ans = 0
astr = bin(a)[2:].zfill(3)
bstr = bin(b)[2:].zfill(3)
# print(astr)
for i in range(2, -1, -1):
    # print(i)
    if astr[i] == '1' or bstr[i] == '1':
        ans += 2**(2-i)

print(ans)
