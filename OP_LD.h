//source destination
#define OP_LD_A_A  0x7F
#define OP_LD_B_A  0x78
#define OP_LD_C_A  0x79
#define OP_LD_D_A  0x7A
#define OP_LD_E_A  0x7B
#define OP_LD_H_A  0x7C
#define OP_LD_L_A  0x7D

#define OP_LD_A_B  0x47
#define OP_LD_B_B  0x40
#define OP_LD_C_B  0x41
#define OP_LD_D_B  0x42
#define OP_LD_E_B  0x43
#define OP_LD_H_B  0x44
#define OP_LD_L_B  0x45

#define OP_LD_A_C  0x4f
#define OP_LD_B_C  0x48
#define OP_LD_C_C  0x49
#define OP_LD_D_C  0x4A
#define OP_LD_E_C  0x4B
#define OP_LD_H_C  0x4C
#define OP_LD_L_C  0x4D

#define OP_LD_A_D  0x57
#define OP_LD_B_D  0x50
#define OP_LD_C_D  0x51
#define OP_LD_D_D  0x52
#define OP_LD_E_D  0x53
#define OP_LD_H_D  0x54
#define OP_LD_L_D  0x55

#define OP_LD_A_E  0x5F
#define OP_LD_B_E  0x58
#define OP_LD_C_E  0x59
#define OP_LD_D_E  0x5A
#define OP_LD_E_E  0x5B
#define OP_LD_H_E  0x5C
#define OP_LD_L_E  0x5D

#define OP_LD_A_H  0x67
#define OP_LD_B_H  0x60
#define OP_LD_C_H  0x61
#define OP_LD_D_H  0x62
#define OP_LD_E_H  0x63
#define OP_LD_H_H  0x64
#define OP_LD_L_H  0x65

#define OP_LD_A_L  0x6F
#define OP_LD_B_L  0x68
#define OP_LD_C_L  0x69
#define OP_LD_D_L  0x6A
#define OP_LD_E_L  0x6B
#define OP_LD_H_L  0x6C
#define OP_LD_L_L  0x6D

#define OP_LD_N_A  0x3E
#define OP_LD_N_B  0x06
#define OP_LD_N_C  0x0E
#define OP_LD_N_D  0x16
#define OP_LD_N_E  0x1E
#define OP_LD_N_H  0x26
#define OP_LD_N_L  0x2E

#define OP_LD_HL_A 0x7E
#define OP_LD_HL_B 0x46
#define OP_LD_HL_C 0x4E
#define OP_LD_HL_D 0x56
#define OP_LD_HL_E 0x5E
#define OP_LD_HL_H 0x66
#define OP_LD_HL_L 0x6E

#define OP_LD_IXD_R 0xDD
#define OP_LD_IYD_R 0xFD

#define OP_LD_A_HL 0x77
#define OP_LD_B_HL 0x70
#define OP_LD_C_HL 0x71
#define OP_LD_D_HL 0x72
#define OP_LD_E_HL 0x73
#define OP_LD_H_HL 0x74
#define OP_LD_L_HL 0x75

#define OP_LD_N_HL 0x36

#define OP_LD_BC_A 0x0A
#define OP_LD_DE_A 0x1A
#define OP_LD_NN_A 0x3A
#define OP_LD_A_BC 0x02
#define OP_LD_A_DE 0x12
#define OP_LD_A_NN 0x32

#define OP_LD_ED 0xED
#define OP_LD_I_A 0x57
#define OP_LD_R_A 0x5F
#define OP_LD_A_I 0x47
#define OP_LD_A_R 0x4F

//16-bit load group
#define OP_LD_NN_BC 0x01
#define OP_LD_NN_DE 0x11
#define OP_LD_NN_HL 0x21
#define OP_LD_NN_SP 0x31

#define OP_LD_NN_HL 0x2A