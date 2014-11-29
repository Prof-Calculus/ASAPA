#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
node *newNode(void);

char *INTEGER = "Integer";
char *REAL = "Real";
char *STRING = "String";
char *FUNCTION = "Function";

node *newIntegerNode(char *name,  int length, int v)
{
	node *p = newNode();
	p->type = INTEGER;
	p->ival = v;
	int i = 0;
	while(i < length)
	{	
		p->chld[i] = ' ';
		p->var_name[i] = name[i++];
	}
	p->var_name[i] = '\0';
	p->next = NULL;
	p->display = &print;
	return p;
}

node *newRealNode(char *name, int length, double v)
{
	node *p = newNode();
	p->type = REAL;
	p->rval = v;
	int i = 0;
	while(i < length)
	{
		p->chld[i] = ' ';
		(p->var_name)[i] = name[i++];
	}
	p->display = &print;
	p->next = NULL;
	return p;
}

node *newFunctionNode(char *name, int length)
{
	node *p = newNode();
	p->type = FUNCTION;
	p->next = NULL;
	int i = 0;
	while(i < length)
	{
		p->chld[i] = ' ';
		(p->var_name)[i] = name[i++];
	}
	p->display = &print;
	return p;
}

node *newStringNode(char *name, int length , char *v)
{
	node *p = newNode();
	p->type = STRING;
	p->sval = v;
	int i = 0;
	while(i < length)
		(p->var_name)[i] = name[i++];
	p->display = &print;
	p->next = NULL;
	return p;
}

node *
newNode()
{
	node *n = (node *) malloc(sizeof(node));
	if (n == 0) { fprintf(stderr,"out of memory"); exit(-1); }
	return n;
}
int print(struct nodeobject* node1)
{
	if(node1 -> type == INTEGER)
		printf("%d",node1 -> ival);
	else if(node1 -> type == REAL)
		printf("%f",node1 -> rval);
	else if(node1 -> type == STRING)
		printf("%s",node1 -> sval);
	else if(node1 -> type != FUNCTION)
		printf("NODE INCORRECT\n");
	return 0;
}
