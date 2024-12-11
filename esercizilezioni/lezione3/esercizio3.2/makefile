LL=esercizio3.2.cc
AA=funzioni.h
BB=esercizio3.2
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`
LDFLAGS=-Wl,-rpath,/usr/lib/x86_64-linux-gnu

esercizio3.2: $(LL) $(AA)
	g++ -o $(BB) $(LL) ${INCS} ${LIBS} ${LDFLAGS}

clean:
	rm esercizio3.2
