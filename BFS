#include<stdio.h>
#include<conio.h>
int a[10][10],n;
void bfs(int);
void main()
{
int i,j,src;
printf("\nenter the no of nodes:\t");
scanf("%d",&n);
printf("\nenter the adjacency matrix:\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&a[i][j]);
}
}
printf("\nenter the source node:\n");
scanf("%d",&src);
bfs(src);
}
void bfs(int src)
{
int q[10],f=0,r=-1,vis[10],i,j;
for(j=1;j<=n;j++)
{
vis[j]=0;
}
vis[src]=1;
r=r+1;
q[r]=src;
while(f<=r)
{
i=q[f];
f=f+1;
for(j=1;j<=n;j++)
{
if(a[i][j]==1&&vis[j]!=1)
{
vis[j]=1;
r=r+1;
q[r]=j;
}
}
}
for(j=1;j<=n;j++)
{
if(vis[j]!=1)
printf("\nnode %d is not reachable\n",j);
else
printf("\nnode %d is reachable\n",j);
}
}
