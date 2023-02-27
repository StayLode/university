OBJ = compito.o bst.o carta.o 
CXXFLAGS=-Wall

carte_fedelta: $(OBJ)
	g++ -o carte_fedelta $(OBJ)

-include dependencies

.PHONY: clean cleanall depend
depend:
	g++ -MM *.cc > dependencies
clean:
	rm -f *.o
cleanall:
	rm -f carte_fedelta *.o