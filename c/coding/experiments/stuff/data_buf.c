#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/*
 * gcc -ggdb -o data_buf data_buf.c
 * valgrind ./data_buf
 */

static struct message {
	uint8_t size;
	uint8_t *data;
} message = {
	15,
	NULL
};

static uint8_t message_size(struct message *msg)
{
	if (msg == NULL) 
		return 0;

	return msg->size;
}

static uint8_t *message_encode(struct message *msg)
{
	if (msg == NULL) 
		return NULL;

	if (msg->data == NULL) 
		msg->data = malloc(sizeof(msg->size));

	*(uint8_t*)msg->data = msg->size;

	return msg->data;
}

static struct message* message_decode(struct message* message_decode, uint8_t *message_encode)
{
	message_decode->size = *(uint8_t*)message_encode;
	message_decode->data = message_encode;

	return message_decode;
}

static void message_free(struct message *msg)
{
	if (msg != NULL && msg->data != NULL) 
		free(msg->data);
}

int main()
{
	uint8_t *msg_enc = message_encode(&message);
	struct message msg_dec;
	memset(&msg_dec, 0, sizeof(struct message));

	message_decode(&msg_dec, msg_enc);
	printf("taille_size=%d\n", msg_dec.size);
	printf("taille_data=%d\n", *(uint8_t*)msg_enc);

	message_free(&msg_dec);

	return 0;
}
