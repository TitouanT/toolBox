#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sha256.h"

#define H_SIZE 32

void gethash (BYTE * hash) {
	char * password = getpass("password: ");
	char * confirm = malloc((1 + strlen(password)) * sizeof(char));
	strcpy(confirm, password);
	password = getpass("confirm: ");


	if (strcmp(password, confirm) != 0) {
		printf("The passwords doesn't match\n");
		free(confirm);
		exit(0);
	}

	SHA256_CTX ctx;
	sha256_init(&ctx);
	sha256_compute(&ctx, (BYTE*)password, strlen(password));
	sha256_convert(&ctx, hash);

	int i;
	for (i = 0; i < strlen(password); i++) confirm[i] = password[i] = 1;
	free(confirm);
}

void modhash (BYTE*hash, int size) {
	BYTE mod = hash[size - 1];
	int i;
	for (i = size - 1; i > 0; i--) {
		hash[i] = hash[i-1] ^ mod;
	}
	hash[0] = mod;
}

int main (int argc, char ** argv) {

	if (argc != 2) {
		printf ("usage: %s <src>\n", argv[0]);
		exit(0);
	}
	char * srcName = argv[1];
	char * dstName = "tmp.bin";

	FILE * src = fopen(srcName, "rb");
	if (src == NULL) {
		printf("can not open file %s\n", srcName);
		exit(0);
	}
	FILE * dst = fopen(dstName, "wb");



	BYTE hash[H_SIZE];
	gethash(hash);

	char dataw, datar;
	fread(&dataw, sizeof(char), 1, src);
	int counter = 0;

	while (!feof(src)) {
		datar = dataw ^ hash[counter];
		fwrite(&datar, sizeof(char), 1, dst);
		fread(&dataw, sizeof(char), 1, src);
		counter++;
		if (counter == H_SIZE) {
			counter = 0;
			modhash(hash, H_SIZE);
		}
	}
	fclose(src);
	fclose(dst);

	src = fopen(dstName, "rb");
	dst = fopen(srcName, "wb");

	char data;

	fread(&data, sizeof(char), 1, src);
	while (!feof(src)) {
		fwrite(&data, sizeof(char), 1, dst);
		fread(&data, sizeof(char), 1, src);
	}

	fclose(src);
	fclose(dst);

	remove(dstName);

	return 0;
}
