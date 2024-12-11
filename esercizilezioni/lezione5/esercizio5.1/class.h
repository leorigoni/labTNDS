#include <iostream> 

using namespace std;

class particella{
    public:
        //costruttori
        particella();
        particella(double massa, double carica);

        //distruttore
        ~particella();

        //metodi
        double getmassa() const{return m_massa;}
        double getcarica() const{return m_carica;}
        void print() const;

    protected:
        double m_massa;
        double m_carica;
};

class elettrone:public particella{
    public:
        //costruttore
        elettrone();
        elettrone(const particella &);
        
        //distruttore
        ~elettrone();

        //metodi
        void print() const;
};
