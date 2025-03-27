#include <unistd.h>

static void print_hex(unsigned char c)
{
    char *hex;
    
    hex = "0123456789abcdef";
    write(1, &hex[c >> 4], 1);
    write(1, &hex[c & 0xF], 1);
}

static void print_address(void *addr)
{
    unsigned long address = (unsigned long)addr;
    char hex_addr[16];
    int i;

    for (i = 15; i >= 0; i--)
    {
        hex_addr[i] = "0123456789abcdef"[address % 16];
        address /= 16;
    }
    write(1, hex_addr, 16);
    write(1, ": ", 2);
}

static void print_memory_line(unsigned char *p, unsigned int len)
{
    unsigned int i;

    // Imprimir valores en hexadecimal
    for (i = 0; i < 16; i++)
    {
        if (i < len)
            print_hex(p[i]);
        else
            write(1, "  ", 2);
        if (i % 2) // Espacio extra cada 2 bytes
            write(1, " ", 1);
    }

    // Imprimir valores en ASCII
    for (i = 0; i < len; i++)
    {
        if (p[i] >= 32 && p[i] <= 126) // Caracteres imprimibles
            write(1, &p[i], 1);
        else
            write(1, ".", 1);
    }
    write(1, "\n", 1);
}

void *ft_print_memory(void *addr, unsigned int size)
{
    unsigned int i;
    unsigned char *p = (unsigned char *)addr;

    for (i = 0; i < size; i += 16)
    {
        print_address(p + i);
        if (size - i < 16)
            print_memory_line(p + i, size - i);
        print_memory_line(p + i, 16);
    }
    return addr;
}
