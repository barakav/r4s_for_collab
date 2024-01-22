// $Id: bblEMSeperate.cpp 749 2006-06-29 11:44:32Z ninio $
#include "bblEM.h"
#include "bblEMSeperate.h"
#include "logFile.h"
//#define VERBOS


bblEMSeperate::bblEMSeperate(vector<tree>& et,
									const vector<sequenceContainer>& sc,
									const vector<stochasticProcess> &sp,
									const vector<Vdouble *> * weights,
									const int maxIterations,
									const MDOUBLE epsilon,
									const MDOUBLE tollForPairwiseDist) {
	MDOUBLE newL =0;
	for (int i=0; i < et.size()/*fix*/; ++i) {
		#ifdef VERBOS
			LOG(5,<<" OPTIMIZING GENE "<<i<<" ... "<<endl);
		#endif
		bblEM bblEM1(et[i],sc[i],sp[i],(weights?(*weights)[i]:NULL),maxIterations,epsilon);
		MDOUBLE resTmp =  bblEM1.getTreeLikelihood();
		#ifdef VERBOS
			LOG(5,<<" GENE "<<i<<" LOG-L = "<< resTmp<<endl);
		#endif
		newL += resTmp;
	}
	_treeLikelihood = newL;
}
