// $Id: errorMsg.cpp 511 2005-12-14 10:43:28Z ninio $

// version 1.01
// last modified 1 Jan 2004
#include "definitions.h"
#include <cassert>
#include "errorMsg.h"
#include "logFile.h"
#include <errno.h>
#include <string.h> //for strerror
#include <stdlib.h>  //for exit()
#include <typeinfo>
ostream *errorMsg::_errorOut= nullptr ;

void errorMsg::reportError(const vector<string>& textToPrint, const int exitCode) {
	for (int i =0 ; i < textToPrint.size() ; ++i) {
		LOG(1,<<textToPrint[i]<<endl);
		cerr<<textToPrint[i]<<endl;
		if (_errorOut != nullptr  &&  typeid(*_errorOut) !=  typeid(cerr))  {
			(*_errorOut)<<textToPrint[i]<<endl;
		}
	}
	if (errno!=0){
	  LOG(1,<<"System Error: "<<strerror(errno)<<endl);
	  cerr<<"System Error: "<<strerror(errno)<<endl;
	}
	assert(0); // always stop here if in DEBUG mode.
	exit(exitCode);
}

void errorMsg::reportError(const string& textToPrint, const int exitCode) {
	LOG(1,<<endl<<textToPrint<<endl);
	cerr<<endl<<textToPrint<<endl;
	if (_errorOut != nullptr  &&  typeid(*_errorOut) !=  typeid(cerr))  {
		(*_errorOut)<<textToPrint<<endl;
	}
	if (errno!=0){
	  LOG(1,<<"System Error: "<<strerror(errno)<<endl);
	  cerr<<"System Error: "<<strerror(errno)<<endl;
	}
	assert(0); // always stop here if in DEBUG mode.
	exit(exitCode);
}


