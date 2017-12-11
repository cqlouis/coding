#include <stdio.h>

typedef void (*p)();

void callback1()
{
	int i;
	for(i = 0; i < 10; i++)
		printf(" %d \n", i);
}

void callback2()
{
	printf("callback 2 \n");
}

void mediator(p function )
{
	function();
}

void main()
{
	mediator(callback1);
	mediator(callback2);
}



