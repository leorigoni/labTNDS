LL=esercizio2.2.cc 
AA=funzioni.cc
BB=vettore.cc
TT=esercizio2.2.o 
NN=funzioni.o 
DD=vettore.o
SS=esercizio2.2

all: compila

compila: $(TT) $(NN) $(DD)
	g++ -o $(SS) $^

$(TT): $(LL)
	g++ -c $<

$(NN): $(AA)
	g++ -c $<

$(DD): $(BB)
	g++ -c $<

clean:
	rm -r $(TT) $(NN) $(DD) $(SS) 1941out.txt 