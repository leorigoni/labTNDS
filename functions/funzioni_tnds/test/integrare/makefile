LL=main.cc
AA=include.h
BB=funzione.h
TT=integra.h
NN=main
LIBS:=`root-config --libs` #necessaria per root
INCS:=`root-config --cflags` #necessaria per root

$(NN): $(LL) $(AA) $(BB) $(TT)
	g++ -o $(NN) $(LL) ${LIBS} ${INCS}

run: $(NN)
	./$(NN)