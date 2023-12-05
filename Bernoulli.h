#include <Distribution.h>
#include <random>

class Bernoulli : public Distribution {
    public:
    bool exp;
    _fp gamma;

    Bernoulli(_fp p, bool exp);

    void setCentre(_fp p);

    _fp getCentre();

    _fp getSample();
};