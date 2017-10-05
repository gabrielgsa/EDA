INC_DIR		=	/usr/include/SDL2
LIB_DIR		=	/usr/lib
LINK_LIBS 	=	-lSDL2 -lSDL2_ttf -lSDL2_mixer -lSDL2_image
.c.o:   $*.h
	@echo "Compilando codigo C => " $@
	gcc -c -Wall -I$(INC_DIR) $*.c

.cpp.o:	$*.h
	@echo "Compilando codigo C++ => " $@
	g++	-c -Wall -I$(INC_DIR) $*.cpp

all:	0-helloWorld 1-helloWorldGames 2-variaveis

0-helloWorld: 0-helloWorld.o
	@echo "Linkando " $@
	g++ -o $@ $^ -L$(LIB_DIR) $(LINK_LIBS)

1-helloWorldGames: 1-helloWorldGames.o
	@echo "Linkando " $@
	g++ -o $@ $^ -L$(LIB_DIR) $(LINK_LIBS)

2-variaveis: 2-variaveis.o
	@echo "Linkando " $@
	g++ -o $@ $^ -L$(LIB_DIR) $(LINK_LIBS)


clean:
	@echo "Limpando o diretorio..."
	rm *.o *.*~ *~ 0-helloWorld

mensagem:
	@echo "teste de mensagem no Makefile"