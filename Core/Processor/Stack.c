static inline void Stack_Push(uint8_t Value)
{
    Memory_CPU_Write(0x100 | CPU.SP, Value);
    CPU.SP--;
}

static inline uint8_t Stack_Pull()
{
    CPU.SP++;
    return Memory_CPU_Read(0x100 | CPU.SP);
}

static inline void Stack_Push_Address(uint16_t Address)
{
    Stack_Push(Address >> 8);
    Stack_Push(Address & 0xFF);
}

static inline uint16_t Stack_Pull_Address()
{
    uint8_t LO = Stack_Pull();
    uint8_t HI = Stack_Pull();
    return (HI << 8) | LO;
}
