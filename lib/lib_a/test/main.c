#include<stdio.h>
#include "sub.h"
#include "add.h"

int main()
{
	int x = 100;
	int y = 200;
	int z = Sub(x,y);
	int f = Add(x,y);
	printf("%d,%d\n",z,f);
}
