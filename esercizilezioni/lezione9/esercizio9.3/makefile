LL=esercizio9.3.cc
AA=funzione.h
BB=operators.h
TT=differenziale.h
NN=utilities.h
SS=esercizio9.3
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

$(SS): $(LL) $(AA) $(BB) $(TT) $(NN)
	g++ -o $(SS) $(LL) ${LIBS} ${INCS}

clean:
	rm $(SS)

cleanall:
	rm $(SS) grafico.pdf