#ifndef SIGNALS_H
#define SIGNALS_H

#include <cstdint>

enum class ALUOp {
	Add,
	Subtract,
	ShiftLeft,
	ShiftRight,
	And,
	Or,
	Xor,
};

struct IFControls {
	// If false, use PC + 2
	bool use_new_address;
};

struct IDControls {
	bool reg_position;
	bool branch_z;
	bool branch_lt;
	bool jump;
	bool reg_write;
	bool use_8bit_data;
};

struct EXControls {
	bool alu_src;
	ALUOp alu_op;
};

struct MEMControls {
	bool mem_write;
	bool mem_read;
};

struct WBControls {
	bool mem_to_reg;
};

struct Controls {
	IFControls if_controls;
	IDControls id_controls;
	EXControls ex_controls;
	MEMControls mem_controls;
	WBControls wb_controls;
};

struct ControlInputs {
	uint16_t instruction;
};

struct IFID {
	uint16_t instruction;
	uint16_t pc_plus_2;
};

struct IDEX {
	EXControls ex_controls;
	MEMControls mem_controls;
	WBControls wb_controls;
	uint16_t data1 = 0;
	uint16_t data2 = 0;
	uint16_t read1 = 0;
	uint16_t read2 = 0;
	int16_t branch_offset = 0;

	uint8_t write_reg = 0;
	uint16_t write_data = 0;

	IDEX() = default;
	IDEX(EXControls ex_controls, MEMControls mem_controls, WBControls wb_controls, uint16_t data1, uint16_t data2, int16_t branch_offset, uint8_t write_reg, uint16_t write_data)
		: ex_controls(ex_controls)
		, mem_controls(mem_controls)
		, wb_controls(wb_controls)
		, data1(data1)
		, data2(data2)
		, branch_offset(branch_offset)
		, write_reg(write_reg)
		, write_data(write_data)
	{}
};

struct EXMEM {
	MEMControls mem_controls;
	WBControls wb_controls;

	uint16_t alu_output;
	uint16_t write_data;

	uint8_t write_reg;
	
};

struct MEMWB {
	WBControls wb_controls;

	uint16_t memory_data;
	uint16_t alu_output;

	uint8_t write_reg;
};

#endif
