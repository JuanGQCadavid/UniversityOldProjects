all: fraccionesclases

fraccionesclases: fraccionesclases.o fraccion.o unidad.o
	$(CXX) -o $@ $^

fraccionesclases.o: fraccionesclases.cpp fraccion.h unidad.h

fraccion.o: fraccion.cpp fraccion.h

unidad.o: unidad.cpp unidad.h

clean:
	rm -f *.o *.*~ *~
	rm -f fraccionesclases
