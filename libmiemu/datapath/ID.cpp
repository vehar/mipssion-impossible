#include "ID.h"

void ID::signals_in(const IFID&, const Controls&, uint8_t write_reg, uint16_t write_data)
{
}

void ID::tick()
{
}

void ID::tock()
{
}

IDEX ID::signals_out() const
{
	return {};
}

uint16_t ID::new_pc_address_out() const
{
	return 0;
}
