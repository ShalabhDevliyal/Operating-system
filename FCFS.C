#include<stdio.h>
struct process_struct{
	int at,bt;
	int ct,tat,wt,rt;
	int pid;
}ps[10];
int main(){
	int n;
	printf("ENTER THE NUMBER OF PROCESSES");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("ENTER THE ARRIVAL TIME OF PROCESS %d 	",i);
		scanf("%d",&ps[i].at);
		ps[i].pid=i;
	}
	for(int i=0;i<n;i++){
		printf("ENTER THE BURST TIME OF PROCESS %d		",i);
		scanf("%d",&ps[i].bt);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(ps[i].at>ps[j].at){
				struct process_struct temp=ps[i];
				ps[i]=ps[j];
				ps[j]=temp;
			}
		}
	}
	ps[0].ct=ps[0].at+ps[0].bt;
	ps[0].tat=ps[0].ct-ps[0].at;
	ps[0].wt=0;
	ps[0].rt=0;
	for(int i=1;i<n;i++){
		if(ps[i].at>ps[i-1].ct){
			ps[i].ct=ps[i].bt+ps[i].at;
		}
		else{
			ps[i].ct=ps[i-1].ct+ps[i].bt;
		}
		ps[i].tat=ps[i].ct-ps[i].at;
		ps[i].wt=ps[i].tat-ps[i].bt;
		ps[i].rt=ps[i].wt;
	}
	printf("OUTPUT\n");
	for(int i=0;i<n;i++){
    	printf("proces %d \t  AT %d \t BT %d \t CT %d \t WT %d \t TAT %d \t RT %d \t\n",ps[i].pid,ps[i].at,ps[i].bt,ps[i].ct,ps[i].wt,ps[i].tat,ps[i].rt);
	}
	
	return 0;
}
