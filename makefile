
AsciiArtTool: RLEList.o AsciiArtTool.o main.o
	gcc RLEList.o AsciiArtTool.o main.o -o AsciiArtTool

RLEList.o: RLEList.c RLEList.h
	gcc -c RLEList.c

AsciiArtTool.o: AsciiArtTool.c AsciiArtTool.h 
	gcc -c AsciiArtTool.c

main.o: calc.h control.h
	gcc -c main.c
