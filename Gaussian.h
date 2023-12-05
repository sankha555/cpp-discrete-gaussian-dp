#include <Distribution.h>
#include <Laplace.h>

class Gaussian : public Distribution {
    Gaussian(_fp mu, _fp sigma);

    Gaussian(_fp sigma);

    _fp getSample();
};