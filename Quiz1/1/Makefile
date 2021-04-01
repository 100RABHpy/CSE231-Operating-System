#_*_ MakeFile _*_

default: compilation1
	ld -e _s checkGreater.o
	./a.out #x=10,y=20 standalone Assembly
	gcc checkGreaterC.c checkGreater.o
	./a.out #x=10,y=6 c program
compilation1:
	nasm -felf64 checkGreater.asm


