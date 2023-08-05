#include<stdio.h>
#include<conio.h>

int find(int v,int parent[10])
{
   while(parent[v]!=v)
   {
      v=parent[v];
   }
   return v;
}

void union1(int i,int j,int parent[10])
{
   if(i<j)
      parent[j]=i;
   else
      parent[i]=j;
}

void kruskal(int n,int a[10][10])
{
   int count,k,min,sum,i,j,t[10][10],u,v,parent[10];
   count=0;
   k=0;
   sum=0;
   for(i=0;i<n;i++)
      parent[i]=i;
   while(count!=n-1)
   {
      min=999;
      for(i=0;i<n;i++)
      {
	 for(j=0;j<n;j++)
	 {

	    if(a[i][j]<min && a[i][j]!=0)
	    {
		min=a[i][j];
		u=i;
		v=j;                                          
	     }
	  }
       }
       i=find(u,parent);
       j=find(v,parent);
       if(i!=j)
       {
	  union1(i,j,parent);
	  t[k][0]=u;
	  t[k][1]=v;
	  k++;
	  count++;
	  sum=sum+a[u][v];
       }
       a[u][v]=a[v][u]=999;
    }
    if(count==n-1)
    {
       printf("spanning tree\n");
       for(i=0;i<n-1;i++)
       {
	  printf("%d %d\n",t[i][0],t[i][1]);
       }
       printf("cost of spanning tree=%d\n",sum);
    }
    else
       printf("spanning tree does not exist\n");
  }


void main()
{
   int n,i,j,a[10][10];
  
   printf("enter the number of nodes\n");
   scanf("%d",&n);
   printf("enter the adjacency matrix\n");
   for(i=0;i<n;i++)
     for(j=0;j<n;j++)
	scanf("%d",&a[i][j]);
   kruskal(n,a);
   getch();

}
