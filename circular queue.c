#include <stdio.h>
int a[10],f=-1,r=-1,size=4,v;
void insert(){

    if((r+1)%size == f){
        printf("Overflow");
    }else{
printf("enter the value:");
            scanf("%d",&v);
        if(f==-1 && r==-1){
            f=0;
            r=0;
            a[r]=v;
        }else{
            r=(r+1)%size;
            a[r]=v;
        }
    }
}
void deeq(){
    if(f==-1){
        printf("Underflow");
    }else{
        if(f==r){
            f=-1;
            r=-1;
        }else if(f == size-1){
            f=0;
        }else{
            f= f+1;
        }
    }
}
void display(){
    int i,c=0 ;
    i = f;
    if(f==-1 && r==-1){
        printf("queue is empty");
    }else{
	printf("\nqueue :");
        while(i>-1 ){
            printf("%d",a[i]);
	if(i==r){
		break;		
		}
            i = (i+1)%size;
            
        }
    }
}
int main() {
    int op;// Write C code here
   do{ 
      /* printf("\nChecking array:");
   for(int i=0;i<size;i++){
       printf("%d \t",a[i]);
   }*/
    printf("\n\nEnter the option:\n1.insert\n2.delete\n3.display \n");
    scanf("%d",&op);
    switch(op) {
  case 1:
            
          insert();
    // code block
    break;
  case 2:deeq();
    // code block
    break;
  case 3:display();
     break;
    // code block
}}while(op !=0);

}