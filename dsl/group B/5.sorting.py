size=int(input("enter array size :"))
arr=[]
for i in range(size):
    a=float(input("enter value :"))
    arr.append(a)

#bubble sort

def bubble(arr):

    for i in range(size):
        flag=False

        for j in range(0,size-i-1): #as last i ar already sorted

            if(arr[j]>arr[j+1]):
                temp=arr[j+1]
                arr[j+1]=arr[j]
                arr[j]=temp
                flag=True

        else:
            print("pass",i+1,": ",arr)

#insertion sort
def insertion(arr):
    for i in range(1,size):
        key=arr[i]
        j=i-1

        while(j>=0 and key<arr[j]):
            temp=arr[j+1]
            arr[j+1]=arr[j]
            arr[j]=temp
            j=j-1
        print("pass :",i," ",arr)
        arr[j+1]=key
    print(arr)

#selection sort


            


