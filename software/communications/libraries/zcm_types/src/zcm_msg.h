// THIS IS AN AUTOMATICALLY GENERATED FILE.
// DO NOT MODIFY BY HAND!!
//
// Generated by zcm-gen

#include <stdint.h>
#include <stdlib.h>
#include <zcm_coretypes.h>
#include <zcm.h>
c
#ifndef _zcm_msg_h
#define _zcm_msg_h

#ifdef __cplusplus
extern "C" {
#endif

#define ZCM_MSG_IS_LITTLE_ENDIAN 0
typedef struct _zcm_msg zcm_msg;
struct _zcm_msg
{
    int8_t     arduino_id;
    int8_t     sensor_id;
    double     sensor_value;
};

/**
 * Create a deep copy of a zcm_msg.
 * When no longer needed, destroy it with zcm_msg_destroy()
 */
zcm_msg* zcm_msg_copy(const zcm_msg* to_copy);

/**
 * Destroy an instance of zcm_msg created by zcm_msg_copy()
 */
void zcm_msg_destroy(zcm_msg* to_destroy);

/**
 * Identifies a single subscription.  This is an opaque data type.
 */
typedef struct _zcm_msg_subscription_t zcm_msg_subscription_t;

/**
 * Prototype for a callback function invoked when a message of type
 * zcm_msg is received.
 */
typedef void(*zcm_msg_handler_t)(const zcm_recv_buf_t* rbuf,
             const char* channel, const zcm_msg* msg, void* userdata);

/**
 * Publish a message of type zcm_msg using ZCM.
 *
 * @param zcm The ZCM instance to publish with.
 * @param channel The channel to publish on.
 * @param msg The message to publish.
 * @return 0 on success, <0 on error.  Success means ZCM has transferred
 * responsibility of the message data to the OS.
 */
int zcm_msg_publish(zcm_t* zcm, const char* channel, const zcm_msg* msg);

/**
 * Subscribe to messages of type zcm_msg using ZCM.
 *
 * @param zcm The ZCM instance to subscribe with.
 * @param channel The channel to subscribe to.
 * @param handler The callback function invoked by ZCM when a message is received.
 *                This function is invoked by ZCM during calls to zcm_handle() and
 *                zcm_handle_timeout().
 * @param userdata An opaque pointer passed to @p handler when it is invoked.
 * @return pointer to subscription type, NULL if failure. Must clean up
 *         dynamic memory by passing the pointer to zcm_msg_unsubscribe.
 */
zcm_msg_subscription_t* zcm_msg_subscribe(zcm_t* zcm, const char* channel, zcm_msg_handler_t handler, void* userdata);

/**
 * Removes and destroys a subscription created by zcm_msg_subscribe()
 */
int zcm_msg_unsubscribe(zcm_t* zcm, zcm_msg_subscription_t* hid);
/**
 * Encode a message of type zcm_msg into binary form.
 *
 * @param buf The output buffer.
 * @param offset Encoding starts at this byte offset into @p buf.
 * @param maxlen Maximum number of bytes to write.  This should generally
 *               be equal to zcm_msg_encoded_size().
 * @param msg The message to encode.
 * @return The number of bytes encoded, or <0 if an error occured.
 */
int zcm_msg_encode(void* buf, uint32_t offset, uint32_t maxlen, const zcm_msg* p);

/**
 * Decode a message of type zcm_msg from binary form.
 * When decoding messages containing strings or variable-length arrays, this
 * function may allocate memory.  When finished with the decoded message,
 * release allocated resources with zcm_msg_decode_cleanup().
 *
 * @param buf The buffer containing the encoded message
 * @param offset The byte offset into @p buf where the encoded message starts.
 * @param maxlen The maximum number of bytes to read while decoding.
 * @param msg Output parameter where the decoded message is stored
 * @return The number of bytes decoded, or <0 if an error occured.
 */
int zcm_msg_decode(const void* buf, uint32_t offset, uint32_t maxlen, zcm_msg* msg);

/**
 * Release resources allocated by zcm_msg_decode()
 * @return 0
 */
int zcm_msg_decode_cleanup(zcm_msg* p);

/**
 * Check how many bytes are required to encode a message of type zcm_msg
 */
uint32_t zcm_msg_encoded_size(const zcm_msg* p);

// ZCM support functions. Users should not call these
int64_t  __zcm_msg_get_hash(void);
uint64_t __zcm_msg_hash_recursive(const __zcm_hash_ptr* p);
int      __zcm_msg_encode_array(void* buf, uint32_t offset, uint32_t maxlen, const zcm_msg* p, uint32_t elements);
int      __zcm_msg_decode_array(const void* buf, uint32_t offset, uint32_t maxlen, zcm_msg* p, uint32_t elements);
int      __zcm_msg_decode_array_cleanup(zcm_msg* p, uint32_t elements);
uint32_t __zcm_msg_encoded_array_size(const zcm_msg* p, uint32_t elements);
uint32_t __zcm_msg_clone_array(const zcm_msg* p, zcm_msg* q, uint32_t elements);

#ifdef __cplusplus
}
#endif

#endif
