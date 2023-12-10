# take arrayay input
array=[]
n=int(input("enter array size :"))
for i in range(n):
    x=int(input("enter value :"))
    array.append(x)
print(array)

# element to search
key=int(input("enter value to check :"))

# linear search

def linear_search():
    for i in range(n):
        if(key==array[i]):
            return

            
def sentinel_search():
    last=array[n-1]
    array[n-1]=key

    i=0
    while(array[i]!=key):
        i+=1

    array[n-1]=last
    if((i<n-1)or(array[n-1]==key)):
        print("present")

    else:
        print("absent")

