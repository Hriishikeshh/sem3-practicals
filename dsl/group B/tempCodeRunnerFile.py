
def partition(high,low,arr):

    pivot=arr[high]
    i=low-1

    for j in range(low,high):
        if(arr[j]<=pivot):
            i=i+1
            temp=arr[j]
            arr[j]=arr[i]
            arr[i]=temp

    temp=arr[i+1]