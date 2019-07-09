edit:main.o node_list.o
	cc -o edit main.o node_list.o
main.o:main.c node_list.h
	cc -c main.c
node_list.o:node_list.c node_list.h
	cc -c node_list.c
clean:
	rm -f node_list.o main.o