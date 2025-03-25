#include "exam_rank02.h"

#include <unistd.h>

void *ft_print_memory(void *addr, unsigned int size)
{
    if (size == 0)
        return (addr);
    unsigned char   *p = addr;
    unsigned int    o = 0;
    while (o < size)
    {
        int len = (size - o < 16) ? size - o : 16;
        unsigned long a = (unsigned long)(p + o);
        char ha[16];
        for (int i = 0; i < 8; i++)
        {
            unsigned char byte = ((unsigned char *)&a)[7 - i];
            ha[2*i] = "0123456789abcdef"[byte >> 4];
            ha[2*i+1] = "0123456789abcdef"[byte & 0xF];
        }
        write(1, ha, 16);
        write(1, ": ", 2);
        for (int g = 0; g < 8; g++)
        {
            int pos = g * 2;
            if (pos >= len)
                write(1, "    ", 4);
            else
            {
                write(1, &"0123456789abcdef"[p[o+pos] >> 4], 1);
                write(1, &"0123456789abcdef"[p[o+pos] & 0xF], 1);
                if (pos + 1 < len)
                {
                    write(1, &"0123456789abcdef"[p[o+pos+1] >> 4], 1);
                    write(1, &"0123456789abcdef"[p[o+pos+1] & 0xF], 1);
                } else write(1, "  ", 2);
            }
            if (g < 7) write(1, " ", 1);
        }
        write(1, " ", 1);
        for (int i = 0; i < 16; i++)
        {
            unsigned char c = (i < len) ? p[o+i] : 0;
            if (i < len && c >= 32 && c <= 126) write(1, &c, 1);
            else write(1, ".", 1);
        }
        write(1, "\n", 1);
        o += 16;
    }
    return addr;
}