csv2svg:   csv2svg.o
	   gcc -o csv2svg csv2svg.o
csv2svg.o: csv2svg.c
	   gcc -c csv2svg.c 
