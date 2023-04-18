#pragma once

#include <vector>
#include <string>
#include <map>
#include <string>


#ifdef LOGMODE
#include <stdio.h>
#endif

class Bus;

class CPU
{
public:
	CPU();
	~CPU();

public:
	uint8_t a = 0x00;
	uint8_t x = 0x00;
	uint8_t y = 0x00;
	uint8_t stack_pointer = 0x00;
	uint8_t program_counter = 0x0000;
	uint8_t status = 0x00;

	void reset();
	void irq();
	void nmi();
	void clock();

	bool complete();

	void Connect(Bus* n)
	{
		bus = n;
	}

	std::map<uint16_t, std::string> disassemble(uint16_t nstart, uint16_t nStop);

	enum FLAGS
	{
		C = (1 << 0), // Carry
		Z = (1 << 1), // Zero
		I = (1 << 2), // Disable Interrupt
		D = (1 << 3), // Decimal Mode
		B = (1 << 4), // Break
		U = (1 << 5), // Unused
		V = (1 << 6), // Overflow
		N = (1 << 7), // Negative
	};

private:

	uint8_t GetFlag(FLAGS f);
	void SetFlag(FLAGS f, bool value);

	uint8_t fetched = 0x00;
	uint16_t temp = 0x0000;
	uint16_t addr_abs = 0x0000;
	uint16_t addr_rel = 0x00;
	uint8_t opcode = 0x00;
	uint8_t cycles = 0;
	uint32_t clock_count = 0;

	Bus* bus = nullptr;
	uint8_t read(uint16_t a);
	void write(uint16_t a, uint8_t d);

	uint8_t fetch();

	struct INSTRUCTION
	{
		std::string name;
		uint8_t		(CPU::* operate)(void) = nullptr;
		uint8_t		(CPU::* addrmode)(void) = nullptr;
		uint8_t		cycles = 0;
	};

	std::vector<INSTRUCTION> lookup;

private:

	// Addressing Modes
	uint8_t IMP(); // Implicit
	uint8_t IMM(); // Immediate
	uint8_t ZP0(); // Zero Page
	uint8_t ZPX(); // Zero Page X
	uint8_t ZPY(); // Zero Page Y
	uint8_t REL(); // Relative
	uint8_t ABS(); // Absolute
	uint8_t ABX(); // Absolute X
	uint8_t ABY(); // Absolute Y
	uint8_t IND(); // Indirect
	uint8_t IZX(); // Indexed Indirect
	uint8_t IZY(); // Indirect Indexted 

private:

	// Opcodes

	// Load/Store Operations

	uint8_t LDA();
	uint8_t LDX();
	uint8_t LDY();
	uint8_t STA();
	uint8_t STX();
	uint8_t STY();

	// Register Transfers

	uint8_t TAX();
	uint8_t TAY();
	uint8_t TXA();
	uint8_t TYA();

	// Stack Operations

	uint8_t TSX();
	uint8_t TXS();
	uint8_t PHA();
	uint8_t PHP();
	uint8_t PLA();
	uint8_t PLP();

	// Logical

	uint8_t AND();
	uint8_t EOR();
	uint8_t ORA();
	uint8_t BIT();

	// Arithmetic

	uint8_t ADC();
	uint8_t SBC();
	uint8_t CMP();
	uint8_t CPX();
	uint8_t CPY();

	// Increment and decrement

	uint8_t INC();
	uint8_t INX();
	uint8_t INY();
	uint8_t DEC();
	uint8_t DEX();
	uint8_t DEY();

	// Shifts

	uint8_t ASL();
	uint8_t LSR();
	uint8_t ROL();
	uint8_t ROR();

	// Jumps nad Calls

	uint8_t JMP();
	uint8_t JSR();
	uint8_t RTS();

	// Branches

	uint8_t BCC();
	uint8_t BCS();
	uint8_t BEQ();
	uint8_t BMI();
	uint8_t BNE();
	uint8_t BPL();
	uint8_t BVC();
	uint8_t BVS();

	// Status flag changes

	uint8_t CLC();
	uint8_t CLD();
	uint8_t CLI();
	uint8_t CLV();
	uint8_t SEC();
	uint8_t SED();
	uint8_t SEI();

	// system Functions

	uint8_t BRK();
	uint8_t NOP();
	uint8_t RTI();


	// caputre "unoffical" codes - identical to NOP
	uint8_t XXX();

#ifdef LOGMODE
	private:
		FILE* logfile = nullptr;
#endif

};