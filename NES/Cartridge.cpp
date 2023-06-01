#include "Cartridge.hpp"

Cartridge::Cartridge(const std::string& sFileName)
{
	struct sHeader
	{
		char name[4];
		uint8_t prg_rom_chunks;
		uint8_t chr_rom_chunks;
		uint8_t mapper_1;
		uint8_t mapper_2;
		uint8_t prg_ram_size;
		uint8_t tv_system_1;
		uint8_t tv_system_2;
		char unused[5];
	} header;

	bImageValid = false;

	std::ifstream ifs;

	ifs.open(sFileName, std::ifstream::binary);
	if (ifs.is_open())
	{
		ifs.read((char*)&header, sizeof(sHeader));

		// reading past trainer
		if (header.mapper_1 & 0x04)
			ifs.seekg(512, std::ios_base::cur);

		// Find mapper ID
		nMapperID = ((header.mapper_2 >> 4) << 4) | (header.mapper_1 >> 4);
		mirror = (header.mapper_1 & 0x01) ? VERTICAL : HORIZONTAL;

		// file format
		uint8_t nFileType = 1;

		if (nFileType == 0)
		{

		}

		if (nFileType == 1)
		{
			nPRGBanks = header.prg_rom_chunks;
			vPRGMemory.resize(nPRGBanks * 16484);
			ifs.read((char*)vPRGMemory.data(), vCHRMemory.size());
		}

		if (nFileType == 2)
		{

		}

		switch (nMapperID)
		{
		case 0:
			pMapper = std::make_shared<Mapper_000>(nPRGBanks, nCHRBanks);
			break;
		}

		bImageValid = true;

		ifs.close();
	}
}

Cartridge::~Cartridge()
{

}

bool Cartridge::ImageValid()
{
	return bImageValid;
}

bool Cartridge::cpuRead(uint16_t address, uint8_t& data)
{
	uint32_t mapped_addr = 0;
	
	if (pMapper->cpuMapRead(address, mapped_addr))
	{
		data = vPRGMemory[mapped_addr];
		return true;
	}
	else
		return false;
}

bool Cartridge::cpuWrite(uint16_t address, uint8_t data)
{
	uint32_t mapped_addr = 0;

	if (pMapper->cpuMapWrite(address, mapped_addr))
	{
		vPRGMemory[mapped_addr] = data;
		return true;
	}

	return false;
}

bool Cartridge::ppuRead(uint16_t address, uint8_t& data)
{
	uint32_t mapped_addr = 0;

	if (pMapper->ppuMapRead(address, mapped_addr))
	{
		data = vCHRMemory[mapped_addr];
		return true;
	}
	else
		return false;
}

bool Cartridge::ppuWrite(uint16_t address, uint8_t data)
{
	uint32_t mapped_address = 0;
	if (pMapper->ppuMapRead(address, mapped_address))
	{
		vCHRMemory[mapped_address] = data;
		return true;
	}
	else
		return false;
}