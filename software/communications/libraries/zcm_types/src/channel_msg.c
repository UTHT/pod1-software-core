// THIS IS AN AUTOMATICALLY GENERATED FILE.
// DO NOT MODIFY BY HAND!!
//
// Generated by zcm-gen

#include <string.h>
#ifndef ZCM_EMBEDDED
#include <stdio.h>
#endif
#include "channel_msg.h"

static int __channel_msg_hash_computed = 0;
static uint64_t __channel_msg_hash;

uint64_t __channel_msg_hash_recursive(const __zcm_hash_ptr* p)
{
    const __zcm_hash_ptr* fp;
    for (fp = p; fp != NULL; fp = fp->parent)
        if (fp->v == __channel_msg_get_hash)
            return 0;

    __zcm_hash_ptr cp;
    cp.parent =  p;
    cp.v = (void*)__channel_msg_get_hash;
    (void) cp;

    uint64_t hash = (uint64_t)0xa8e268eca1489254LL
         + __int8_t_hash_recursive(&cp)
         + __int8_t_hash_recursive(&cp)
         + __double_hash_recursive(&cp)
        ;

    return (hash<<1) + ((hash>>63)&1);
}

int64_t __channel_msg_get_hash(void)
{
    if (!__channel_msg_hash_computed) {
        __channel_msg_hash = (int64_t)__channel_msg_hash_recursive(NULL);
        __channel_msg_hash_computed = 1;
    }

    return __channel_msg_hash;
}

int __channel_msg_encode_array(void* buf, uint32_t offset, uint32_t maxlen, const channel_msg* p, uint32_t elements)
{
    uint32_t pos = 0, element;
    int thislen;

    for (element = 0; element < elements; ++element) {

        thislen = __int8_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].arduino_id), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int8_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].sensor_id), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __double_encode_array(buf, offset + pos, maxlen - pos, &(p[element].sensor_value), 1);
        if (thislen < 0) return thislen; else pos += thislen;

    }
    return pos;
}

int channel_msg_encode(void* buf, uint32_t offset, uint32_t maxlen, const channel_msg* p)
{
    uint32_t pos = 0;
    int thislen;
    int64_t hash = __channel_msg_get_hash();

    thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    thislen = __channel_msg_encode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

uint32_t __channel_msg_encoded_array_size(const channel_msg* p, uint32_t elements)
{
    uint32_t size = 0, element;
    for (element = 0; element < elements; ++element) {

        size += __int8_t_encoded_array_size(&(p[element].arduino_id), 1);

        size += __int8_t_encoded_array_size(&(p[element].sensor_id), 1);

        size += __double_encoded_array_size(&(p[element].sensor_value), 1);

    }
    return size;
}

uint32_t channel_msg_encoded_size(const channel_msg* p)
{
    return 8 + __channel_msg_encoded_array_size(p, 1);
}

int __channel_msg_decode_array(const void* buf, uint32_t offset, uint32_t maxlen, channel_msg* p, uint32_t elements)
{
    uint32_t pos = 0, element;
    int thislen;

    for (element = 0; element < elements; ++element) {

        thislen = __int8_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].arduino_id), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int8_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].sensor_id), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __double_decode_array(buf, offset + pos, maxlen - pos, &(p[element].sensor_value), 1);
        if (thislen < 0) return thislen; else pos += thislen;

    }
    return pos;
}

int __channel_msg_decode_array_cleanup(channel_msg* p, uint32_t elements)
{
    uint32_t element;
    for (element = 0; element < elements; ++element) {

        __int8_t_decode_array_cleanup(&(p[element].arduino_id), 1);

        __int8_t_decode_array_cleanup(&(p[element].sensor_id), 1);

        __double_decode_array_cleanup(&(p[element].sensor_value), 1);

    }
    return 0;
}

int channel_msg_decode(const void* buf, uint32_t offset, uint32_t maxlen, channel_msg* p)
{
    uint32_t pos = 0;
    int thislen;
    int64_t hash = __channel_msg_get_hash();

    int64_t this_hash;
    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &this_hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (this_hash != hash) return -1;

    thislen = __channel_msg_decode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int channel_msg_decode_cleanup(channel_msg* p)
{
    return __channel_msg_decode_array_cleanup(p, 1);
}

uint32_t __channel_msg_clone_array(const channel_msg* p, channel_msg* q, uint32_t elements)
{
    uint32_t n = 0, element;
    for (element = 0; element < elements; ++element) {

        n += __int8_t_clone_array(&(p[element].arduino_id), &(q[element].arduino_id), 1);

        n += __int8_t_clone_array(&(p[element].sensor_id), &(q[element].sensor_id), 1);

        n += __double_clone_array(&(p[element].sensor_value), &(q[element].sensor_value), 1);

    }
    return n;
}

channel_msg* channel_msg_copy(const channel_msg* p)
{
    channel_msg* q = (channel_msg*) malloc(sizeof(channel_msg));
    __channel_msg_clone_array(p, q, 1);
    return q;
}

void channel_msg_destroy(channel_msg* p)
{
    __channel_msg_decode_array_cleanup(p, 1);
    free(p);
}

int channel_msg_publish(zcm_t* zcm, const char* channel, const channel_msg* p)
{
      uint32_t max_data_size = channel_msg_encoded_size (p);
      uint8_t* buf = (uint8_t*) malloc (max_data_size);
      if (!buf) return -1;
      int data_size = channel_msg_encode (buf, 0, max_data_size, p);
      if (data_size < 0) {
          free (buf);
          return data_size;
      }
      int status = zcm_publish (zcm, channel, buf, (uint32_t)data_size);
      free (buf);
      return status;
}

struct _channel_msg_subscription_t {
    channel_msg_handler_t user_handler;
    void* userdata;
    zcm_sub_t* z_sub;
};
static
void channel_msg_handler_stub (const zcm_recv_buf_t* rbuf,
                            const char* channel, void* userdata)
{
    int status;
    channel_msg p;
    memset(&p, 0, sizeof(channel_msg));
    status = channel_msg_decode (rbuf->data, 0, rbuf->data_size, &p);
    if (status < 0) {
        #ifndef ZCM_EMBEDDED
        fprintf (stderr, "error %d decoding channel_msg!!!\n", status);
        #endif
        return;
    }

    channel_msg_subscription_t* h = (channel_msg_subscription_t*) userdata;
    h->user_handler (rbuf, channel, &p, h->userdata);

    channel_msg_decode_cleanup (&p);
}

channel_msg_subscription_t* channel_msg_subscribe (zcm_t* zcm,
                    const char* channel,
                    channel_msg_handler_t f, void* userdata)
{
    channel_msg_subscription_t* n = (channel_msg_subscription_t*)
                       malloc(sizeof(channel_msg_subscription_t));
    n->user_handler = f;
    n->userdata = userdata;
    n->z_sub = zcm_subscribe (zcm, channel,
                              channel_msg_handler_stub, n);
    if (n->z_sub == NULL) {
        #ifndef ZCM_EMBEDDED
        fprintf (stderr,"couldn't reg channel_msg ZCM handler!\n");
        #endif
        free (n);
        return NULL;
    }
    return n;
}

int channel_msg_unsubscribe(zcm_t* zcm, channel_msg_subscription_t* hid)
{
    int status = zcm_unsubscribe (zcm, hid->z_sub);
    if (0 != status) {
        #ifndef ZCM_EMBEDDED
        fprintf(stderr,
           "couldn't unsubscribe channel_msg_handler %p!\n", hid);
        #endif
        return -1;
    }
    free (hid);
    return 0;
}
