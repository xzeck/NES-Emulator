#pragma once
#include "mapper.hpp"

class Mapper_000 : public Mapper
{
public:
	Mapper_000(uint8_t prgBanks, uint8_t chrbanks);
	~Mapper_000();

public:
	bool cpuMapRead(uint16_t address, uint32_t& mapped_address) override;
	bool cpuMapWrite(uint16_t address, uint32_t& mapped_address) override;
	bool ppuMapRead(uint16_t address, uint32_t& mapped_address) override;
	bool ppuMapWrite(uint16_t address, uint32_t & mapped_address) override;
};