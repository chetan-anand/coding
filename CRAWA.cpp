#include<btis/stdc++.h>
using namespace std;

int main() {

	int x , y , t;
		scanf("%d",&t);
		while(t--)
			{scanf("%d %d",&x,&y);

			if(y%2==0)
				{
					if(y>0)
						{	if(x<y && y+x>=0) { printf("YES\n");continue;}
							else if(x>0)
									{	 if(x%2) printf("YES\n");
										else printf("NO\n");
										continue;
									}
							else
									{
										if(x%2==0 ) printf("YES\n");
										else printf("NO\n");
										continue;
									}
						}
					else if(y<=0)
							{
								if(x>=y && x<2-y)	{ printf("YES\n");continue;}
								else if(x>0) {if(x%2) printf("YES\n");
												else printf("NO\n");
												continue;  }
									else if(x<0)	{ if(x%2==0) printf("YES\n");
														else printf("NO\n");
													continue;  }
							}
				}
			else
				{if(y>0)
						{
							if(x>0)
									{	 if(x%2 && x>=y) printf("YES\n");
										else printf("NO\n");
										continue;
									}
							else
									{
										if(x%2==0 && y+x <0) printf("YES\n");
										else printf("NO\n");
										continue;
									}
						}
				else {

						if(x>0)
									{	 if(x%2 && x+y>0) printf("YES\n");
										else printf("NO\n");
										continue;
									}
							else
									{
										if(x%2==0 && x-y <0) printf("YES\n");
										else printf("NO\n");
										continue;
									}
						}


				}
			}

	// your code goes here
	return 0;
}
