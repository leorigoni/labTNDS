LL=esercizio5.0.cc 
AA=posizione.cc
TT=esercizio5.0.o 
NN=posizione.o 
SS=esercizio5.0

compila: $(TT) $(NN)
	g++ -o $(SS) $^

$(TT): $(LL)
	g++ -c $<

$(NN): $(AA)
	g++ -c $<

clean:
	rm -r $(TT) $(NN) 