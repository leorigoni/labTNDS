LL=esercizio10.0.cc
AA=randomgen.h
SS=esercizio10.0
LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

$(SS): $(LL) $(AA)
	g++ -o $(SS) $(LL) ${LIBS} ${INCS}

clean:
	rm $(SS)

cleanall:
	rm $(SS) grafico.pdf