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
} cpu_t;


static cpu_t CPU;


static inline void Update_Flags_ZN(uint8_t value)
{
    CPU.Z = value == 0;
    CPU.N = value >> 7;
}

static inline void Status_Write(uint8_t status)
{
    CPU.C = status >> 7;
    CPU.Z = (status >> 6) & 0x1;
    CPU.I = (status >> 5) & 0x1;
    CPU.D = (status >> 4) & 0x1;
    CPU.B = (status >> 3) & 0x1;
    CPU.S = (status >> 2) & 0x1;
    CPU.V = (status >> 1) & 0x1;
    CPU.N = status & 0x1;
}

static inline uint8_t Status_Read()
{
    return (CPU.C << 7) | (CPU.Z << 6) | (CPU.I << 5) | (CPU.D << 4) | (CPU.B << 3) | (CPU.S << 2) | (CPU.V << 1) | CPU.N;
}
