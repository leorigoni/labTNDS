LL=main.cc
AA=include.h
BB=funzione.h
TT=integrazione.h
SS=main
LIBS:=`root-config --libs` #necessaria per root
INCS:=`root-config --cflags` #necessaria per root

$(SS): $(LL) $(AA) $(BB) $(TT)
	g++ -o $(SS) $(LL) ${LIBS} ${INCS}

run: $(SS)
	./$(SS)

clean:
	rm $(SS)