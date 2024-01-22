// $Id: suffStatComponent.h 652 2006-03-20 11:39:07Z eyalprivman $

#ifndef ___SUFF_STAT_COMPONENT
#define ___SUFF_STAT_COMPONENT

#include "definitions.h"
#include "doubleRep.h"
#include <vector>
using namespace std;

// spec = for a specific node. global = for all the nodes
// hom = no rate variation. gam = with rate variation
// pos = for one position
//-------------------------------------------------------------
class suffStatSpecHomPos{ // this is for a specific node. 
	public:
		void set(const int letter,const doubleRep& val) {
			_V[letter]=val;
		}
		
		doubleRep get(const int letter) const	{
		    doubleRep tmp=_V[letter];
//		    cout << "tmp =";
//		    tmp.outputn(cout);
		    
		    return tmp;
		}

		void allocatePlace(const int alphabetSize) {
			_V.resize(alphabetSize);
		}
		bool isEmpty (){return (_V.empty());};
		int size() const {return _V.size();}

	private:
		vector<doubleRep> _V;//size = letter
};
//-------------------------------------------------------------

//-------------------------------------------------------------
class suffStatGlobalHomPos{ // this is for all nodes
	public:
		void set(const int nodeId,const int letter,const doubleRep val) {
			_V[nodeId].set(letter,val);
		}
		
		doubleRep get(const int nodeId,const int letter) const	{
		    doubleRep tmp(_V[nodeId].get(letter));
//		    tmp;
		    
//		    cout << "tmp2=";
//		    tmp.outputn(cout);
		    return tmp;
		}

		void allocatePlace(const int numOnNodes,const int alphabetSize) {
			_V.resize(numOnNodes);
			for (int i=0;i<_V.size();++i) {_V[i].allocatePlace(alphabetSize);}
		}
		bool isEmpty (){return (_V.empty());};
		int size() const {return _V.size();}
	private:
		vector<suffStatSpecHomPos> _V;//size = number of nodes.
};
//-------------------------------------------------------------
class suffStatGlobalGamPos{ // this is for all nodes
	public:
		void set(const int categor,const int nodeId,const int letter,const doubleRep val) {
			_V[categor].set(nodeId,letter,val);
		}
		
		doubleRep get(const int categor,const int nodeId,const int letter) const	{
			return _V[categor].get(nodeId,letter);
		}

		void allocatePlace(const int categor,const int numOnNodes,const int alphabetSize) {
			_V.resize(categor);
			for (int i=0;i<_V.size();++i) {_V[i].allocatePlace(numOnNodes,alphabetSize);}
		}
		bool isEmpty (){return (_V.empty());}
		int size() const {return _V.size();}

	suffStatGlobalHomPos& operator[] (int index) {return _V[index];}
	const suffStatGlobalHomPos& operator[] (int index) const {return _V[index];}
	private:
		vector<suffStatGlobalHomPos> _V;//size = letter
};
//-------------------------------------------------------------
class suffStatGlobalGam{ // this is for all positions (and for all nodes).
	public:
		void set(const int pos,const int categor,const int nodeId,const int letter,const doubleRep val) {
			_V[pos].set(categor,nodeId,letter,val);
		}
		
		doubleRep get(const int pos,const int categor,const int nodeId,const int letter) const	{
			return _V[pos].get(categor,nodeId,letter);
		}

		void allocatePlace(const int pos,const int categor,const int numOnNodes,const int alphabetSize) {
			_V.resize(pos);
			for (int i=0;i<_V.size();++i) {_V[i].allocatePlace(categor,numOnNodes,alphabetSize);}
		}
		bool isEmpty (){return (_V.empty());}
		int size() const {return _V.size();}
	suffStatGlobalGamPos& operator[] (int index) {return _V[index];}
	const suffStatGlobalGamPos& operator[] (int index) const {return _V[index];}
	private:
		vector<suffStatGlobalGamPos> _V;
};

// from ItayM not to use with the EM algorithm.
class suffStatGlobalHom{ // this is for all positions (and for all nodes).
	public:
		void set(const int pos, const int nodeId, const int letter,const doubleRep val) {
			_V[pos].set(nodeId, letter, val);
		}
		
		doubleRep get(const int pos, const int nodeId, const int letter) const {
			return _V[pos].get(nodeId, letter);
		}

		void allocatePlace(const int pos, const int numOnNodes, const int alphabetSize) {
			_V.resize(pos);
			for (int i=0;i<_V.size();++i) {_V[i].allocatePlace(numOnNodes, alphabetSize);}
		}
		bool isEmpty (){return (_V.empty());};
	suffStatGlobalHomPos& operator[] (int index) {return _V[index];}
	const suffStatGlobalHomPos& operator[] (int index) const {return _V[index];}
	private:
		vector<suffStatGlobalHomPos> _V;
};


#endif

