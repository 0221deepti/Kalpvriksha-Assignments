// Merge Sort
#include<stdio.h>
#include<stdlib.h>
void merge_array(int array[],int low,int mid,int high){
    int i=low;
    int j=mid+1;
    int k=low;
    int sort_arr[high+1];
    while(i<=mid && j<=high){
        if(array[i]<array[j]){
            sort_arr[k]=array[i];
            i++;
             k++;
        }
        else{
            sort_arr[k]=array[j];
            j++;
             k++;
        }
       
    }
    while(i<=mid){
        sort_arr[k]=array[i];
            i++;
            k++; 
    }
    while(j<=high){
        sort_arr[k]=array[j];
            j++;
            k++;
    }
    for(int i=low;i<=high;i++){
        array[i]=sort_arr[i];
    }

}
void MergeSort(int array[],int low,int high){
    if(low<high){
        int mid=low+(high-low)/2;
        MergeSort(array,low,mid);
        MergeSort(array,mid+1,high);
        merge_array(array,low,mid,high);
    }
}

void print_array(int array[],int len){
    for(int i=0;i<len;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}
int main(){
    int n;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    
    int array[10000];
    printf("Enter array elements\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    
    printf("Unsorted array: ");
    print_array(array, n);

    int low=0;
    int high=n-1;

    MergeSort(array,low,high);
    
    printf("Sorted array: ");
    print_array(array, n);
}
