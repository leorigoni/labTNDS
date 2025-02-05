LL=esercizio12.0.cc
AA=esperimentoprisma.h
HH=randomgen.h
GG=include.h
DD=utilities.h #inserire utilities_long.h se si vuole l'output completo
SS=esercizio12.0
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

$(SS): $(LL) $(AA) $(HH) $(GG) $(DD)
	g++ -o $(SS) $(LL) ${LIBS} ${INCS}

run: $(SS)
	./$(SS)

clean:
	rm $(SS)