size=int(input("enter array size :"))
arr=[]
for i in range(size):
    a=float(input("enter value :"))
    arr.append(a)


def partition(high,low,arr):

    pivot=arr[high]
    i=low-1

    for j in range(low,high):
        if(arr[j]<pivot):
            i=i+1
            
            temp=arr[j]
            arr[j]=arr[i]
            arr[i]=temp

    temp=arr[i+1]
    arr[i+1]=pivot
    pivot=arr[i]

    return i+1


def quick_sort(high,low,arr):
    if(low<high):
        pi=partition(high,low,arr)

        #after pivot placement left sort
        quick_sort(pi-1,low,arr)

        #after pivot placement right sort
        quick_sort(high,pi+1,arr)



quick_sort(size-1,0,arr)
print(arr)