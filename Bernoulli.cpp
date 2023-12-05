#include <Bernoulli.h>

Bernoulli::Bernoulli(_fp p, bool exp = false){    
    if(exp){
        assert(p < 0);

        // sample from Bernoulli(e^-p)
        // TODO: fix this 
        this->centre = -p;
        this->gamma = p;
    }else{
        assert(p > 0);
        // sample from Bernoulli(p)
        this->centre = p;
    }
    this->exp = exp;
}

_fp Bernoulli::getSample(){
    if(this->exp){
        // sample from Bernoulli(e^-y)
        if(this->gamma < 1){
            int k = 0;
            while(1){
                Bernoulli A(this->gamma.numerator()/(this->gamma.denominator()*k));
                if(A.getSample() == 1){
                    k++;
                }else{
                    break;
                }
            }
            return k & 1; // if k is odd, return 1; else return 0;
        }else{
            _fp gamma = this->gamma;
            int gamma_floor = (int) gamma.numerator() / gamma.denominator();
            for(int i = 1; i <= gamma_floor; i++){
                Bernoulli B(-1, true);
                if(B.getSample() == 0){
                    return 0;
                }
            }

            Bernoulli C(gamma - gamma_floor, true);
            return C.getSample();
        }
    }
    
    uniform_int_distribution<int> uniform(0, this->centre.denominator()-1);
    int u = uniform(Distribution::generator);
    return u < this->centre.numerator();
}
