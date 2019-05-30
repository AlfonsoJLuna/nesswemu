static inline void Check_Page_Crossed(uint16_t Address_1, uint16_t Address_2)
{
    if ((Address_1 & 0xFF00) != (Address_2 & 0xFF00))
    {
        CPU.CycleCount++;
    }
}

static inline uint16_t Immediate()
{
    return CPU.PC + 1;
}

static inline uint16_t Zero_Page()
{
    return Memory_CPU_Read(CPU.PC + 1);
}

static inline uint16_t Zero_Page_X()
{
    return (Zero_Page() + CPU.XI) & 0xFF;
}

static inline uint16_t Zero_Page_Y()
{
    return (Zero_Page() + CPU.YI) & 0xFF;
}

static inline uint16_t Absolute()
{
    return (Memory_CPU_Read(CPU.PC + 2) << 8) | Memory_CPU_Read(CPU.PC + 1);
}

static inline uint16_t Absolute_X()
{
    uint16_t Address = Absolute();
    return Address + CPU.XI;
}

static inline uint16_t Absolute_X_Read()
{
    uint16_t Address = Absolute();
    Check_Page_Crossed(Address, Address + CPU.XI);
    return Address + CPU.XI;
}

static inline uint16_t Absolute_Y()
{
    uint16_t Address = Absolute();
    return Address + CPU.YI;
}

static inline uint16_t Absolute_Y_Read()
{
    uint16_t Address = Absolute();
    Check_Page_Crossed(Address, Address + CPU.YI);
    return Address + CPU.YI;
}

static inline uint16_t Indirect()
{
    uint16_t Address = Absolute();
    return (Memory_CPU_Read((Address & 0xFF00) | ((Address + 1) & 0xFF)) << 8) | Memory_CPU_Read(Address);
}

static inline uint16_t Indexed_Indirect()
{
    uint16_t Address = Zero_Page_X();
    return (Memory_CPU_Read((Address + 1) & 0xFF) << 8) | Memory_CPU_Read(Address);
}

static inline uint16_t Indirect_Indexed()
{
    uint16_t AddressZP = Zero_Page();
    uint16_t Address = (Memory_CPU_Read((AddressZP + 1) & 0xFF) << 8) | Memory_CPU_Read(AddressZP);
    return Address + CPU.YI;
}

static inline uint16_t Indirect_Indexed_Read()
{
    uint16_t AddressZP = Zero_Page();
    uint16_t Address = (Memory_CPU_Read((AddressZP + 1) & 0xFF) << 8) | Memory_CPU_Read(AddressZP);
    Check_Page_Crossed(Address, Address + CPU.YI);
    return Address + CPU.YI;
}

static inline uint16_t Relative()
{
    uint8_t Offset = Memory_CPU_Read(CPU.PC + 1);
    uint16_t Address;
    if (Offset < 0x80)
    {
        Address = CPU.PC + 2 + Offset;
    }
    else
    {
        Address = CPU.PC + 2 + Offset - 0x100;
    }
    return Address;
}
