prog : asapa
	gcc asapa.c node.c node.h -o asapa

clean :
	rm util.o life.o 
