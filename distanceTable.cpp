// $Id: distanceTable.cpp 513 2005-12-19 13:59:07Z eyalprivman $

#include "definitions.h"
#include "distanceTable.h"

void giveDistanceTable(const distanceMethod* dis,
		       const sequenceContainer& sc,
		       VVdouble& res,
		       vector<string>& names,
		       const vector<MDOUBLE> * weights){
	int numberOfSeqs = sc.numberOfSeqs();//check if sc is changing
	res.resize(numberOfSeqs);
	for (int z=0; z< numberOfSeqs;++z) res[z].resize(numberOfSeqs,0.0);//is that really needed more than once??

//multithreading if sc[j] is only input you can divide i by n threads
	for (int i=0; i < numberOfSeqs; ++i) {
		for (int j=i+1; j < numberOfSeqs; ++j) {
			res[i][j] = dis->giveDistance(sc[i],sc[j],weights,NULL);
			//LOG(5,<<"res["<<i<<"]["<<j<<"] ="<<res[i][j]<<endl);
		}
		names.push_back(sc[i].name());
	}
}




