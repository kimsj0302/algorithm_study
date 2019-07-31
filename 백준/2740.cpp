#include<iostream>

int A[101][101],B[101][101],C[101][101];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&A[i][j]);
    int k;
    scanf("%d %d",&m,&k);
    for(int i=0;i<m;i++)
        for(int j=0;j<k;j++)
            scanf("%d",&B[i][j]);

    for(int i=0;i<n;i++)
        for(int j=0;j<k;j++)
            for(int l=0;l<m;l++){
                C[i][j]+=A[i][l]*B[l][j];
            }
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++)
            printf("%d ",C[i][j]);
        printf("\n");
    }
}
