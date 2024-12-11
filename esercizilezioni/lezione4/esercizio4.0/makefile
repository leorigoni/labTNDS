LL=esercizio4.0.cc
AA=funzioni.h
BB=esercizio4.0
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esercizio3.2: $(LL) $(AA)
	g++ -o $(BB) $(LL) ${INCS} ${LIBS}

clean:
	rm  out/*out.txt

cleanall:
	rm esercizio4.0 
