LL=esercizio8.1.cc
AA=funzione.h
BB=operators.h
TT=eulero.h
NN=utilities.h
SS=esercizio8.1
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

$(SS): $(LL) $(AA) $(BB) $(TT) $(NN)
	g++ -o $(SS) $(LL) ${LIBS} ${INCS}

clean:
	rm $(SS)

cleanall:
	rm $(SS) grafico.pdf