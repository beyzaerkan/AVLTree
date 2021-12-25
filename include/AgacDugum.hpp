#ifndef AgacDugum_hpp
#define AgacDugum_hpp
#include "DogruKuyrugu.hpp"

class AgacDugum
{
public:
    DogruKuyrugu* veri;
    AgacDugum* sol;
    AgacDugum* sag;
    AgacDugum(DogruKuyrugu* veri);
};

#endif