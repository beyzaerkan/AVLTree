/** 
* @ file        DogruKuyrugu.cpp
* @ description Kuyrukta ekleme, siralama, nokta sayisinı bulma, yazdirma ve kuyrugun uzunlugunu bulma
                fonksiyonlarinin bulundugu dosyadir. 
                Ayni zamanda kurucu ve yikici fonksiyonlara da ulasilabilir.
* @ course      1-B
* @ assignment  2
* @ date        25.12.2021
* @ author      Beyza Erkan  beyza.erkan@ogr.sakarya.edu.tr
*/
#include <math.h>
#include <iostream>
#include "DogruKuyrugu.hpp"

using namespace std;

DogruKuyrugu::DogruKuyrugu()
{
    ilk = son = 0;
    orijineUzaklik = 0;
    toplamUzunluk = 0;
};

DogruKuyrugu::~DogruKuyrugu(){
    while(ilk!=0){
        Dugum* gec = ilk;
        ilk = ilk->sonraki;
        delete gec;
    }
}


// x y z koordinatlarina göre ekleme yapar
void DogruKuyrugu::ekle(int x, int y, int z)
{
    orijineUzaklik = sqrt(pow(x,2)+pow(y,2)+pow(z,2));
    Dugum* yeni = new Dugum(x, y ,z);
    yeni->orijineUzaklik = orijineUzaklik;
      
    if(ilk==0){
         ilk = yeni;
         son = ilk;
     }
     else if(ilk->sonraki == 0){
         Dugum* gec = ilk;
         ilk->sonraki = yeni;
         yeni->sonraki = 0;
         son++;
     }
    else{
        Dugum* gec = ilk;
        while(gec->sonraki != 0){
            gec = gec->sonraki;
        }
        gec->sonraki = yeni;
        yeni->sonraki  = 0;
        son++;
    }
}

//noktalari orijine uzakliklarına gore siralar
void DogruKuyrugu::sirala(){
        Dugum* gec = ilk;
        Dugum* gec1 = ilk;

       for (int i = 0; i < noktaSayisi(); i++) {
        for (int j = 0; j < noktaSayisi() - 1; j++) {
            if (gec->orijineUzaklik < gec1->orijineUzaklik) {
                int temp = gec->orijineUzaklik;
                gec->orijineUzaklik = gec1->orijineUzaklik;
                gec1->orijineUzaklik = temp;

            }
            gec1 = gec1->sonraki;
        }
         gec1 = ilk;
         gec = ilk->sonraki;
         for (int k = 0; k < i; k++) {
                gec = gec->sonraki;
         }
    }
}

//kuyruktaki nokta sayisini verir
int DogruKuyrugu::noktaSayisi(){
    Dugum* temp=ilk;
    int count = 0;
    while(temp!=0){
        temp = temp->sonraki;
        count++;
    }
    return count;
}


//ilk elemandan baslayarak son elemana kadar elemanların orijine uzaklıklarını ekrana yazar
void DogruKuyrugu::yazdir(){
    Dugum* temp=ilk;
    
    while(temp!=0){
        cout<<temp->orijineUzaklik<<" ";
        temp = temp->sonraki;
    }
    cout<<endl;

}

//kuyrugun uzunlugunu hesaplar
int DogruKuyrugu::kuyrukUzunlugu(){
    int araUzaklik = 0;
    int x1;
    int y1;
    int z1;
    Dugum* temp=ilk;
    while(temp->sonraki!=0){
        x1 = temp->sonraki->x;
        y1 = temp->sonraki->y;
        z1 = temp->sonraki->z;
        araUzaklik = sqrt(pow(x1- temp->x, 2) + pow(y1- temp->y, 2) + pow(z1-temp->z, 2) );
        toplamUzunluk += araUzaklik;
        temp = temp->sonraki;
    }
    return toplamUzunluk;
}



