/*
 * SDAT - SBNK (Sound Bank) structures
 * By Naram Qashat (CyberBotX)
 * Last modification on 2013-03-30
 *
 * Nintendo DS Nitro Composer (SDAT) Specification document found at
 * http://www.feshrine.net/hacking/doc/nds-sdat.html
 */

#ifndef CSAR_CBNK_H
#define CSAR_CBNK_H

#include "CWAR.h"
#include "INFOEntry.h"
#include "common.h"

struct CBNKInstrumentRange
{
	uint8_t lowNote;
	uint8_t highNote;
	uint16_t record;
	uint16_t cwav;
	uint16_t cwar;
	uint8_t noteNumber;
	uint8_t attackRate;
	uint8_t decayRate;
	uint8_t sustainLevel;
	uint8_t releaseRate;
	uint8_t pan;

	CBNKInstrumentRange(uint8_t lowerNote, uint8_t upperNote, int recordType);

	void Read(PseudoReadFile &file);
};

struct CBNKInstrument
{
	uint8_t record;
	std::vector<CBNKInstrumentRange> ranges;

	CBNKInstrument();

	void Read(PseudoReadFile &file, uint32_t startOffset);
};

struct CBNK
{
	std::string filename;
	std::vector<CBNKInstrument> instruments;

	int32_t entryNumber;
	INFOEntryBANK info;

	CBNK(const std::string &fn = "");

	void Read(PseudoReadFile &file);
};

#endif
