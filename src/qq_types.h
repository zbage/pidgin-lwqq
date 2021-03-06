#ifndef QQ_TYPES_H_H
#define QQ_TYPES_H_H
typedef struct _AsyncListener AsyncListener;

#include <type.h>
#include <connection.h>
#define QQ_MAGIC 0x4153
typedef struct qq_account {
    LwqqClient* qq;
    PurpleAccount* account;
    PurpleConnection* gc;
    int disable_send_server;///< this ensure not send buddy category change etc event to server
    enum {
        DISCONNECT,
        CONNECTED,
        LOAD_COMPLETED
    }state;
    GPtrArray* opend_chat;
    int magic;//0x4153
} qq_account;
qq_account* qq_account_new(PurpleAccount* account);
void qq_account_free(qq_account* ac);
int open_new_chat(qq_account* ac,LwqqGroup* group);
#define opend_chat_search(ac,group) open_new_chat(ac,group)
#define opend_chat_index(ac,id) g_ptr_array_index(ac->opend_chat,id)




//void qq_msg_check(qq_account* ac);
//void qq_set_basic_info(int result,void* data);
#endif
