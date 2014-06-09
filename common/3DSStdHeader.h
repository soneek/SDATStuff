/*
 * CSAR - Nintendo 3DS Standard Header structure
 * By soneek [soneek00@gmail.com]
 * Last modification on 2013-03-25
 *
 * Nintendo DS Nitro Composer (SDAT) Specification document found at
 * http://www.feshrine.net/hacking/doc/nds-sdat.html
 */

#ifndef CSAR_3DSSTDHEADER_H
#define CSAR_3DSSTDHEADER_H

#include "common.h"

struct 3DSStdHeader
{
	int8_t type[4];
	uint32_t magic;
	uint32_t fileSize;
	uint16_t size;
	uint16_t blocks;

	3DSStdHeader();

	void Read(PseudoReadFile &file);
	void Verify(const std::string &typeToCheck, uint32_t magicToCheck) const;
	void Write(PseudoWrite &file) const;
};

#endif
