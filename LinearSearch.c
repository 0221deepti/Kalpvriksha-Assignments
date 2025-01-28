// Linear Search
#include<stdio.h>
void linear_search(int array[],int n,int key){
    for(int i=0;i<n;i++){
        if(array[i]==key){
            printf("%d first found at index:%d",key,i);
            return;
        }
    }
    printf("Element not found\n");
}
int main(){
    int n;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    if (n <= 0) {
    printf("Array is empty.\n");
    return 0;
    }
    
    
    int array[10000];
    printf("Enter array elements\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    
    int key=0;
    printf("Enter key to find\n");
    scanf("%d",&key);

    linear_search(array,n,key);

}
