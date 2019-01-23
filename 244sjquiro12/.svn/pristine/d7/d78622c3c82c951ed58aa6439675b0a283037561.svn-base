
all:evaluacioncompleja

evaluacioncompleja: evaluacioncompleja.o complejo.o
	$(CXX) -o $@ $^

evaluacioncompleja.o: evaluacioncompleja.cpp complejo.h

complejo.o: complejo.cpp complejo.h

clean:
	rm -f *.*~ *.o
	rm -f evaluacioncompleja
