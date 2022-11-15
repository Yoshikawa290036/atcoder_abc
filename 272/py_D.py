# -*- coding: utf-8 -*-

import math

N, M = map(int, input().strip().split())

msq = math.sqrt(M)

for i in range(1, N+1):
    for j in range(1, N+1):
        length = math.sqrt((i-1)**2 + (j-1)**2)
        # print(i, j, length, math.ceil(length/msq))
        print(math.ceil(length/msq),end=' ')
    print()
