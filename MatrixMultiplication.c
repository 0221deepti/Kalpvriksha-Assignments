#include<stdio.h>
#include <stdlib.h>

void get_matrix1(int row1,int col1,int matrix1[row1][col1]){
    printf("Enter values for matrix 1:\n");
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            scanf("%d",&matrix1[i][j]);
        }
    }
}
void get_matrix2(int row2,int col2,int matrix2[row2][col2]){
    printf("Enter values for matrix 2:\n");
    for(int i=0;i<row2;i++){
        for(int j=0;j<col2;j++){
            scanf("%d",&matrix2[i][j]);
        }
    }
}
void multiply_matrix(int row1,int col1,int matrix1[row1][col1],int row2,int col2,int matrix2[row2][col2]){
    if(col1!=row2){
        printf("MAtrix multiplication not possible\n");
        return;
    }
    int k_row=row1;
    int k_col=col2;
    int **k_matrix=(int**)malloc(k_row * sizeof(int *));
    if(k_matrix==NULL){
        printf("memory allocation fails\n");
        return;
    }
    for(int i=0;i<k_row;i++){
        k_matrix[i]=(int*)malloc(k_col*sizeof(int));
        if(k_matrix[i]==NULL){
        printf("memory allocation fails\n");
        for (int j = 0; j < i; j++) {
        free(k_matrix[j]);
    }
    free(k_matrix);
    return;
    }
    }
    for(int i=0;i<k_row;i++){
        for(int j=0;j<k_col;j++){
            k_matrix[i][j]=0;
            for(int k=0;k<col1;k++){
                k_matrix[i][j]+=matrix1[i][k]*matrix2[k][j];
            }
        }
    }
    printf("Resultant matrix:\n");
    for(int i=0;i<k_row;i++){
        for(int j=0;j<k_col;j++){
           printf("%d ",k_matrix[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<k_row;i++){
        free(k_matrix[i]);
    }
    free(k_matrix);
}


int main(){
    int row1,col1,row2,col2;
    printf("Enter row and coloumn for matrix 1: ");
    scanf("%d %d",&row1,&col1);
    int matrix1[row1][col1];
  
    printf("Enter row and coloumn for matrix 2: ");
    scanf("%d %d",&row2,&col2);
    int matrix2[row2][col2];

    get_matrix1(row1,col1,matrix1);
    get_matrix2(row2,col2,matrix2);
    multiply_matrix(row1,col1,matrix1,row2,col2,matrix2);
}
