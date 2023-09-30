// #include<stdio.h>
// #define max 10
// void merge(int [],int [],int,int,int,int);
// void merge_sort(int arr[],int low,int high);
// void copy(int [],int [],int,int);
// int main()
// {
//     int i,n,arr[max];

//     printf("enter the no. of elements:");
//     scanf("%d",&n);
//     arr[n];
//     printf("enter the elements of list: ");
//     for(i=0;i<=n-1;i++)
//     {
//         scanf("%d",&arr[i]);
//     }
//     printf("\n\nEntered list: ");
//     for(i=0;i<=n-1;i++)
//     {
//         printf("%d ",arr[i]);
//     }
//     merge_sort(arr,0,n-1);
//     printf("\n\nSorted list: ");
//     for(i=0;i<=n-1;i++)
//     {
//         printf("%d ",arr[i]);
//     }
//     printf("\n\n");
// }

// void merge_sort(int arr[],int low,int high)
// {
//     int mid;
//     int temp[max];
//     if(low<high)
//     {
//         mid=(low+high)/2;
//         merge_sort(arr,low,mid);
//         merge_sort(arr,mid+1,high);

//         merge(arr,temp,low,mid,mid+1,high);
//         copy(arr,temp,low,high);
//     }
// }

// void merge(int arr[],int temp[],int low1,int high1,int low2,int high2)
// {
//     int i=low1;
//     int j=low2;
//     int k=low1;
//     while((i<=high1) && (j<=high2))
//     {
//         if(arr[i]<=arr[j])
//             temp[k++]=arr[i++];
//         else
//             temp[k++]=arr[j++];
//     }
//     while(i<=high1)
//         temp[k++]=arr[i++];
//     while(j<=high2)
//         temp[k++]=arr[j++];
// }

// void copy(int arr[],int temp[],int low,int high)
// {
//     int i;
//     for(i=low;i<=high;i++)
//     {
//         arr[i]=temp[i];
//     }
// }


#include <stdio.h>

int array[100];

void merge(int left, int mid, int right)
{
    int leftArray[10];
    int rightArray[10];
   
    int sizeOfLeftArray = mid - left + 1;
    int sizeOfRightArray = right - (mid + 1) + 1;

    // Eg:-
    // Left            mid (mid+1)    right
    // ┌────┬────┬────┬────┬────┬────┬────┐
    // │ 32 │ 23 │ 11 │ 71 │ 42 │ 63 │ 35 │
    // └────┴────┴────┴────┴────┴────┴────┘
    // Left = 0
    // mid = 3
    // right = 6

    // sizeOfLeftArray = mid - left + 1 = 3 - 0 + 1 = 4
    // sizeOfRightArray = right - (mid + 1) + 1 = 6 - (3+1) + 1 = 3

    // ┌────┬────┬────┬────┐
    // │ 32 │ 23 │ 11 │ 71 │ leftArray
    // └────┴────┴────┴────┘
    // ┌────┬────┬────┐
    // │ 42 │ 63 │ 35 │ rightArray
    // └────┴────┴────┘
   
    // Copying Elements from 'array' to 'leftArray'
    for(int i=0; i<sizeOfLeftArray; i++)
    {
        leftArray[i] = array[left + i];
    }
   
    // Copying Elements from 'array' to 'rightArray'
    for(int i=0; i<sizeOfRightArray; i++)
    {
        rightArray[i] = array[(mid + 1) + i];
    }
   
    int i = 0; // For Left array index
    int j = 0; // For Right array index
    int k = left; // For main array index
   
    while(i < sizeOfLeftArray && j < sizeOfRightArray){
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        }
        else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i < sizeOfLeftArray) {
        array[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < sizeOfRightArray) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergesort(int left, int right){
    if(left >= right){
        return;
    }
    int mid = (left + right) / 2;
   
    mergesort(left, mid);
    mergesort(mid+1, right);
   
    merge(left, mid, right);
}


int main() {
    int size;
    printf("Enter the number of elements : ");
    scanf("%d", &size);
   
    printf("Enter the elements in the array : ");
    for(int i=0; i<size; i++){
        scanf("%d", &array[i]);
    }
    mergesort(0, size-1);
   
    for(int i = 0; i<size; i++){
        printf("%d ", array[i]);
    }
    return 0;
}