#include "random.h"

using namespace std;

RandomNumbers::RandomNumbers(unsigned long int s) : seed(s)
{
	if (seed==0) {
		random_device rd; 
		seed = rd();
	}

	rng = mt19937(seed); 
}

void RandomNumbers::uniform_double(std::vector<double>& r, double lower, double upper) {
	if (r.size() == 0) {} //si vecteur est vide 
	uniform_real_distribution<> distribution(lower, upper);
	for (size_t i=0; i<r.size(); ++i) { 
	r[i]=(distribution(rng)); 
	}
}

double RandomNumbers::uniform_double(double lower, double upper) {
	uniform_real_distribution<> distribution(lower, upper);
	return distribution(rng);
}

void RandomNumbers::normal(std::vector<double>& r, double mean, double sd) {
	normal_distribution<> distribution(mean, sd);
	for (size_t i=0; i<r.size(); ++i) {  
	r.push_back(distribution(rng));
	}
}

double RandomNumbers::normal(double mean, double sd) {
	normal_distribution<> distribution(mean, sd);
	return distribution(rng);
}

void RandomNumbers::poisson(std::vector<int>& r, double mean) {
	poisson_distribution<> distribution(mean);
	for (size_t i=0; i<r.size(); ++i) {  
	r.push_back(distribution(rng));
	}
}

int RandomNumbers::poisson(double mean){
	poisson_distribution<> distribution(mean);
	return distribution(rng);
}


