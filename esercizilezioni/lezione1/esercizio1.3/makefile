LL=esercizio1.3.cc 
TT=funzioni.cc 
NN=esercizio1.3.o 
DD=funzioni.o 
SS=esercizio1.3 

all: compila

compila: $(NN) $(DD)
	g++ -o $(SS) $^

$(NN): $(LL)
	g++ -c $<

$(DD): $(TT)
	g++ -c $<

