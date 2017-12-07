#include <stdlib.h>

void check_magic_number(void)
{
    short tmp = (short)(0x1234 << 8);
    char c = ((char *)&tmp)[0];
    int i = 0 << (int)c;
}

/*@ requires INT_MIN < x <= INT_MAX; */
int absolute_int(int x)
{
    int abs_x;
    if (x < 0)
        abs_x = -x;
    else
        abs_x = x;
    return abs_x;
}

char *encrypt(char *str, int len, int d)
{
    int shift = absolute_int(d);
    int i = 0;
    char *buf = (char *)malloc(len);

    if (buf) {
        while (*str) {
            /* Spaces are not encrypted. */
            buf[i] = *str == ' ' ? ' ' : *str + (char)shift;
            i++;
            str++;
        }
        buf[i] = '\0';
    }
    return buf;
}

char *decrypt(char *str, int len, int d)
{
    int shift = absolute_int(d);
    int i = 0;
    char *buf = (char *)malloc(len);

    if (buf) {
        while (*str) {
            /* Spaces are not decrypted. */
            buf[i] = *str == ' ' ? ' ' : *str - (char)shift;
            i++;
            str++;
        }
        buf[i] = '\0';
    }
    return buf;
}
