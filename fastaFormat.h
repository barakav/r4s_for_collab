// $Id: fastaFormat.h 391 2005-06-12 12:44:57Z ninio $

#ifndef ___FASTA_FORMAT
#define ___FASTA_FORMAT

#include "sequenceContainer.h"

class fastaFormat{
public:
	static sequenceContainer read(istream &infile, const alphabet* alph);
	//readUnAligned: the input sequences do not need to be aligned (not all sequences are the same length).
	static sequenceContainer readUnAligned(istream &infile, const alphabet* alph);
	static void write(ostream &out, const sequenceContainer& sd);
};

#endif

/* EXAMPLE OF FASTA FORMAT:
>Langur
KIFERCELARTLKKLGLDGYKGVSLANWVCLAKWESGYNTEATNYNPGDESTDYGIFQINSRYWCNNGKPGAVDACHISCSALLQNNIADAVACAKRVVSDQGIRAWVAWRNHCQNKDVSQYVKGCGV
>Baboon
KIFERCELARTLKRLGLDGYRGISLANWVCLAKWESDYNTQATNYNPGDQSTDYGIFQINSHYWCNDGKPGAVNACHISCNALLQDNITDAVACAKRVVSDQGIRAWVAWRNHCQNRDVSQYVQGCGV
>Human
KVFERCELARTLKRLGMDGYRGISLANWMCLAKWESGYNTRATNYNAGDRSTDYGIFQINSRYWCNDGKPGAVNACHLSCSALLQDNIADAVACAKRVVRDQGIRAWVAWRNRCQNRDVRQYVQGCGV
>Rat
KTYERCEFARTLKRNGMSGYYGVSLADWVCLAQHESNYNTQARNYDPGDQSTDYGIFQINSRYWCNDGKPRAKNACGIPCSALLQDDITQAIQCAKRVVRDQGIRAWVAWQRHCKNRDLSGYIRNCGV
>Cow
KVFERCELARTLKKLGLDGYKGVSLANWLCLTKWESSYNTKATNYNPSSESTDYGIFQINSKWWCNDGKPNAVDGCHVSCSELMENDIAKAVACAKKIVSEQGITAWVAWKSHCRDHDVSSYVEGCTL
>Horse
KVFSKCELAHKLKAQEMDGFGGYSLANWVCMAEYESNFNTRAFNGKNANGSSDYGLFQLNNKWWCKDNKRSSSNACNIMCSKLLDENIDDDISCAKRVVRDKGMSAWKAWVKHCKDKDLSEYLASCNL


*/


