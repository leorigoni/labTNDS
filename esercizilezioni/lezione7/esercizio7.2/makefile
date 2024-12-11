LL=esercizio7.2.cc
AA=funzioni.h
BB=integrale.h
SS=esercizio7.2
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

$(SS): $(LL) $(AA) $(BB)
	g++ -o $(SS) $(LL) ${LIBS} ${INCS}

clean:
	rm $(SS)