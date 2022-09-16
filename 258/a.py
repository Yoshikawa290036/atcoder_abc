# encording with utf-8
k = int(input())
hh = 21

if k >= 60:
    hh = hh+1
    k = k-60

strhh = str(hh).zfill(2)
strkk = str(k).zfill(2)

print('{}:{}'.format(strhh, strkk))
