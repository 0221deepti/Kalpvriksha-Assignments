// // Given an array arr[] of positive integers.
// Your task is to sort them so that the first part of the array contains odd numbers 
// sorted in descending order, and the rest of the portion contains even numbers sorted in ascending order.
// Examples:


// Input: arr[] = [1, 2, 3, 5, 4, 7, 10]Output: [7, 5, 3, 1, 2, 4, 10]Explanation: 7 5 3 1 are odds in descending order and 2 4 10 are evens in ascending order.
 #include<stdio.h>
 #include<stdlib.h>
int comp1(const void* a,const void* b){
   return *(int*)a-*(int*)b;
}
int comp2(const void* a,const void* b){
   return *(int*)b-*(int*)a;
}

void merge(int odd[],int m,int even[],int k,int array[]){
    for(int i=0;i<m;i++){
        array[i]=odd[i];
    }
    int p=0;
    for(int i=m;i<m+k;i++){
        array[i]=even[p];
        p++;
    }
}
void print_array(int array[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
}
void sort_array(int array[],int n){

    int odd[1000];
    int even[1000];
    int k=0;
    int m=0;
    for(int i=0;i<n;i++){
        if(array[i]%2==0){
            even[k++]=array[i];
        }
        else{
            odd[m++]=array[i];
        }
    }
    qsort(even,k,sizeof(even[0]),comp1);
    qsort(odd,m,sizeof(odd[0]),comp2);
    merge(odd,m,even,k,array);
}
 int main(){
    int n;
    printf("Enter number of elements in array:");
    scanf("%d",&n);
    printf("Enter elements\n");
    int array[1000];
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    sort_array(array,n);
    print_array(array,n);

 }
