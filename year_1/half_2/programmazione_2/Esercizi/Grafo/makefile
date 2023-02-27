OBJ = main.o grafo.o coda-bfs.o 
CXXFLAGS=-Wall

final-grafo: $(OBJ)
	g++ -o final-grafo $(OBJ)

-include dependencies

.PHONY: clean cleanall
depend:
	g++ -MM *.cc > dependencies
clean:
	rm -f *.o
cleanall:
	rm -f final-grafo *.o

