#_*_ MakeFile _*_

default: compilation1
	gcc -m32  P4_1.c P4_1.o 
	./a.out  # 1+2+3+4
	gcc P4_2.c P4_2.o
	./a.out  #5+6+7+8
compilation1:
	nasm -felf32 P4_1.asm
	nasm -felf64 P4_2.asm

