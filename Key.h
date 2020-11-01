#pragma once
#ifndef KEY_H
#define KEY_H
#include <Windows.h>
#include "pth.h"
#define Func_G(block28,G_t, i) *block28 |= ((block56b >> (64 - G_t)) & 0x01) << (31 - i)
#define Func_H(H_t, i) block_48b |= ((block_56b >> (64 - H_t)) & 0x01) << (63 - i);
#define LSHIFT_28BIT(x, L) ((((x) << (L)) | ((x) >> (-(L) & 27))) & (((unsigned long long)1 << 32) - 1))
class Key
{
private:

	unsigned long long* Block_key;
public:
	Key() {};
	~Key() {};
	unsigned long long* GetKey(unsigned long long key) {
		Block_key = new unsigned long long[16];
		ekey_expansion(key, Block_key);
		return Block_key;
	}
	void ekey_expansion(unsigned long long key, unsigned long long* block16_key48bit) {
		unsigned long C_block28b = 0, D_block28b = 0;
		G_56bits_to_28bits(key, &C_block28b, &D_block28b);
		key_expansion_to_48bits(C_block28b, D_block28b, block16_key48bit);
	};
	void G_56bits_to_28bits(unsigned long long block56b, unsigned long * C_block28b, unsigned long * D_block28b) {
		for (int i = 0; i < 28; ++i) {
			*C_block28b |= ((block56b >> (64 -  __K1P[i])) & 0x01) << (31 - i);
			*D_block28b |= ((block56b >> (64 -  __K2P[i])) & 0x01) << (31 - i);
		}
	}
	void key_expansion_to_48bits(unsigned long C_block28b, unsigned long D_block28b, unsigned long long* block16_key48bit) {
		unsigned long long block_56b;
		int n;
		for (DWORD i = 0; i < 16; i++)
		{
			switch (i)
			{
				case 0: case 1: case 8: case 15: n = 1; break;
				default: n = 2; break;
			}
			C_block28b = LSHIFT_28BIT(C_block28b, n);
			D_block28b = LSHIFT_28BIT(D_block28b, n);
			block_56b = join_28bits_to_56bits(C_block28b, D_block28b);
			block16_key48bit[i] = key_contraction_permutation(block_56b);
		}
	}
	unsigned long long join_28bits_to_56bits(unsigned long C_block28bit, unsigned long D_block28bit) {
		unsigned long long block_56b;
		block_56b = (C_block28bit >> 4);
		block_56b = ((block_56b << 32) | D_block28bit) << 4;
		return block_56b;
	}
	unsigned long long key_contraction_permutation(unsigned long long block_56b) {
		unsigned long long block_48b = 0;
		for (uint8_t i = 0; i < 48; ++i) {
			block_48b |= ((block_56b >> (64 - __CP[i])) & 0x01) << (63 - i);
		}
		return block_48b;
	}
};

#endif // !KEY_H
