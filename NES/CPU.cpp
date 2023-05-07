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

// Indirect
// The instruction contains the 16 bit address of the least significant byte of another 16 bit memory address
// Let's say the instruction is pointing to $0120 which contains $FC
// Then it will read the next address too which is $0121 which contains $FF
// So it will load $FFFC 
uint8_t CPU::IND()
{
	uint16_t lo_ptr = read(program_counter++);
	uint16_t hi_ptr = read(program_counter++);

	uint16_t ptr = (hi_ptr << 8) | lo_ptr;

	if (lo_ptr == 0x00FF) // Page boundry
	{
		addr_abs = (read(ptr & 0xFF00) << 8) | read(ptr + 0);
	}
	else // Normal Behavior
	{
		addr_abs = (read(ptr + 1) << 8) | read(ptr + 0);
	}

	return 0;
}

// Indirect X
uint8_t CPU::IZX()
{
	uint16_t t = read(program_counter++);

	uint16_t lo = read((uint16_t)(t + (uint16_t)x) & 0x00FF);
	uint16_t hi = read((uint16_t)(t + (uint16_t)x + 1) & 0x00FF);

	addr_abs = (hi << 8) | lo;

	return 0;
}

// Indirect Y
uint8_t CPU::IZY()
{
	uint16_t t = read(program_counter++);

	uint16_t lo = read(t & 0x00FF);
	uint16_t hi = read(t + 1) & 0x00FF;

	addr_abs = (hi << 8) | lo;
	addr_abs += y;

	if ((addr_abs & 0xFF00) != (hi << 8))
		return 1;
	else
		return 0;
}


// Fetch
uint8_t CPU::fetch()
{
	if (!(lookup[opcode].addrmode == &CPU::IMP))
		fetched = read(addr_abs);

	return fetched;
}

// Instructions

// ADC 
// A,Z,C,N = A + M + C
// Flags:  C, Z, V, N
uint8_t CPU::ADC()
{
	fetch();

	temp = (uint16_t)a + (uint16_t)fetched + (uint16_t)GetFlag(C);

	// Set Carry Flag
	// Set if overflow in bit 7
	SetFlag(C, temp > 255);

	// Zero  Flag is set result is 0
	// set if A = 0 
	SetFlag(Z, (temp & 0x00FF) == 0);

	// Set signed Overflow flag
	// (+ve num) + (+ve num) = (-ve res) -> overflow
	// (-ve num) + (-ve num) = (+ve res) -> overflow
	SetFlag(V, (~((uint16_t)a ^ (uint16_t)fetched) & ((uint16_t)a ^ (uint16_t)temp)) & 0x0080);

	// Set Negative flag
	// Set if bit 7 is set
	SetFlag(N, temp & 0x80);

	// load 8 bit result into accumulator
	a = temp & 0x00FF;

	return 1;
}

// SBC
// A,Z,C,N = A - M - (1 - C)
// Flags: C, Z, V, N
uint8_t CPU::SBC()
{
	fetch();
	
	// inverting the bottom 8 bits with xor
	// To make a signed psitive number we can invert bits and add 1
	// 10 = 00001010 -> 11110101 + 00000001 -> 11110110
	uint16_t m = ((uint16_t)fetched ^ 0x00FF);

	// We convert A = A - M - (1 - C) -> A = A + -1 *(M - (1 - C)) -> A = A + (-M + 1 + C) 
	// We don't need to add 1 since we have already added 1 while converting to 2's complement
	temp = (uint16_t)a + m + (uint16_t)GetFlag(C);
	
	// Same as addition
	SetFlag(C, temp & 0xFF00);
	SetFlag(Z, ((temp & 0x00FF) == 0));
	SetFlag(V, (temp ^ (uint16_t)a) & (temp ^ m) & 0x0080);
	SetFlag(N, temp & 0x0080);

	a = temp & 0x00FF;

	return 1;
}

// AND
// Flags:  A, Z, N
uint8_t CPU::AND()
{
	fetch();
	a = a & fetched;

	// Set Zero Flag
	SetFlag(Z, a == 0x00);

	// Set Negative Flag
	SetFlag(N, a & 0x80);

	return 1;
}

// ASL
// Flags: Z, C, N
uint8_t CPU::ASL()
{
	fetch();

	temp = (uint16_t)fetched << 1;

	// Set Carry Flag
	SetFlag(C, (temp & 0xFF00) > 0);
	 
	// Set Zero Flag
	SetFlag(Z, (temp & 0x00FF) == 0x00);

	// Set Negative Flag
	SetFlag(N, temp & 0x80);

	if (lookup[opcode].addrmode == &CPU::IMP)
		a = temp & 0x00FF;
	else
		write(addr_abs, temp & 0x00FF);

	return 0;
}

/*
The following line would repeat throughout the branch instrcutions:


if ((addr_abs & 0xFF00) != (program_counter & 0xFF00))
			cycles++;

This is to check if the page is crossed or not to increment the cycle count
*/

// BCC: Branch if Carry Clear
// if(C == 0) program_counter = address

uint8_t CPU::BCC()
{

	// 2 cycles
	if (GetFlag(C) == 0)
	{
		// Add a cycle since branch succeeds 
		cycles++;
		addr_abs = program_counter + addr_rel;
		
		// Add another cycle if new page
		if ((addr_abs & 0xFF00) != (program_counter & 0xFF00))
			cycles++;

		program_counter = addr_abs;
	}

	return 0;
}

// BCS: Branch if Carry Set
// If Carry flag is set add displacement to program counter
uint8_t CPU::BCS()
{
	if (GetFlag(C) == 1)
	{
		cycles++;
		addr_abs = program_counter + addr_rel;

		if ((addr_abs & 0xFF00) != (program_counter & 0xFF00))
			cycles++;

		program_counter = addr_abs;
	}

	return 0;
}

// BEQ: Branch if Equal
// If Zero flag is set add displacement to program counter
uint8_t CPU::BEQ()
{
	if (GetFlag(Z) == 1)
	{
		cycles++;
		addr_abs = program_counter + addr_rel;

		if ((addr_abs & 0xFF00) != (program_counter & 0xFF00))
			cycles++;

		program_counter = addr_abs;
	}

	return 0;
}

// BIT: Bit Test
// Used to test if bits are set in a target memory location
// Mask patter in A is ANDed with value in memory to set or clear the zero flag
// Bits 7 and 6 of the vlaue from memory are copied into N and V flag
uint8_t CPU::BIT()
{
	fetch();
	temp = a & fetched;
	SetFlag(Z, (temp & 0x00FF) == 0x00);
	SetFlag(V, fetched & (1 << 6));
	SetFlag(N, fetched & (1 << 7));

	return 0;
}

// BMI: Branch if Minus
// Add relative displacement to program counter if Negative flag is set
uint8_t CPU::BMI()
{
	if (GetFlag(N) == 1)
	{
		cycles++;
		addr_abs = program_counter + addr_rel;

		if ((addr_abs & 0xFF00) != (program_counter & 0xFF00))
			cycles++;

		program_counter = addr_abs;
	}

	return 0;
}

// BNE: Branch if Not Equal
// If Zero flag is set add relative address to program counter
uint8_t CPU::BNE()
{
	if (GetFlag(Z) == 0)
	{
		cycles++;
		addr_abs = program_counter + addr_rel;

		if ((addr_abs & 0xFF00) != (program_counter & 0xFF00))
			cycles++;

		program_counter = addr_abs;
	}

	return 0;
}

//BPL: Branc if Positive
// If negative flag is clear then add relative displacement
uint8_t CPU::BPL()
{
	if (GetFlag(N) == 0)
	{
		cycles++;
		addr_abs = program_counter + addr_rel;

		if ((addr_abs & 0xFF00) != (program_counter & 0xFF00))
			cycles++;

		program_counter = addr_abs;
	}

	return 0;
}

// BRK: Break
// Generates an interrupt request
// Steps:
// 1. Program counter and processor status are pushed to the stack
// 2. IRQ interrupt vector at FFFE/F is loaded into the program counter
// 3. Break flag is set to 1

uint8_t CPU::BRK()
{
	program_counter++;
	SetFlag(I, 1);
	
	// Write program counter to the stack
	write(0x0100 + stack_pointer, (program_counter >> 8) & 0x00FF);
	stack_pointer--;
	write(0x100 + stack_pointer, program_counter & 0x00FF);
	stack_pointer--;

	// Write processor status to the stack and set breka flag
	SetFlag(B, 1);
	write(0x0100 + stack_pointer, status);
	stack_pointer--;
	SetFlag(B, 0);

	// Load IRQ Interrupt vector from 0xFFFE/F
	program_counter = (uint16_t)read(0xFFFE) | ((uint16_t)read(0xFFFF) << 8);

	return 0;
}

// BVC: Branch Overflow Clear
// If Overflow fla is set then add relative displacement to program counter
uint8_t CPU::BVC()
{
	if (GetFlag(V) == 0)
	{
		cycles++;
		addr_abs = program_counter + addr_rel;

		if ((addr_abs & 0xFF00) != (program_counter & 0xFF00))
			cycles++;

		program_counter = addr_abs;
	}

	return 0;
}

//BVS: Branch if Overflow Set
uint8_t CPU::BVS()
{
	if (GetFlag(V) == 1)
	{
		cycles++;
		addr_abs = program_counter + addr_rel;

		if ((addr_abs & 0xFF00) != (program_counter & 0xFF00))
			cycles++;

		program_counter = addr_abs;
	}

	return 0;
}

//CLC: Clear Carry Flag
// Set Carry Flag to 0
uint8_t CPU::CLC()
{
	SetFlag(C, false);
	return 0;
}

//CLD: Clear Decimal Mode
uint8_t CPU::CLD()
{
	SetFlag(D, false);
	return 0;
}

//CLI: Clear Interrupt
uint8_t CPU::CLI()
{
	SetFlag(I, false);
	return 0;
}

uint8_t CPU::CLV()
{
	SetFlag(V, false);
	return 0;
}

// CMP: Compare
// Compares accumlator content with memory contents
// Flags: N, C, Z
// C -> 1 : A >= M
// Z -> 0 : A == M
// N -> 1 : (A & 0x0080) == 1
uint8_t CPU::CMP()
{
	fetch();
	temp = (uint16_t)a - (uint16_t)fetched;

	SetFlag(C, a >= fetched);
	// A - M == 0
	SetFlag(Z, (temp & 0x00FF) == 0x0000);
	SetFlag(N, (temp & 0x0080));

	return 1;
}

// CPX: Compare X Register
// Compares contents of X register with memory held value
// Flags: Z, C, N
// C -> 1 : X >= M
// Z -> 1 : X == M
// N -> 1 : (X & 0x0080) == 1
uint8_t CPU::CPX()
{
	fetch();
	temp = (uint16_t)x - (uint16_t)fetched;

	SetFlag(C, x >= fetched);
	// X - M == 0
	SetFlag(Z, (temp & 0x00FF) == 0x0000);
	SetFlag(N, (temp & 0x0080));

	return 0;
}

// CPY: Compare Y Register
// Compares contents for Y regiser with memory held value
// Flags: Z, C, N
// C -> 1 : Y >= M
// Z -> 1 : Y == M
// N -> 1 : (Y & 0x0080) == 1
uint8_t CPU::CPY()
{
	fetch();
	temp = (uint16_t)y - (uint16_t)fetched;

	SetFlag(C, y >= fetched);
	// Y - M == 0
	SetFlag(Z, (temp & 0x00FF) == 0x0000);
	SetFlag(N, (temp & 0x0080));

	return 0;
}

// DEC: Decrement value at memory location
// M = M - 1
// Flags: N, Z
uint8_t CPU::DEC()
{
	fetch();
	temp = fetched - 1;
	write(addr_abs, temp & 0x00FF);
	SetFlag(Z, (temp & 0x00FF) == 0x0000);
	SetFlag(N, temp & 0x0080);

	return 0;
}

// DEX: Decrement X Register
// X = X - 1
// Flags: N, Z
uint8_t CPU::DEX()
{
	x--;
	SetFlag(Z, x == 0x00);
	SetFlag(N, x & 0x80);

	return 0;
}

// DEY: Decrement Y Register
// Y = Y - 1
// Flags: N, Z
uint8_t CPU::DEY()
{
	y--;
	SetFlag(Z, y == 0x00);
	SetFlag(N, y & 0x80);

	return 0;
}

// EOR: Exclusive OR
// A = A ^ M
// Flags: Z, N
uint8_t CPU::EOR()
{
	fetch();
	a = a ^ fetched;
	SetFlag(Z, a == 0x00);
	SetFlag(N, a & 0x80);

	return 1;
}

//INC: Increment value at memory location
// M = M + 1
// Flags: N, Z
uint8_t CPU::INC()
{
	fetch();
	temp = fetched + 1;
	write(addr_abs, temp & 0x00FF);
	SetFlag(Z, (temp & 0x00FF) == 0x0000);
	SetFlag(N, temp & 0x0080);

	return 0;
}

// INX: Increment X register
// X = X + 1
// Flags: N, Z
uint8_t CPU::INX()
{
	x++;
	SetFlag(Z, x == 0x00);
	SetFlag(N, x & 0x80);

	return 0;
}

// INY: Increment Y register
// Y = Y + 1
// Flags: N, Z

uint8_t CPU::INY()
{
	y++;
	SetFlag(Z, y == 0x00);
	SetFlag(N, y & 0x80);

	return 0;
}

// JMP: Jump to memory location
uint8_t CPU::JMP()
{
	program_counter = addr_abs;
	return 0;
}

//JSR: Jump to Sub Routine
// psuhes address - 1 on to the stack
// then sets the program counter to target memory address
uint8_t CPU::JSR()
{
	// address - 1 
	program_counter--;
	
	// push address - 1 to stack
	// We do 2 push because program_counter is 16 bits
	
	write(0x0100 + stack_pointer, (program_counter >> 8) & 0x00FF);
	stack_pointer--;
	write(0x0100 + stack_pointer, program_counter & 0x00FF);
	stack_pointer--;

	// Set program counter to target
	program_counter = addr_abs;

	return 0;
}

//LDA: Load Accumulator
// Loads a byte of memory into the accumulator
// Falgs: Z, N
uint8_t CPU::LDA()
{
	fetch();
	a = fetched;

	// Set Zero flag
	SetFlag(Z, a == 0x00);

	// Set Negative flag
	SetFlag(N, a & 0x80);

	return 1;
}

// LDX: Load X register
// Loads a byte of memory into the X register
// Flags: Z, N
uint8_t CPU::LDX()
{
	fetch();
	x = fetched;
	SetFlag(Z, x == 0x00);
	SetFlag(N, x & 0x80);

	return 1;
}

// LDY: Load Y Register
// Loads a byt  of memory into the Y register
// Flags: Z, N
uint8_t CPU::LDY()
{
	fetch();
	y = fetched;
	SetFlag(Z, y == 0x00);
	SetFlag(N, y & 0x80);

	return 1;
}

// LSR: Logical Shift Right
// Each of the bits in accumulator or memory is shift one place to the right.
// The bit that was in bit 0 is shifted into carry flag
//  Bit 7 is set to zero
uint8_t CPU::LSR()
{
	fetch();
	// Calculate carry before shifting
	SetFlag(C, fetched & 0x0001);

	// Shift one bit to right
	temp = fetched >> 1;

	// Check if zero
	SetFlag(Z, (temp & 0x00FF) == 0x0000);

	// Check if negative
	SetFlag(N, temp & 0x0080);

	// Check addressing mode
	// if implied addressing then store the result into accumulator
	// else write into to memory
	if (lookup[opcode].addrmode == &CPU::IMP)
		a = temp & 0x00FF;
	else
		write(addr_abs, temp & 0x00FF);

	return 0;
}

// NOP: No Operation
// Doesn't make any changes to processor other than normal incrementing of the program counter to next instruction
// Flags: No flags affected

uint8_t CPU::NOP()
{
	// opcodes list: https://wiki.nesdev.com/w/index.php/CPU_unofficial_opcodes
	switch (opcode)
	{
	case 0x1C:
	case 0x3C:
	case 0x5C:
	case 0x7C:
	case 0xDC:
	case 0xFC:
		return 1;
		break;
	}

	return 0;
}

// ORA: Logical Inclusive OR
// Bit by bit OR performed on the content of accumulator using the content of a byte in memory
// A = A | M
// Flags: Z, N
uint8_t CPU::ORA()
{
	fetch();
	a = a | fetched;
	SetFlag(Z, a == 0x00);
	SetFlag(N, a & 0x80);

	return 1;
}

// PHA: Push accumulator to stack
uint8_t CPU::PHA()
{
	write(0x0100 + stack_pointer, a);
	stack_pointer--;
	return 0;
}

// PHP: Push status flag to Stack
uint8_t CPU::PHP()
{
	write(0x0100 + stack_pointer, status | B | U);
	SetFlag(B, 0);
	SetFlag(U, 0);
	stack_pointer--;

	return 0;
}

// PLA: Pull Accumulator
// pulls an 8 bit value form the stack into the accumulator.
// Flags: Z, N
uint8_t CPU::PLA()
{
	stack_pointer++;
	a = read(0x0100 + stack_pointer);
	SetFlag(Z, a == 0x00);
	SetFlag(N, a & 0x80);

	return 0;
}

// PLP: Pull Processor Status
// Pulls an 8 bit value from the stack into the processor flags
// The flags will take on new state  determined by the value pulled
uint8_t CPU::PLP()
{
	stack_pointer++;
	status = read(0x0100 + stack_pointer);
	SetFlag(U, 1);

	return 0;
}

// ROL: Rotate Left
// Move each of the bits in Accumulator or Memory to left
// Bit 0 is filled with current value of carry flag
// bit 7 becomes new carry flag value
uint8_t CPU::ROL()
{
	fetch();
	// Rotate Left and add carry flag to bit 7
	temp = (uint16_t)(fetched << 1) | GetFlag(C);
	
	// Set carry flag
	SetFlag(C, temp & 0xFF00);

	// Set Zero flag
	SetFlag(Z, (temp & 0x00FF) == 0x0000);

	// Set Negative flag
	SetFlag(N, temp & 0x0080);

	// Check addressing mode and choose where to save the data
	if (lookup[opcode].addrmode == &CPU::IMP)
		a = temp & 0x00FF;
	else
		write(addr_abs, temp & 0x00FF);

	return 0;
}

// ROR: Rotate Right
// Move each bits in accumulator or memory to right
// Bit 7 is filled with current value of carry flag
// bit 0 becomes new carry flag value
uint8_t CPU::ROR()
{
	fetch();

	temp = (uint16_t)(GetFlag(C) << 7) | (fetched >> 1);

	SetFlag(C, fetched & 0x01);
	SetFlag(Z, (temp & 0x00FF) == 0x00);
	SetFlag(N, temp & 0x0080);

	if (lookup[opcode].addrmode == CPU::IMP)
		a = temp & 0x00FF;
	else
		write(addr_abs, temp & 0x00FF);

	return 0;
}

//RTI: Return from Interrupt
// Used at the end for interrupt processing routine
// It pulls the processor flags from the stack followed by the program counter
uint8_t CPU::RTI()
{
	stack_pointer++;
	// read status from location
	status = read(0x0100 + stack_pointer);

	// Invert break flag
	status &= ~B;

	// Invert unused flag
	status &= ~U;

	// increment stack pointer to get data for program  counter
	stack_pointer++;

	// Read twice because program counter is 16 bit long
	program_counter = (uint16_t)read(0x0100 + stack_pointer);
	stack_pointer++;
	program_counter |= (uint16_t)read(0x0100 + stack_pointer) << 8;
}

// RTS: Return from Subroutine
// used at the end of subroutine to return to the calling routine
// Pulls program counter - 1 from the stack
uint8_t CPU::RTS()
{
	// reading data into program counter
	// Reading twice because program counter is 16 bit
	stack_pointer++;
	program_counter = (uint16_t)read(0x0100 + stack_pointer);
	stack_pointer++;
	program_counter |= (uint16_t)read(0x0100 + stack_pointer) << 8;

	program_counter++;

	return 0;
}

// SEC: Set Carry Flag
// C = 1
// Flags: C
uint8_t CPU::SEC()
{
	SetFlag(C, 1);
	return 0;
}

// SED: Set Decimal Flag
// D = 1
// Flags: D
uint8_t CPU::SED()
{
	SetFlag(D, 1);
	return 0;
}

// SEI: Set Interrupt disable
// I = 1
// Flags: I
uint8_t CPU::SEI()
{
	SetFlag(I, 1);
	return 0;
}


// STA: Store Accumulator
// Stores contents of accumulator in memory
// M = A
uint8_t CPU::STA()
{
	write(addr_abs, a);
	return 0;
}

// STX: Store X Register
// Stores contents of X register into memory
// M = X
uint8_t CPU::STX()
{
	write(addr_abs, x);
	return 0;
}

// STY: Store Y Register
// M = Y
// Stores contents of Y register into memory
uint8_t CPU::STY()
{
	write(addr_abs, y);
	return 0;
}

// TAX: Transfer Accumulator to X
// Copies currnet contens of accumulator into X register
// X = A
// Sets Z and N flags as appropriate
// Flags: Z, N
uint8_t CPU::TAX()
{
	x = a;
	SetFlag(Z, x == 0x00);
	SetFlag(N, x & 0x80);

	return 0;
}

// TAY: Transfer Accumulator to Y
// Copies current content of accumulator into Y register
// Y = A
// Flags: Z, N
uint8_t CPU::TAY()
{
	y = a;
	SetFlag(Z, y == 0x00);
	SetFlag(N, y & 0x80);

	return 0;
}

// TSX: Transfer Stack pointer to X Register
// Copies currnet contents of stack pointer into X register
// X = stack pointer
// Flags: Z, N
uint8_t CPU::TSX()
{
	x = stack_pointer;
	SetFlag(Z, x == 0x00);
	SetFlag(N, x & 0x80);

	return 0;
}

// TXA: Transfer X register into accumulator
// Copies current contnets of X register into accumulator
// A = X
// Flags: Z, N
uint8_t CPU::TXA()
{
	a = x;
	SetFlag(Z, a == 0x00);
	SetFlag(N, a & 0x80);

	return 0;
}

// TXS: Transfer X register into stack pointer
// Copies current content of X register into stack pointer
// stack_pointer = X
uint8_t CPU::TXS()
{
	stack_pointer = x;
	return 0;
}

// TYA: Transfer Y to accumulator
// Copies current  contents of Y register into accumulator
// A = Y
// Flags: Z, N
uint8_t CPU::TYA()
{
	a = y;
	SetFlag(Z, a == 0x00);
	SetFlag(N, a & 0x80);

	return 0;
}

// illegal opcode
uint8_t CPU::XXX()
{
	return 0;
}

// helper function
bool CPU::complete()
{
	return cycles == 0;
}