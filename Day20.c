#include<stdio.h>
int main(){
int n;
printf("Enter n:");
scanf("%d",&n);
int a[n];
printf("Enter elements:");
for(int i=0;i<n;i++){
scanf("%d",&a[i]);
}
int count=0;
for(int i=0;i<n;i++){
int sum=0;
for(int j=i;j<n;j++){
sum=sum+a[j];
if(sum==0){
count++;
}
}
}
printf("Count=%d",count);
return 0;
}