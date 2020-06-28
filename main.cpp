#include <cstdio>
#include "AES.h"

int main()
{
    byte key[] = { 0x6E, 0x66, 0xAE, 0x0B,
        0xE7, 0x29, 0x41, 0xEB,
        0xA6, 0x53, 0x10, 0x21,
        0x13, 0x76, 0x08, 0x2E
    };

    char src[] = "my test";
    printf("data before encryption. len = [%u]:\n", strlen(src));
    for (UINT i = 0; i < strlen(src); i++)
    {
        printf("0x%02X ", src[i]);
    }
    printf("\n\n");

    void* dst = 0;
    CAES aes(key);
    const UINT dst_len = aes.Encrypt(reinterpret_cast<void*>(src), sizeof(src), dst, 0);
    printf("encrypted data. len = [%u]:\n", dst_len);
    for (UINT i = 0; i < dst_len; i++)
    {
        printf("0x%02X ", reinterpret_cast<BYTE*>(dst)[i]);
    }
    printf("\n\n");

    aes.Decrypt(dst, dst_len);
    printf("decrypted data:\n");
    for (UINT i = 0; i < dst_len; i++)
    {
        printf("0x%02X ", reinterpret_cast<BYTE*>(dst)[i]);
    }
    printf("\n\n");

    delete[] dst;

    return 0;
}
