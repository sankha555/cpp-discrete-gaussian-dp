#include <Laplace.h>

Laplace::Laplace(_fp mu, _fp lambda){
    this->centre = mu;
    this->scale = lambda;
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
    ;
}