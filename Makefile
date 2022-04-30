
AsciiArtTool: RLEList.o AsciiArtTool.o main.o
	gcc RLEList.o AsciiArtTool.o main.o -o AsciiArtTool

RLEList.o: RLEList.c RLEList.h
	gcc -c RLEList.c

AsciiArtTool.o: AsciiArtTool.c AsciiArtTool.h RLEList.c RLEList.h
	gcc -c AsciiArtTool.c

main.o: main.c AsciiArtTool.c AsciiArtTool.h RLEList.c RLEList.h
	gcc -c main.c
