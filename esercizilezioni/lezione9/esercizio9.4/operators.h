#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#include<numeric>
using namespace std;

template <typename t> inline vector<t> operator+(const vector<t> &a, const vector<t> &b){
    if(a.size()!=b.size()){ 
        cout << "Trying to sum vectors with different size, exiting" << endl ; 
        exit(-1); 
    }; 
    vector<t> result(a.size());
    for(int i=0; i<static_cast<int>(a.size()); i++){
        result[i]=a[i]+b[i];
    }    
    return result;
}
                                                                                              
template <typename t> inline vector<t> operator-(const vector<t> &a, const vector<t> &b){
    if(a.size()!=b.size()){ 
        cout << "Trying to subtract vectors with different size, exiting" << endl ; 
        exit(-1); 
    }; 
    vector<t> result(a.size());
    for(int i=0; i<static_cast<int>(a.size()); i++){
        result[i]=a[i]-b[i];
    }    
    return result;
}

template <typename t> inline t operator*(const vector<t> &a, const vector<t> &b){
    if(a.size()!=b.size()){
        cout << "Trying to multiply vectors with different size, exiting" << endl ;
        exit(-1);
    };
    t sum=0;
    for(int i=0; i<static_cast<int>(a.size()); i++){
        sum+=a[i]*b[i];
    }
    return sum; 
}

template <typename t> inline vector<t> operator*(t c, const vector<t> &a){
    vector<t> result(a.size());
    for(int i=0; i<static_cast<int>(a.size()); i++){
        result[i]=c*a[i];
    }
    return result;
}

template <typename t> inline vector<t> operator*(const vector<t> &a, t c){
    vector<t> result(a.size());
    for(int i=0; i<static_cast<int>(a.size()); i++){
        result[i]=c*a[i];
    }
    return result;
}

template <typename t> inline vector<t> operator/(const vector<t> &a, t c){
    vector<t> result(a.size());
    for(int i=0; i<static_cast<int>(a.size()); i++){
        result[i]=a[i]/c;
    }
    return result;
}

template <typename t> inline vector<t>& operator+=(vector<t>& a, const vector<t>& b){
    if(a.size()!=b.size()){
        cout << "Trying to sum vectors with different size, exiting" << endl ;
        exit(-1);
    };
    for(int i=0; i<static_cast<int>(a.size()); i++){
        a[i]+=b[i];
    }
    return a;
}

template <typename t> inline vector<t>& operator-=(vector<t>& a, const vector<t>& b){
    if(a.size()!=b.size()){
        cout << "Trying to subtract vectors with different size, exiting" << endl ;
        exit(-1);
    };
    for(int i=0; i<static_cast<int>(a.size()); i++){
        a[i]-=b[i];
    }
    return a;
}

template <typename t> inline void print(const vector<t> &v ){
    cout << "Printing vector" << endl;
    for(auto it=v.begin(); it!=v.end(); it++ ){
        cout << *it << " " ;
    }
    cout << endl;
    cout << "End of printing vector" << endl;
};

// ===============================================================================

template <typename t> class linearvector: public vector<t>{
    public:
    linearvector<t>(): vector<t>(){};
    linearvector<t> (int size): vector<t>(size){};
    linearvector<t> operator+(const linearvector<t> &a ){
        assert(a.size()==this->size());    
        linearvector<t> result(a.size());
        for(int i=0; i<static_cast<int>(a.size()); i++){
            result[i]=a[i]+(*this)[i];
        }    
        return result;    
    }
};