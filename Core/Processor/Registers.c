typedef struct
{
    uint16_t PC;
    uint8_t  SP;
    uint8_t  AC;
    uint8_t  XI;
    uint8_t  YI;

    uint8_t C : 1;
    uint8_t Z : 1;
    uint8_t I : 1;
    uint8_t D : 1;
    uint8_t B : 1;
    uint8_t S : 1;
    uint8_t V : 1;
    uint8_t N : 1;

    uint64_t CycleCount;
    uint64_t TargetCycle;
} cpu_t;


static cpu_t CPU;


static inline void Update_Flags_ZN(uint8_t Value)
{
    CPU.Z = Value == 0;
    CPU.N = Value >> 7;
}

static inline void Status_Write(uint8_t Status)
{
    CPU.C = Status >> 7;
    CPU.Z = (Status >> 6) & 0x1;
    CPU.I = (Status >> 5) & 0x1;
    CPU.D = (Status >> 4) & 0x1;
    CPU.B = (Status >> 3) & 0x1;
    CPU.S = (Status >> 2) & 0x1;
    CPU.V = (Status >> 1) & 0x1;
    CPU.N = Status & 0x1;
}

static inline uint8_t Status_Read()
{
    return (CPU.C << 7) | (CPU.Z << 6) | (CPU.I << 5) | (CPU.D << 4) | (CPU.B << 3) | (CPU.S << 2) | (CPU.V << 1) | CPU.N;
}

uint64_t Processor_CPU_Get_Cycle_Count()
{
    return CPU.CycleCount;
}
