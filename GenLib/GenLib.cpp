#include <iostream>

extern "C"
{
    int __stdcall lenght(char* buffer, char* str)					// вычисление длины строки
    {
        if (str == nullptr)
            return 0;
        int len = 0;
        for (int i = 0; i < 256; i++)
            if (str[i] == '\0')
            {
                len = i; break;
            }
        return len;
    }


    int __stdcall strcmpp(char* buffer, char* first, char* last)					// преобразование символьного литерала
    {
        while (true) {
            if (*first != *last) {
                return 0;
            }
            first++;
            last++;
            if (*first == '\0' && *last == '\0') {
                break;
            }
        }


        return 1;
    }


    char* __stdcall strcopy(char* buffer, char* str)				// копирование строк
    {
        int i = NULL, len1 = NULL, len2 = NULL;
        for (int j = 0; str[j] != '\0'; j++)
        {
            if (i == 255)
                break;
            buffer[i++] = str[j];
        }
        buffer[i] = '\0';
        return buffer;
    }


    int __stdcall outnum(int value)									// вывод в консоль целочисленного литерала
    {
        std::cout << value;
        return 0;
    }


    int __stdcall outstr(char* ptr)									// вывод в консоль строкового литерала
    {
        if (ptr == nullptr)
            std::cout << std::endl;
        for (int i = 0; ptr[i] != '\0'; i++)
            std::cout << ptr[i];
        return 0;
    }
}