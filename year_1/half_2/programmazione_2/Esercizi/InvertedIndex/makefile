OBJ = compito.o liste.o tipo.o
CXXFLAGS=-Wall

Inverted-index: $(OBJ)
	g++ -o Inverted-index $(OBJ)

-include dependencies

.PHONY: clean cleanall
depend:
	g++ -MM *.cc > dependencies
clean:
	rm -f *.o
cleanall:
	rm -f Inverted-index *.o

