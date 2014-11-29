#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "node.h"

node *START = NULL, *STOP = NULL;
node2 *STACK = NULL;

node* data_type(char word[])
{
	node *p = START;
	while(p != NULL && strcmp(p->var_name, word))
	{
		p = p->next;		
	}
	return p;
}

void string_copy(char *a, char *b, int i)
{
	char temp[100];
	temp[0] = b[i];
	strcpy(a,temp);
}

int operate_value(char line[], int length)
{
	
	return 1;
}

int private_functions(FILE *fp, char line[], int length)
{
	fgets(line, length, fp);
	if(STACK == NULL)
	{
		STACK-> start_ptr = START;
		START = NULL;
	}
	else
	{
		node2* temp;
		//malloc
		temp -> start_ptr = START;
		temp -> prev_node = STACK;
		STACK = temp;
		START = NULL;
	}
	char *arguments = (char*) malloc(sizeof(char) * (length));
	int i = 0, j = 0;
	while(i < length && line[i] == '(')
		i++;
		
	while(line[i] != ')')
		arguments[j++] = line[i++];
	
	while(line != '}')
	{
		if( // come across the same function,
		// Call this function again
		
		// call identify line ..
	}
	node2* temp = STACK;
	STACK = STACK -> prev_node;
	free(temp);
	return 1;
}

int assign_value(char line[], int length)
{
	char *vals = (char*) malloc(sizeof(char) * (length));
	char *name = (char*) malloc(sizeof(char) * (150));;
	int i = 0;
	while(i < length && line[i] != ' ' && line[i] != '=' )
		name[i] = line[i++];
	name[i] = '\0';	
	while(line[i] == ' ')
		i++;
	if(line[i] == '=')
	{
		i++;
		while(line[i] == ' ')
			i++;
	}	
	node *p = data_type(name);
	if( line[i] == '\"' )
	{
		int g = 0;
		i++;
		while(i < length && line[i] != '\"')
			vals[g++] = line[i++];
		vals[g] = '\0';
		
		if(p == NULL)
			p = newStringNode(name, strlen(name), vals);
		else
			strcpy(p->sval, vals);
	}
	else
	{
		int j = i, fl = 0;
		while(j < length)
		{
			if(line[j] == '.')
				fl = 1;
			j++;
		}
		j = 0;
		while(i < length)
		{
			vals[j++] = line[i++];
		}
		vals[j] = '\0';
		if(fl == 0)	
		{
			if(p == NULL)
				p = newIntegerNode(name, strlen(name), atoi(vals));
			else
				p->ival = atoi(vals);
		}
		else
		{
			if(p == NULL)
				p = newRealNode(name, strlen(name), atof(vals));
			else
				p->rval = atof(vals);
		}
	}
	p->next = NULL;
	if(START == NULL)
	{
		START = p;
		STOP = START;
	}
	else
	{
		STOP -> next = p;
		STOP = STOP -> next;
	}
	
	return 1;
}

void delete(node *data)
{
	node* temp = NULL;
	while(data != NULL)
	{
		if(data->next != NULL)
			printf("lp\n");
		temp = data->next;
		if(data != NULL)
			free(data);
		data = temp;
	}
	//free(temp);	   
}


void memory_of_variables(char line[], int length)
{
	node *p, *temp1;
   	char c;
   	char *word;
   	word = (char *) malloc(sizeof(char) * 100); 
   	int i = 3, count1 = 0; 

   	temp1 = START;
   	while(temp1->next != NULL)
 		temp1 = temp1 -> next;
   	
   	while( i < length)
  	{
   		c = line[i];
   		if( c != ',' && c != '\n')
   			word[count1++] = c;   								
   		else
   		{
   			if( line[0] == 'i' && line[1] == 'n')
   				p = newIntegerNode(word, count1, 0);
		   	else if( line[0] == 'f' && line[1] == 'l' )
   				p = newRealNode(word, count1, 0.0);
   			else if( line[0] == 'c' && line[1] == 'h' )
	   			p = newStringNode(word, count1,"ok"); 
   			else if( line[0] == '(' && line[1] == ')' )
   				p = newFunctionNode(word, count1);	
   			if(START == NULL)
			{
				START = p;
				STOP = START;
			}
			else
			{
				STOP -> next = p;
				STOP = STOP -> next;
			}
			count1 = 0;
			free(word);
			word = (char *) malloc(sizeof(char) * 100); 
		}
		i++;
	}
	/*	if(c == '}')
   		{
   			store_START->child = START;
   			START = store_START;
   			store_START = NULL;
   			starting = 0;
   			open = 0;
   		}
   		if(c == '{')
   		{
   			store_START = START;
   			START = NULL;
   			starting = 1;
   			open = 1;
   		}*/
   //	printf("\n");
   	return ;
}		


int input_line(char line[], int length)
{
	
	char *name = (char *) malloc(sizeof(char) * (strlen(line))); ;

		int i = 3;
		while(i < (strlen(line) - 1) && line[i] != '\n')
		{
			name[i-3] = line[i];
			++i;
		}
		
	char input[400];
	int len;
	
	scanf("%s",input,400);
	len=strlen(input);
	
	char *new_str = (char *) malloc(sizeof(char) * len); 
	
	node *rgh;
	rgh = data_type(name);	
	
	if(input[0] == '\"')
	{
		rgh->sval = (char *) malloc(sizeof(char) * (len - 1));
		for (i=1;i<len-1;i++)
		{	
			rgh->sval[i-1] = input[i];
		}
		rgh->sval[i] = '\0';
	}
	else 
	{
		strcpy(new_str, input);
		
		int floating = 0;
		for (i=0;i<strlen(input);i++)
			if(input[i] == '.')
				floating = 1;
				
		if(floating == 0)
		{
			int val = atoi( new_str );
			rgh->ival = val;
		}
		else
		{
			float val = atof( new_str );
			rgh->rval = val;	
		}
	}
	//assign_value(rgh->var_name);
	free(new_str);
	return 1;
}


int output_line(char line[], int length)
{
	// The correct print syntax is :
	// <- Hello welcome to ASAPA. Value of a is \: @ (a is already defined): a
	
	//Equivalent C syntax is (assuming a is integer) :
	// printf("Hello welcome to ASAPA. Value of a is : %d (a is already defined)",a);
	
	int i, count = 0, j;
	
	char *words = (char*) malloc(sizeof(char) * (length));
	
	i = 3;
	//Loop to position i at the place where the variables to be printed are written
	while( i < length-1)
	{	
		if(line[i] == ':' && line[i-1] != '\\')
			break;
		i++;
	}
	i++;
	j = 0;
	//Loop to write the variables to be written in a list of strings
	for(;i < length-1; ++i)
	{
		if(line[i] == '\n')
		{
			words[j] = '\0';
			j = 0;
		}
		else
			words[j++] = line[i];
	}
	
	count = 0;
	for(i = 3; (i < length) ; ++i)
	{
		if(line[i] == '@' && line[i-1] != '\\') //printing a variable
		{
			node *c = data_type(words);
			print(c);
		}	
		else if(( line[i] == ':' ) && (line[i-1] != '\\'))//Coming out of the loop
		{
			//printf("\n"); // you temme : do you want a print statement to end in \n automatically ??
			break;
		} 
		else if(( line[i] == ':' ) && (line[i-1] == '\\'))
		{
			printf("%c",line[i]);
		} 
		else if(( line[i] == 'n' ) && (line[i-1] == '\\'))
		{
			printf("\n");
		} 		
		else if(( line[i] == 't' ) && (line[i-1] == '\\'))
		{
			printf("\t");
		} 			
		else if(line[i] != '\\')
			printf("%c",line[i]);
	}
	free(words);
	return 1;
}


int identify_line(char line[], int length, char *filename)
{
	char word[500];
	int i = 0, j = 0, eq = 0, op = 0;
	while(i < 500 && line[i] != ' ')
	{
		if(line[i] == '=')
			eq = 1;
		else if(line[i] == '+' || line[i] == '*' || line[i] == '-' || line[i] == '/')
			op = 1;
		word[i] = line[i++];
		
	}
	j = i;
	while(j < length && eq == 0)
	{
		if(line[j] == '=')
			eq = 1;
		else if(line[j] == '+' || line[j] == '*' || line[j] == '-' || line[j] == '/')
			op = 1;
		j++;
	}
	word[i] = '\0';
			
	if(strcmp(word,"in") == 0 || strcmp(word,"ch") == 0 || strcmp(word,"fl") == 0)
	{
		memory_of_variables(line, length);
		return 1;
	}
	else if(line[0] == '<' && line[1] == '-' && line[2] == ' ')
	{
		if(output_line(line, length) == 1)
			return 1;
	}
	else if(line[0] == '-' && line[1] == '>'&& line[2] == ' ')
	{
		if(input_line(line, length) == 1)
			return 1;		
	}
	else if(eq == 1 && op == 0)
	{
		if(assign_value(line, length) == 1)
			return 1;
	}
	else if(op == 0)
	{
		if(operate_value(line, length) == 1)
			return 1;
	}	
	else if(evaluate_functions(filename, word))
	{
		return 1;
	}
	return 0;
}

int execute_program(char filename[])
{
	int line_length = 500, line_count = 0;
	
	FILE *fp;
    	fp = fopen(filename,"r"); // read mode
 
   	if( fp == NULL )
   	{
      		printf("Error while opening the file.\n");
      		return 0;
   	}
   	
   	char *line;
   	line = (char*) malloc(sizeof(char) * line_length);
   	int j = 0;
   	fgets(line, line_length, fp);
   	
	while (!feof(fp))
	{
		//if(line[0] == '{')
		//	while(line[0] == '}')
		//		fgets(line, line_length, fp);
		
		//fgets(line, line_length, fp);	
		if(identify_line(line, strlen(line), filename) == 0)
    		{
			printf("ERROR: Unable to identify line : %d\n",line_count+1);
			//return 0;
		}
		else
			line_count++;
		++j;
		fgets(line, line_length, fp);
	}	
	delete(START);
	return 1;	
}
	
int evaluate_functions(char filename[], char fn_name[])
{
	 /*
	This is to evaluate functions in our asapa. It works like this
	When you come across a function name, you store the function name in fn_name. Then you reopen the entire code and then start reading from the beginning till the line which starts with def.
	If the word that follows the "def" is same as the function name, what you do is call a function called execute_line or execute_loop ( take a look at the pre-defined function execute program, to get an idea of how it should be done.
	Do this from the start of the open-parenthesis "{" till the close-parenthesis "}".
	Put that in a loop. 
	Test your code by you yourself writing a main function and checking whether it is executing the lines. write normal print statements in your function.
	I will take care of the return statement as well as assigning values to the arguments.
	Just see to it that it identifies all the lines defined within braces.
		
	I will take care of managing the argument values and the return value.
	
	Identify all the lines till you encounter a close brace.
	*/
	int line_length=300;
	char *line;
	line = (char*) malloc(sizeof(char) * line_length);
	
	char a[1000],b[1000];
	FILE * inp;
	inp=fopen(filename,"r");
	fgets(a, 1000, inp);
	
	while(!(feof(inp)))
	{
		if(feof(inp))
			break;

		else
		{
			char str[] = "def";
			strcat(str," ");
			strcat(str,fn_name);
			if(!strcmp(a,str))
			{
				fscanf(inp,"%s",b);//scans "{" and keeps it apart.
				fgets(a, 1000, inp);
				while(strcmp(a,"}"))
				{
					identify_line(a, strlen(line), filename);
					fgets(a, 1000, inp);
					if(strcmp(a,"}"))
						break;
				}
			}
			else
				fscanf(inp,"%s",a);	
		}
	}
}

int main(int argc, char*argv[])
{ 
	if(argc != 2)
	{
		printf("ERROR: Invalid command line arguments\n");
		return -1;
	}
	execute_program(argv[1]);	
	return 1;
}
