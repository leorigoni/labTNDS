MM=main.cc #nome file main
FF=functions.cc #nome file funzioni
AA=main.o #deve essere uguale al nome del file main ma con .o finale
UU=functions.o #deve essere uguale al nome del file funzioni ma con .o finale
PP=prog #nome file eseguibile

all: compila esegui

compila: $(AA) $(UU)
	g++ -o $(PP) $^

$(AA): $(MM)
	g++ -c $<

$(UU): $(FF)
	g++ -c $<

esegui: $(PP)
	./$(PP)

clean:
	rm -f $(AA) $(UU) $(PP)