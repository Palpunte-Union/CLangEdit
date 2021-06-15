#include "ProcessBuilder.h"

int main(int argc, char *argv[])
{
	printf("Debug[%d] start\n", GetCurrentProcessId());

	LPTSTR commandLine = (LPTSTR)argv[1];

	int r = execute(commandLine);

	if (childProcess != NULL) {
		if(!CloseHandle(childProcess)) {
			printError("CloseHandle(childProcess)");
		}
	}

	printf("Debug[%d] end\n", GetCurrentProcessId());
    system("pause");
	return r;
}