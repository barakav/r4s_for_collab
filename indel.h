// 	$Id: indel.h 920 2006-09-21 09:26:12Z ninio $	
#ifndef ____INDEL
#define ____INDEL

#include "definitions.h"
#include "errorMsg.h"
#include "alphabet.h"


class indel : public alphabet {
public:
	explicit indel(); 
	virtual ~indel() {}
	virtual alphabet* clone() const { return new indel(*this); }
	int unknown() const  {return -2;}
	int gap() const  {errorMsg::reportError("The method indel::gap() is used"); return -1;} // What is it for ? I don't need this !!!
	int size() const {return 2;}
	int stringSize() const {return 1;} // one letter code.
	int relations(const int charInSeq, const int charToCheck) const;
	int fromChar(const string& str, const int pos) const;
	int fromChar(const char s) const;
	string fromInt(const int in_id) const;
	vector<int> fromString(const string& str) const;
	bool isSpecific(const int id) const {return (id>=0 && id < size()/*why? chanfe to unsigned*/);}

};//end of class

#endif
