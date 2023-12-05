#include <Laplace.h>

Laplace::Laplace(_fp mu = 0, _fp lambda){
    this->centre = mu;
    assert(lambda.numerator() >= 1);
    assert(lambda.denominator() >= 1);
    this->scale = lambda;
}

Laplace::Laplace(_fp lambda){
    Laplace(0, lambda);
}

void Laplace::setCentre(_fp mu){
    this->centre = mu;
}

void Laplace::setScale(_fp lambda){
    this->scale = lambda;
}

_fp Laplace::getCentre(){
    return this->centre;
}

_fp Laplace::getScale(){
    return this->scale;
}

_fp Laplace::getSample(){
    int t = this->scale.numerator();
    int s = this->scale.denominator();

    _fp z = 0;

    _fp p(1, 2);
    Bernoulli B(p, false);
    uniform_int_distribution<int> uniform(0, t-1);
    int u;
    while(1){
        u = uniform(Distribution::generator);
        
        Bernoulli D(-u/t, true);
        if(D.getSample() == 0){
            continue;
        }

        int v = 0;
        while(1){
            Bernoulli A(-1, true);
            if(A.getSample() == 0){
                break;
            }
            v++;
        }

        int x = u + t*v;
        int y = x/s;
        
        int b = B.getSample();
        if(b == 1 && y == 0){
            continue;
        }

        z = (1 - 2*b)*y;
    }

    return z + this->centre;
}