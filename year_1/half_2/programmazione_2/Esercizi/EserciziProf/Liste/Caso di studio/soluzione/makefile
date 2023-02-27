OBJ = main.o liste.o tipo.o

inverted-index: $(OBJ)
	g++ -o inverted-index $(OBJ)

main.o: tipo.h liste.h parola.h

liste.o: tipo.h liste.h

tipo.o: tipo.h

.PHONY: clean cleanall
clean:
	rm -f *.o
cleanall:
	rm -f Web-list *.o