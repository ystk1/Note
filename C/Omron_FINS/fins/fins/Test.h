
//�e��^�C�}�[�l
typedef struct _timer
{
    unsigned short PP_T1; 
    unsigned short PP_T2; 
    unsigned short PP_T3; 
    unsigned short PP_T4; 
    unsigned short PP_T5; 
    unsigned short PP_T6; 
    unsigned short PP_T7;
    unsigned short PP_T8; 
};

// �e��^�C�}�[�l
typedef struct _timer_P1
{
    unsigned short PP_T1;
    unsigned short PP_T2;
    unsigned short PP_T3;
    unsigned short PP_T4;
    unsigned short PP_T5;
    unsigned short PP_T6;
    unsigned short PP_T7;
    unsigned short PP_T8;
};

typedef struct TDATA_SH 
{
     struct _timer g_tm;   // �e��^�C�}�[�l
};


short					g_D1000, g_D1010, g_D1011;
short					g_Read_D1000, g_Read_D1010, g_Read_D1011;