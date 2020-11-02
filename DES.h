#pragma once
#ifndef DES_H
#define DES_H
#include "Key.h"
#define IP_fun(IP,num) new_block64b |= ((*block64b >> IP) & 0x01) << num
#define E_fun(E,num) block48b |= (unsigned long long)((*block32b >> E) & 0x01) << num
#define P_fun(P, num) new_block32b |= ((*block32b >> P) & 0x01) << num
template < typename T >
class Base_DES
{
public:
	Base_DES() {
	};
	~Base_DES() {
	};
	virtual T Encrypt(T block) = 0;
	
private:

};
template < typename T >
class DES :public Base_DES<T>
{
public:
	Key key;
	const unsigned long long* block_key;
	DES() {};
	~DES() {};
	T Encrypt(T block)override {

		unsigned long L0, R0;
		block = initial_permutation(&block);
		L0 = (unsigned long)(block >> 32);
		R0 = (unsigned long)(block);

		feistel_cipher(&L0, &R0, block_key);
		block = join_32bits_to_64bits(&L0, &R0);
		block = final_permutation(&block);
		return block;
	} 
	void SetKey(unsigned long long key64) {
		block_key = key.GetKey(key64);
	}
private:
	unsigned long long final_permutation(const unsigned long long* block64b) {
		unsigned long long new_block64b = 0;
		/*for (DWORD i = 0; i < 64; ++i) {
			new_block64b |= ((block64b >> (64 - __FP[i])) & 0x01) << (63 - i);
		}*/
		IP_fun(IPM_0, 63);
		IP_fun(IPM_1, 62);
		IP_fun(IPM_2, 61);
		IP_fun(IPM_3, 60);
		IP_fun(IPM_4, 59);
		IP_fun(IPM_5, 58);
		IP_fun(IPM_6, 57);
		IP_fun(IPM_7, 56);
		IP_fun(IPM_8, 55);
		IP_fun(IPM_9, 54);
		IP_fun(IPM_10, 53);
		IP_fun(IPM_11, 52);
		IP_fun(IPM_12, 51);
		IP_fun(IPM_13, 50);
		IP_fun(IPM_14, 49);
		IP_fun(IPM_15, 48);
		IP_fun(IPM_16, 47);
		IP_fun(IPM_17, 46);
		IP_fun(IPM_18, 45);
		IP_fun(IPM_19, 44);
		IP_fun(IPM_20, 43);
		IP_fun(IPM_21, 42);
		IP_fun(IPM_22, 41);
		IP_fun(IPM_23, 40);
		IP_fun(IPM_24, 39);
		IP_fun(IPM_25, 38);
		IP_fun(IPM_26, 37);
		IP_fun(IPM_27, 36);
		IP_fun(IPM_28, 35);
		IP_fun(IPM_29, 34);
		IP_fun(IPM_30, 33);
		IP_fun(IPM_31, 32);
		IP_fun(IPM_32, 31);
		IP_fun(IPM_33, 30);
		IP_fun(IPM_34, 29);
		IP_fun(IPM_35, 28);
		IP_fun(IPM_36, 27);
		IP_fun(IPM_37, 26);
		IP_fun(IPM_38, 25);
		IP_fun(IPM_39, 24);
		IP_fun(IPM_40, 23);
		IP_fun(IPM_41, 22);
		IP_fun(IPM_42, 21);
		IP_fun(IPM_43, 20);
		IP_fun(IPM_44, 19);
		IP_fun(IPM_45, 18);
		IP_fun(IPM_46, 17);
		IP_fun(IPM_47, 16);
		IP_fun(IPM_48, 15);
		IP_fun(IPM_49, 14);
		IP_fun(IPM_50, 13);
		IP_fun(IPM_51, 12);
		IP_fun(IPM_52, 11);
		IP_fun(IPM_53, 10);
		IP_fun(IPM_54, 9);
		IP_fun(IPM_55, 8);
		IP_fun(IPM_56, 7);
		IP_fun(IPM_57, 6);
		IP_fun(IPM_58, 5);
		IP_fun(IPM_59, 4);
		IP_fun(IPM_60, 3);
		IP_fun(IPM_61, 2);
		IP_fun(IPM_62, 1);
		IP_fun(IPM_63, 0);
		//cout << "-ip" << endl;
		//cout << bitset<sizeof(new_block64b)* CHAR_BIT>(new_block64b) << endl << endl;
		return new_block64b;
	}
	unsigned long long join_32bits_to_64bits(const unsigned long* block32b_1, const unsigned long* block32b_2) {
		unsigned long long block64b;
		block64b = (unsigned long long)block32b_1;
		block64b = (unsigned long long)(block64b << 32) | *block32b_2;
		return block64b;
	}
	
	inline unsigned long long initial_permutation(const unsigned long long* block64b) {	
		unsigned long long new_block64b = 0;
		/*for (DWORD i = 0; i < 64; ++i) {
			new_block64b |= ((block64b >> (64 - __IP[i])) & 0x01) << (63 - i);
		}*/
		IP_fun(IP_0, 63);
		IP_fun(IP_1, 62);
		IP_fun(IP_2, 61);
		IP_fun(IP_3, 60);
		IP_fun(IP_4, 59);
		IP_fun(IP_5, 58);
		IP_fun(IP_6, 57);
		IP_fun(IP_7, 56);
		IP_fun(IP_8, 55);
		IP_fun(IP_9, 54);
		IP_fun(IP_10, 53);
		IP_fun(IP_11, 52);
		IP_fun(IP_12, 51);
		IP_fun(IP_13, 50);
		IP_fun(IP_14, 49);
		IP_fun(IP_15, 48);
		IP_fun(IP_16, 47);
		IP_fun(IP_17, 46);
		IP_fun(IP_18, 45);
		IP_fun(IP_19, 44);
		IP_fun(IP_20, 43);
		IP_fun(IP_21, 42);
		IP_fun(IP_22, 41);
		IP_fun(IP_23, 40);
		IP_fun(IP_24, 39);
		IP_fun(IP_25, 38);
		IP_fun(IP_26, 37);
		IP_fun(IP_27, 36);
		IP_fun(IP_28, 35);
		IP_fun(IP_29, 34);
		IP_fun(IP_30, 33);
		IP_fun(IP_31, 32);
		IP_fun(IP_32, 31);
		IP_fun(IP_33, 30);
		IP_fun(IP_34, 29);
		IP_fun(IP_35, 28);
		IP_fun(IP_36, 27);
		IP_fun(IP_37, 26);
		IP_fun(IP_38, 25);
		IP_fun(IP_39, 24);
		IP_fun(IP_40, 23);
		IP_fun(IP_41, 22);
		IP_fun(IP_42, 21);
		IP_fun(IP_43, 20);
		IP_fun(IP_44, 19);
		IP_fun(IP_45, 18);
		IP_fun(IP_46, 17);
		IP_fun(IP_47, 16);
		IP_fun(IP_48, 15);
		IP_fun(IP_49, 14);
		IP_fun(IP_50, 13);
		IP_fun(IP_51, 12);
		IP_fun(IP_52, 11);
		IP_fun(IP_53, 10);
		IP_fun(IP_54, 9);
		IP_fun(IP_55, 8);
		IP_fun(IP_56, 7);
		IP_fun(IP_57, 6);
		IP_fun(IP_58, 5);
		IP_fun(IP_59, 4);
		IP_fun(IP_60, 3);
		IP_fun(IP_61, 2);
		IP_fun(IP_62, 1);
		IP_fun(IP_63, 0);


		//cout << "ip" << endl;
		//cout << bitset<sizeof(new_block64b)* CHAR_BIT>(new_block64b) << endl << endl;
		return new_block64b;
	}
	inline void feistel_cipher(unsigned long* N1, unsigned long* N2,const unsigned long long* keys48b) {

			for (DWORD round = 0; round < 16; ++round) {
				round_feistel_cipher(N1, N2, &keys48b[round]);
			}
			swap(N1, N2);
			
	
		/*case 'D': case 'd': {
			for (int8_t round = 15; round >= 0; --round) {
				round_feistel_cipher(N1, N2, keys48b[round]);
			}
			swap(N1, N2);
			break;
		}
		}*/
		
	}
	static inline void swap(unsigned long* N1, unsigned long* N2) {
		unsigned long temp = *N1;
		*N1 = *N2;
		*N2 = temp;
	}
	inline void round_feistel_cipher(unsigned long* N1, unsigned long* N2, const unsigned long long* key48b) {
		unsigned long temp = *N2;
		*N2 = func_F(N2, key48b) ^ *N1;		
		*N1 = temp;
	}
	inline unsigned long func_F(unsigned long* block32b,const unsigned long long* key48b) {		
		unsigned long long block48b = expansion_permutation(block32b);
		block48b ^= *key48b;										
		block32b = substitutions(&block48b);						
		return permutation(block32b);
	}
	//#define E_fun(E,num) block48b |= (unsigned long long)((block32b >> E) & 0x01) << num
	inline unsigned long long expansion_permutation(const unsigned long* block32b) {			//расширяющая перестановка на 32-х битный блок
		unsigned long long block48b = 0;
		/*for (DWORD i = 0; i < 48; ++i) {
			block48b |= (unsigned long long)((block32b >> (32 - __EP[i])) & 0x01) << (63 - i);
		}*/
		E_fun(E_0, 63);
		E_fun(E_1, 62);
		E_fun(E_2, 61);
		E_fun(E_3, 60);
		E_fun(E_4, 59);
		E_fun(E_5, 58);
		E_fun(E_6, 57);
		E_fun(E_7, 56);
		E_fun(E_8, 55);
		E_fun(E_9, 54);
		E_fun(E_10, 53);
		E_fun(E_11, 52);
		E_fun(E_12, 51);
		E_fun(E_13, 50);
		E_fun(E_14, 49);
		E_fun(E_15, 48);
		E_fun(E_16, 47);
		E_fun(E_17, 46);
		E_fun(E_18, 45);
		E_fun(E_19, 44);
		E_fun(E_20, 43);
		E_fun(E_21, 42);
		E_fun(E_22, 41);
		E_fun(E_23, 40);
		E_fun(E_24, 39);
		E_fun(E_25, 38);
		E_fun(E_26, 37);
		E_fun(E_27, 36);
		E_fun(E_28, 35);
		E_fun(E_29, 34);
		E_fun(E_30, 33);
		E_fun(E_31, 32);
		E_fun(E_32, 31);
		E_fun(E_33, 30);
		E_fun(E_34, 29);
		E_fun(E_35, 28);
		E_fun(E_36, 27);
		E_fun(E_37, 26);
		E_fun(E_38, 25);
		E_fun(E_39, 24);
		E_fun(E_40, 23);
		E_fun(E_41, 22);
		E_fun(E_42, 21);
		E_fun(E_43, 20);
		E_fun(E_44, 19);
		E_fun(E_45, 18);
		E_fun(E_46, 17);
		E_fun(E_47, 16);
		return block48b;
	}
	unsigned long* substitutions(const unsigned long long* block48b) {					//S-boxes
		unsigned char blocks4b[4], blocks6b[8] = { 0 };//8 блоков по 6 бит, и по 4, в одном эл-те массива содержится 2 блока по 4 бита
		split_48bits_to_6bits(block48b, blocks6b);//принимается 48-битный блок, разбиваем его на блоки по 6 бит
		substitution_6bits_to_4bits(blocks6b, blocks4b);//подстановка 6 битовых блоков в 4-битные
		return join_4bits_to_32bits(blocks4b);
	}
	void split_48bits_to_6bits(const unsigned long long* block48b, unsigned char* blocks6b) {
		/*for (DWORD i = 0; i < 8; ++i) {
			blocks6b[i] = (block48b >> (58 - (i * 6))) << 2;
		}*/
		blocks6b[0] = (*block48b >> 58) << 2;
		blocks6b[1] = (*block48b >> 52) << 2;
		blocks6b[2] = (*block48b >> 46) << 2;
		blocks6b[3] = (*block48b >> 40) << 2;
		blocks6b[4] = (*block48b >> 34) << 2;
		blocks6b[5] = (*block48b >> 28) << 2;
		blocks6b[6] = (*block48b >> 22) << 2;
		blocks6b[7] = (*block48b >> 16) << 2;
	}
	void substitution_6bits_to_4bits(const unsigned char* blocks6b, unsigned char* blocks4b) {
		unsigned char block2b, block4b;
		//cout << "START " << endl;
		//for (DWORD i = 0, j = 0; i < 8; i += 2, ++j) {//пропускаем блок через таблицу S-box 
		//	block2b = extreme_bits(blocks6b[i]);
		//	block4b = middle_bits(blocks6b[i]);
		//	blocks4b[j] = __Sbox[i][block2b][block4b];
		//	block2b = extreme_bits(blocks6b[i + 1]);
		//	block4b = middle_bits(blocks6b[i + 1]);
		//	blocks4b[j] = (blocks4b[j] << 4) | __Sbox[i + 1][block2b][block4b];
		//	cout << "block2b = extreme_bits(blocks6b[" << i << "]);" << endl;
		//	cout << "block4b = middle_bits(blocks6b[" << i << "]);" << endl;
		//	cout << "blocks4b[" << j << "] = __Sbox_" << i << "[block2b][block4b];" << endl;
		//	cout << "block2b = extreme_bits(blocks6b[" << i +1<< "]);" << endl;
		//	cout << "block4b = middle_bits(blocks6b[" << i+1 << "]);" << endl;
		//	cout << "blocks4b[" << j << "] = (blocks4b[" << j << "] << 4) | __Sbox_" << i + 1 << "[block2b][block4b];" << endl;
		//}
		//cout << "end " << endl;
		block2b = extreme_bits(&blocks6b[0]);
		block4b = middle_bits(&blocks6b[0]);
		blocks4b[0] = __Sbox_0[block2b][block4b];
		block2b = extreme_bits(&blocks6b[1]);
		block4b = middle_bits(&blocks6b[1]);
		blocks4b[0] = (blocks4b[0] << 4) | __Sbox_1[block2b][block4b];
		block2b = extreme_bits(&blocks6b[2]);
		block4b = middle_bits(&blocks6b[2]);
		blocks4b[1] = __Sbox_2[block2b][block4b];
		block2b = extreme_bits(&blocks6b[3]);
		block4b = middle_bits(&blocks6b[3]);
		blocks4b[1] = (blocks4b[1] << 4) | __Sbox_3[block2b][block4b];
		block2b = extreme_bits(&blocks6b[4]);
		block4b = middle_bits(&blocks6b[4]);
		blocks4b[2] = __Sbox_4[block2b][block4b];
		block2b = extreme_bits(&blocks6b[5]);
		block4b = middle_bits(&blocks6b[5]);
		blocks4b[2] = (blocks4b[2] << 4) | __Sbox_5[block2b][block4b];
		block2b = extreme_bits(&blocks6b[6]);
		block4b = middle_bits(&blocks6b[6]);
		blocks4b[3] = __Sbox_6[block2b][block4b];
		block2b = extreme_bits(&blocks6b[7]);
		block4b = middle_bits(&blocks6b[7]);
		blocks4b[3] = (blocks4b[3] << 4) | __Sbox_7[block2b][block4b];
	}
	unsigned char extreme_bits(const unsigned char* block6b) {
		return ((*block6b >> 6) & 0x2) | ((*block6b >> 2) & 0x1);
	}
	unsigned char middle_bits(const unsigned char* block6b) {
		return (*block6b >> 3) & 0xF;
	}
	unsigned long* join_4bits_to_32bits(unsigned char* blocks4b) {
		unsigned long block32b;
		for (unsigned char* p = blocks4b; p < blocks4b + 4; ++p) {
			block32b = (block32b << 8) | *p;
		}
		return &block32b;
	}
	// #defined P_fun(P, num) new_block32b |= ((block32b >> P) & 0x01) << num
	unsigned long permutation(const unsigned long* block32b) {						//перестановка таблицы Р
		unsigned long new_block32b = 0;
		//for (DWORD i = 0; i < 32; ++i) {
		//	new_block32b |= ((block32b >> (32 - __P[i])) & 0x01) << (31 - i);
		//	//cout << "#define P_" << i << " " << 32 - __P[i] << endl;
		//	cout << "P_fun(P_" << i << ", " << (31 - i) << ");" << endl;
		//}
		P_fun(P_0, 31);
		P_fun(P_1, 30);
		P_fun(P_2, 29);
		P_fun(P_3, 28);
		P_fun(P_4, 27);
		P_fun(P_5, 26);
		P_fun(P_6, 25);
		P_fun(P_7, 24);
		P_fun(P_8, 23);
		P_fun(P_9, 22);
		P_fun(P_10, 21);
		P_fun(P_11, 20);
		P_fun(P_12, 19);
		P_fun(P_13, 18);
		P_fun(P_14, 17);
		P_fun(P_15, 16);
		P_fun(P_16, 15);
		P_fun(P_17, 14);
		P_fun(P_18, 13);
		P_fun(P_19, 12);
		P_fun(P_20, 11);
		P_fun(P_21, 10);
		P_fun(P_22, 9);
		P_fun(P_23, 8);
		P_fun(P_24, 7);
		P_fun(P_25, 6);
		P_fun(P_26, 5);
		P_fun(P_27, 4);
		P_fun(P_28, 3);
		P_fun(P_29, 2);
		P_fun(P_30, 1);
		P_fun(P_31, 0);
		return new_block32b;
	}
};
template < typename T >
class DES3 :public Base_DES<T>
{
public:
	DES3() {};
	~DES3() {};
	T Encrypt(T block)override {
		cout << "DES DES DES start" << endl;
		return block;
	}

private:

};

template < typename T >
class Mods :public Base_DES<T>
{
protected:
	 
public:
	Mods() {
	
	};
	~Mods() {};
	/*Base_DES<T>* base_des;
	void SetEncryp(Base_DES<T>* des) {
		base_des = des;
	}*/
private:

};

template < typename T >
class ECB : public Mods<T>
{
public:
	ECB() {};
	~ECB() {};
	 T Encrypt(T block) override {
		return base_des->Encrypt(block);
	}
	Base_DES<T>* base_des;
	 void SetEncryp(Base_DES<T>* des) {
		 base_des = des;
	 }
private:

};
template < typename T >
class CBC : public Mods<T>
{
public:
	CBC() {};
	~CBC() {};
	T Encrypt(T block) override {
		cout << "CBC" << endl;
		return base_des->Encrypt(block);
	}
	Base_DES<T>* base_des;
	void SetEncryp(Base_DES<T>* des) {
		 base_des = des;
	}
private:
};

#endif // !DES_H

