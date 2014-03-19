#include<stdio.h>

int main()
{
	char a[100];
	char b[100];
	/*scanf("%s",a);
	scanf("%s",b);*/
	char ch;
	FILE *ptr,*wptr;
	ptr=fopen("input.txt","r");
	wptr=fappend("output.txt","w+");
	
	while(ch!=EOF)
	{
		ch=fgetc(ptr);

		fputc(ch,wptr);
	}
	fclose(wptr);
	fclose(ptr);
	return 0;
}
