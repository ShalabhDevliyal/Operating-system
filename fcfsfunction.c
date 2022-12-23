#include <stdio.h>
#include <math.h>

void fcfs(int cylinders[], int n, int head)
{
 int head_movements = 0;
    for (int i = 0; i < n; i++){
        head_movements += abs(cylinders[i] - head);
        head = cylinders[i];}
        printf("total head movements: %d\n", head_movements);
    return;
}
int main()
{
 int n;
 printf("Enter n: ");
 scanf("%d",&n);

 int cylinders[n]; 
 printf("Enter order of cylinder requests: ");
 for (int i = 0; i < n ; i++)
 scanf("%d",&cylinders[i]);
 
 int head;
 printf("Enter head: ");
 scanf("%d",&head);
 
 fcfs(cylinders,n,head);
 return 0;
}