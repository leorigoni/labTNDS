LL=funzioni.cc #funzioni.cc is the file that contains the main function
AA=qualsiasi.h #qualsiasi.h is the file that contains the function prototypes
LIBS:=`root-config --libs` #necessaria per root
INCS:=`root-config --cflags` #necessaria per root
SS=funzioni #funzioni is the name of the executable

$(SS): $(LL) $(AA)
	g++ -o $(SS) $(LL) ${LIBS} ${INCS}

clean:
	rm $(SS)