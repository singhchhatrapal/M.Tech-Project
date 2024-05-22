#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#define m 100
#include<stdlib.h>
//define n 29


int main()
{
//Variable Radius Covering Salesman Problem.
int i,j,k,iniarr[30][30],m1;
int rr,r1,v,z1,elt=20,o;

int elit[30][30];
int sum2;
float minimum;
int z2;
int w3;
float probcost[3];
int x1,x2;
int temp3;

int totcostarray[30];
int sum1,a1,a2,w1,w2;
int costarr[30];
int d2;

int g1=0,maxitr=100;
int itr;
int randam[30],max;
int j1,j2,r;
float temp;

int temp1;
int n=29,e,s1,l,k1,k2;
int mask[30];
int ssn=7,d1;
int cost[50][50],d;

FILE *file;
FILE *fp;
int ran[20];
float x;
int radius;
float prob[30];

int sum;

printf("enter radius");
scanf("%d",&radius);
    if((file = fopen("bbb.txt", "r"))==NULL)       /* open a text file for reading */
	{
 	exit(1);
  	}

//Filling of cost Matrix from file bayg29.dat

file = fopen("bbb.txt", "r");		                                 //couldn't open the requested file!

for(i=0;i<n;i++)
{
      for(j=0;j<n;j++)
	  {
      fscanf(file,"%d",&cost[i][j]);
      }
}

for(i=0;i<n;i++)
{
      for(j=0;j<n;j++)
	  {
       printf("%d",cost[i][j]);
       printf("   ");
       
      }
  printf("\n");
}
//Initialization by random number using modulo operator

for(k=0;k<30;k++)
{
for(i=0;i<ssn;i++)
{
  int rr,r1;
 label1: rr=(rand()+i+1)%n;
 r1=rr;   //sarr[rr];

   iniarr[k][i]=r1;
   for(j=0;j<i;j++)
   {

 if(r1!=iniarr[k][j])
 iniarr[k][i]=r1;
 else
    goto label1;
   }
}

iniarr[k][ssn]=iniarr[k][0];
}

for(k=0;k<29;k++)
{
for(i=0;i<=ssn;i++)
{
	printf("%d",iniarr[k][i]);
	printf("  ");
}

	printf("\n");
}
//getch();
//Beginning of While Loop

while(g1<1)
{

for(k=0;k<30;k++)

{
sum=0;
	for(l=0;l<29;l++)
{
	mask[l]=0;
}


for(j1=0;j1<=29;j1++)
{
costarr[j1]=0;
}


/*for(x=0;x<29;x++)
for(x1=0;x1<=29;x1++)
{ totcost[x][x1]==0;
}*/

for(i=0;i<ssn;i++)
{
	d1=iniarr[k][i];
	mask[d1]=1;
	for (int v=0;v<29;v++)
 {
	
	if(cost[d1][v] <= radius && v!=d1)
   {
    printf("\nThe node address is  \n");
    printf("%d   %d", d1,v );
	printf("            ");

	  printf("%d",cost[d1][v]);
	  printf("  ");
	  printf("%d",radius);

	  printf("  ");

	  if(mask[v]!=1)
   {
	  	mask[v]=1;
	  	costarr[v]=cost[d1][v];
  }
	  if (mask[v]==1)
	  {
	  	for(m1=0;m1<=i;m1++)
	  {
	  		d2=iniarr[k][m1];
	  	if(cost[d2][v]>cost[d1][v])	
	  	{
		    costarr[v]=cost[d1][v];
	  	mask[v]=1;		  
		}
	  		
		}
	  }
		
		
	
	}
	
	}
	
	
}

sum1=0;
for(a1=0;a1<30;a1++)
{
sum1=sum1+costarr[a1];

}
printf(" %d ",sum1);
sum2=0;
for(a2=0;a2<6;a2++)

{
w1=iniarr[k][a2];
w2=iniarr[k][a2+1];
sum2=sum2+cost[w1][w2];

}
w3=iniarr[k][0];
sum2=sum2+cost[w2][w3];
sum1=sum1+sum2;


printf("%d\n",sum1);
totcostarray[k]=sum1;
printf("\n");
printf("             ");
printf("Sum1  is ");
printf("%d ",sum1);
printf("            ");
printf("\n");

for(e=0;e<29;e++)
{
sum=sum+mask[e];
}
printf(" sum   ");
printf("  %d",sum);




printf("prob ");
float k1=sum;
x=k1/29.0;
prob[k]=x;
printf("%f",x);
}

/*for(i=0;i<29;i++)
{printf("%f",prob[i]);
printf("  ");
}*/
printf("\n mmmmmmmmmmmmmmmmm \n");
//getch();
//return 0;
//getch();
minimum=99999.9;
for(x1=0;x1<29;x1++)
{
if(minimum>=totcostarray[x1])	
{
minimum=totcostarray[x1];
}
}
//printf("Minimum");
//printf("%f", minimum);


for(x2=0;x2<29;x2++)
{
probcost[x2]=minimum/totcostarray[x1];
}

printf("\nProb cost are\n");
for(x2=0;x2<29;x2++)
{
printf("%f\n",probcost[x2]);
}

printf("\n");
printf("\nProbability Coverage are \n");

for(i=0;i<29;i++)
{
printf("%f\n",prob[i]);
if(prob[i]==1.0)
{ 
printf("\n");
printf("total cost= %d",totcostarray[i]);
printf("\n");
}
}


for(i=0;i<29;i++)
{
prob[i]=probcost[i];


}






//getch();
for(k1=0;k1<29;k1++)
{
                           //printf("nnnnnnnnnnnnnnnnnnn");
for(k2=k1+1;k2<29;k2++)
{
	if(prob[k1] <= prob[k2])
	{
	//	printf("why");
		temp=prob[k1];
		prob[k1]=prob[k2];
		prob[k2]=temp;
		
       for(z1=0;z1<=ssn;z1++)
	   {temp1=iniarr[k1][z1];
       	iniarr[k1][z1]=iniarr[k2][z1];
       	iniarr[k2][z1]=temp1;
       }
       	
       	
       	
		   
       }
       	
		
		
		
	//printf("%f",prob[i]);
   // printf("    ");}





}

}
printf(" \n  cccccccccccccccccccccccccccccccccccc  \n ");
for(i=0;i<=30;i++)
{

printf("\n");
for(j=0;j<=ssn;j++)
{ 
printf("%d",iniarr[i][j]);
  printf("   ");
}
printf("\n");
}
printf("\n");
for(i=0;i<30;i++)
{
  printf("probability = %f",prob[i]);

}

/*for(i=0;i<20;i++)
{  
for(j=0;j<=ssn;j++)
{elit[i][j]=iniarr[i][j];
}}*/


  
  for(k=0;k<30;k++)
{
for(i=0;i<=ssn;i++){
	elit[k][i]=iniarr[k][i];
	
}
}
  
  for(k=0;k<30;k++)
{
printf("\n");
for(i=0;i<=ssn;i++){
	printf("%d",elit[k][i]);
	printf("   ");

}
printf("\n");
}
  
  
 printf("\n");
  
 for(i=0;i<=20;i++) 
 {
 rr=(rand()+1)%7;
 r1=rr;//sarr[rr];
 
 
  randam[i]=r1;
    printf(" %d",randam[i]);
   printf("     ");
   
 
    }
  
  printf("\n   ");
  for(i=0;i<=20;i=i+2) 
 { 
 d1=randam[i];
 for(j=d1;j<=7;j++)
   {
   temp=elit[i][j];
   elit[i][j]=elit[i+1][j];
   elit[i+1][j]=temp;
      }
      elit[i][8]=elit[i][0];
	  }
 
 
 
 for(i=0;i<=20;i=i+2) 
 { 
 for(j=d1;j<=7;j++)
   {
   iniarr[i][j]=elit[i][j];
   }
   
   }
 
 for(i=0;i<=20;i++) 
 {
 printf("\n");
 for(j=0;j<=8;j++)
 {
 printf("%d",elit[i][j]);
 printf("   ");
 }
 }
  
/*for(k1=0;k1<=20;k1+2)
{ label2: randam[k1]=rand()%7;
printf("%d",randam[k1]);
if(k1!=20)
{ goto label2;
}
}*/
 
 printf("\n \n mutation \n");
 
 for(i=0;i<2;i++) 
 {
 rr=(rand()+1)%20;
 r1=rr;//sarr[rr];
 
  ran[i]=r1;
   printf("\n%d\n ",randam[i]);
   printf("     ");
  
 }
    
 max=0;
for(i=0;i<=1;i++)

{
	d1=ran[i];
printf("\nThe row number is ");
printf("%d \n",d1);
//getch();
	for(k=0;k<ssn;k++)
	
{ 
  if(max<iniarr[d1][k])
  {
  max=iniarr[d1][k];
  
 }
 
 }
  printf("\nThe max element in that row is");
printf("%d\n",max);
 
  r=(rand()+1)%7;
  printf("The position of mutation  in that row is  ");
  //getch();
  
  printf("%d\n ",r);
  //getch();
  iniarr[d1][r]=max;
  
}
 
  for(i=0;i<=20;i++) 
 {
 	
 for(j=0;j<=8;j++)
 { 	
 iniarr[i][j]=elit[i][j];
 }
 
 }
 
 /* for(z2=0;z2<=29;z2++)
  { printf("%d",totcostarray[z2]);
  printf(" , ");
  }*/
   
  for(m1=0;m1<=30;m1++)
  {
    printf("total cost = %d\n ",totcostarray[m1]);
 // printf(" \ncost  ");
  }
  
 //End of While Loop
 g1=g1+1;
 //getch();
 radius=radius+1;
 
 
}


  
}   
 







				    	