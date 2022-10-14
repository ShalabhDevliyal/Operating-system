#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct process_struct{
    int pid,at,bt;
    int start_time,remi;
    int tat,wt,rt,ct;
}ps[100];

int compartator(const void *p,const void *q){
    int l=((struct process_struct *)p)->at;
    int r=((struct process_struct *)q)->at;
    
    int c=((struct process_struct *)p)->pid;
    int d=((struct process_struct *)q)->pid;
    if(l==r){
        return (c-d);
    }
    return (l-r);
}

int findmax(int a,int b){
    return a>b?a:b;
}

int main(){
    int n;
    printf("ENTER THE NUMBER OF PROCESSES   ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("ENTER THE ARRIVAL TIME OF PROCESS ");
        scanf("%d",&ps[i].at);
        ps[i].pid=i+1;
    }
    for(int i=0;i<n;i++){
        printf("ENTER THE BURST TIME OF PROCESS    ");
        scanf("%d",&ps[i].bt);
        ps[i].remi=ps[i].bt;
    }
    int tq;
    printf("ENTER THE TIME QUANTUM  ");
    scanf("%d",&tq);
    bool visited[100]={false};
    
    int current_time=0,completed=0;
    int queue[100],front=-1,rear=-1;
    
    qsort((void*)ps , n, sizeof ps[0], compartator);

    front=rear=0;
    queue[rear]=0;
    visited[0]=true;
    int index;
    
    while(completed!=n){
        index=queue[front];
        front++;
        if(ps[index].remi==ps[index].bt){
            ps[index].start_time=findmax(current_time,ps[index].at);
            current_time=ps[index].start_time;
        }
        if(ps[index].remi-tq > 0){
            ps[index].remi-=tq;
            current_time+=tq;
        }
        else{
            current_time += ps[index].remi;
            ps[index].remi=0;
            completed++;
            ps[index].ct=current_time;
            ps[index].tat=ps[index].ct - ps[index].at;
            ps[index].wt=ps[index].tat - ps[index].bt;
            ps[index].rt=ps[index].start_time - ps[index].at;
        }
        for(int i=1;i<n;i++){
            if(ps[i].remi > 0 && ps[i].at<=current_time && visited[i]==false){
                queue[++rear]=i;
                visited[i]=true;
            }
        }
        if(ps[index].remi > 0){
            queue[++rear]=index;
        }
        if(front>rear){
            for(int i=1;i<n;i++){
                if(ps[i].remi>0){
                    queue[rear++]=i;
                    visited[i]=true;
                    break;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
        printf("%d   %d   %d   %d   %d   %d   %d   %d\n",ps[i].pid,ps[i].at,ps[i].bt,ps[i].start_time,ps[i].ct,ps[i].tat,ps[i].wt,ps[i].rt);
    
}
