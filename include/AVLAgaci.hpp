#ifndef AVLAgaci_hpp
#define AVLAgaci_hpp
#include "AgacDugum.hpp"
#include "DogruKuyrugu.hpp"
using namespace std;

class AVLAgaci
{
public:
	AVLAgaci();
	~AVLAgaci();
	void ekle(DogruKuyrugu* veri);
	void postOrder();
	int yukseklik();
private:
	AgacDugum* solaDondur(AgacDugum* Dugum);
	AgacDugum* sagaDondur(AgacDugum* Dugum);
	void postOrder(AgacDugum* index);
	int yukseklik(AgacDugum* aktifDugum);
	AgacDugum* ekle(DogruKuyrugu* veri,AgacDugum* aktifDugum);
	AgacDugum* kok;
};
#endif