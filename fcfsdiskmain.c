#include<stdio.h>
#include<stdlib.h>
int main()
{
    int total_head_movement=0,initial_pos,n;
    printf("Enter the no of cylinders : ");
    scanf("%d",&n);
    int request_queue[n];
    printf("\n Enter the Cylinder values in Request queue : ");
    for(int i=0;i<n;i++)
    scanf("%d",&request_queue[i]);
    printf("\n Enter the initial value of Read/Write head : ");
    scanf("%d",&initial_pos);

    for(int i=0;i<n;i++)
    {
        total_head_movement += abs(initial_pos - request_queue[i]);
        initial_pos= request_queue[i];
    }

printf("\n The total no of Head movement : %d",total_head_movement);
printf("\n Average head movements : %.2f",(float)total_head_movement/n);
}