#include <Distribution.h>

using namespace std;

#define SEQUENTIAL 0
#define PARALLEL 1

class Laplace : public Distribution {
    Laplace(_fp mu, _fp lambda);

    Laplace(_fp lambda);

    void setCentre(_fp mu);

    void setScale(_fp lambda);

    _fp getCentre();

    _fp getScale();

    _fp getSample();
};