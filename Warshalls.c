#include<stdio.h>
#define MAX 5

 void Warshal(int graph[][MAX],int n)
 {
     for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                    graph[i][j]=graph[i][j]||(graph[i][k]&&graph[k][j]);
            }
        }
     }
 }

 void main()
 {
     int graph[MAX][MAX],n;
     printf("Enter the number of Vertices\n");
     scanf("%d",&n);
     printf("Enter the Adjacency Matrix\n");
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
     }
     Warshal(graph,n);
     printf("Transitive Closure Matrix\n");
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",graph[i][j]);
        }
        printf("\n");
     }
 }
