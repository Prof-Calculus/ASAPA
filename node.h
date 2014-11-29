typedef struct nodeobject
{
	char *type;
	int ival;
	double rval;
	char *sval;
	char var_name[150];
	char chld[150];
	int (*display)(struct nodeobject*);
	struct nodeobject *next;
	struct nodeobject *child;
}node;

extern char *INTEGER;
extern char *REAL;
extern char *STRING;

extern node *newIntegerNode(char *name, int length, int value);
extern node *newRealNode(char *name, int length, double value);
extern node *newStringNode(char *name, int length, char *value);
extern node *newFunctionNode(char *name, int length);
int print(struct nodeobject* node1);
