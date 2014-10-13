//source destination
static const int OP_LD_A_A = 0x7F;
static const int OP_LD_B_A = 0x78;
static const int OP_LD_C_A = 0x79;
static const int OP_LD_D_A = 0x7A;
static const int OP_LD_E_A = 0x7B;
static const int OP_LD_H_A = 0x7C;
static const int OP_LD_L_A = 0x7D;

static const int OP_LD_A_B = 0x47;
static const int OP_LD_B_B = 0x40;
static const int OP_LD_C_B = 0x41;
static const int OP_LD_D_B = 0x42;
static const int OP_LD_E_B = 0x43;
static const int OP_LD_H_B = 0x44;
static const int OP_LD_L_B = 0x45;

static const int OP_LD_A_C = 0x4f;
static const int OP_LD_B_C = 0x48;
static const int OP_LD_C_C = 0x49;
static const int OP_LD_D_C = 0x4A;
static const int OP_LD_E_C = 0x4B;
static const int OP_LD_H_C = 0x4C;
static const int OP_LD_L_C = 0x4D;

static const int OP_LD_A_D = 0x57;
static const int OP_LD_B_D = 0x50;
static const int OP_LD_C_D = 0x51;
static const int OP_LD_D_D = 0x52;
static const int OP_LD_E_D = 0x53;
static const int OP_LD_H_D = 0x54;
static const int OP_LD_L_D = 0x55;

static const int OP_LD_A_E = 0x5F;
static const int OP_LD_B_E = 0x58;
static const int OP_LD_C_E = 0x59;
static const int OP_LD_D_E = 0x5A;
static const int OP_LD_E_E = 0x5B;
static const int OP_LD_H_E = 0x5C;
static const int OP_LD_L_E = 0x5D;

static const int OP_LD_A_H = 0x67;
static const int OP_LD_B_H = 0x60;
static const int OP_LD_C_H = 0x61;
static const int OP_LD_D_H = 0x62;
static const int OP_LD_E_H = 0x63;
static const int OP_LD_H_H = 0x64;
static const int OP_LD_L_H = 0x65;

static const int OP_LD_A_L = 0x6F;
static const int OP_LD_B_L = 0x68;
static const int OP_LD_C_L = 0x69;
static const int OP_LD_D_L = 0x6A;
static const int OP_LD_E_L = 0x6B;
static const int OP_LD_H_L = 0x6C;
static const int OP_LD_L_L = 0x6D;

static const int OP_LD_N_A = 0x3E;
static const int OP_LD_N_B = 0x06;
static const int OP_LD_N_C = 0x0E;
static const int OP_LD_N_D = 0x16;
static const int OP_LD_N_E = 0x1E;
static const int OP_LD_N_H = 0x26;
static const int OP_LD_N_L = 0x2E;

static const int OP_LD_HL_A = 0x7E;
static const int OP_LD_HL_B = 0x46;
static const int OP_LD_HL_C = 0x4E;
static const int OP_LD_HL_D = 0x56;
static const int OP_LD_HL_E = 0x5E;
static const int OP_LD_HL_H = 0x66;
static const int OP_LD_HL_L = 0x6E;

static const int OP_LD_IXD_R = 0xDD;
static const int OP_LD_IYD_R = 0xFD;

static const int OP_LD_A_HL = 0x77;
static const int OP_LD_B_HL = 0x70;
static const int OP_LD_C_HL = 0x71;
static const int OP_LD_D_HL = 0x72;
static const int OP_LD_E_HL = 0x73;
static const int OP_LD_H_HL = 0x74;
static const int OP_LD_L_HL = 0x75;

static const int OP_LD_N_HL = 0x36;

static const int OP_LD_BC_A = 0x0A;
static const int OP_LD_DE_A = 0x1A;
static const int OP_LD_NN_A = 0x3A;
static const int OP_LD_A_BC = 0x02;
static const int OP_LD_A_DE = 0x12;
static const int OP_LD_A_NN = 0x32;

static const int OP_LD_ED = 0xED;
static const int OP_LD_I_A = 0x57;
static const int OP_LD_R_A = 0x5F;
static const int OP_LD_A_I = 0x47;
static const int OP_LD_A_R = 0x4F;

//16-bit load group
static const int OP_LD_NN_BC = 0x01;
static const int OP_LD_NN_DE = 0x11;
static const int OP_LD_NN_HL = 0x21;
static const int OP_LD_NN_SP = 0x31;

static const int OP_LD_NN_HL_M = 0x2A;

static const int OP_LD_NN_DD_BC = 0x4B;
static const int OP_LD_NN_DD_DE = 0x5B;
static const int OP_LD_NN_DD_HL = 0x6B;
static const int OP_LD_NN_DD_SP = 0x7B;

static const int OP_LD_HL_NN = 0x22;

static const int OP_LD_DD_NN_BC = 0x43;
static const int OP_LD_DD_NN_DE = 0x53;
static const int OP_LD_DD_NN_HL = 0x63;
static const int OP_LD_DD_NN_SP = 0x73;

static const int OP_LD_HL_SP = 0xF9;
