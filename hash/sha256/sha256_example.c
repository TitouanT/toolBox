#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <unistd.h>
#include "sha256.h"

void print_hash(unsigned char hash[])
{
	int idx;
	for (idx=0; idx < 32; idx++)
		printf("%02x",hash[idx]);
	printf("\n");
}

int main(int argc, char ** argv)
{
	BYTE hash[32], *msg = (BYTE *) getpass("msg to hash: ");
	// unsigned char hash[32], *msg = argv[argc - 1];
	SHA256_CTX ctx;

	// Hash one
	sha256_init(&ctx);
	sha256_compute(&ctx,msg,strlen((char *)msg));
	sha256_convert(&ctx,hash);
	print_hash(hash);

	return 0;
}
