LL=esercizio12.0.cc
AA=esperimentoprisma.h
HH=randomgen.h
GG=include.h
DD=utilities.h
SS=esercizio12.0
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

$(SS): $(LL) $(AA) $(HH) $(GG) $(DD)
	g++ -o $(SS) $(LL) ${LIBS} ${INCS}

clean:
	rm $(SS)