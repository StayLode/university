OBJ = compito.o liste.o tipo.o

inverted_index: $(OBJ)
	g++ -o inverted_index $(OBJ)	

.PHONY: clean cleanall
clean:
	rm -f *.o
cleanall:
	rm -f inverted_index *.o