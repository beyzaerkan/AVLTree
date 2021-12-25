/** 
* @ file        AgacDugum.cpp
* @ description Agaca ait dugum sinifinin govdesinin oldugu kisimdir. Dugumun icerikleri tanimlanir.
* @ course      1-B
* @ assignment  2
* @ date        25.12.2021
* @ author      Beyza Erkan  beyza.erkan@ogr.sakarya.edu.tr
*/
#include "AgacDugum.hpp"

AgacDugum::AgacDugum(DogruKuyrugu* veri)
{
    this->veri = veri;
    sol=sag=0;
}