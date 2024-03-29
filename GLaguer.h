// $Id: GLaguer.h 391 2005-06-12 12:44:57Z ninio $
#ifndef ___GLAGUER
#define ___GLAGUER

#include "definitions.h"
#include <vector>
using namespace std;

typedef double raterootarray[35][35];

class GLaguer
{
public:
	explicit GLaguer(const int pointsNum, const MDOUBLE alpha, Vdouble & points, Vdouble & weights);
	
	void GetPhylipLaguer(const int pointsNum, MDOUBLE alf, Vdouble & points, Vdouble & weights);

private:
	void gaulag(Vdouble &x, Vdouble  &w, const MDOUBLE alf, const int pointsNum);
	
	void lgr(long m, double alpha, raterootarray lgroot);
	double glaguerre(long m, double b, double x);


private:
	Vdouble _points;
	Vdouble _weights;
};

#endif
