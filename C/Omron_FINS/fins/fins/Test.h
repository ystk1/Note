
//�e��^�C�}�[�l
typedef struct _timer
{
    //		unsigned char		Swait;				// �\��

    unsigned short nFrkStop;    // ̫��������~���ިڰ
    unsigned short nLvl_Chk_Up; // �����ٓ��쎞��ʒu�m�F��ϰ
    unsigned short nLvl_Chk_Dw; // �����ٓ��쎞��ʒu�m�F��ϰ

    //		unsigned short				yobi0;				// �\�� <61136>
    unsigned short PP_T1; // PP1�T�C�N���^�C���A�E�g <61136>

    unsigned short lvl_l;      // �t�H�[�N�o�����^�C�}�[�i�I�j
    unsigned short nBay_Tech1; // ���s����è��ݸޒ[�����o���~�ިڰ
                               //		unsigned short				Br_Off;				// �u���[�LOFF�^�C�}�[�i���g�p�j <61136>
    unsigned short PP_T2;      // PP�o������^�C���A�E�g <61136>
    unsigned short rool;       // �h��~��

    unsigned short cl_pa;     // �ׂ͂ݏo���ُ�
    unsigned short cw_pa;     // �׎p�ُ�m�F
    unsigned short nBay_Wait; // ���s��ʒu�m�F��ϰ
    unsigned short nLvl_Wait; // ���~��ʒu�m�F��ϰ
    unsigned short nFrk_Wait; // ̫����ʒu�m�F��ϰ
    unsigned short nBay_Tech; // ���s����è��ݸޔ��]���҂�����

    unsigned short nBay_T_On;  // ���sPset  ON�ިڰ
    unsigned short nBay_T_Off; //          OFF�ިڰ
    unsigned short nLvl_T_On;  // ���~Pset  ON�ިڰ
    unsigned short nLvl_T_Off; //          OFF�ިڰ
    unsigned short nFrk_T_On;  // ̫��Pset  ON�ިڰ
    unsigned short nFrk_T_Off; //          OFF�ިڰ

    unsigned short nLvl_H_Check; // ���~���ٓ�������Ď��J�n

    unsigned short over[3]; // �I�[�o�[�^�C���E�`�F�c�N

    unsigned short lvl_ls; // �t�H�[�N�o�����^�C�}�[�i�r�s�j
    unsigned short Bz_On;  // �u�U�[�I���^�C��

    unsigned short nT_Bay_SON_Off; // S-ON OFF�^�C�}
    unsigned short nT_Lvl_SON_Off; // S-ON OFF�^�C�}
    unsigned short nT_Frk_SON_Off; // S-ON OFF�^�C�}

    unsigned short nSt_Ovt1; // ST�������(�\��E���s)
    unsigned short nSt_Ovt2; // ST�������(�אρE�׍~)
    unsigned short nLvl_Son; // S-ON�ިڰ

    unsigned short Bz_On_Wait; // ���񓮍�҂��޻ްON����
    unsigned short overEco[3]; // �I�[�o�[�^�C��(�ȴȐ�p)
                               //		unsigned short				nFrk_Org[2];		// ̫�����_���A�p��ϰ
    unsigned short PP_T3;      // PP�J����^�C���A�E�g <61136>
    unsigned short PP_T4;      // PP���_���A����^�C���A�E�g <61136>

    //		unsigned short				yobi[4];			// �\�� <61136>
    unsigned short PP_T5; // PP���_���Aoff�f�B���[�^�C�}�[(�J��) <61136>
    unsigned short PP_T6; // PP���_���Aon�f�B���[�^�C�}�[(�J��) <61136>
    unsigned short PP_T7; // PP���_���Aoff�f�B���[�^�C�}�[(�L�k) <61136>
    unsigned short PP_T8; // PP���_���Aon�f�B���[�^�C�}�[(�L�k) <61136>
};

// �e��^�C�}�[�l
typedef struct _timer_P1
{
    //		unsigned char		Swait;				// �\��

    unsigned short nFrkStop;    // ̫��������~���ިڰ
    unsigned short nLvl_Chk_Up; // �����ٓ��쎞��ʒu�m�F��ϰ
    unsigned short nLvl_Chk_Dw; // �����ٓ��쎞��ʒu�m�F��ϰ

    //		unsigned short		yobi0;				// �\�� <61136>
    unsigned short PP_T1; // PP1�T�C�N���^�C���A�E�g <61136>

    unsigned short lvl_l;      // �t�H�[�N�o�����^�C�}�[�i�I�j
    unsigned short nBay_Tech1; // ���s����è��ݸޒ[�����o���~�ިڰ
                               //		unsigned short		Br_Off;				// �u���[�LOFF�^�C�}�[�i���g�p�j <61136>
    unsigned short PP_T2;      // PP�o������^�C���A�E�g <61136>
    unsigned short rool;       // �h��~��

    unsigned short cl_pa; // �ׂ͂ݏo���ُ�
    unsigned short cw_pa; // �׎p�ُ�m�F

    unsigned short nBay_Wait; // ���s��ʒu�m�F��ϰ
    unsigned short nLvl_Wait; // ���~��ʒu�m�F��ϰ
    unsigned short nFrk_Wait; // ̫����ʒu�m�F��ϰ
    unsigned short nBay_Tech; // ���s����è��ݸޔ��]���҂�����

    unsigned short nBay_T_On;  // ���sPset  ON�ިڰ
    unsigned short nBay_T_Off; //          OFF�ިڰ
    unsigned short nLvl_T_On;  // ���~Pset  ON�ިڰ
    unsigned short nLvl_T_Off; //          OFF�ިڰ
    unsigned short nFrk_T_On;  // ̫��Pset  ON�ިڰ
    unsigned short nFrk_T_Off; //          OFF�ިڰ

    unsigned short nLvl_H_Check; // ���~���ٓ�������Ď��J�n

    unsigned short over[3]; // �I�[�o�[�^�C���E�`�F�c�N

    unsigned short lvl_ls; // �t�H�[�N�o�����^�C�}�[�i�r�s�j
    unsigned short Bz_On;  // �u�U�[�I���^�C��

    unsigned short nT_Bay_SON_Off; // S-ON OFF�^�C�}
    unsigned short nT_Lvl_SON_Off; // S-ON OFF�^�C�}
    unsigned short nT_Frk_SON_Off; // S-ON OFF�^�C�}

    unsigned short nSt_Ovt1; // ST�������(�\��E���s)
    unsigned short nSt_Ovt2; // ST�������(�אρE�׍~)
    unsigned short nLvl_Son; // S-ON�ިڰ

    unsigned short Bz_On_Wait; // ���񓮍�҂��޻ްON����
    unsigned short overEco[3]; // �I�[�o�[�^�C��(�ȴȐ�p)
                               //		unsigned short		nFrk_Org[2];		// ̫�����_���A�p��ϰ
    unsigned short PP_T3;      // PP�J����^�C���A�E�g <61136>
    unsigned short PP_T4;      // PP���_���A����^�C���A�E�g <61136>

    //		unsigned short		yobi[4];			// �\�� <61136>
    unsigned short PP_T5; // PP���_���Aoff�f�B���[�^�C�}�[(�J��) <61136>
    unsigned short PP_T6; // PP���_���Aon�f�B���[�^�C�}�[(�J��) <61136>
    unsigned short PP_T7; // PP���_���Aoff�f�B���[�^�C�}�[(�L�k) <61136>
    unsigned short PP_T8; // PP���_���Aon�f�B���[�^�C�}�[(�L�k) <61136>
};

//*************************************************************************************************
//�@SH2-CD2�p�̎��ۂ���۸��тŎg�p����è��ݸ��ް��\����
//  ��EMAKE��"extern"��t�������Ȃ��ׁA�\���̓��̕ϐ���`�ɂ́A�擪�ɽ�߰� or TAB������
//*************************************************************************************************
typedef struct TDATA_SH // SH2���Ŏg�p����ׂɁA�������E�Œ�`
                        // �eð��ق͌Œ蒷�ŗ̈�m�ۂ��āA�ϒ����~�߂�
                        // �eð��ِ�MAX�́AMD4.H�Œ�`
{
    // //*************************************************************************************************

    // //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    // //		�e��e�[�u��
    // //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    // //************************************************
    // // SH2�߲���́Aint(4�޲�)�ƂȂ�
    // //************************************************
    // unsigned char *g_end_add;     // �K��l�G���h�A�h���X
    // short g_Ramrom;               // �\��
    // unsigned char *g_pKasoBayAdr; // ���z�A�e�[�u��
    // unsigned char g_cKasoBayCnt;
    // unsigned char *g_pKasoLvlAdr; // ���z�i�e�[�u��
    // unsigned char g_pKasoLvlCnt;
    // struct TBL_NISUGATA *g_pNisugataAdr; // ����׌��o�p�e�[�u��
    // unsigned char g_cNisugataCnt;
    // struct TBL_TOKUSYU *g_pTokuTanaAdr; // ����I�e�[�u��
    // unsigned char g_cTokuTanaCnt;
    // long *g_pBayStopAdr; // ���s��~�ʒu
    // unsigned char g_cBayStopCnt;
    // long *g_pLvlStopAdr; // ���~��~�ʒu
    // unsigned char g_cLvlStopCnt;
    // struct HOSEI_DATA *g_pBayHoseiAdr; // ���s�␳
    // short g_nBayHoseiCnt;
    // struct HOSEI_DATA *g_pLvlHoseiAdr; // ���~�␳
    // unsigned char g_cLvlHoseiCnt;
    // unsigned char *g_pTechLvlAdr; // �e�B�[�`���O�i
    // unsigned char g_cTechLvlCnt;
    // struct TECH_DATA *g_pTechCalAdr; // �e�B�[�`���O���Z�w���e�[�u��
    // unsigned char g_cTechtCalCnt;
    // struct TECH_KINSHI_AREA *g_pTechKinAreaAdr; // �e�B�[�`���O�֎~���
    // unsigned char g_cTechtKinAreaCnt;

    // long g_lTableYobi[5]; // �\���G���A�i�e�[�u����`�ǉ��p�j

    // //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    // //			�Œ�̈�
    // //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

     struct _timer g_tm;   // �e��^�C�}�[�l
    // long g_lTimerYobi[5]; // �\���G���A

    // // �e��K��l
    // unsigned char g_cTanFlg; // 		�[�ُ햳���׸�
    //                          // 		bit0:���s bit1:���~
    // unsigned char g_Cropt;   // 		�N���[���E�I�v�V����
    // unsigned char g_yobi[2]; // 		�\��
    // struct RACK_LAYOUT g_Rack_Tbl;     // ���b�N���C�A�E�g
    // struct _org g_org;                 // �e��e���_�l
    // struct _l_lv g_lv;                 // �I�㉺���x��
    // struct _frk_w g_fw;                // �t�H�[�N�X�g���[�N
    // struct _frk_h g_FrkHosei;          // �t�H�[�N�␳�f�[�^�i���g�p�j
    // struct _ok g_Ok;                   // ���e��~�덷
    // struct _TenkenD g_TenkenD;         // �_�����쎞�]�T����
    // struct _CountD g_CountD;           // ���ė]�T����
    // struct BAY_INV_Data g_Bay_Inv_Dat; // ���sINV�ް�
    // struct LVL_INV_Data g_Lvl_Inv_Dat; // ���~INV�ް�
    // struct FRK_INV_Data g_Frk_Inv_Dat; // ̫��INV�ް�
    // struct Kg_Dat g_Bay_Kg_Dat;        // ���s���������ް�
    // struct Kg_Dat g_Lvl_Kg_Dat;        // ���~���������ް�
    // struct Oikomi_Dat g_Oikomi;        // ��ʒu�ǂ������ް�
    // struct _AUTOTECH g_AutoTech;       // ����è��ݸ����Ұ�
    // struct _SOFTLIMIT g_SoftLimit;     // ����ЯĐݒ�
    //long g_lYobi[20]; // �\���ر

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //			�ϗ̈�i�̈�m�ۗp�Ƃ��čő吔�ł̒�`���s���j
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    // unsigned char g_Ks_Bay_dumy[TABLE_KASO_BAY_MAX];                 // ���z�Að���
    // unsigned char g_Ks_Lvl_dumy[TABLE_KASO_LVL_MAX];                 // ���z�ið���
    // struct TBL_NISUGATA g_cag_tbl_d[TABLE_CAG_MAX];                  // ����׌��oð���
    // struct TBL_TOKUSYU g_st_dumy[TABLE_TOKUSYU_MAX];                 // ����Ið���
    // long g_b_dumy[TABLE_BAY_MAX];                                    // ���s��~�ʒu
    // long g_l_dumy[TABLE_LVL_MAX];                                    // ���~��~�ʒu
    // unsigned char g_tlvl_dumy[TABLE_LVL_TECH_MAX];                   // è��ݸޒið���
    // struct TECH_DATA g_td_dumy[TABLE_TECH_CAL_MAX];                  // è��ݸމ��Z�w��ð���
    // struct TECH_KINSHI_AREA g_tk_dumy[TABLE_KIN_AREA_MAX];           // è��ݸދ֎~���
    // struct HOSEI_DATA g_bh_dumy[TABLE_BAY_MAX * TABLE_LVL_TECH_MAX]; // ���s�␳
    // struct HOSEI_DATA g_lh_dumy[TABLE_BAY_MAX];                      // ���~�␳

    // struct TBL_TOKUSYU g_st_dumy2[500]; // �\���Ƃ��ē���Ið���500���̗̈���m��

    // unsigned short g_DUMMY[94]; // �f�[�^�T�C�Y�����p
    // unsigned char g_end;        // �f�[�^�E�G���h�t���O

    //*************************************************************************************************
};