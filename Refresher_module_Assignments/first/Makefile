#_*_ MakeFile _*_


first: first.o
	gcc first.o -o first
	./first
first.o: first.s
	gcc -c first.s 
first.s: first.i
	gcc -S first.i 
first.i:first.c
	gcc -E first.c -o first.i