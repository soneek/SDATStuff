/*
 * CSAR - CSAR structure
 * By soneek [soneek00@gmail.com]
 * Last modification on 2014-06-07
 *
 * Nintendo DS Nitro Composer (SDAT) Specification document found at
 * http://www.feshrine.net/hacking/doc/nds-sdat.html
 */

#ifndef CSAR_CSAR_H
#define CSAR_CSAR_H

#include "3DSStdHeader.h"
#include "SYMBSection.h"
#include "INFOSection.h"
#include "FATSection.h"
#include "SSEQ.h"
#include "SBNK.h"
#include "SWAR.h"
#include "common.h"

struct SDAT
{
	static bool failOnMissingFiles;

	std::string filename;
	3DSStdHeader header;
	uint32_t STRGOffset;
	uint32_t STRGSize;
	uint32_t INFOOffset;
	uint32_t INFOSize;
	uint32_t FILEOffset;
	uint32_t FILESize;

	STRGSection strgSection;
	INFOSection infoSection;
	FATSection fatSection;

	bool symbSectionNeedsCleanup;
	uint16_t count;

	std::vector<std::unique_ptr<CSEQ>> CSEQs;
	std::vector<std::unique_ptr<CBNK>> CBNKs;
	std::vector<std::unique_ptr<CWAR>> CWARs;

	CSAR();
	CSAR(const CSAR &csar);
	CSAR &operator=(const CSAR &csar);

	void Read(const std::string &fn, PseudoReadFile &file, bool shouldFailOnMissingFiles = true);
	void Write(PseudoWrite &file) const;

	CSAR &operator+=(const CSAR &other);
	void Strip(const IncOrExc &includesAndExcludes, bool verbose, bool removeExcluded = true);
};

#endif
