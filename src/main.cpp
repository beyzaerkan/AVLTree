/** 
* @ file        main.cpp
* @ description Dosyadan okuma islemini gerceklestirir. Satirleri uclu ayirarak x y z koordinatlarina atar.
                DogruKuyrugu ve AVLAgaci sınıflarinda tanimlanan fonksiyonlari kullanir.
* @ course      1-B
* @ assignment  2
* @ date        25.12.2021
* @ author      Beyza Erkan  beyza.erkan@ogr.sakarya.edu.tr
*/
#include <iomanip>
#include <fstream>
#include <ctype.h>
#include <string>
#include <DogruKuyrugu.hpp>
#include <AVLAgaci.hpp>
using namespace std;

int main()
{
    //koordinatlar
	int x = 0;
	int y = 0;
	int z = 0;
    
    int toplamUzunluk = 0; //kuyrugun uzunlugu

    string satir; //dosyadaki satirlari temsil eder.
    size_t pos = 0;
    int nokta[3]={-1}, 
    adim=0;

    AVLAgaci agac;

    ifstream readFile("Noktalar.txt");
    
   if ( readFile.is_open() ){

    while ( getline(readFile, satir) ){
        DogruKuyrugu* kuyruk = new DogruKuyrugu(); // her satiri okudugunda DogruKuyrugu' nu cagirir.

        while(satir.size()>0){
            if(satir[0]==' '){ //satirin basinda bosluk varsa siler
                satir.erase(0,1);
                continue;
            }
            int pos = satir.find(" ");
            int koordinat = stoi(satir.substr(0,pos)); // bastan bosluga kadar olan kismi alir
    
            nokta[adim]=koordinat;
            adim++;
            if(adim==3){ // nokta dizisinin icine 3 ekleme yapidiginda kuyruga ekler ve adım'ı 0 yaparak nokta dizisine en bastan ekler
                x = nokta[0]; //ilk elemani x'e esitler
                y = nokta[1]; //ikinci elemani y'ye esitler
                z = nokta[2]; //ucuncu elemani z'ye esitler
                kuyruk->ekle(x,y,z); // kuyruga ekler
                adim=0;
            }
        satir.erase(0,pos);
        }  
        kuyruk->sirala();  //kuyrugun icindeki elemanlari orijine olan uzakliklarina gore siralar

        toplamUzunluk = kuyruk->kuyrukUzunlugu(); // kuyrugun uzunlugunu bulur
        agac.ekle(kuyruk); // kuyrugu agaca ekler
    }
    
    //dosyayi kapatir
    readFile.close();
  }
  //agaci postorder olarak dolasir ve ekrana kuyruktaki noktalarin orijine uzakliklarini yazdirir
  agac.postOrder();
   return 0;
}