#binary and fibonacci search

# take array input
array=[]
size=int(input("enter array size :"))
for i in range(size):
    x=int(input("enter value :"))
    array.append(x)
print(array)

key=int(input("enter value to search :"))
#binary search iterative
def binary_search(array,l,h,key):

    low=l
    high=h-1

    while(high>=low):

        mid=low + (high-1) // 2
        if(array[mid]==key):
            return mid

        elif(array[mid]>key):
            high=mid-1

        elif(array[mid]<key):
            low=mid+1

    return -1

result=binary_search(array,0,size-1,key)

if(result!=-1):
    print("present at ",result)

else:
    print("absent")

        

    

