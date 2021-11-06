all:app.out
cc=gcc
objs=1.o 2.o root.o

app.out: $(objs)
	$(cc) -o app.out 1.o 2.o root.o

root.o:
	$(cc) -c root.c
1.o:
	$(cc) -c 1.c
2.o:
	$(cc) -c 2.c

clean : 
	rm edit root.o 1.o 2.o