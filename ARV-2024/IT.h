#pragma once
#include <iostream>

#define MAXSIZE_ID	8						// ������������ ����� �������� ��������������
#define SCOPED_ID_MAXSIZE   MAXSIZE_ID*2	// ������������ ����� �������� ������������� + ������� ���������
#define MAXSIZE_TI	4096					// ������������ ����� ���������� ����� � ������� ���������������
#define NUM_DEFAULT	0x00000000				// �������� �� ��������� ��� int
#define STR_DEFAULT	0x00					// �������� �� ��������� ��� sting
#define NULLIDX_TI	0xffffffff				// ��� �������� ������� ���������������
#define STR_MAXSIZE	255						// ������������ ����� ���������� ��������
#define NUM_MAXSIZE INT_MAX					// ������������ �������� ��� ���� number
#define NUM_MINSIZE INT_MIN					// ����������� �������� ��� ���� number
#define MAX_PARAMS_COUNT 3					// ������������ ���������� ���������� � �������
#define STRCOPY_PARAMS_CNT 1				// ���-�� ���������� � ������� strcopy
#define LENGHT_PARAMS_CNT 1					// ���-�� ���������� � ������� lenght
#define STRCMPP_PARAMS_CNT 2					// ���-�� ���������� � ������� STRCMPP
#define STRCOPY_TYPE IT::IDDATATYPE::STR
#define LENGHT_TYPE IT::IDDATATYPE::NUM
#define STRCMPP_TYPE IT::IDDATATYPE::NUM


namespace IT
{
    enum IDDATATYPE { NUM = 1, STR = 2, PROC = 3, UNDEF = 4, OCTSTR = 5 };	// ���� ������ ���������������: ��������, ���������, ��� ����, ��������������
    enum IDTYPE { V = 1, F = 2, P = 3, L = 4, S = 5 };		// ���� ���������������: ����������, �������, ��������, �������, ����������� �������
    enum STDFNC { F_STRCOPY, F_LENGTH, F_STRCMPP, F_NOT_STD };	// ����������� �������
    static const IDDATATYPE STRCOPY_PARAMS[] = { IT::IDDATATYPE::STR };	// ��������� ������� strcopy
    static const IDDATATYPE LENGHT_PARAMS[] = { IT::IDDATATYPE::STR };	// ��������� ������� lenght
    static const IDDATATYPE STRCMPP_PARAMS[] = { IT::IDDATATYPE::STR, IT::IDDATATYPE::STR };	// ��������� �-��� strcmpp

    struct Entry
    {
        union
        {
            int	vint;            			// �������� integer
            struct
            {
                int len;					// ���������� ��������
                char str[STR_MAXSIZE - 1];	// �������
            } vstr;							// �������� ������
            struct
            {
                int count;					// ���������� ���������� �������
                IDDATATYPE* types;			// ���� ���������� �������
            } params;
        } value;							// �������� ��������������
        int			idxfirstLE;				// ������ � ������� ������		
        char		id[SCOPED_ID_MAXSIZE];	// �������������
        IDDATATYPE	iddatatype;				// ��� ������
        IDTYPE		idtype;					// ��� ��������������

        Entry()								// ����������� ��� ����������
        {
            this->value.vint = NUM_DEFAULT;
            this->value.vstr.len = NULL;
            this->value.params.count = NULL;
        };
        Entry(char* id, int idxLT, IDDATATYPE datatype, IDTYPE idtype) // ����������� � �����������
        {
            strncpy_s(this->id, id, SCOPED_ID_MAXSIZE - 1);
            this->idxfirstLE = idxLT;
            this->iddatatype = datatype;
            this->idtype = idtype;
        };
    };

    struct IdTable		// ��������� ������� ���������������
    {
        int maxsize;	// ������� ������� ��������������� < TI_MAXSIZE
        int size;		// ������� ������ ������� ��������������� < maxsize
        Entry* table;	// ������ ����� ������� ���������������
    };
    IdTable Create(int size = NULL);	// ������� ������� ��������������� < TI_MAXSIZE
    void Add(					// �������� ������ � ������� ���������������
        IdTable& idtable,		// ��������� ������� ���������������
        Entry entry);			// ������ ������� ��������������� 
    int isId(					// �������: ����� ������(���� ����), TI_NULLIDX(���� ����)
        IdTable& idtable,		// ��������� ������� ���������������
        char id[SCOPED_ID_MAXSIZE]);	// �������������
    bool SetValue(IT::Entry* entry, char* value);	// ������ �������� ��������������
    bool SetValue(IT::IdTable& idtable, int index, char* value);
    void writeIdTable(std::ostream* stream, IT::IdTable& idtable); // ������� ������� ���������������
};