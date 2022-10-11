# encording with utf-8

n = int(input())
# print(bin(n)[2:])
nstr = bin(n)[2:]
# x = []
# print(nstr)

# for i in range(len(nstr)):
#     if nstr[len(nstr)-1-i] == '1':
#         x.append(pow(2, i))

# for i in range(len(x)):
#     ans = x[i]
#     print(ans)
#     for j in range(i):
#         ans += x[j]
#         print(ans)


for i in range(n+1):
    istr = bin(i)[2:]
    # print(i, istr, end='')
    for j in range(len(istr)):
        if istr[len(istr)-1-j] == '1' and nstr[len(nstr)-1-j] != '1':
            break
    else:
        print(int(istr, 2))
    #     print('\t true', end='')
    # print()
