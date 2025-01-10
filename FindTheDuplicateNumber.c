/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and using only constant extra space.
Example 1:
Input: nums = [1,3,4,2,2]
Output: 2
Example 2:
Input: nums = [3,1,3,4,2]
Output: 3
Example 3:
Input: nums = [3,3,3,3,3]
Output: 3
Constraints:
1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
*/
//Solution
#include<stdio.h>
#include<stdlib.h>

int findDuplicate(int* nums, int numsSize) {
    int hash[numsSize];
    for(int i=0;i<numsSize;i++)
        hash[i] = 0;
    for(int i=0;i<numsSize;i++)
        hash[nums[i]]++;
    for(int i=0;i<numsSize;i++){
        if(hash[i] > 1){
            return i;
        }
    }
    return -1;
}
int main(){
int n;
scanf("%d",&n);
int*nums=(int*)malloc(n*sizeof(int));
for(int i=0;i<n;i++){
scanf("%d",&nums[i]);
}
int res=findDuplicate(nums,n);
printf("Duplicate Element:%d",res);
return 0;
}
