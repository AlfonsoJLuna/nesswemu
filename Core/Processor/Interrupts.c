static inline void RST()
{
    CPU.I = 1;
    CPU.D = 0;
    CPU.S = 1;
    CPU.PC = (Memory_CPU_Read(0xFFFD) << 8) | Memory_CPU_Read(0xFFFC);
}

static inline void NMI()
{
    Stack_Push_Address(CPU.PC);
    Stack_Push(Status_Read());
    CPU.I = 1;
    CPU.PC = (Memory_CPU_Read(0xFFFB) << 8) | Memory_CPU_Read(0xFFFA);
}

static inline void IRQ()
{
    Stack_Push_Address(CPU.PC);
    Stack_Push(Status_Read());
    CPU.I = 1;
    CPU.PC = (Memory_CPU_Read(0xFFFF) << 8) | Memory_CPU_Read(0xFFFE);
}
