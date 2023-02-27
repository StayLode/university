OBJ = main.o albero.o stringa.o

albero: $(OBJ)
	g++ -o albero $(OBJ)

-include dipendenze


.PHONY: clean cleanall dipendenze
clean:
	rm -f *.o
cleanall:
	rm -f Web-list dipendenze *.o
dipendenze:
	g++ -MM *.cc > dipendenze

