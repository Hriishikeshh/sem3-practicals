a=[2,5,6,8,9]
n=len(a)
x=int(input("enter value to be searched :"))

def fibonacci_search():
    fib=[]
    a1=0
    b=1
    for i in range(10):
        fib.append(a1)
        temp=a1
        a1=b
        b=temp+b

    global mid
    m=0
    while(fib[m]<=n):
        m=m+1

    offset=-1
    while(fib[m]>0):
        mid=min(offset+fib[m-2],n-1)
        if(x==a[mid]):
            print("pass : mid:", mid, "value:", a[mid])
            return mid
            break

        elif(x>=a[mid]):
            print("pass : mid:", mid, "value:", a[mid])
            m=m-1
            offset=mid

        elif(x<a[mid]):
            print("pass : mid:", mid, "value:", a[mid])
            m=m-2

    if(fib[m-1] and a[offset]==x):
        print("pass : mid:", mid, "value:", a[mid])
        return(offset+1)
    return -1
result=fibonacci_search()

if(result>0):
    print("found at ",mid)
else:
    print("absent")



