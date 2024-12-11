#include"posizione.h"

int main(int argc, char** argv){

    //input
    if(argc!=4){
        std::cerr << "Usage: " << argv[0] << " <x> <y> <z>" << endl;
        return -1;
    }
    double x = atof(argv[1]);
    double y = atof(argv[2]);
    double z = atof(argv[3]);
    posizione p(x,y,z);

    //output
    cout << "Coordinate cartesiane: (" << p.getx() << "; " << p.gety() << "; " << p.getz() << ")" << endl;
    cout << "Coordinate cilindriche: (" << p.getrho() << "; " << p.getphi() << "; " << p.getz() << ")" << endl;
    cout << "Coordinate sferiche: (" << p.getr() << "; " << p.getphi() << "; " << p.gettheta() << ")" << endl;

    return 0;
}
