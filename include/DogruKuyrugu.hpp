#ifndef DogruKuyrugu_hpp
#define DogruKuyrugu_hpp
#include "Dugum.hpp"

using namespace std;
class DogruKuyrugu {
public:
    DogruKuyrugu();
    ~DogruKuyrugu();
    void ekle(int x, int y, int z);
    void sirala();
    int kuyrukUzunlugu();
    int noktaSayisi();
    void yazdir();
    int toplamUzunluk;
    int orijineUzaklik;
    Dugum* ilk;
    Dugum* son;
};
#endif