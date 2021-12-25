/** 
* @ file        Dugum.cpp
* @ description Dugum sinifinin govdesinin oldugu kisimdir. Dugumun icerikleri tanimlanir.
* @ course      1-B
* @ assignment  2
* @ date        25.12.2021
* @ author      Beyza Erkan  beyza.erkan@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"

using namespace std;

Dugum::Dugum(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    orijineUzaklik = 0;
    sonraki = 0; 
};