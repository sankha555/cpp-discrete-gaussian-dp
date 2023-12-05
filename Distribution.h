#include <math.h>
#include <cassert>
#include <random>
#include <boost/rational.hpp>

using namespace std;
using namespace boost;

using _fp = rational<int>;

class Distribution {
    public:
    _fp centre = 0;
    _fp scale = 0;
    static default_random_engine generator;

    virtual void setCentre(_fp centre);
    
    virtual void setScale(_fp scale);

    virtual _fp getCentre();

    virtual _fp getScale();

    virtual _fp getSample();
};