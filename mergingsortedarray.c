//program to merge 2 sorted array
#include<stdio.h>

int main(){
int i=0,j=0,k=0,n1,n2,a[10],b[10],c[30];
printf("Enter size of 1st array: ");
scanf("%d",&n1);
printf("\nEnter array Elements: ");
for( i;i<n1;i++){
scanf("%d",&a[i]);	
}
printf("Enter size of 2nd array: ");
scanf("%d",&n2);
printf("\nEnter  array Elements: ");
for( j;j<n2;j++){
	scanf("%d",&b[j]);	
}
i=0;
j=0;
while(i<n1 && j<n2)	{
	if(a[i]<b[j]){
		c[k]=a[i]; 
		i++;
	}else if(a[i]>b[j]){
		c[k]=b[j];
		j++;
	}else{
		c[k]=b[j];
		j++;i++;
	}
	k++;
}

while(i<n1){
	c[k]=a[i];
	i++;k++;
}
while(j<n2){
	c[k]=b[j];
	j++;k++;
}
	printf("--Array sorted--\n");
    for(i=0;i<k;i++){
	printf("%d\n",c[i]);
}
	return 0;
}
