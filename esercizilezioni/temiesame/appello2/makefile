LL=main.cc
AA=include.h
BB=funzione.h
TT=differenziali.h
YY=operators.h
PP=utilities.h
NN=main
LIBS:=`root-config --libs` #necessaria per root
INCS:=`root-config --cflags` #necessaria per root

$(NN): $(LL) $(AA) $(BB) $(TT) $(YY) $(PP)
	g++ -o $(NN) $(LL) ${LIBS} ${INCS}

run: $(NN)
	./$(NN)