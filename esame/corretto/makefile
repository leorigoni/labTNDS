LL=main.cc
AA=includes.h
BB=funzione.h
TT=cercazeri.h
NN=integrazione.h
DD=randomgen.h
SS=montecarlo.h
OO=main
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

$(OO): $(LL) $(AA) $(BB) $(TT) $(NN) $(DD) $(SS)
	g++ -o $(OO) $(LL) ${LIBS} ${INCS}

run: $(OO)
	./$(OO)

clean: $(OO)
	rm $(OO)