static void* Opcode[] =
{
	&&Opcode00, &&Opcode01, &&Opcode02, &&Opcode03, &&Opcode04, &&Opcode05, &&Opcode06, &&Opcode07, &&Opcode08, &&Opcode09, &&Opcode0A, &&Opcode0B, &&Opcode0C, &&Opcode0D, &&Opcode0E, &&Opcode0F,
	&&Opcode10, &&Opcode11, &&Opcode12, &&Opcode13, &&Opcode14, &&Opcode15, &&Opcode16, &&Opcode17, &&Opcode18, &&Opcode19, &&Opcode1A, &&Opcode1B, &&Opcode1C, &&Opcode1D, &&Opcode1E, &&Opcode1F,
	&&Opcode20, &&Opcode21, &&Opcode22, &&Opcode23, &&Opcode24, &&Opcode25, &&Opcode26, &&Opcode27, &&Opcode28, &&Opcode29, &&Opcode2A, &&Opcode2B, &&Opcode2C, &&Opcode2D, &&Opcode2E, &&Opcode2F,
	&&Opcode30, &&Opcode31, &&Opcode32, &&Opcode33, &&Opcode34, &&Opcode35, &&Opcode36, &&Opcode37, &&Opcode38, &&Opcode39, &&Opcode3A, &&Opcode3B, &&Opcode3C, &&Opcode3D, &&Opcode3E, &&Opcode3F,
	&&Opcode40, &&Opcode41, &&Opcode42, &&Opcode43, &&Opcode44, &&Opcode45, &&Opcode46, &&Opcode47, &&Opcode48, &&Opcode49, &&Opcode4A, &&Opcode4B, &&Opcode4C, &&Opcode4D, &&Opcode4E, &&Opcode4F,
	&&Opcode50, &&Opcode51, &&Opcode52, &&Opcode53, &&Opcode54, &&Opcode55, &&Opcode56, &&Opcode57, &&Opcode58, &&Opcode59, &&Opcode5A, &&Opcode5B, &&Opcode5C, &&Opcode5D, &&Opcode5E, &&Opcode5F,
	&&Opcode60, &&Opcode61, &&Opcode62, &&Opcode63, &&Opcode64, &&Opcode65, &&Opcode66, &&Opcode67, &&Opcode68, &&Opcode69, &&Opcode6A, &&Opcode6B, &&Opcode6C, &&Opcode6D, &&Opcode6E, &&Opcode6F,
	&&Opcode70, &&Opcode71, &&Opcode72, &&Opcode73, &&Opcode74, &&Opcode75, &&Opcode76, &&Opcode77, &&Opcode78, &&Opcode79, &&Opcode7A, &&Opcode7B, &&Opcode7C, &&Opcode7D, &&Opcode7E, &&Opcode7F,
	&&Opcode80, &&Opcode81, &&Opcode82, &&Opcode83, &&Opcode84, &&Opcode85, &&Opcode86, &&Opcode87, &&Opcode88, &&Opcode89, &&Opcode8A, &&Opcode8B, &&Opcode8C, &&Opcode8D, &&Opcode8E, &&Opcode8F,
	&&Opcode90, &&Opcode91, &&Opcode92, &&Opcode93, &&Opcode94, &&Opcode95, &&Opcode96, &&Opcode97, &&Opcode98, &&Opcode99, &&Opcode9A, &&Opcode9B, &&Opcode9C, &&Opcode9D, &&Opcode9E, &&Opcode9F,
	&&OpcodeA0, &&OpcodeA1, &&OpcodeA2, &&OpcodeA3, &&OpcodeA4, &&OpcodeA5, &&OpcodeA6, &&OpcodeA7, &&OpcodeA8, &&OpcodeA9, &&OpcodeAA, &&OpcodeAB, &&OpcodeAC, &&OpcodeAD, &&OpcodeAE, &&OpcodeAF,
	&&OpcodeB0, &&OpcodeB1, &&OpcodeB2, &&OpcodeB3, &&OpcodeB4, &&OpcodeB5, &&OpcodeB6, &&OpcodeB7, &&OpcodeB8, &&OpcodeB9, &&OpcodeBA, &&OpcodeBB, &&OpcodeBC, &&OpcodeBD, &&OpcodeBE, &&OpcodeBF,
	&&OpcodeC0, &&OpcodeC1, &&OpcodeC2, &&OpcodeC3, &&OpcodeC4, &&OpcodeC5, &&OpcodeC6, &&OpcodeC7, &&OpcodeC8, &&OpcodeC9, &&OpcodeCA, &&OpcodeCB, &&OpcodeCC, &&OpcodeCD, &&OpcodeCE, &&OpcodeCF,
	&&OpcodeD0, &&OpcodeD1, &&OpcodeD2, &&OpcodeD3, &&OpcodeD4, &&OpcodeD5, &&OpcodeD6, &&OpcodeD7, &&OpcodeD8, &&OpcodeD9, &&OpcodeDA, &&OpcodeDB, &&OpcodeDC, &&OpcodeDD, &&OpcodeDE, &&OpcodeDF,
	&&OpcodeE0, &&OpcodeE1, &&OpcodeE2, &&OpcodeE3, &&OpcodeE4, &&OpcodeE5, &&OpcodeE6, &&OpcodeE7, &&OpcodeE8, &&OpcodeE9, &&OpcodeEA, &&OpcodeEB, &&OpcodeEC, &&OpcodeED, &&OpcodeEE, &&OpcodeEF,
	&&OpcodeF0, &&OpcodeF1, &&OpcodeF2, &&OpcodeF3, &&OpcodeF4, &&OpcodeF5, &&OpcodeF6, &&OpcodeF7, &&OpcodeF8, &&OpcodeF9, &&OpcodeFA, &&OpcodeFB, &&OpcodeFC, &&OpcodeFD, &&OpcodeFE, &&OpcodeFF
};


void Processor_CPU_Run()
{
	goto *Opcode[Memory_CPU_Read(CPU.PC)];

	Opcode00:	BRK(Implied());				CPU.Cycles += 7;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode01:	ORA(Indexed_Indirect());	CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode02:	KIL(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode03:	SLO(Indexed_Indirect());	CPU.Cycles += 8;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode04:	NOP(Zero_Page());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode05:	ORA(Zero_Page());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode06:	ASL(Zero_Page());			CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode07:	SLO(Zero_Page());			CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode08:	PHP(Implied());				CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode09:	ORA(Immediate());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode0A:	ASL(Accumulator());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode0B:	ANC(Immediate());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode0C:	NOP(Absolute());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode0D:	ORA(Absolute());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode0E:	ASL(Absolute());			CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode0F:	SLO(Absolute());			CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode10:	BPL(Relative());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode11:	ORA(Indirect_Indexed());	CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode12:	KIL(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode13:	SLO(Indirect_Indexed());	CPU.Cycles += 8;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode14:	NOP(Zero_Page_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode15:	ORA(Zero_Page_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode16:	ASL(Zero_Page_X());			CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode17:	SLO(Zero_Page_X());			CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode18:	CLC(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode19:	ORA(Absolute_Y());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode1A:	NOP(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode1B:	SLO(Absolute_Y());			CPU.Cycles += 7;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode1C:	NOP(Absolute_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode1D:	ORA(Absolute_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode1E:	ASL(Absolute_X());			CPU.Cycles += 7;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode1F:	SLO(Absolute_X());			CPU.Cycles += 7;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode20:	JSR(Absolute());			CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode21:	AND(Indexed_Indirect());	CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode22:	KIL(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode23:	RLA(Indexed_Indirect());	CPU.Cycles += 8;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode24:	BIT(Zero_Page());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode25:	AND(Zero_Page());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode26:	ROL(Zero_Page());			CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode27:	RLA(Zero_Page());			CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode28:	PLP(Implied());				CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode29:	AND(Immediate());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode2A:	ROL(Accumulator());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode2B:	ANC(Immediate());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode2C:	BIT(Absolute());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode2D:	AND(Absolute());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode2E:	ROL(Absolute());			CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode2F:	RLA(Absolute());			CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode30:	BMI(Relative());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode31:	AND(Indirect_Indexed());	CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode32:	KIL(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode33:	RLA(Indirect_Indexed());	CPU.Cycles += 8;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode34:	NOP(Zero_Page_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode35:	AND(Zero_Page_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode36:	ROL(Zero_Page_X());			CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode37:	RLA(Zero_Page_X());			CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode38:	SEC(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode39:	AND(Absolute_Y());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode3A:	NOP(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode3B:	RLA(Absolute_Y());			CPU.Cycles += 7;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode3C:	NOP(Absolute_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode3D:	AND(Absolute_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode3E:	ROL(Absolute_X());			CPU.Cycles += 7;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode3F:	RLA(Absolute_X());			CPU.Cycles += 7;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode40:	RTI(Implied());				CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode41:	EOR(Indexed_Indirect());	CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode42:	KIL(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode43:	SRE(Indexed_Indirect());	CPU.Cycles += 8;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode44:	NOP(Zero_Page());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode45:	EOR(Zero_Page());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode46:	LSR(Zero_Page());			CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode47:	SRE(Zero_Page());			CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode48:	PHA(Implied());				CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode49:	EOR(Immediate());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode4A:	LSR(Accumulator());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode4B:	ALR(Immediate());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode4C:	JMP(Absolute());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode4D:	EOR(Absolute());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode4E:	LSR(Absolute());			CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode4F:	SRE(Absolute());			CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode50:	BVC(Relative());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode51:	EOR(Indirect_Indexed());	CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode52:	KIL(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode53:	SRE(Indirect_Indexed());	CPU.Cycles += 8;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode54:	NOP(Zero_Page_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode55:	EOR(Zero_Page_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode56:	LSR(Zero_Page_X());			CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode57:	SRE(Zero_Page_X());			CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode58:	CLI(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode59:	EOR(Absolute_Y());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode5A:	NOP(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode5B:	SRE(Absolute_Y());			CPU.Cycles += 7;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode5C:	NOP(Absolute_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode5D:	EOR(Absolute_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode5E:	LSR(Absolute_X());			CPU.Cycles += 7;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode5F:	SRE(Absolute_X());			CPU.Cycles += 7;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode60:	RTS(Implied());				CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode61:	ADC(Indexed_Indirect());	CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode62:	KIL(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode63:	RRA(Indexed_Indirect());	CPU.Cycles += 8;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode64:	NOP(Zero_Page());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode65:	ADC(Zero_Page());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode66:	ROR(Zero_Page());			CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode67:	RRA(Zero_Page());			CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode68:	PLA(Implied());				CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode69:	ADC(Immediate());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode6A:	ROR(Accumulator());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode6B:	ARR(Immediate());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode6C:	JMP(Indirect());			CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode6D:	ADC(Absolute());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode6E:	ROR(Absolute());			CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode6F:	RRA(Absolute());			CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode70:	BVS(Relative());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode71:	ADC(Indirect_Indexed());	CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode72:	KIL(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode73:	RRA(Indirect_Indexed());	CPU.Cycles += 8;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode74:	NOP(Zero_Page_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode75:	ADC(Zero_Page_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode76:	ROR(Zero_Page_X());			CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode77:	RRA(Zero_Page_X());			CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode78:	SEI(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode79:	ADC(Absolute_Y());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode7A:	NOP(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode7B:	RRA(Absolute_Y());			CPU.Cycles += 7;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode7C:	NOP(Absolute_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode7D:	ADC(Absolute_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode7E:	ROR(Absolute_X());			CPU.Cycles += 7;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode7F:	RRA(Absolute_X());			CPU.Cycles += 7;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode80:	NOP(Immediate());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode81:	STA(Indexed_Indirect());	CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode82:	NOP(Immediate());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode83:	SAX(Indexed_Indirect());	CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode84:	STY(Zero_Page());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode85:	STA(Zero_Page());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode86:	STX(Zero_Page());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode87:	SAX(Zero_Page());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode88:	DEY(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode89:	NOP(Immediate());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode8A:	TXA(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode8B:	XAA(Immediate());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode8C:	STY(Absolute());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode8D:	STA(Absolute());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode8E:	STX(Absolute());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode8F:	SAX(Absolute());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode90:	BCC(Relative());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode91:	STA(Indirect_Indexed());	CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode92:	KIL(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode93:	AHX(Indirect_Indexed());	CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode94:	STY(Zero_Page_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode95:	STA(Zero_Page_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode96:	STX(Zero_Page_Y());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode97:	SAX(Zero_Page_Y());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	Opcode98:	TYA(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode99:	STA(Absolute_Y());			CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode9A:	TXS(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	Opcode9B:	TAS(Absolute_Y());			CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode9C:	SHY(Absolute_X());			CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode9D:	STA(Absolute_X());			CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode9E:	SHX(Absolute_Y());			CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	Opcode9F:	AHX(Absolute_Y());			CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeA0:	LDY(Immediate());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeA1:	LDA(Indexed_Indirect());	CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeA2:	LDX(Immediate());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeA3:	LAX(Indexed_Indirect());	CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeA4:	LDY(Zero_Page());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeA5:	LDA(Zero_Page());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeA6:	LDX(Zero_Page());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeA7:	LAX(Zero_Page());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeA8:	TAY(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	OpcodeA9:	LDA(Immediate());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeAA:	TAX(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	OpcodeAB:	LAX(Immediate());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeAC:	LDY(Absolute());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeAD:	LDA(Absolute());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeAE:	LDX(Absolute());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeAF:	LAX(Absolute());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeB0:	BCS(Relative());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeB1:	LDA(Indirect_Indexed());	CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeB2:	KIL(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	OpcodeB3:	LAX(Indirect_Indexed());	CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeB4:	LDY(Zero_Page_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeB5:	LDA(Zero_Page_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeB6:	LDX(Zero_Page_Y());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeB7:	LAX(Zero_Page_Y());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeB8:	CLV(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	OpcodeB9:	LDA(Absolute_Y());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeBA:	TSX(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	OpcodeBB:	LAS(Absolute_Y());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeBC:	LDY(Absolute_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeBD:	LDA(Absolute_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeBE:	LDX(Absolute_Y());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeBF:	LAX(Absolute_Y());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeC0:	CPY(Immediate());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeC1:	CMP(Indexed_Indirect());	CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeC2:	NOP(Immediate());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeC3:	DCP(Indexed_Indirect());	CPU.Cycles += 8;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeC4:	CPY(Zero_Page());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeC5:	CMP(Zero_Page());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeC6:	DEC(Zero_Page());			CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeC7:	DCP(Zero_Page());			CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeC8:	INY(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	OpcodeC9:	CMP(Immediate());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeCA:	DEX(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	OpcodeCB:	AXS(Immediate());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeCC:	CPY(Absolute());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeCD:	CMP(Absolute());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeCE:	DEC(Absolute());			CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeCF:	DCP(Absolute());			CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeD0:	BNE(Relative());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeD1:	CMP(Indirect_Indexed());	CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeD2:	KIL(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	OpcodeD3:	DCP(Indirect_Indexed());	CPU.Cycles += 8;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeD4:	NOP(Zero_Page_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeD5:	CMP(Zero_Page_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeD6:	DEC(Zero_Page_X());			CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeD7:	DCP(Zero_Page_X());			CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeD8:	CLD(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	OpcodeD9:	CMP(Absolute_Y());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeDA:	NOP(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	OpcodeDB:	DCP(Absolute_Y());			CPU.Cycles += 7;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeDC:	NOP(Absolute_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeDD:	CMP(Absolute_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeDE:	DEC(Absolute_X());			CPU.Cycles += 7;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeDF:	DCP(Absolute_X());			CPU.Cycles += 7;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeE0:	CPX(Immediate());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeE1:	SBC(Indexed_Indirect());	CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeE2:	NOP(Immediate());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeE3:	ISC(Indexed_Indirect());	CPU.Cycles += 8;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeE4:	CPX(Zero_Page());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeE5:	SBC(Zero_Page());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeE6:	INC(Zero_Page());			CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeE7:	ISC(Zero_Page());			CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeE8:	INX(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	OpcodeE9:	SBC(Immediate());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeEA:	NOP(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	OpcodeEB:	SBC(Immediate());			CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeEC:	CPX(Absolute());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeED:	SBC(Absolute());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeEE:	INC(Absolute());			CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeEF:	ISC(Absolute());			CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeF0:	BEQ(Relative());			CPU.Cycles += 3;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeF1:	SBC(Indirect_Indexed());	CPU.Cycles += 5;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeF2:	KIL(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	OpcodeF3:	ISC(Indirect_Indexed());	CPU.Cycles += 8;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeF4:	NOP(Zero_Page_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeF5:	SBC(Zero_Page_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeF6:	INC(Zero_Page_X());			CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeF7:	ISC(Zero_Page_X());			CPU.Cycles += 6;	goto *Opcode[Memory_CPU_Read(CPU.PC += 2)];
	OpcodeF8:	SED(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	OpcodeF9:	SBC(Absolute_Y());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeFA:	NOP(Implied());				CPU.Cycles += 2;	goto *Opcode[Memory_CPU_Read(CPU.PC += 1)];
	OpcodeFB:	ISC(Absolute_Y());			CPU.Cycles += 7;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeFC:	NOP(Absolute_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeFD:	SBC(Absolute_X());			CPU.Cycles += 4;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeFE:	INC(Absolute_X());			CPU.Cycles += 7;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];
	OpcodeFF:	ISC(Absolute_X());			CPU.Cycles += 7;	goto *Opcode[Memory_CPU_Read(CPU.PC += 3)];

	Interrupt:

	Halt:
}
