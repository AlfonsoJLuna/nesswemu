// Load Accumulator
static inline void LDA(uint16_t Address)
{
    CPU.AC = Memory_CPU_Read(Address);
    Update_Flags_ZN(CPU.AC);
}

// Load X Register
static inline void LDX(uint16_t Address)
{
    CPU.XI = Memory_CPU_Read(Address);
    Update_Flags_ZN(CPU.XI);
}

// Load Y Register
static inline void LDY(uint16_t Address)
{
    CPU.YI = Memory_CPU_Read(Address);
    Update_Flags_ZN(CPU.YI);
}

// Store Accumulator
static inline void STA(uint16_t Address)
{
    Memory_CPU_Write(Address, CPU.AC);
}

// Store X Register
static inline void STX(uint16_t Address)
{
    Memory_CPU_Write(Address, CPU.XI);
}

// Store Y Register
static inline void STY(uint16_t Address)
{
    Memory_CPU_Write(Address, CPU.YI);
}

// Transfer Accumulator to X
static inline void TAX()
{
    CPU.XI = CPU.AC;
    Update_Flags_ZN(CPU.XI);
}

// Transfer Accumulator to Y
static inline void TAY()
{
    CPU.YI = CPU.AC;
    Update_Flags_ZN(CPU.YI);
}

// Transfer X to Accumulator
static inline void TXA()
{
    CPU.AC = CPU.XI;
    Update_Flags_ZN(CPU.AC);
}

// Transfer Y to Accumulator
static inline void TYA()
{
    CPU.AC = CPU.YI;
    Update_Flags_ZN(CPU.AC);
}

// Transfer Stack Pointer to X
static inline void TSX()
{
    CPU.XI = CPU.SP;
    Update_Flags_ZN(CPU.XI);
}

// Transfer X to Stack Pointer
static inline void TXS()
{
    CPU.SP = CPU.XI;
}

// Push Accumulator
static inline void PHA()
{
    Stack_Push(CPU.AC);
}

// Push Processor Status
static inline void PHP()
{
    Stack_Push(Status_Read());
}

// Pull Accumulator
static inline void PLA()
{
    CPU.AC = Stack_Pull();
    Update_Flags_ZN(CPU.AC);
}

// Pull Processor Status
static inline void PLP()
{
    Status_Write(Stack_Pull());
    CPU.B = 0;
}

// Logical AND
static inline void AND(uint16_t Address)
{
    CPU.AC &= Memory_CPU_Read(Address);
    Update_Flags_ZN(CPU.AC);
}

// Exclusive OR
static inline void EOR(uint16_t Address)
{
    CPU.AC ^= Memory_CPU_Read(Address);
    Update_Flags_ZN(CPU.AC);
}

// Logical Inclusive OR
static inline void ORA(uint16_t Address)
{
    CPU.AC |= Memory_CPU_Read(Address);
    Update_Flags_ZN(CPU.AC);
}

// Bit Test
static inline void BIT(uint16_t Address)
{
    uint8_t Value = Memory_CPU_Read(Address);
    CPU.Z = (Value & CPU.AC) == 0;
    CPU.V = Value >> 6 & 0x1;
    CPU.N = Value >> 7;
}

static inline void Binary_Adder(uint8_t Value)
{
    uint16_t Result = CPU.AC + Value + CPU.C;
    CPU.V = (~(CPU.AC ^ Value) & (CPU.AC ^ Result) & 0x80) >> 7;
    CPU.AC = Result & 0xFF;
    CPU.C = Result >> 8;
    Update_Flags_ZN(CPU.AC);
}

// Add with Carry
static inline void ADC(uint16_t Address)
{
    Binary_Adder(Memory_CPU_Read(Address));
}

// Subtract with Carry
static inline void SBC(uint16_t Address)
{
    Binary_Adder(~Memory_CPU_Read(Address));
}

// Compare Accumulator
static inline void CMP(uint16_t Address)
{
    uint8_t Value = Memory_CPU_Read(Address);
    CPU.C = CPU.AC >= Value;
    Update_Flags_ZN(CPU.AC - Value);
}

// Compare X Register
static inline void CPX(uint16_t Address)
{
    uint8_t Value = Memory_CPU_Read(Address);
    CPU.C = CPU.XI >= Value;
    Update_Flags_ZN(CPU.XI - Value);
}

// Compare Y Register
static inline void CPY(uint16_t Address)
{
    uint8_t Value = Memory_CPU_Read(Address);
    CPU.C = CPU.YI >= Value;
    Update_Flags_ZN(CPU.YI - Value);
}

// Increment Memory
static inline void INC(uint16_t Address)
{
    uint8_t Result = Memory_CPU_Read(Address) + 1;
    Memory_CPU_Write(Address, Result);
    Update_Flags_ZN(Result);
}

// Increment X Register
static inline void INX()
{
    CPU.XI++;
    Update_Flags_ZN(CPU.XI);
}

// Increment Y Register
static inline void INY()
{
    CPU.YI++;
    Update_Flags_ZN(CPU.YI);
}

// Decrement Memory
static inline void DEC(uint16_t Address)
{
    uint8_t Result = Memory_CPU_Read(Address) - 1;
    Memory_CPU_Write(Address, Result);
    Update_Flags_ZN(Result);
}

// Decrement X Register
static inline void DEX()
{
    CPU.XI--;
    Update_Flags_ZN(CPU.XI);
}

// Decrement Y Register
static inline void DEY()
{
    CPU.YI--;
    Update_Flags_ZN(CPU.YI);
}

// Arithmetic Shift Left (Memory location as target)
static inline void ASL(uint16_t Address)
{
    uint8_t Value = Memory_CPU_Read(Address);
    CPU.C = Value >> 7;
    Value <<= 1;
    Memory_CPU_Write(Address, Value);
    Update_Flags_ZN(Value);
}

// Arithmetic Shift Left (Accumulator as target)
static inline void ASL_Accumulator()
{
    CPU.C = CPU.AC >> 7;
    CPU.AC <<= 1;
    Update_Flags_ZN(CPU.AC);
}

// Logical Shift Right (Memory location as target)
static inline void LSR(uint16_t Address)
{
    uint8_t Value = Memory_CPU_Read(Address);
    CPU.C = Value & 0x1;
    Value >>= 1;
    Memory_CPU_Write(Address, Value);
    Update_Flags_ZN(Value);
}

// Logical Shift Right (Accumulator as target)
static inline void LSR_Accumulator()
{
    CPU.C = CPU.AC & 0x1;
    CPU.AC >>= 1;
    Update_Flags_ZN(CPU.AC);
}

// Rotate Left (Memory location as target)
static inline void ROL(uint16_t Address)
{
    uint8_t Carry = CPU.C;
    uint8_t Value = Memory_CPU_Read(Address);
    CPU.C = Value >> 7;
    Value = Value << 1 | Carry;
    Memory_CPU_Write(Address, Value);
    Update_Flags_ZN(Value);
}

// Rotate Left (Accumulator as target)
static inline void ROL_Accumulator()
{
    uint8_t Carry = CPU.C;
    CPU.C = CPU.AC >> 7;
    CPU.AC = CPU.AC << 1 | Carry;
    Update_Flags_ZN(CPU.AC);
}

// Rotate Right (Memory location as target)
static inline void ROR(uint16_t Address)
{
    uint8_t Carry = CPU.C;
    uint8_t Value = Memory_CPU_Read(Address);
    CPU.C = Value & 0x1;
    Value = Value >> 1 | Carry << 7;
    Memory_CPU_Write(Address, Value);
    Update_Flags_ZN(Value);
}

// Rotate Right (Accumulator as target)
static inline void ROR_Accumulator()
{
    uint8_t Carry = CPU.C;

    CPU.C = CPU.AC & 0x1;
    CPU.AC = CPU.AC >> 1 | Carry << 7;
    Update_Flags_ZN(CPU.AC);
}

// Jump
static inline void JMP(uint16_t Address)
{
    CPU.PC = Address;
}

// Jump to Subroutine
static inline void JSR(uint16_t Address)
{
    Stack_Push_Address(CPU.PC - 1);
    CPU.PC = Address;
}

// Return from Subroutine
static inline void RTS()
{
    CPU.PC = Stack_Pull_Address() + 1;
}

// Branch if Carry Clear
static inline void BCC(uint16_t Address)
{
    if (!CPU.C)
    {
        CPU.CycleCount++;
		Check_Page_Crossed(CPU.PC, Address);
        CPU.PC = Address;
    }
}

// Branch if Carry Set
static inline void BCS(uint16_t Address)
{
    if (CPU.C)
    {
        CPU.CycleCount++;
		Check_Page_Crossed(CPU.PC, Address);
        CPU.PC = Address;
    }
}

// Branch if Equal
static inline void BEQ(uint16_t Address)
{
    if (CPU.Z)
    {
        CPU.CycleCount++;
		Check_Page_Crossed(CPU.PC, Address);
        CPU.PC = Address;
    }
}

// Branch if Minus
static inline void BMI(uint16_t Address)
{
    if (CPU.N)
    {
        CPU.CycleCount++;
		Check_Page_Crossed(CPU.PC, Address);
        CPU.PC = Address;
    }
}

// Branch if Not Equal
static inline void BNE(uint16_t Address)
{
    if (!CPU.Z)
    {
        CPU.CycleCount++;
		Check_Page_Crossed(CPU.PC, Address);
        CPU.PC = Address;
    }
}

// Branch if Positive
static inline void BPL(uint16_t Address)
{
    if (!CPU.N)
    {
        CPU.CycleCount++;
		Check_Page_Crossed(CPU.PC, Address);
        CPU.PC = Address;
    }
}

// Branch if Overflow Clear
static inline void BVC(uint16_t Address)
{
    if (!CPU.V)
    {
        CPU.CycleCount++;
		Check_Page_Crossed(CPU.PC, Address);
        CPU.PC = Address;
    }
}

// Branch if Overflow Set
static inline void BVS(uint16_t Address)
{
    if (CPU.V)
    {
        CPU.CycleCount++;
		Check_Page_Crossed(CPU.PC, Address);
        CPU.PC = Address;
    }
}

// Clear Carry Flag
static inline void CLC()
{
    CPU.C = 0;
}

// Clear Decimal Mode
static inline void CLD()
{
    CPU.D = 0;
}

// Clear Interrupt Disable
static inline void CLI()
{
    CPU.I = 0;
}

// Clear Overflow Flag
static inline void CLV()
{
    CPU.V = 0;
}

// Set Carry Flag
static inline void SEC()
{
    CPU.C = 1;
}

// Set Decimal Mode
static inline void SED()
{
    CPU.D = 1;
}

// Set Interrupt Disable
static inline void SEI()
{
    CPU.I = 1;
}

// Software Interrupt
static inline void BRK()
{
    Stack_Push_Address(CPU.PC);
    CPU.B = 1;
    Stack_Push(Status_Read());
    CPU.B = 0;
    CPU.I = 1;
    CPU.PC = Memory_CPU_Read(0xFFFF) << 8 | Memory_CPU_Read(0xFFFE);
}

// No Operation
static inline void NOP()
{
    // Do nothing
}

// Return from Interrupt
static inline void RTI()
{
    Status_Write(Stack_Pull());
    CPU.B = 0;
    CPU.PC = Stack_Pull_Address();
}


// Unofficial

static inline void AHX(uint16_t Address)
{

}

static inline void ALR(uint16_t Address)
{

}

static inline void ANC(uint16_t Address)
{

}

static inline void ARR(uint16_t Address)
{

}

static inline void AXS(uint16_t Address)
{

}

static inline void DCP(uint16_t Address)
{

}

static inline void ISC(uint16_t Address)
{

}

static inline void KIL()
{

}

static inline void LAS(uint16_t Address)
{

}

static inline void LAX(uint16_t Address)
{

}

static inline void RLA(uint16_t Address)
{

}

static inline void RRA(uint16_t Address)
{

}

static inline void SAX(uint16_t Address)
{

}

static inline void SHX(uint16_t Address)
{

}

static inline void SHY(uint16_t Address)
{

}

static inline void SLO(uint16_t Address)
{

}

static inline void SRE(uint16_t Address)
{

}

static inline void TAS(uint16_t Address)
{

}

static inline void XAA(uint16_t Address)
{

}
