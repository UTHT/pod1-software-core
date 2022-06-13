// THIS IS AN AUTOMATICALLY GENERATED FILE.
// DO NOT MODIFY BY HAND!!
//
// Generated by zcm-gen

#include <string.h>
#ifndef ZCM_EMBEDDED
#include <stdio.h>
#endif
#include "channel_array_msg.h"

static int __channel_array_hash_computed = 0;
static uint64_t __channel_array_hash;

uint64_t __channel_array_hash_recursive(const __zcm_hash_ptr* p)
{
    const __zcm_hash_ptr* fp;
    for (fp = p; fp != NULL; fp = fp->parent)
        if (fp->v == __channel_array_get_hash)
            return 0;

    __zcm_hash_ptr cp;
    cp.parent =  p;
    cp.v = (void*)__channel_array_get_hash;
    (void) cp;

    uint64_t hash = (uint64_t)0x7cfe058cc15c527fLL
         + __int8_t_hash_recursive(&cp)
         + __string_hash_recursive(&cp)
         + __int64_t_hash_recursive(&cp)
         + __double_hash_recursive(&cp)
         + __string_hash_recursive(&cp)
         + __string_hash_recursive(&cp)
        ;

    return (hash<<1) + ((hash>>63)&1);
}

int64_t __channel_array_get_hash(void)
{
    if (!__channel_array_hash_computed) {
        __channel_array_hash = (int64_t)__channel_array_hash_recursive(NULL);
        __channel_array_hash_computed = 1;
    }

    return __channel_array_hash;
}

int __channel_array_encode_array(void* buf, uint32_t offset, uint32_t maxlen, const channel_array* p, uint32_t elements)
{
    uint32_t pos_byte = 0, element;
    int thislen;

    for (element = 0; element < elements; ++element) {

        /* arduino_id */
        thislen = __int8_t_encode_array(buf, offset + pos_byte, maxlen - pos_byte, &(p[element].arduino_id), 1);
        if (thislen < 0) return thislen; else pos_byte += thislen;

        /* sensor */
        thislen = __string_encode_array(buf, offset + pos_byte, maxlen - pos_byte, &(p[element].sensor), 1);
        if (thislen < 0) return thislen; else pos_byte += thislen;

        /* sz */
        thislen = __int64_t_encode_array(buf, offset + pos_byte, maxlen - pos_byte, &(p[element].sz), 1);
        if (thislen < 0) return thislen; else pos_byte += thislen;

        /* data */
        thislen = __double_encode_array(buf, offset + pos_byte, maxlen - pos_byte, p[element].data, p[element].sz);
        if (thislen < 0) return thislen; else pos_byte += thislen;

        /* units */
        thislen = __string_encode_array(buf, offset + pos_byte, maxlen - pos_byte, &(p[element].units), 1);
        if (thislen < 0) return thislen; else pos_byte += thislen;

        /* statusMsg */
        thislen = __string_encode_array(buf, offset + pos_byte, maxlen - pos_byte, &(p[element].statusMsg), 1);
        if (thislen < 0) return thislen; else pos_byte += thislen;

    }
    return pos_byte;
}

int channel_array_encode(void* buf, uint32_t offset, uint32_t maxlen, const channel_array* p)
{
    uint32_t pos = 0;
    int thislen;
    int64_t hash = __channel_array_get_hash();

    thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    thislen = __channel_array_encode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

uint32_t __channel_array_encoded_array_size(const channel_array* p, uint32_t elements)
{
    uint32_t size = 0, element;
    for (element = 0; element < elements; ++element) {

        size += __int8_t_encoded_array_size(&(p[element].arduino_id), 1); // arduino_id

        size += __string_encoded_array_size(&(p[element].sensor), 1); // sensor

        size += __int64_t_encoded_array_size(&(p[element].sz), 1); // sz

        size += __double_encoded_array_size(p[element].data, p[element].sz); // data

        size += __string_encoded_array_size(&(p[element].units), 1); // units

        size += __string_encoded_array_size(&(p[element].statusMsg), 1); // statusMsg

    }
    return size;
}

uint32_t channel_array_encoded_size(const channel_array* p)
{
    return 8 + __channel_array_encoded_array_size(p, 1);
}

int __channel_array_decode_array(const void* buf, uint32_t offset, uint32_t maxlen, channel_array* p, uint32_t elements)
{
    uint32_t pos_byte = 0, element;
    int thislen;

    for (element = 0; element < elements; ++element) {

        /* arduino_id */
        thislen = __int8_t_decode_array(buf, offset + pos_byte, maxlen - pos_byte, &(p[element].arduino_id), 1);
        if (thislen < 0) return thislen; else pos_byte += thislen;

        /* sensor */
        thislen = __string_decode_array(buf, offset + pos_byte, maxlen - pos_byte, &(p[element].sensor), 1);
        if (thislen < 0) return thislen; else pos_byte += thislen;

        /* sz */
        thislen = __int64_t_decode_array(buf, offset + pos_byte, maxlen - pos_byte, &(p[element].sz), 1);
        if (thislen < 0) return thislen; else pos_byte += thislen;

        /* data */
        p[element].data = (double*) zcm_malloc(sizeof(double) * p[element].sz);
        thislen = __double_decode_array(buf, offset + pos_byte, maxlen - pos_byte, p[element].data, p[element].sz);
        if (thislen < 0) return thislen; else pos_byte += thislen;

        /* units */
        thislen = __string_decode_array(buf, offset + pos_byte, maxlen - pos_byte, &(p[element].units), 1);
        if (thislen < 0) return thislen; else pos_byte += thislen;

        /* statusMsg */
        thislen = __string_decode_array(buf, offset + pos_byte, maxlen - pos_byte, &(p[element].statusMsg), 1);
        if (thislen < 0) return thislen; else pos_byte += thislen;

    }
    return pos_byte;
}

int __channel_array_decode_array_cleanup(channel_array* p, uint32_t elements)
{
    uint32_t element;
    for (element = 0; element < elements; ++element) {

        __int8_t_decode_array_cleanup(&(p[element].arduino_id), 1);

        __string_decode_array_cleanup(&(p[element].sensor), 1);

        __int64_t_decode_array_cleanup(&(p[element].sz), 1);

        __double_decode_array_cleanup(p[element].data, p[element].sz);
        if (p[element].data) free(p[element].data);

        __string_decode_array_cleanup(&(p[element].units), 1);

        __string_decode_array_cleanup(&(p[element].statusMsg), 1);

    }
    return 0;
}

int channel_array_decode(const void* buf, uint32_t offset, uint32_t maxlen, channel_array* p)
{
    uint32_t pos = 0;
    int thislen;
    int64_t hash = __channel_array_get_hash();

    int64_t this_hash;
    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &this_hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (this_hash != hash) return -1;

    thislen = __channel_array_decode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int channel_array_decode_cleanup(channel_array* p)
{
    return __channel_array_decode_array_cleanup(p, 1);
}

uint32_t __channel_array_clone_array(const channel_array* p, channel_array* q, uint32_t elements)
{
    uint32_t n = 0, element;
    for (element = 0; element < elements; ++element) {

        n += __int8_t_clone_array(&(p[element].arduino_id), &(q[element].arduino_id), 1);

        n += __string_clone_array(&(p[element].sensor), &(q[element].sensor), 1);

        n += __int64_t_clone_array(&(p[element].sz), &(q[element].sz), 1);

        q[element].data = (double*) zcm_malloc(sizeof(double) * q[element].sz);
        n += __double_clone_array(p[element].data, q[element].data, p[element].sz);

        n += __string_clone_array(&(p[element].units), &(q[element].units), 1);

        n += __string_clone_array(&(p[element].statusMsg), &(q[element].statusMsg), 1);

    }
    return n;
}

channel_array* channel_array_copy(const channel_array* p)
{
    channel_array* q = (channel_array*) malloc(sizeof(channel_array));
    __channel_array_clone_array(p, q, 1);
    return q;
}

void channel_array_destroy(channel_array* p)
{
    __channel_array_decode_array_cleanup(p, 1);
    free(p);
}

int channel_array_publish(zcm_t* zcm, const char* channel, const channel_array* p)
{
      uint32_t max_data_size = channel_array_encoded_size (p);
      uint8_t* buf = (uint8_t*) malloc (max_data_size);
      if (!buf) return -1;
      int data_size = channel_array_encode (buf, 0, max_data_size, p);
      if (data_size < 0) {
          free (buf);
          return data_size;
      }
      int status = zcm_publish (zcm, channel, buf, (uint32_t)data_size);
      free (buf);
      return status;
}

struct _channel_array_subscription_t {
    channel_array_handler_t user_handler;
    void* userdata;
    zcm_sub_t* z_sub;
};
static
void channel_array_handler_stub (const zcm_recv_buf_t* rbuf,
                            const char* channel, void* userdata)
{
    int status;
    channel_array p;
    memset(&p, 0, sizeof(channel_array));
    status = channel_array_decode (rbuf->data, 0, rbuf->data_size, &p);
    if (status < 0) {
        #ifndef ZCM_EMBEDDED
        fprintf (stderr, "error %d decoding channel_array!!!\n", status);
        #endif
        return;
    }

    channel_array_subscription_t* h = (channel_array_subscription_t*) userdata;
    h->user_handler (rbuf, channel, &p, h->userdata);

    channel_array_decode_cleanup (&p);
}

channel_array_subscription_t* channel_array_subscribe (zcm_t* zcm,
                    const char* channel,
                    channel_array_handler_t f, void* userdata)
{
    channel_array_subscription_t* n = (channel_array_subscription_t*)
                       malloc(sizeof(channel_array_subscription_t));
    n->user_handler = f;
    n->userdata = userdata;
    n->z_sub = zcm_subscribe (zcm, channel,
                              channel_array_handler_stub, n);
    if (n->z_sub == NULL) {
        #ifndef ZCM_EMBEDDED
        fprintf (stderr,"couldn't reg channel_array ZCM handler!\n");
        #endif
        free (n);
        return NULL;
    }
    return n;
}

int channel_array_unsubscribe(zcm_t* zcm, channel_array_subscription_t* hid)
{
    int status = zcm_unsubscribe (zcm, hid->z_sub);
    if (0 != status) {
        #ifndef ZCM_EMBEDDED
        fprintf(stderr,
           "couldn't unsubscribe channel_array_handler %p!\n", hid);
        #endif
        return -1;
    }
    free (hid);
    return 0;
}
