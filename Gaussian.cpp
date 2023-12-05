#include <Gaussian.h>

Gaussian::Gaussian(_fp mu, _fp sigma){
    this->centre = mu;
    this->scale = sigma;
}

Gaussian::Gaussian(_fp sigma){
    Gaussian(0, sigma);
}

_fp Gaussian::getSample(){
    int t = (int)(this->scale.numerator() / this->scale.denominator()) + 1;
    Laplace Y(t);

    int sigma2 = (this->scale * this->scale).numerator()/(this->scale * this->scale).denominator();

    _fp g;
    while (t){
        _fp s = Y.getSample();
        int y = (int) s.numerator() / s.denominator();

        _fp bernoulliParam((y - sigma2)*(y-sigma2), 2*sigma2*t*t);
        Bernoulli C(-bernoulliParam, true);
        if(C.getSample()){
            g = y;
            break;
        }
    }

    return g + this->centre;
}