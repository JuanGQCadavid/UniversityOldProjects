CXXFLAGS = -g

verificarTres: verificarTres.o tresMayor.o
	g++ $(CXXFLAGS) -o $@ $^
verificarTres.o: verificarTres.cpp tresMayor.h

tresMayor.o: tresMayor.cpp tresMayor.h

clean:
	rm -f *.o
	rm -f verificarTres
