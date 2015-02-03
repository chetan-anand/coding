#include<stdio.h>
#include<math.h>
#define pi 3.14
void menu()
{
    printf("\nSelect yor choice \n");
	printf("1. Area of circle  \n");
	printf("2.  \n");

	printf("3. Exit \n");
}
void AreaCircle()
{
    float r;
    printf("Enter the radius of circle ");
    scanf("%f",&r);
    float area;
    area=pi*r*r;
    printf("Area of circle is %f\n",area);

}
int main()

{
	char n;

	 do
	 {
	 menu();
	 scanf("%c",&n);

	 switch(n)
	 {

	 	case '1':
	 		AreaCircle();
	 			break;

	    case'2':

	    	break;
	    default :
	   	printf("Exit");


	 }
       }
      while(n!='3');

  return 0;

}
