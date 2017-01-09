#include "inc.h"

void    print_bits(unsigned char octet);

unsigned char	swap_bits(unsigned char octet)
{
	return (octet >> 4 | octet << 4);
}

int 			main(void)
{
	unsigned char a = 65;
	print_bits(swap_bits(a));
}
