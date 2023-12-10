size=int(input("enter array size :"))
arr=[]
for i in range(size):
    a=float(input("enter value :"))
    arr.append(a)

#bubble sort

def bubble(arr):

    for i in range(size):

        for j in range(0,size-i-1): #as last i ar already sorted

            if(arr[j]>arr[j+1]):
                temp=arr[j+1]
                arr[j+1]=arr[j]
                arr[j]=temp

        else:
            print("pass",i+1,": ",arr)

    print("bubble sort :")

#insertion sort
def insertion(arr):
    for i in range(size):
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
def selection(arr):
    for i in range(size):
        min_index=i
        for j in range(i+1,size):
            if(arr[j]<arr[min_index]):
                min_index=j

        temp=arr[min_index]
        arr[min_index]=arr[i]
        arr[i]=temp
        print("pass ",i+1," :",arr)
    
    print(arr)
selection(arr)

#shell sort
def shell(arr):
    gap=size//2
    while(gap>0):
        j=gap
        while(j<size):
            i=j-gap
            while(i>=0):
                if(arr[i+gap]>arr[i]):
                    break
                else:
                    temp=arr[i+gap]
                    arr[i+gap]=arr[i]
                    arr[i]=temp
                i=i-gap
            j+=1
        print("pass :",arr)
        gap=gap//2

    print(arr)

            


