#include<iostream>
using namespace std;


template<typename T>
void insertion(T arr[],int size){
    T key;
    int i,j;
    for(i=1;i<size;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

template<typename P>
void selection(P arr[],int size){
    int temp;
    for(int i=0;i<size;i++){
        int j=i;
        for(j=i+1;j<size;j++){
            if(arr[j]<arr[i]){
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
}

int main(){
    int arr1[]={5,2,3,1};
    float arr2[]={4.5,2.5,7.9,1.2};

    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int size2=sizeof(arr2)/sizeof(arr2[0]);

    cout<<"insertion sorted array :"<<endl;
    insertion<int>(arr1,size1);
    insertion<float>(arr2,size2);

    for(int i=0;i<size1;i++){
        cout<<arr1[i]<<" ";
    }

    cout<<endl;

    for(int i=0;i<size2;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    cout<<"selection sorted array :"<<endl;
    selection<int>(arr1,size1);
    selection<float>(arr2,size2);

    for(int i=0;i<size1;i++){
        cout<<arr1[i]<<" ";
    }

    cout<<endl;

    for(int i=0;i<size2;i++){
        cout<<arr2[i]<<" ";
    }

}