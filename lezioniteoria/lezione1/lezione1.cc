Le Basi:

-esempi base:

    #include<iostream>

    int main(){

        std::cout << "Hello Word" << std::endl;

        return 0;
    }

    #include<iostream> //libreria da cui prendere funzioni
    int main() //funzione che non accetta nulla di input e da un output int
    return 0; //output int che si aspetta il main , 0 perchè così l'esecuzione è corretta
    std:: //
    cout/endl //funzioni contenute in iostream

    #include<iostream>

    int main(){

        double a,b;
        std::cout << "Input first number: " << std::endl;
        std::cin >> a;
        std::cout << "Input second number: " << std::endl;
        std::cin >> b;
        double c=a+b;
        std::cout << "La somma vale: " << c << std:: endl;

        return 0;
    }

-variabili base:

    int //interi
    double //numeri in doppia precizione
    unsigned int //int senza segno

    puntatori:

        double a=15;
        double *address=&a;
        //& (variable) returns the address of the variable
        //* (pointer) returns the variable pointed by the address

-strutture di controllo:

    if(){ }else...
    for(){} //se conosco il numero di cicli da fare
    while(){} (do while/while do) //se non so il numero di cicli da fare

-mai duplicare il codice ???

    creare funzioni per le cose che si necessitano fare
    mai riscrivere funzioni nel main, scriverle fuori e chiamarle

    double sum(double a, double b){ //esempio
        return a+b;
    };

-funzioni esempio

    void scambiabyvalue(double a, double b){ //non funziona
        double tmp=a;
        a=b;
        b=tmp;
    }

    void scambiabyreference(double &a, dobule &b){ //funziona
        double tmp=a;
        a=b;
        b=tmp;
    }

    void scambiabypointer(double *a, double *b){ //funziona
        double c=*a;
        *a=*b;
        *b=c;
    }

    bisogna distingue tra variabili globali e variabili locali.

    non si usano le varibili globali !!!! (ricordalo a sofi !!!)

-aprie copiare chiude da file

    #include<fstream>

    ifstream input("nomenano");
    ofstream output("nanonome");

    if(!imput){
        //controllare se è aperto
    }

    input.close();
    output.close();

    //ci sono altre funzionalità che vedremo in seguito

-comunicare con l esterno

    #include<iostream>
    using namespace std;
    int main( int argc, char** argv){
        //da capire bene
    }

    ./hw_argc_1 data.txt 1000
    3
    ./hw_argc_1
    data.txt
    1000

-array 

    solo array dinamici !!!

    double *dynamic=new double[nelements];

    delete[]dynamic;