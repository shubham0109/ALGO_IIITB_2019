def f( a,b):
    if a[0] < b[0]:
        return True;
    if a[0] == b[0]:
        if a[1] < b[1]:
            return True
    return  False
n = int(input())
c=[]
for i in range(n):
    x,y = [int(x) for x in input().split(' ')]
    c.append((x,y))
print(c)

c = sorted(c,reverse=False,key=lambda x, y: )
print(c)
