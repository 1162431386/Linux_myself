edit:main.o sequence_list.o
	cc -o edit main.o sequence_list.o
main.o:main.c sequence_list.h
	cc -c main.c
node_list.o:sequence_list.c sequence_list.h
	cc -c sequence_list.c
clean:
	rm -f sequence_list.o main.o