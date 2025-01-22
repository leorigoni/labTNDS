LL=main.cc
AA=condensiamo.h
HH=randomgen.h
GG=include.h
DD=utilities.h
SS=main
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

$(SS): $(LL) $(AA) $(HH) $(GG) $(DD)
	g++ -o $(SS) $(LL) ${LIBS} ${INCS}

run: $(SS)
	./$(SS)