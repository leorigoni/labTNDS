LL=esercizio5.1.cc 
AA=class.cc
TT=esercizio5.1.o 
NN=class.o 
SS=esercizio5.1

compila: $(TT) $(NN)
	g++ -o $(SS) $^

$(TT): $(LL)
	g++ -c $<

$(NN): $(AA)
	g++ -c $<

clean:
	rm -r $(TT) $(NN) 