LL=esercizio11.2.cc
AA=funzione.h
BB=integrale.h
HH=randomgen.h
YY=utilities.h
SS=esercizio11.2
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

$(SS): $(LL) $(AA) $(BB) $(HH) $(YY)
	g++ -o $(SS) $(LL) ${LIBS} ${INCS}

clean:
	rm data.txt

cleanall:
	rm $(SS) data.txt