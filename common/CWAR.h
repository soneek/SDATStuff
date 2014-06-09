/*
 * CSAR - CWAR (Wave Archive) structures
 * By soneek
 * Last modification on 2013-03-30
 *
 * Nintendo DS Nitro Composer (SDAT) Specification document found at
 * http://www.feshrine.net/hacking/doc/nds-sdat.html
 */

#ifndef CSAR_CWAR_H
#define CSAR_CWAR_H

#include <map>
#include "CWAV.h"
#include "INFOEntry.h"
#include "common.h"

struct CWAR
{
	std::string filename;
	std::map<uint32_t, CWAV> cwavs;

	int32_t entryNumber;
	INFOEntryWAVEARC info;

	SWAR(const std::string &fn = "");

	void Read(PseudoReadFile &file);
};

#endif
