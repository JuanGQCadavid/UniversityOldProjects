all: incrementarfactor

incrementarfactor: incrementarfactor.o incrementar.o
	$(CXX) -o $@ $^

incrementarfactor.o: incrementarfactor.cpp incrementar.h

incrementar.o: incrementar.cpp incrementar.h
