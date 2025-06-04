#ifndef BIT_MATH
#define BIT_MATH

#define  SET_BIT(R,BIT)   R|=(1<<BIT)
#define  CLR_BIT(R,BIT)   R&=~(1<<BIT)
#define  TOG_BIT(R,BIT)   R^=(1<<BIT)
#define  GET_BIT(R,BIT)   ((R>>BIT)&0x01)
#define Alis_Address(BitBand_Address, BitNumber) ((volatile uint32_t *)(0x22000000 + ((BitBand_Address - 0x20000000) * 32) + (BitNumber * 4)))

#endif
