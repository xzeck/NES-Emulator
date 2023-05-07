#include "Mapper_000.hpp"

Mapper_000::Mapper_000(uint8_t prgBanks, uint8_t chrBanks) : Mapper(prgBanks, chrBanks)
{

}

Mapper_000::~Mapper_000()
{

}

bool Mapper_000::cpuMapRead(uint16_t address, uint32_t& mapped_address)
{

	if (address >= 0x8000 && address <= 0xFFFF)
	{
		mapped_address = address & (nPRGBanks > 1 ? 0x7FFF : 0x3FFF);
		return true;
	}

	return false;
}
bool Mapper_000::cpuMapWrite(uint16_t address, uint32_t& mapped_address)
{
	if (address >= 0x8000 && address <= 0xFFFF)
	{
		mapped_address = address & (nPRGBanks > 1 ? 0x7FFF : 0x3FFF);
		return true;
	}

	return false;
}

bool Mapper_000::ppuMapRead(uint16_t address, uint32_t& mapped_address)
{
	// No mapping required for PPU
	// PPU address Bus			CHR ROM
	// 0x0000 -> 0x1FFF: Map	0x0000 -> 0x1FFF

	if (address >= 0x0000 && address <= 0x1FFF)
	{
		mapped_address = address;
		return true;
	}

	return false;
}

bool Mapper_000::ppuMapWrite(uint16_t address, uint32_t& mapped_address)
{
	if (address >= 0x0000 && address <= 0x1FFF)
	{
		if (nCHRBanks == 0)
		{
			mapped_address = address;
			return true;
		}
	}

	return false;
}