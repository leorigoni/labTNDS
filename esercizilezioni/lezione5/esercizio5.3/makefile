LL=esercizio5.3.cc
AA=posizione.h
BB=particella.h
TT=campovettoriale.h
NN=puntomateriale.h
SS=esercizio5.3
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

$(SS): $(LL) $(AA) $(BB) $(TT) $(NN)
	g++ -o $(SS) $(LL) ${INCS} ${LIBS}

clean:
	rm $(SS)