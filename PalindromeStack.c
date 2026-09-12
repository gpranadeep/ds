#include <stdio.h>
#include <string.h>
int main(){
	printf("Enter a String : ");
	char str[100];
	scanf("%s",str);
	int top=strlen(str)-1;
	int pal=0;
	for(int i=0;i<=strlen(str)/2;i++){
		if(str[top]!=str[i]){
			pal=1;
			break;
		}
		top--;
	}
	if (pal==0){
		printf("%s is palindrome",str);
	}
	else{
		printf("%s is not palindrome",str);
	}
	return 0;
	
}