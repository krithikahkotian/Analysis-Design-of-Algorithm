#include<stdio.h>
void main()
{
    int i,j,n,v,k,min,u,c[20][20],s[20],d[20];
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("Enter the cost adjacency matrix\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&c[i][j]);
        }
    }
    printf("Enter the source vertices: ");
    scanf("%d",&v);
    for(i=1;i<=n;i++){
        s[i]=0;
        d[i]=c[v][i];
    }
    d[v]=0;
    s[v]=1;
    for(k=2;k<=n;k++){
        min=999;
        for(i=1;i<n;i++){
            if((s[i]==0)&&(d[i]<min)){
                min=d[i];
                u=i;
            }
        }
        s[u]=1;
        for(i=1;i<=n;i++){
            if(s[i]==0){
                if(d[i]>(d[u]+c[u][i])){
                    d[i]=(d[u]+c[u][i]);
                    }
            }
        }
    }
    printf("The shortest distance from %d is ",v);
    for(i=1;i<=n;i++){
        printf("\n%d --> %d = %d",v,i,d[i]);
    }
}
