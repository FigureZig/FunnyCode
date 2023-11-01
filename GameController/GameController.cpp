#include <iostream>
#include "KernelInterface.hpp"

int main()
{
	KernelInterface Driver = KernelInterface("\\\\.\\Sample");

	ULONG address = Driver.GetClientAddress();

	std::cout << "Current address of HL2: " << address << std::endl;

	while (1)
	{

	}
}