LL=esercizio11.2.cc
AA=funzione.h
BB=integrale.h
HH=randomgen.h
SS=esercizio11.2
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

$(SS): $(LL) $(AA) $(BB) $(HH)
	g++ -o $(SS) $(LL) ${LIBS} ${INCS}

clean:
	rm $(SS)