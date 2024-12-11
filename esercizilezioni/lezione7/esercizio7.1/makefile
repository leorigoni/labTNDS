LL=esercizio7.1.cc
AA=funzioni.h
BB=integrale.h
SS=esercizio7.1
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

$(SS): $(LL) $(AA) $(BB)
	g++ -o $(SS) $(LL) ${LIBS} ${INCS}

clean:
	rm $(SS)