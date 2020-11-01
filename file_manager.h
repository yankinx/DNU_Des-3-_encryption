#ifndef FILE_MANAGER
#define FILE MANAGER

#include <direct.h>

template<class T>
class File_Manager
{
private:
	HANDLE ReadFileHandle, WriteFileHandle;
	DWORD read_file_size, last_block_size, size_buff, ClusterSize;
	T* ReadBuff1, *ReadBuff2, *WriteBuff;
	BOOL Decryption;
	Base_DES<unsigned long long>* Enc_des_mod;
	T** InitiationReadBufs() {
		ReadBuff1 = new T[size_buff + 1];
		ReadBuff2 = new T[size_buff + 1];
		WriteBuff = new T[size_buff + 1];
		ReadBuff2[512] = 0;
		T** buf = new T*[2];
		buf[0] = ReadBuff1;
		buf[1] = ReadBuff2;
		return buf;
	}
	HANDLE GetFileHandle(LPCSTR File_name, bool IsRead = true, bool IsOverl = true) {

		 return CreateFile(File_name,
			IsRead ? GENERIC_READ :
			GENERIC_WRITE,
			0,
			NULL,
			IsRead ? OPEN_EXISTING :
			CREATE_ALWAYS,
			FILE_FLAG_SEQUENTIAL_SCAN |
			(IsOverl ? FILE_FLAG_OVERLAPPED : 0),
			NULL
		);
	}
	void SetClusterSize(LPCSTR file_name) {
		_diskfree_t drive_info;
		ClusterSize = _getdiskfree((int)file_name[0] -'A'+1, &drive_info);
		DWORD size = drive_info.sectors_per_cluster * drive_info.bytes_per_sector;
		ClusterSize = ClusterSize > size ? ClusterSize : size;
	}
public:
	File_Manager() {
	}
	~File_Manager() {
	}
	void setEnctupt(Base_DES<unsigned long long>* enc) {
		Enc_des_mod = enc;
	}
	void SetReadFile(LPCSTR file_name) {
		ReadFileHandle = GetFileHandle(file_name);
		SetClusterSize(file_name);
	}
	void SetWriteFile(LPCSTR file_name) {
		WriteFileHandle = GetFileHandle(file_name, false);
		SetClusterSize(file_name);
	}
	bool Async_Encrypt(bool Decryption) {
		BOOL decryption = Decryption;
		OVERLAPPED Overl_Read, Overl_Write;
		BOOL result_of_read, result_of_write = true;
		DWORD NbytesRead, NbytesWrite = 0;
		Overl_Read.Internal = Overl_Read.InternalHigh = Overl_Read.Offset= Overl_Read.OffsetHigh = 0;
		Overl_Read.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
		Overl_Write.Internal = Overl_Write.InternalHigh = Overl_Write.Offset = Overl_Write.OffsetHigh = 0;
		Overl_Write.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
		bool NBuf = false, NBufNew;
		if (ReadFileHandle == INVALID_HANDLE_VALUE || WriteFileHandle == INVALID_HANDLE_VALUE)
		{
			cout << "FAILE HENDL" << endl;
			return false;
		}
		size_buff = ClusterSize / sizeof(T);
		T** TReadBufs = InitiationReadBufs();
		//Первое считывание
		// ------------------------------------------------------------
		result_of_read = ReadFile(ReadFileHandle, TReadBufs[true], ClusterSize, &NbytesRead, &Overl_Read);
			//--------------------------------------------------------
		    //
			read_file_size = GetFileSize(ReadFileHandle, NULL);
			last_block_size = read_file_size % sizeof(T);
		if (result_of_read == FALSE) {
			GetOverlappedResult(ReadFileHandle, &Overl_Read, &NbytesRead, TRUE);
		}
		//-------------------------------------------------------------
		//Вход в основной цикл 
		//-------------------------------------------------------------
			DWORD num = read_file_size / ClusterSize;
			DWORD Counter_full_clusters = decryption ?
				read_file_size % ClusterSize == 1 ? num - 1 : num :
				num;
			DWORD ms = GetTickCount();
		if (num)
		{
			do
			{
				Counter_full_clusters--;
				Overl_Read.Offset += NbytesRead;
				NBufNew = NBuf ^ 1;
				Counter_full_clusters ? result_of_read = ReadFile(ReadFileHandle, TReadBufs[NBuf], ClusterSize, &NbytesRead, &Overl_Read) : false;

				if (result_of_write == FALSE) {
					GetOverlappedResult(WriteFileHandle, &Overl_Write, &NbytesWrite, TRUE);
				}
				Overl_Write.Offset += NbytesWrite;
				NBuf = NBufNew;

					// DES цикл 
					//------------------------
					for (DWORD i = 0; i < size_buff; i++)
					{
					WriteBuff[i] = Enc_des_mod->Encrypt(TReadBufs[NBuf][i]);
					//	WriteBuff[i] = DES_Encrypt(TReadBufs[NBuf][i])
					}
					//------------------------
				result_of_write = WriteFile(WriteFileHandle, WriteBuff, ClusterSize, &NbytesWrite, &Overl_Write);

				if (result_of_read == FALSE)
				{
					GetOverlappedResult(WriteFileHandle, &Overl_Read, &NbytesRead, TRUE);
				}
			} while (Counter_full_clusters);
		}
		if (result_of_write == FALSE) {
			GetOverlappedResult(WriteFileHandle, &Overl_Write, &NbytesWrite, TRUE);
		}
		Overl_Write.Offset += NbytesWrite;
		//-------------------------------------------------------------
		//Обработка последнего кластера
		//-------------------------------------------------------------
		if (decryption)
		{
			DWORD last_cluster_size = read_file_size - Overl_Read.Offset;
			DWORD sum_last_bloks = last_cluster_size / sizeof(T);
			ReadBuff1[sum_last_bloks] = 0;
			result_of_read = ReadFile(ReadFileHandle, ReadBuff1, last_cluster_size, &NbytesRead, &Overl_Read);

			if (result_of_write == FALSE) {
				GetOverlappedResult(WriteFileHandle, &Overl_Write, &NbytesWrite, TRUE);
			}
				// DES цикл 
				//------------------------
				for (DWORD i = 0; i < sum_last_bloks; i++)
				{
					//cout << "CRIPT " << i << endl;
				//	cout << "S " << bitset<sizeof(ReadBuff1[i])* CHAR_BIT>(ReadBuff1[i]) << endl << endl;
					ReadBuff1[i] = Enc_des_mod->Encrypt(ReadBuff1[i]);
				//	cout << "F " << bitset<sizeof(ReadBuff1[i])* CHAR_BIT>(ReadBuff1[i]) << endl << endl;
				}

			DWORD lws = sum_last_bloks * sizeof(T);
			if (last_block_size)
			{
				lws = lws - (sizeof(T) - ReadBuff1[sum_last_bloks]);
			}
			result_of_write = WriteFile(WriteFileHandle, ReadBuff1, lws, &NbytesWrite, &Overl_Write);

			if (result_of_write == FALSE) {
				GetOverlappedResult(WriteFileHandle, &Overl_Write, &NbytesWrite, TRUE);
			}
		}
		else {
			DWORD last_cluster_size = read_file_size % ClusterSize;
			if (last_cluster_size == 0) {
				return true;
			}

			result_of_read = ReadFile(ReadFileHandle, ReadBuff1, last_cluster_size, &NbytesRead, &Overl_Read);
			
			if (result_of_read == FALSE) {
				GetOverlappedResult(ReadFileHandle, &Overl_Read, &NbytesRead, TRUE);
			}
			DWORD sum_last_bloks = last_cluster_size % sizeof(T) ? last_cluster_size / sizeof(T) + 1 : last_cluster_size / sizeof(T);
				// DES цикл 
				//------------------------
				for (DWORD i = 0; i < sum_last_bloks; i++)
				{
				//cout << "CRIPT " << i << endl;
				//cout << "S "<< bitset<sizeof(ReadBuff1[i])* CHAR_BIT>(ReadBuff1[i]) << endl << endl;
					ReadBuff1[i] = Enc_des_mod->Encrypt(ReadBuff1[i]);
				//cout <<"F "<< bitset<sizeof(ReadBuff1[i])* CHAR_BIT>(ReadBuff1[i]) << endl << endl;
				}
				//------------------------'

			DWORD lws = sum_last_bloks * sizeof(T);
			if (last_block_size)
			{
				ReadBuff1[sum_last_bloks] = last_block_size;
				lws = sum_last_bloks * sizeof(T) + 1;
			}
			result_of_write = WriteFile(WriteFileHandle, ReadBuff1, lws, &NbytesWrite, &Overl_Write);

			if (result_of_write == FALSE) {
				GetOverlappedResult(WriteFileHandle, &Overl_Write, &NbytesWrite, TRUE);
			}

		}
		cout <<"TIME END  " << GetTickCount() - ms << endl;
		CloseHandle(ReadFileHandle);
		CloseHandle(WriteFileHandle);
		delete ReadBuff1;
		delete ReadBuff2;
		delete WriteBuff;
		return true;
	}
};
#endif 
