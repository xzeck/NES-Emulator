#include "cpu.hpp"
#include "Bus.hpp"

CPU::CPU()
{
	using cpu = CPU;
	lookup =
	{
		// ADC

		{"ADC", &cpu::ADC, &cpu::IMM, 2},
		{"ADC", &cpu::ADC, &cpu::ZP0, 3},
		{"ADC", &cpu::ADC, &cpu::ZPX, 4},
		{"ADC", &cpu::ADC, &cpu::ABS, 4},
		{"ADC", &cpu::ADC, &cpu::ABX, 4},
		{"ADC", &cpu::ADC, &cpu::ABY, 4},
		{"ADC", &cpu::ADC, &cpu::IZX, 6},
		{"ADC", &cpu::ADC, &cpu::IZY, 5},

		// AND

		{"AND", &cpu::AND, &cpu::IMM, 2},
		{"AND", &cpu::AND, &cpu::ZP0, 3},
		{"AND", &cpu::AND, &cpu::ZPX, 4},
		{"AND", &cpu::AND, &cpu::ABS, 4},
		{"AND", &cpu::AND, &cpu::ABX, 4},
		{"AND", &cpu::AND, &cpu::ABY, 4},
		{"AND", &cpu::AND, &cpu::IZX, 6},
		{"AND", &cpu::AND, &cpu::IZY, 5},

		// ASL
		{"ASL", &cpu::ASL, &cpu::IMM, 2},
		{"ASL", &cpu::ASL, &cpu::ZP0, 5},
		{"ASL", &cpu::ASL, &cpu::ZPX, 6},
		{"ASL", &cpu::ASL, &cpu::ABS, 6},
		{"ASL", &cpu::ASL, &cpu::ABX, 7},

		// BCC
		{"BCC", &cpu::BCC, &cpu::REL, 2},

		// BCS
		{"BCS", &cpu::BCS, &cpu::REL, 2},

		// BEQ
		{"BEQ", &cpu::BEQ, &cpu::REL, 2},

		// BIT
		{"BIT", &cpu::BIT, &cpu::ZP0, 3},
		{"BIT", &cpu::BIT, &cpu::ABS, 4},

		// BMI
		{"BMI", &cpu::BMI, &cpu::REL, 2},

		// BNE
		{"BNE", &cpu::BNE, &cpu::REL, 2},

		// BPL
		{"BPL", &cpu::BPL, &cpu::REL, 2},

		// BRK
		{"BRK", &cpu::BRK, &cpu::IMP, 7},

		// BVC
		{"BVC", &cpu::BVC, &cpu::REL, 2},

		// BVS
		{"BVS", &cpu::BVS, &cpu::REL, 2},

		// CLC
		{"CLC", &cpu::CLC, &cpu::IMP, 2},

		// CLD
		{"CLD", &cpu::CLD, &cpu::IMP, 2},

		// CLI
		{"CLI", &cpu::CLI, &cpu::IMP, 2},

		// CLV
		{"CLV", &cpu::CLV, &cpu::IMP, 2},

		// CMP
		{"CMP", &cpu::CMP, &cpu::IMM, 2},
		{"CMP", &cpu::CMP, &cpu::ZP0, 3},
		{"CMP", &cpu::CMP, &cpu::ZPX, 4},
		{"CMP", &cpu::CMP, &cpu::ABS, 4},
		{"CMP", &cpu::CMP, &cpu::ABX, 4},
		{"CMP", &cpu::CMP, &cpu::ABY, 4},
		{"CMP", &cpu::CMP, &cpu::IZX, 6},
		{"CMP", &cpu::CMP, &cpu::IZY, 5},

		// CPX
		{"CPX", &cpu::CPX, &cpu::IMM, 2},
		{"CPX", &cpu::CPX, &cpu::ZP0, 3},
		{"CPX", &cpu::CPX, &cpu::ABS, 4},

		// CPY
		{"CPY", &cpu::CPY, &cpu::IMM, 2},
		{"CPY", &cpu::CPY, &cpu::ZP0, 3},
		{"CPY", &cpu::CPY, &cpu::ABS, 4},

		// DEC
		{"DEC", &cpu::DEC, &cpu::ZP0, 5},
		{"DEC", &cpu::DEC, &cpu::ZPX, 6},
		{"DEC", &cpu::DEC, &cpu::ABS, 6},
		{"DEC", &cpu::DEC, &cpu::ABX, 7},

		// DEX
		{"DEX", &cpu::DEX, &cpu::IMP, 2},

		// DEY
		{"DEY", &cpu::DEY, &cpu::IMP, 2},

		// EOR
		{"EOR", &cpu::EOR, &cpu::IMM, 2},
		{"EOR", &cpu::EOR, &cpu::ZP0, 3},
		{"EOR", &cpu::EOR, &cpu::ZPX, 4},
		{"EOR", &cpu::EOR, &cpu::ABS, 4},
		{"EOR", &cpu::EOR, &cpu::ABX, 4},
		{"EOR", &cpu::EOR, &cpu::ABY, 4},
		{"EOR", &cpu::EOR, &cpu::IZX, 6},
		{"EOR", &cpu::EOR, &cpu::IZY, 5},

		// INC
		{"INC", &cpu::INC, &cpu::ZP0, 3},
		{"INC", &cpu::INC, &cpu::ZPX, 4},
		{"INC", &cpu::INC, &cpu::ABS, 4},
		{"INC", &cpu::INC, &cpu::ABX, 4},

		// INX
		{"INX", &cpu::INX, &cpu::IMP, 2},

		// INY
		{"INY", &cpu::INY, &cpu::IMP, 2},

		// JMP
		{"JMP", &cpu::JMP, &cpu::ABS, 3},
		{"JMP", &cpu::JMP, &cpu::IND, 5},

		// JSR
		{"JSR", &cpu::JSR, &cpu::ABS, 6},

		// LDA
		{"LDA", &cpu::LDA, &cpu::IMM, 2},
		{"LDA", &cpu::LDA, &cpu::ZP0, 3},
		{"LDA", &cpu::LDA, &cpu::ZPX, 4},
		{"LDA", &cpu::LDA, &cpu::ABS, 4},
		{"LDA", &cpu::LDA, &cpu::ABX, 4},
		{"LDA", &cpu::LDA, &cpu::ABY, 4},
		{"LDA", &cpu::LDA, &cpu::IZX, 6},
		{"LDA", &cpu::LDA, &cpu::IZY, 5},

		// LDX
		{"LDX", &cpu::LDX, &cpu::IMM, 2},
		{"LDX", &cpu::LDX, &cpu::ZP0, 3},
		{"LDX", &cpu::LDX, &cpu::ZPY, 4},
		{"LDX", &cpu::LDX, &cpu::ABS, 4},
		{"LDX", &cpu::LDX, &cpu::ABY, 4},

		// LDY
		{"LDY", &cpu::LDY, &cpu::IMM, 2},
		{"LDY", &cpu::LDY, &cpu::ZP0, 3},
		{"LDY", &cpu::LDY, &cpu::ZPX, 4},
		{"LDY", &cpu::LDY, &cpu::ABS, 4},
		{"LDY", &cpu::LDY, &cpu::ABX, 4},

		// LSR
		{"LSR", &cpu::LSR, &cpu::IMM, 2},
		{"LSR", &cpu::LSR, &cpu::ZP0, 5},
		{"LSR", &cpu::LSR, &cpu::ZPX, 6},
		{"LSR", &cpu::LSR, &cpu::ABS, 6},
		{"LSR", &cpu::LSR, &cpu::ABX, 7},

		// NOP
		{"NOP", &cpu::NOP, &cpu::IMP, 2},

		// ORA
		{"ORA", &cpu::ORA, &cpu::IMM, 2},
		{"ORA", &cpu::ORA, &cpu::ZP0, 3},
		{"ORA", &cpu::ORA, &cpu::ZPX, 4},
		{"ORA", &cpu::ORA, &cpu::ABS, 4},
		{"ORA", &cpu::ORA, &cpu::ABX, 4},
		{"ORA", &cpu::ORA, &cpu::ABY, 4},
		{"ORA", &cpu::ORA, &cpu::IZX, 6},
		{"ORA", &cpu::ORA, &cpu::IZY, 5},

		// PHA
		{"PHA", &cpu::PHA, &cpu::IMP, 3},

		// PHP
		{"PHP", &cpu::PHP, &cpu::IMP, 3},
		
		// PLA
		{"PLA", &cpu::PLA, &cpu::IMP, 4},

		// PLP
		{"PLP", &cpu::PLP, &cpu::IMP, 4},

		// ROL 
		{"ROL", &cpu::ROL, &cpu::IMM, 2},
		{"ROL", &cpu::ROL, &cpu::ZP0, 5},
		{"ROL", &cpu::ROL, &cpu::ZPX, 6},
		{"ROL", &cpu::ROL, &cpu::ABS, 6},
		{"ROL", &cpu::ROL, &cpu::ABX, 7},
		
		// ROR
		{"ROR", &cpu::ROR, &cpu::IMM, 2},
		{"ROR", &cpu::ROR, &cpu::ZP0, 5},
		{"ROR", &cpu::ROR, &cpu::ZPX, 6},
		{"ROR", &cpu::ROR, &cpu::ABS, 6},
		{"ROR", &cpu::ROR, &cpu::ABX, 7},

		// RTI
		{"RTI", &cpu::RTI, &cpu::IMP, 6},

		// RTS
		{"RTS", &cpu::RTS, &cpu::IMP, 6},

		// SBC
		{"SBC", &cpu::SBC, &cpu::IMM, 2},
		{"SBC", &cpu::SBC, &cpu::ZP0, 3},
		{"SBC", &cpu::SBC, &cpu::ZPX, 4},
		{"SBC", &cpu::SBC, &cpu::ABS, 4},
		{"SBC", &cpu::SBC, &cpu::ABX, 4},
		{"SBC", &cpu::SBC, &cpu::ABY, 4},
		{"SBC", &cpu::SBC, &cpu::IZX, 6},
		{"SBC", &cpu::SBC, &cpu::IZY, 5},

		// SEC
		{"SEC", &cpu::SEC, &cpu::IMP, 2},

		// SED
		{"SED", &cpu::SED, &cpu::IMP, 2},

		// SEI
		{"SEI", &cpu::SEI, &cpu::IMP, 2},

		// STA
		{"STA", &cpu::STA, &cpu::ZP0, 3},
		{"STA", &cpu::STA, &cpu::ZPX, 4},
		{"STA", &cpu::STA, &cpu::ABS, 4},
		{"STA", &cpu::STA, &cpu::ABX, 5},
		{"STA", &cpu::STA, &cpu::ABY, 5},
		{"STA", &cpu::STA, &cpu::IZX, 6},
		{"STA", &cpu::STA, &cpu::IZY, 6},

		// STX
		{"STX", &cpu::STX, &cpu::ZP0, 3},
		{"STX", &cpu::STX, &cpu::ZPY, 4},
		{"STX", &cpu::STX, &cpu::ABS, 4},

		// STY
		{"STY", &cpu::STY, &cpu::ZP0, 3},
		{"STY", &cpu::STY, &cpu::ZPY, 4},
		{"STY", &cpu::STY, &cpu::ABS, 4},

		// TAX
		{"TAX", &cpu::TAX, &cpu::IMP, 2},

		// TAY
		{"TAY", &cpu::TAY, &cpu::IMP, 2},

		// TSX
		{"TSX", &cpu::TSX, &cpu::IMP, 2},

		// TXA
		{"TXA", &cpu::TXA, &cpu::IMP, 2},

		// TXA
		{"TXS", &cpu::TXS, &cpu::IMP, 2},

		// TYA
		{"TYA", &cpu::TYA, &cpu::IMP, 2},

		// ???
		{"???", &cpu::NOP, &cpu::IMP, 2},
		{"???", &cpu::NOP, &cpu::IMP, 2},
		{"???", &cpu::NOP, &cpu::IMP, 2},
		{"???", &cpu::NOP, &cpu::IMP, 2},
		{"???", &cpu::NOP, &cpu::IMP, 2},
		{"???", &cpu::NOP, &cpu::IMP, 2},
		{"???", &cpu::NOP, &cpu::IMP, 2},
		{"???", &cpu::NOP, &cpu::IMP, 2},
		{"???", &cpu::NOP, &cpu::IMP, 2},
		{"???", &cpu::NOP, &cpu::IMP, 3},
		{"???", &cpu::NOP, &cpu::IMP, 3},
		{"???", &cpu::NOP, &cpu::IMP, 3},
		{"???", &cpu::NOP, &cpu::IMP, 4},
		{"???", &cpu::NOP, &cpu::IMP, 4},
		{"???", &cpu::NOP, &cpu::IMP, 4},
		{"???", &cpu::NOP, &cpu::IMP, 4},
		{"???", &cpu::NOP, &cpu::IMP, 4},
		{"???", &cpu::NOP, &cpu::IMP, 4},
		{"???", &cpu::NOP, &cpu::IMP, 4},
		{"???", &cpu::NOP, &cpu::IMP, 4},
		{"???", &cpu::NOP, &cpu::IMP, 4},
		{"???", &cpu::NOP, &cpu::IMP, 4},
		{"???", &cpu::NOP, &cpu::IMP, 4},
		{"???", &cpu::NOP, &cpu::IMP, 4},
		{"???", &cpu::NOP, &cpu::IMP, 4},
		{"???", &cpu::NOP, &cpu::IMP, 5},
		{"???", &cpu::SBC, &cpu::IMP, 2},
		{"???", &cpu::XXX, &cpu::IMP, 2},
		{"???", &cpu::XXX, &cpu::IMP, 2},
		{"???", &cpu::XXX, &cpu::IMP, 2},
		{"???", &cpu::XXX, &cpu::IMP, 2},
		{"???", &cpu::XXX, &cpu::IMP, 2},
		{"???", &cpu::XXX, &cpu::IMP, 2},
		{"???", &cpu::XXX, &cpu::IMP, 2},
		{"???", &cpu::XXX, &cpu::IMP, 2},
		{"???", &cpu::XXX, &cpu::IMP, 2},
		{"???", &cpu::XXX, &cpu::IMP, 2},
		{"???", &cpu::XXX, &cpu::IMP, 2},
		{"???", &cpu::XXX, &cpu::IMP, 2},
		{"???", &cpu::XXX, &cpu::IMP, 2},
		{"???", &cpu::XXX, &cpu::IMP, 2},
		{"???", &cpu::XXX, &cpu::IMP, 2},
		{"???", &cpu::XXX, &cpu::IMP, 2},
		{"???", &cpu::XXX, &cpu::IMP, 2},
		{"???", &cpu::XXX, &cpu::IMP, 2},
		{"???", &cpu::XXX, &cpu::IMP, 2},
		{"???", &cpu::XXX, &cpu::IMP, 3},
		{"???", &cpu::XXX, &cpu::IMP, 3},
		{"???", &cpu::XXX, &cpu::IMP, 4},
		{"???", &cpu::XXX, &cpu::IMP, 4},
		{"???", &cpu::XXX, &cpu::IMP, 4},
		{"???", &cpu::XXX, &cpu::IMP, 4},
		{"???", &cpu::XXX, &cpu::IMP, 4},
		{"???", &cpu::XXX, &cpu::IMP, 4},
		{"???", &cpu::XXX, &cpu::IMP, 5},
		{"???", &cpu::XXX, &cpu::IMP, 5},
		{"???", &cpu::XXX, &cpu::IMP, 5},
		{"???", &cpu::XXX, &cpu::IMP, 5},
		{"???", &cpu::XXX, &cpu::IMP, 5},
		{"???", &cpu::XXX, &cpu::IMP, 5},
		{"???", &cpu::XXX, &cpu::IMP, 5},
		{"???", &cpu::XXX, &cpu::IMP, 5},
		{"???", &cpu::XXX, &cpu::IMP, 5},
		{"???", &cpu::XXX, &cpu::IMP, 5},
		{"???", &cpu::XXX, &cpu::IMP, 6},
		{"???", &cpu::XXX, &cpu::IMP, 6},
		{"???", &cpu::XXX, &cpu::IMP, 6},
		{"???", &cpu::XXX, &cpu::IMP, 6},
		{"???", &cpu::XXX, &cpu::IMP, 6},
		{"???", &cpu::XXX, &cpu::IMP, 6},
		{"???", &cpu::XXX, &cpu::IMP, 6},
		{"???", &cpu::XXX, &cpu::IMP, 6},
		{"???", &cpu::XXX, &cpu::IMP, 6},
		{"???", &cpu::XXX, &cpu::IMP, 6},
		{"???", &cpu::XXX, &cpu::IMP, 6},
		{"???", &cpu::XXX, &cpu::IMP, 6},
		{"???", &cpu::XXX, &cpu::IMP, 6},
		{"???", &cpu::XXX, &cpu::IMP, 6},
		{"???", &cpu::XXX, &cpu::IMP, 6},
		{"???", &cpu::XXX, &cpu::IMP, 7},
		{"???", &cpu::XXX, &cpu::IMP, 7},
		{"???", &cpu::XXX, &cpu::IMP, 7},
		{"???", &cpu::XXX, &cpu::IMP, 7},
		{"???", &cpu::XXX, &cpu::IMP, 7},
		{"???", &cpu::XXX, &cpu::IMP, 7},
		{"???", &cpu::XXX, &cpu::IMP, 7},
		{"???", &cpu::XXX, &cpu::IMP, 7},
		{"???", &cpu::XXX, &cpu::IMP, 7},
		{"???", &cpu::XXX, &cpu::IMP, 7},
		{"???", &cpu::XXX, &cpu::IMP, 7},
		{"???", &cpu::XXX, &cpu::IMP, 7},
		{"???", &cpu::XXX, &cpu::IMP, 8},
		{"???", &cpu::XXX, &cpu::IMP, 8},
		{"???", &cpu::XXX, &cpu::IMP, 8},
		{"???", &cpu::XXX, &cpu::IMP, 8},
		{"???", &cpu::XXX, &cpu::IMP, 8},
		{"???", &cpu::XXX, &cpu::IMP, 8},
		{"???", &cpu::XXX, &cpu::IMP, 8},
		{"???", &cpu::XXX, &cpu::IMP, 8},
		{"???", &cpu::XXX, &cpu::IMP, 8},
		{"???", &cpu::XXX, &cpu::IMP, 8},
		{"???", &cpu::XXX, &cpu::IMP, 8},
		{"???", &cpu::XXX, &cpu::IMP, 8}
	};
}

CPU::~CPU()
{

}

// BUS

uint8_t CPU::read(uint16_t address)
{
	return bus->read(address);
}

void CPU::write(uint16_t address, uint8_t data)
{
	bus->write(address, data);
}

void CPU::reset()
{
	addr_abs = 0x0FFFC;
	uint16_t lo = read(addr_abs + 0);
	uint16_t hi = read(addr_abs + 1);

	program_counter = (hi << 8) + 1;
	
	// register reset
	a = 0;
	x = 0;
	y = 0;
	stack_pointer = 0xFD;
	status = 0x00 | U;

	addr_rel = 0x0000;
	addr_abs = 0x0000;
	fetched = 0x00;

	// reset time
	cycles = 0;
}

void CPU::irq()
{
	if (GetFlag(I) == 0)
	{
		// push program counter to stack
		write(0x0100 + stack_pointer, (program_counter >> 8) & 0x00FF);
		stack_pointer--;

		// program counter is 16 bit so we need to push it twice
		write(0x0100 + stack_pointer, (program_counter >> 8) & 0x00FF);
		stack_pointer--;
		
		// Push status register to stack
		SetFlag(B, 0);
		SetFlag(U, 1);
		SetFlag(I, 1);
		write(0x0100 + stack_pointer, status);
		stack_pointer--;

		// Read address for program counter from fixed location
		addr_abs = 0x0FFFE;
		uint16_t lo = read(addr_abs + 0);
		uint16_t hi = read(addr_abs + 1);
		program_counter = (hi << 8) | lo;

		// IRQ cycle time
		cycles = 7;
	}
}


// Non-Makable Interrupt
void CPU::nmi()
{
	// push program counter to stack
	write(0x0100 + stack_pointer, (program_counter >> 8) & 0x00FF);
	stack_pointer--;

	// program counter is 16 bit so we need to push it twice
	write(0x0100 + stack_pointer, (program_counter >> 8) & 0x00FF);
	stack_pointer--;
	
	// Push status register to stack
	SetFlag(B, 0);
	SetFlag(U, 1);
	SetFlag(I, 1);
	write(0x0100 + stack_pointer, status);
	stack_pointer--;

	addr_abs = 0x0FFFA;
	uint16_t lo = read(addr_abs + 0);
	uint16_t hi = read(addr_abs + 1);
	program_counter = (hi << 8) | lo;

	// NMI cycle time
	cycles = 8;
}

void CPU::clock()
{
	if (cycles == 0)
	{
		opcode = read(program_counter);

#ifdef LOGMODE
		uint16_t log_pc = pc;
#endif

		SetFlag(U, true);

		// increment program counter
		program_counter++;

		// Get number of cycles
		cycles = lookup[opcode].cycles;

		// get required addressing mode
		uint8_t additional_cycles_1 = (this->*lookup[opcode].addrmode)();

		// perform the operation
		uint8_t additional_cycles_2 = (this->*lookup[opcode].operate)();

		cycles += (additional_cycles_1 + additional_cycles_2);

		SetFlag(U, true);

#ifdef LOGMODE
		if (logfile == nullptr) logfile = fopen("log.txt", "w");
		if (logfile != nullptr)
		{
			fprintf(logfile, "CLOCK_COUNT:%10d:%02d \
							  PROGRAM COUNTER:%04X %s \
							  REGISTER=(A:%02X X:%02X Y:%02X) \
							  FLAGS=(%s%s%s%s%s%s%s%s) \
							  STACK_POINTER:%02X\n",
				clock_count, 0, log_pc, "XXX", a, x, y,
				GetFlag(N) ? "N" : ".", GetFlag(V) ? "V" : ".", GetFlag(U) ? "U" : ".",
				GetFlag(B) ? "B" : ".", GetFlag(D) ? "D" : ".", GetFlag(I) ? "I" : ".",
				GetFlag(Z) ? "Z" : ".", GetFlag(C) ? "C" : ".", stack_pointer);
		}
#endif

		// Increment global clock counter
		clock_count++;

		// decrement  cycles remaining for this instruction
		cycles--;
	}
}


// FLAGS
uint8_t CPU::GetFlag(FLAGS flag)
{
	return ((status & flag) > 0) ? 1 : 0;
}

void CPU::SetFlag(FLAGS flag, bool value)
{
	if (value) status |= flag;
	else status &= ~flag;
}

// Addressing Modes
// Ref: https://www.nesdev.org/obelisk-6502-guide/addressing.html, http://archive.6502.org/datasheets/rockwell_r650x_r651x.pdf

// Implied addressing mode
uint8_t CPU::IMP()
{
	fetched = a;
	return 0;
}

// Immediate Mode
// Second byte of instruction contains the operand
// we can use this to load the next instruction 
uint8_t CPU::IMM()
{
	addr_abs = program_counter++;
	return 0;
}

// Zero Page
// Instruction with this addressing mode only uses 8 bit address
// Meaning first 256 bytes 0x0000 - 0x00FF
uint8_t CPU::ZP0()
{
	addr_abs = read(program_counter);
	program_counter++;
	addr_abs &= 0x00FF;
	return 0;
}

// ZPX - Zero Page with X Offset
// Same as ZP0
// Effective address is calculatedby adding the second byte to contents of the X register
uint8_t CPU::ZPX()
{
	addr_abs = (read(program_counter) + x);
	program_counter++;
	addr_abs &= 0x00FF;
	return 0;
}

// ZPY - Zero Page with Y Offset
// Same as ZPX but with Y Register
uint8_t CPU::ZPY()
{
	addr_abs = (read(program_counter) + y);
	program_counter++;
	addr_abs &= 0x00FF;
	return 0;
}

// Relative

uint8_t CPU::REL()
{
	addr_rel = read(program_counter);
	program_counter++;
	// Check second byte which is an operand
	// check if the operand is in the range
	if (addr_rel & 0x80)
		addr_rel |= 0xFF00;
	
	return 0;
}

// Absolute
// Read a full 16 bit addressing mode
uint8_t CPU::ABS()
{
	uint16_t lo = read(program_counter++);
	uint16_t hi = read(program_counter++);

	addr_abs = (hi << 8) | lo;

	return 0;
}

// Absolute with X offset
//Same as absolute addressing but with X register offset
uint8_t CPU::ABX()
{
	uint16_t lo = read(program_counter++);
	uint16_t hi = read(program_counter++);

	addr_abs = (hi << 8) | lo;
	addr_abs += x;

	if ((addr_abs & 0xFF00) != (hi << 8))
		return 1;
	else
		return 0;
}

// Absolute with Y offset
//Same as absolute addressing but with Y register as offset
uint8_t CPU::ABY()
{
	uint16_t lo = read(program_counter);
	program_counter++;
	uint16_t hi = read(program_counter);
	program_counter++;

	addr_abs = (hi << 8) | lo;
	addr_abs += y;

	if ((addr_abs & 0xFF00) != (hi << 8))
		return 1;
	else
		return 0;
}

