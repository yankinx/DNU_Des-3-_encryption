

static const unsigned long long __K1P[28] = {
	57, 49, 41, 33, 25, 17, 9 , 1 , 58, 50, 42, 34, 26, 18,
	10, 2 , 59, 51, 43, 35, 27, 19, 11, 3 , 60, 52, 44, 36,
};
static const unsigned long long __K2P[28] = {
	63, 55, 47, 39, 31, 23, 15, 7 , 62, 54, 46, 38, 30, 22,
	14, 6 , 61, 53, 45, 37, 29, 21, 13, 5 , 28, 20, 12, 4 ,
};
static const unsigned long long __CP[48] = {
	14, 17, 11, 24, 1 , 5 , 3 , 28, 15, 6 , 21, 10,
	23, 19, 12, 4 , 26, 8 , 16, 7 , 27, 20, 13, 2 ,
	41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48,
	44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32,
};


//static const uint8_t __EP[48] = {
//	32, 1 , 2 , 3 , 4 , 5 , 4 , 5 , 6 , 7 , 8 , 9 ,
//	8 , 9 , 10, 11, 12, 13, 12, 13, 14, 15, 16, 17,
//	16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25,
//	24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1 ,
//};
#define E_0 0
#define E_1 31
#define E_2 30
#define E_3 29
#define E_4 28
#define E_5 27
#define E_6 28
#define E_7 27
#define E_8 26
#define E_9 25
#define E_10 24
#define E_11 23
#define E_12 24
#define E_13 23
#define E_14 22
#define E_15 21
#define E_16 20
#define E_17 19
#define E_18 20
#define E_19 19
#define E_20 18
#define E_21 17
#define E_22 16
#define E_23 15
#define E_24 16
#define E_25 15
#define E_26 14
#define E_27 13
#define E_28 12
#define E_29 11
#define E_30 12
#define E_31 11
#define E_32 10
#define E_33 9
#define E_34 8
#define E_35 7
#define E_36 8
#define E_37 7
#define E_38 6
#define E_39 5
#define E_40 4
#define E_41 3
#define E_42 4
#define E_43 3
#define E_44 2
#define E_45 1
#define E_46 0
#define E_47 31
static const uint8_t __Sbox[8][4][16] = {
	{ // 0
		{14, 4 , 13, 1 , 2 , 15, 11, 8 , 3 , 10, 6 , 12, 5 , 9 , 0 , 7 },
		{0 , 15, 7 , 4 , 14, 2 , 13, 1 , 10, 6 , 12, 11, 9 , 5 , 3 , 8 },
		{4 , 1 , 14, 8 , 13, 6 , 2 , 11, 15, 12, 9 , 7 , 3 , 10, 5 , 0 },
		{15, 12, 8 , 2 , 4 , 9 , 1 , 7 , 5 , 11, 3 , 14, 10, 0 , 6 , 13},
	},
	{ // 1
		{15, 1 , 8 , 14, 6 , 11, 3 , 4 , 9 , 7 , 2 , 13, 12, 0 , 5 , 10},
		{3 , 13, 4 , 7 , 15, 2 , 8 , 14, 12, 0 , 1 , 10, 6 , 9 , 11, 5 },
		{0 , 14, 7 , 11, 10, 4 , 13, 1 , 5 , 8 , 12, 6 , 9 , 3 , 2 , 15},
		{13, 8 , 10, 1 , 3 , 15, 4 , 2 , 11, 6 , 7 , 12, 0 , 5 , 14, 9 },
	},
	{ // 2
		{10, 0 , 9 , 14, 6 , 3 , 15, 5 , 1 , 13, 12, 7 , 11, 4 , 2 , 8 },
		{13, 7 , 0 , 9 , 3 , 4 , 6 , 10, 2 , 8 , 5 , 14, 12, 11, 15, 1 },
		{13, 6 , 4 , 9 , 8 , 15, 3 , 0 , 11, 1 , 2 , 12, 5 , 10, 14, 7 },
		{1 , 10, 13, 0 , 6 , 9 , 8 , 7 , 4 , 15, 14, 3 , 11, 5 , 2 , 12},
	},
	{ // 3
		{7 , 13, 14, 3 , 0 , 6 , 9 , 10, 1 , 2 , 8 , 5 , 11, 12, 4 , 15},
		{13, 8 , 11, 5 , 6 , 15, 0 , 3 , 4 , 7 , 2 , 12, 1 , 10, 14, 9 },
		{10, 6 , 9 , 0 , 12, 11, 7 , 13, 15, 1 , 3 , 14, 5 , 2 , 8 , 4 },
		{3 , 15, 0 , 6 , 10, 1 , 13, 8 , 9 , 4 , 5 , 11, 12, 7 , 2 , 14},
	},
	{ // 4
		{2 , 12, 4 , 1 , 7 , 10, 11, 6 , 8 , 5 , 3 , 15, 13, 0 , 14, 9 },
		{14, 11, 2 , 12, 4 , 7 , 13, 1 , 5 , 0 , 15, 10, 3 , 9 , 8 , 6 },
		{4 , 2 , 1 , 11, 10, 13, 7 , 8 , 15, 9 , 12, 5 , 6 , 3 , 0 , 14},
		{11, 8 , 12, 7 , 1 , 14, 2 , 13, 6 , 15, 0 , 9 , 10, 4 , 5 , 3 },
	},
	{ // 5
		{12, 1 , 10, 15, 9 , 2 , 6 , 8 , 0 , 13, 3 , 4 , 14, 7 , 5 , 11},
		{10, 15, 4 , 2 , 7 , 12, 9 , 5 , 6 , 1 , 13, 14, 0 , 11, 3 , 8 },
		{9 , 14, 15, 5 , 2 , 8 , 12, 3 , 7 , 0 , 4 , 10, 1 , 13, 11, 6 },
		{4 , 3 , 2 , 12, 9 , 5 , 15, 10, 11, 14, 1 , 7 , 6 , 0 , 8 , 13},
	},
	{ // 6
		{4 , 11, 2 , 14, 15, 0 , 8 , 13, 3 , 12, 9 , 7 , 5 , 10, 6 , 1 },
		{13, 0 , 11, 7 , 4 , 9 , 1 , 10, 14, 3 , 5 , 12, 2 , 15, 8 , 6 },
		{1 , 4 , 11, 13, 12, 3 , 7 , 14, 10, 15, 6 , 8 , 0 , 5 , 9 , 2 },
		{6 , 11, 13, 8 , 1 , 4 , 10, 7 , 9 , 5 , 0 , 15, 14, 2 , 3 , 12},
	},
	{ // 7
		{13, 2 , 8 , 4 , 6 , 15, 11, 1 , 10, 9 , 3 , 14, 5 , 0 , 12, 7 },
		{1 , 15, 13, 8 , 10, 3 , 7 , 4 , 12, 5 , 6 , 11, 0 , 14, 9 , 2 },
		{7 , 11, 4 , 1 , 9 , 12, 14, 2 , 0 , 6 , 10, 13, 15, 3 , 5 , 8 },
		{2 , 1 , 14, 7 , 4 , 10, 8 , 13, 15, 12, 9 , 0 , 3 , 5 , 6 , 11},
	},
};
//static const uint8_t __P[32] = {
//	16, 7 , 20, 21, 29, 12, 28, 17, 1 , 15, 23, 26, 5 , 18, 31, 10,
//	2 , 8 , 24, 14, 32, 27, 3 , 9 , 19, 13, 30, 6 , 22, 11, 4 , 25,
//};
#define P_0 16
#define P_1 25
#define P_2 12
#define P_3 11
#define P_4 3
#define P_5 20
#define P_6 4
#define P_7 15
#define P_8 31
#define P_9 17
#define P_10 9
#define P_11 6
#define P_12 27
#define P_13 14
#define P_14 1
#define P_15 22
#define P_16 30
#define P_17 24
#define P_18 8
#define P_19 18
#define P_20 0
#define P_21 5
#define P_22 29
#define P_23 23
#define P_24 13
#define P_25 19
#define P_26 2
#define P_27 26
#define P_28 10
#define P_29 21
#define P_30 28
#define P_31 7
//static const uint8_t __IP[64] = {
//	2	,	10	,	18	,	26	,	34	,	42	,	50	,	58	,
//4	,	12	,	20	,	28	,	36	,	44	,	52	,	60	,
//6	,	14	,	22	,	30	,	38	,	46	,	54	,	62	,
//8	,	16	,	24	,	32	,	40	,	48	,	56	,	64	,
//1	,	9	,	17	,	25	,	33	,	41	,	49	,	57	,
//3	,	11	,	19	,	27	,	35	,	43	,	51	,	59	,
//5	,	13	,	21	,	29	,	37	,	45	,	53	,	61	,
//7	,	15	,	23	,	31	,	39	,	47	,	55	,	63	,
//
//};
#define IP_0 62
#define IP_1 54
#define IP_2 46
#define IP_3 38
#define IP_4 30
#define IP_5 22
#define IP_6 14
#define IP_7 6
#define IP_8 60
#define IP_9 52
#define IP_10 44
#define IP_11 36
#define IP_12 28
#define IP_13 20
#define IP_14 12
#define IP_15 4
#define IP_16 58
#define IP_17 50
#define IP_18 42
#define IP_19 34
#define IP_20 26
#define IP_21 18
#define IP_22 10
#define IP_23 2
#define IP_24 56
#define IP_25 48
#define IP_26 40
#define IP_27 32
#define IP_28 24
#define IP_29 16
#define IP_30 8
#define IP_31 0
#define IP_32 63
#define IP_33 55
#define IP_34 47
#define IP_35 39
#define IP_36 31
#define IP_37 23
#define IP_38 15
#define IP_39 7
#define IP_40 61
#define IP_41 53
#define IP_42 45
#define IP_43 37
#define IP_44 29
#define IP_45 21
#define IP_46 13
#define IP_47 5
#define IP_48 59
#define IP_49 51
#define IP_50 43
#define IP_51 35
#define IP_52 27
#define IP_53 19
#define IP_54 11
#define IP_55 3
#define IP_56 57
#define IP_57 49
#define IP_58 41
#define IP_59 33
#define IP_60 25
#define IP_61 17
#define IP_62 9
#define IP_63 1
//static const uint8_t __FP[64] = {
//
//	33, 1, 41, 9 , 49, 17, 57, 25,
//	34, 2, 42, 10, 50, 18, 58, 26,
//	35, 3, 43, 11, 51, 19, 59, 27,
//	36, 4, 44, 12, 52, 20, 60, 28,
//	37, 5, 45, 13, 53, 21, 61, 29,
//	38, 6, 46, 14, 54, 22, 62, 30,
//	39, 7, 47, 15, 55, 23, 63, 31,
//	40, 8, 48, 16, 56, 24, 64, 32,
//
//
//};
#define IPM_0 31
#define IPM_1 63
#define IPM_2 23
#define IPM_3 55
#define IPM_4 15
#define IPM_5 47
#define IPM_6 7
#define IPM_7 39
#define IPM_8 30
#define IPM_9 62
#define IPM_10 22
#define IPM_11 54
#define IPM_12 14
#define IPM_13 46
#define IPM_14 6
#define IPM_15 38
#define IPM_16 29
#define IPM_17 61
#define IPM_18 21
#define IPM_19 53
#define IPM_20 13
#define IPM_21 45
#define IPM_22 5
#define IPM_23 37
#define IPM_24 28
#define IPM_25 60
#define IPM_26 20
#define IPM_27 52
#define IPM_28 12
#define IPM_29 44
#define IPM_30 4
#define IPM_31 36
#define IPM_32 27
#define IPM_33 59
#define IPM_34 19
#define IPM_35 51
#define IPM_36 11
#define IPM_37 43
#define IPM_38 3
#define IPM_39 35
#define IPM_40 26
#define IPM_41 58
#define IPM_42 18
#define IPM_43 50
#define IPM_44 10
#define IPM_45 42
#define IPM_46 2
#define IPM_47 34
#define IPM_48 25
#define IPM_49 57
#define IPM_50 17
#define IPM_51 49
#define IPM_52 9
#define IPM_53 41
#define IPM_54 1
#define IPM_55 33
#define IPM_56 24
#define IPM_57 56
#define IPM_58 16
#define IPM_59 48
#define IPM_60 8
#define IPM_61 40
#define IPM_62 0
#define IPM_63 32