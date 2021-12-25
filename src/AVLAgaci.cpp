/** 
* @ file        AVLAgaci.cpp
* @ description AVL agacinda ekleme, yukseklik bulma, postorder dolasma, sola, saga dondurme fonksiyonlarinin bulundugu dosyadir. 
                Ayni zamanda kurucu ve yikici fonksiyonlara da ulasilabilir.
* @ course      1-B
* @ assignment  2
* @ date        25.12.2021
* @ author      Beyza Erkan  beyza.erkan@ogr.sakarya.edu.tr
*/
#include <cmath>
#include <iomanip>
#include<iostream>
#include "AVLAgaci.hpp"

AVLAgaci::AVLAgaci()
{
    kok = 0;
}
AVLAgaci::~AVLAgaci()
{

}

void AVLAgaci::ekle(DogruKuyrugu* veri)
{
    kok = ekle(veri,kok);
}

int AVLAgaci::yukseklik() 
{
	return yukseklik(kok);
}

void AVLAgaci::postOrder() {
	postOrder(kok);
}

// agaci sol - sag - yazdir seklinde dolasir
//icinde bulunan kuyrugun noktalarinin orijine olan uzakliklarini yazdirir. 
void AVLAgaci::postOrder(AgacDugum* aktif) 
{
	if (aktif) {
        postOrder(aktif->sol);
        postOrder(aktif->sag);
        aktif->veri->yazdir();
    } 
    	
}

//yuksekligi bulur
int AVLAgaci::yukseklik(AgacDugum* aktifDugum) 
{
	if(aktifDugum)
    {
        return 1+max(yukseklik(aktifDugum->sol), yukseklik(aktifDugum->sag));
    }
    return -1;
}

//kuyruklari agaca ekler
AgacDugum* AVLAgaci::ekle(DogruKuyrugu* veri,AgacDugum* aktifDugum) 
{
    if(aktifDugum==0)
        return new AgacDugum(veri);

	else if(aktifDugum->veri->toplamUzunluk<veri->toplamUzunluk)
    {
        aktifDugum->sag=ekle(veri,aktifDugum->sag);
        if(yukseklik(aktifDugum->sag)-yukseklik(aktifDugum->sol)>1)
        {   
            if(veri->toplamUzunluk>aktifDugum->sag->veri->toplamUzunluk)
                aktifDugum = solaDondur(aktifDugum);
                
            else
            {
                aktifDugum->sag = sagaDondur(aktifDugum->sag);
                aktifDugum =solaDondur(aktifDugum);
            }
        }
    }
    else if(aktifDugum->veri->toplamUzunluk>veri->toplamUzunluk)
    {
        aktifDugum->sol = ekle(veri,aktifDugum->sol);
        if(yukseklik(aktifDugum->sol)-yukseklik(aktifDugum->sag)>1)
        {

            if(veri<aktifDugum->sol->veri)
                aktifDugum = sagaDondur(aktifDugum);
            else
            {
                aktifDugum->sol = solaDondur(aktifDugum->sol);
                aktifDugum =sagaDondur(aktifDugum);
            }
        }

    }
    return aktifDugum;
}


AgacDugum* AVLAgaci::solaDondur(AgacDugum* buyukEbeveyn) 
{
	AgacDugum* sagCocuk = buyukEbeveyn->sag;
    buyukEbeveyn->sag = sagCocuk->sol;
    sagCocuk->sol = buyukEbeveyn;
    return sagCocuk;
}

AgacDugum* AVLAgaci::sagaDondur(AgacDugum* buyukEbeveyn) 
{
	AgacDugum* solCocuk = buyukEbeveyn->sol;
    buyukEbeveyn->sol = solCocuk->sag;
    solCocuk->sag = buyukEbeveyn;
    return solCocuk;
}
