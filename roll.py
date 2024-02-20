def f(x):
    _=1
    for i in range(1,x+1):
        _*=i
    return _

n=int(input())
ans=0
for i in range(1,n+1):
    ans=ans+f(i)
print(ans)