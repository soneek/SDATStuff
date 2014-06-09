/*
 * SDAT - SSEQ (Sequence) structure
 * By Naram Qashat (CyberBotX) [cyberbotx@cyberbotx.com]
 * Last modification on 2013-03-30
 *
 * Nintendo DS Nitro Composer (SDAT) Specification document found at
 * http://www.feshrine.net/hacking/doc/nds-sdat.html
 */

#ifndef CSAR_CSEQ_H
#define CSAR_CSEQ_H

#include "INFOEntry.h"
#include "common.h"

struct CSEQ
{
	std::string filename, origFilename;
	std::vector<uint8_t> data;

	int32_t entryNumber;
	INFOEntryCSEQ info;

	CSEQ(const std::string &fn = "", const std::string &origFn = "");
	CSEQ(const CSEQ &sseq);
	CSEQ &operator=(const CSEQ &sseq);

	void Read(PseudoReadFile &file);
};

#endif
