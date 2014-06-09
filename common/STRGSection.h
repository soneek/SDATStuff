/*
 * CSAR - STRG (String/Filename) Section structures
 * By soneek [soneek00@gmail.com]
 * Last modification on 2013-03-25
 *
 * Nintendo DS Nitro Composer (SDAT) Specification document found at
 * http://www.feshrine.net/hacking/doc/nds-sdat.html
 */

#ifndef CSAR_STRGSECTION_H
#define CSAR_STRGSECTION_H

#include "common.h"

struct STRGRecord
{
	uint32_t count;
	std::vector<uint32_t> entryOffsets;
	std::vector<std::string> entries;

	STRGRecord();

	void Read(PseudoReadFile &file, uint32_t startOffset);
	uint32_t Size() const;
	void FixOffsets(uint32_t startOffset);
	void WriteHeader(PseudoWrite &file) const;
	void WriteData(PseudoWrite &file) const;
};

struct STRGSection
{
	int8_t type[4];
	uint32_t size;
	uint32_t recordOffsets[8];
	STRGRecord SEQrecord;
	STRGRecord BANKrecord;
	STRGRecord WAVEARCrecord;

	STRGSection();

	void Read(PseudoReadFile &file);
	uint32_t Size() const;
	void FixOffsets();
	void Write(PseudoWrite &file) const;
};

#endif
