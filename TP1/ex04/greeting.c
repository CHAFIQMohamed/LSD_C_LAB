#include<stdio.h>
#include<stdlib.h>

void english()
{
	printf("hello");
}
void arabic()
{
	printf("salam");
}
void frensh()
{
	printf("salut");
}
int main()
{

	void (*greeting[])()={english,arabic,frensh};
	unsigned int i;
        printf("Enter Choice: 0 for english, 1 for arabic and 2 for frensh ");
	scanf("%d",&i);
 
	if (i > 2) return 0;
  
        (*greeting[i])(); 
	return 0;
	
}
