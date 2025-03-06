#ifndef CONVERSATION_H
#define CONVERSATION_H

#include "common.h"

void send_message(const char *sender, const char *receiver, const char *message);
void list_messages(const char *receiver);

#endif // CONVERSATION_H
