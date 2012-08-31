
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from HelloWorldAsyncRequestReply.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Connext distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Connext manual.
*/


#include <string.h>

#ifdef __cplusplus
#ifndef ndds_cpp_h
  #include "ndds/ndds_cpp.h"
#endif
#else
#ifndef ndds_c_h
  #include "ndds/ndds_c.h"
#endif
#endif

#ifndef osapi_type_h
  #include "osapi/osapi_type.h"
#endif
#ifndef osapi_heap_h
  #include "osapi/osapi_heap.h"
#endif

#ifndef osapi_utility_h
  #include "osapi/osapi_utility.h"
#endif

#ifndef cdr_type_h
  #include "cdr/cdr_type.h"
#endif

#ifndef cdr_encapsulation_h
  #include "cdr/cdr_encapsulation.h"
#endif

#ifndef cdr_stream_h
  #include "cdr/cdr_stream.h"
#endif

#ifndef pres_typePlugin_h
  #include "pres/pres_typePlugin.h"
#endif



#include "HelloWorldAsyncRequestReplyPlugin.h"


/* --------------------------------------------------------------------------------------
 *  Type sumaRequest
 * -------------------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

sumaRequest *
sumaRequestPluginSupport_create_data_ex(RTIBool allocate_pointers){
    sumaRequest *sample = NULL;

    RTIOsapiHeap_allocateStructure(
        &sample, sumaRequest);

    if(sample != NULL) {
        if (!sumaRequest_initialize_ex(sample,allocate_pointers)) {
            RTIOsapiHeap_freeStructure(&sample);
            return NULL;
        }
    }
    return sample; 
}


sumaRequest *
sumaRequestPluginSupport_create_data(void)
{
    return sumaRequestPluginSupport_create_data_ex(RTI_TRUE);
}


void 
sumaRequestPluginSupport_destroy_data_ex(
    sumaRequest *sample,RTIBool deallocate_pointers) {

    sumaRequest_finalize_ex(sample,deallocate_pointers);

    RTIOsapiHeap_freeStructure(sample);
}


void 
sumaRequestPluginSupport_destroy_data(
    sumaRequest *sample) {

    sumaRequestPluginSupport_destroy_data_ex(sample,RTI_TRUE);

}


RTIBool 
sumaRequestPluginSupport_copy_data(
    sumaRequest *dst,
    const sumaRequest *src)
{
    return sumaRequest_copy(dst,src);
}


void 
sumaRequestPluginSupport_print_data(
    const sumaRequest *sample,
    const char *desc,
    unsigned int indent_level)
{


    RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
      RTILog_debug("%s:\n", desc);
    } else {
      RTILog_debug("\n");
    }

    if (sample == NULL) {
      RTILog_debug("NULL\n");
      return;
    }


    RTICdrType_printArray(
        sample->clientServiceId, (4), RTI_CDR_UNSIGNED_LONG_SIZE,
        (RTICdrTypePrintFunction)RTICdrType_printUnsignedLong,
        "clientServiceId", indent_level + 1);
            
    RTICdrType_printUnsignedLong(
        &sample->numSec, "numSec", indent_level + 1);
            
    RTICdrType_printLong(
        &sample->id1, "id1", indent_level + 1);
            
    RTICdrType_printLong(
        &sample->id2, "id2", indent_level + 1);
            

}

sumaRequest *
sumaRequestPluginSupport_create_key_ex(RTIBool allocate_pointers){
    sumaRequest *key = NULL;

    RTIOsapiHeap_allocateStructure(
        &key, sumaRequestKeyHolder);

    sumaRequest_initialize_ex(key,allocate_pointers);
    return key;
}


sumaRequest *
sumaRequestPluginSupport_create_key(void)
{
    return  sumaRequestPluginSupport_create_key_ex(RTI_TRUE);
}


void 
sumaRequestPluginSupport_destroy_key_ex(
    sumaRequestKeyHolder *key,RTIBool deallocate_pointers)
{
    sumaRequest_finalize_ex(key,deallocate_pointers);

    RTIOsapiHeap_freeStructure(key);
}


void 
sumaRequestPluginSupport_destroy_key(
    sumaRequestKeyHolder *key) {

  sumaRequestPluginSupport_destroy_key_ex(key,RTI_TRUE);

}



/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */



PRESTypePluginParticipantData 
sumaRequestPlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{

    if (registration_data) {} /* To avoid warnings */
    if (participant_info) {} /* To avoid warnings */
    if (top_level_registration) {} /* To avoid warnings */
    if (container_plugin_context) {} /* To avoid warnings */
    if (type_code) {} /* To avoid warnings */
    return PRESTypePluginDefaultParticipantData_new(participant_info);

}


void 
sumaRequestPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{

  PRESTypePluginDefaultParticipantData_delete(participant_data);
}


PRESTypePluginEndpointData
sumaRequestPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    PRESTypePluginEndpointData epd = NULL;

    unsigned int serializedKeyMaxSize;

    if (top_level_registration) {} /* To avoid warnings */
    if (containerPluginContext) {} /* To avoid warnings */


    epd = PRESTypePluginDefaultEndpointData_new(
            participant_data,
            endpoint_info,
            (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
            sumaRequestPluginSupport_create_data,
            (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
            sumaRequestPluginSupport_destroy_data,
            (PRESTypePluginDefaultEndpointDataCreateKeyFunction)
            sumaRequestPluginSupport_create_key,
            (PRESTypePluginDefaultEndpointDataDestroyKeyFunction)
            sumaRequestPluginSupport_destroy_key);

    if (epd == NULL) {
        return NULL;
    }
   
    serializedKeyMaxSize = sumaRequestPlugin_get_serialized_key_max_size(
        epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);
    
    if (!PRESTypePluginDefaultEndpointData_createMD5Stream(
            epd,serializedKeyMaxSize)) 
    {
        PRESTypePluginDefaultEndpointData_delete(epd);
        return NULL;
    }

    
    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        if (PRESTypePluginDefaultEndpointData_createWriterPool(
                epd,
                endpoint_info,
            (PRESTypePluginGetSerializedSampleMaxSizeFunction)
                sumaRequestPlugin_get_serialized_sample_max_size, epd,
            (PRESTypePluginGetSerializedSampleSizeFunction)
            sumaRequestPlugin_get_serialized_sample_size,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }
    


    return epd;    
}


void 
sumaRequestPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  

    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}


RTIBool 
sumaRequestPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    sumaRequest *dst,
    const sumaRequest *src)
{
    if (endpoint_data) {} /* To avoid warnings */
    return sumaRequestPluginSupport_copy_data(dst,src);
}

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */


RTIBool 
sumaRequestPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const sumaRequest *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    RTIBool retval = RTI_TRUE;


  if (endpoint_data) {} /* To avoid warnings */
  if (endpoint_plugin_qos) {} /* To avoid warnings */


  if(serialize_encapsulation) {

    if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
        return RTI_FALSE;
    }

    position = RTICdrStream_resetAlignment(stream);

  }

  if(serialize_sample) {

    if (!RTICdrStream_serializePrimitiveArray(
        stream, (void*)sample->clientServiceId, (4), RTI_CDR_UNSIGNED_LONG_TYPE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeUnsignedLong(
        stream, &sample->numSec)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeLong(
        stream, &sample->id1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeLong(
        stream, &sample->id2)) {
        return RTI_FALSE;
    }
            
  }

  if(serialize_encapsulation) {
    RTICdrStream_restoreAlignment(stream,position);
  }


  return retval;
}


RTIBool 
sumaRequestPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    sumaRequest *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }
    
    if(deserialize_sample) {


    if (!RTICdrStream_deserializePrimitiveArray(
        stream, (void*)sample->clientServiceId, (4), RTI_CDR_UNSIGNED_LONG_TYPE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeUnsignedLong(
        stream, &sample->numSec)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeLong(
        stream, &sample->id1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeLong(
        stream, &sample->id2)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}

 
 
RTIBool 
sumaRequestPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    sumaRequest **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    if (drop_sample) {} /* To avoid warnings */

    return sumaRequestPlugin_deserialize_sample( 
        endpoint_data, (sample != NULL)?*sample:NULL,
        stream, deserialize_encapsulation, deserialize_sample, 
        endpoint_plugin_qos);
 
}



RTIBool sumaRequestPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (skip_sample) {

    if (!RTICdrStream_skipPrimitiveArray(
        stream, (4), RTI_CDR_UNSIGNED_LONG_TYPE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipUnsignedLong(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipLong(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipLong(stream)) {
        return RTI_FALSE;
    }
            
    }


    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


unsigned int 
sumaRequestPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getPrimitiveArrayMaxSizeSerialized(
        current_alignment, (4), RTI_CDR_UNSIGNED_LONG_TYPE);
            
    current_alignment +=  RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


unsigned int 
sumaRequestPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getPrimitiveArrayMaxSizeSerialized(
        current_alignment, (4), RTI_CDR_UNSIGNED_LONG_TYPE);
            
    current_alignment +=  RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


/* Returns the size of the sample in its serialized form (in bytes).
 * It can also be an estimation in excess of the real buffer needed 
 * during a call to the serialize() function.
 * The value reported does not have to include the space for the
 * encapsulation flags.
 */
unsigned int
sumaRequestPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const sumaRequest * sample) 
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */
    if (sample) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment += RTICdrType_getPrimitiveArrayMaxSizeSerialized(
        current_alignment, (4), RTI_CDR_UNSIGNED_LONG_TYPE);
            
    current_alignment += RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}

/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */


PRESTypePluginKeyKind 
sumaRequestPlugin_get_key_kind(void)
{

    return PRES_TYPEPLUGIN_USER_KEY;
     
}


RTIBool 
sumaRequestPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const sumaRequest *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if(serialize_key) {

    if (!RTICdrStream_serializePrimitiveArray(
        stream, (void*)sample->clientServiceId, (4), RTI_CDR_UNSIGNED_LONG_TYPE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeUnsignedLong(
        stream, &sample->numSec)) {
        return RTI_FALSE;
    }
            
    }


    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


RTIBool sumaRequestPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    sumaRequest *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;  
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

    if (!RTICdrStream_deserializePrimitiveArray(
        stream, (void*)sample->clientServiceId, (4), RTI_CDR_UNSIGNED_LONG_TYPE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeUnsignedLong(
        stream, &sample->numSec)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


 
RTIBool sumaRequestPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    sumaRequest **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    if (drop_sample) {} /* To avoid warnings */
    return sumaRequestPlugin_deserialize_key_sample(
        endpoint_data, (sample != NULL)?*sample:NULL, stream,
        deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
}



unsigned int
sumaRequestPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int encapsulation_size = current_alignment;


    unsigned int initial_alignment = current_alignment;


    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {
        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }


        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }
        

    current_alignment +=  RTICdrType_getPrimitiveArrayMaxSizeSerialized(
        current_alignment, (4), RTI_CDR_UNSIGNED_LONG_TYPE);
            
    current_alignment +=  RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


RTIBool 
sumaRequestPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    sumaRequest *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

    if (!RTICdrStream_deserializePrimitiveArray(
        stream, (void*)sample->clientServiceId, (4), RTI_CDR_UNSIGNED_LONG_TYPE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeUnsignedLong(
        stream, &sample->numSec)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipLong(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipLong(stream)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}





RTIBool 
sumaRequestPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    sumaRequestKeyHolder *dst, 
    const sumaRequest *src)
{  

    if (endpoint_data) {} /* To avoid warnings */

    if (!RTICdrType_copyArray(
        dst->clientServiceId, src->clientServiceId, (4), RTI_CDR_UNSIGNED_LONG_SIZE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyUnsignedLong(
        &dst->numSec, &src->numSec)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


RTIBool 
sumaRequestPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    sumaRequest *dst, const
    sumaRequestKeyHolder *src)
{

    if (endpoint_data) {} /* To avoid warnings */

    if (!RTICdrType_copyArray(
        dst->clientServiceId, src->clientServiceId, (4), RTI_CDR_UNSIGNED_LONG_SIZE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyUnsignedLong(
        &dst->numSec, &src->numSec)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


RTIBool 
sumaRequestPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const sumaRequest *instance)
{
    struct RTICdrStream * md5Stream = NULL;

    md5Stream = PRESTypePluginDefaultEndpointData_getMD5Stream(endpoint_data);

    if (md5Stream == NULL) {
        return RTI_FALSE;
    }

    RTIOsapiMemory_zero(
        RTICdrStream_getBuffer(md5Stream),
        RTICdrStream_getBufferLength(md5Stream));
    RTICdrStream_resetPosition(md5Stream);
    RTICdrStream_setDirtyBit(md5Stream, RTI_TRUE);

    if (!sumaRequestPlugin_serialize_key(
            endpoint_data,instance,md5Stream, RTI_FALSE, RTI_CDR_ENCAPSULATION_ID_CDR_BE, RTI_TRUE,NULL)) {
        return RTI_FALSE;
    }
    
    if (PRESTypePluginDefaultEndpointData_getMaxSizeSerializedKey(endpoint_data) > (unsigned int)(MIG_RTPS_KEY_HASH_MAX_LENGTH)) {
        RTICdrStream_computeMD5(md5Stream, keyhash->value);
    } else {
        RTIOsapiMemory_zero(keyhash->value,MIG_RTPS_KEY_HASH_MAX_LENGTH);
        RTIOsapiMemory_copy(
            keyhash->value, 
            RTICdrStream_getBuffer(md5Stream), 
            RTICdrStream_getCurrentPositionOffset(md5Stream));
    }

    keyhash->length = MIG_RTPS_KEY_HASH_MAX_LENGTH;
    return RTI_TRUE;
}


RTIBool 
sumaRequestPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos) 
{   
    char * position = NULL;
    sumaRequest * sample;

    if (endpoint_plugin_qos) {} /* To avoid warnings */



    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }


    sample = (sumaRequest *)
                PRESTypePluginDefaultEndpointData_getTempSample(endpoint_data);

    if (sample == NULL) {
        return RTI_FALSE;
    }


    if (!RTICdrStream_deserializePrimitiveArray(
        stream, (void*)sample->clientServiceId, (4), RTI_CDR_UNSIGNED_LONG_TYPE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeUnsignedLong(
        stream, &sample->numSec)) {
        return RTI_FALSE;
    }
            
    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    if (!sumaRequestPlugin_instance_to_keyhash(
            endpoint_data, keyhash, sample)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}


/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */
 
struct PRESTypePlugin *sumaRequestPlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
        PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);
    if (plugin == NULL) {
       return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
        (PRESTypePluginOnParticipantAttachedCallback)
        sumaRequestPlugin_on_participant_attached;
    plugin->onParticipantDetached =
        (PRESTypePluginOnParticipantDetachedCallback)
        sumaRequestPlugin_on_participant_detached;
    plugin->onEndpointAttached =
        (PRESTypePluginOnEndpointAttachedCallback)
        sumaRequestPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
        (PRESTypePluginOnEndpointDetachedCallback)
        sumaRequestPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
        (PRESTypePluginCopySampleFunction)
        sumaRequestPlugin_copy_sample;
    plugin->createSampleFnc =
        (PRESTypePluginCreateSampleFunction)
        sumaRequestPlugin_create_sample;
    plugin->destroySampleFnc =
        (PRESTypePluginDestroySampleFunction)
        sumaRequestPlugin_destroy_sample;

    plugin->serializeFnc =
        (PRESTypePluginSerializeFunction)
        sumaRequestPlugin_serialize;
    plugin->deserializeFnc =
        (PRESTypePluginDeserializeFunction)
        sumaRequestPlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
        (PRESTypePluginGetSerializedSampleMaxSizeFunction)
        sumaRequestPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
        (PRESTypePluginGetSerializedSampleMinSizeFunction)
        sumaRequestPlugin_get_serialized_sample_min_size;


    plugin->getSampleFnc =
        (PRESTypePluginGetSampleFunction)
        sumaRequestPlugin_get_sample;
    plugin->returnSampleFnc =
        (PRESTypePluginReturnSampleFunction)
        sumaRequestPlugin_return_sample;

    plugin->getKeyKindFnc =
        (PRESTypePluginGetKeyKindFunction)
        sumaRequestPlugin_get_key_kind;


    plugin->getSerializedKeyMaxSizeFnc =   
        (PRESTypePluginGetSerializedKeyMaxSizeFunction)
        sumaRequestPlugin_get_serialized_key_max_size;
    plugin->serializeKeyFnc =
        (PRESTypePluginSerializeKeyFunction)
        sumaRequestPlugin_serialize_key;
    plugin->deserializeKeyFnc =
        (PRESTypePluginDeserializeKeyFunction)
        sumaRequestPlugin_deserialize_key;
    plugin->deserializeKeySampleFnc =
        (PRESTypePluginDeserializeKeySampleFunction)
        sumaRequestPlugin_deserialize_key_sample;

    plugin->instanceToKeyHashFnc = 
        (PRESTypePluginInstanceToKeyHashFunction)
        sumaRequestPlugin_instance_to_keyhash;
    plugin->serializedSampleToKeyHashFnc = 
        (PRESTypePluginSerializedSampleToKeyHashFunction)
        sumaRequestPlugin_serialized_sample_to_keyhash;

    plugin->getKeyFnc =
        (PRESTypePluginGetKeyFunction)
        sumaRequestPlugin_get_key;
    plugin->returnKeyFnc =
        (PRESTypePluginReturnKeyFunction)
        sumaRequestPlugin_return_key;

    plugin->instanceToKeyFnc =
        (PRESTypePluginInstanceToKeyFunction)
        sumaRequestPlugin_instance_to_key;
    plugin->keyToInstanceFnc =
        (PRESTypePluginKeyToInstanceFunction)
        sumaRequestPlugin_key_to_instance;
    plugin->serializedKeyToKeyHashFnc = NULL; /* Not supported yet */
    
    plugin->typeCode =  (struct RTICdrTypeCode *)sumaRequest_get_typecode();
    
    plugin->languageKind = PRES_TYPEPLUGIN_DDS_TYPE; 

    /* Serialized buffer */
    plugin->getBuffer = 
        (PRESTypePluginGetBufferFunction)
        sumaRequestPlugin_get_buffer;
    plugin->returnBuffer = 
        (PRESTypePluginReturnBufferFunction)
        sumaRequestPlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =
        (PRESTypePluginGetSerializedSampleSizeFunction)
        sumaRequestPlugin_get_serialized_sample_size;

    plugin->endpointTypeName = sumaRequestTYPENAME;

    return plugin;
}

void
sumaRequestPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 

/* --------------------------------------------------------------------------------------
 *  Type sumaReply
 * -------------------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

sumaReply *
sumaReplyPluginSupport_create_data_ex(RTIBool allocate_pointers){
    sumaReply *sample = NULL;

    RTIOsapiHeap_allocateStructure(
        &sample, sumaReply);

    if(sample != NULL) {
        if (!sumaReply_initialize_ex(sample,allocate_pointers)) {
            RTIOsapiHeap_freeStructure(&sample);
            return NULL;
        }
    }
    return sample; 
}


sumaReply *
sumaReplyPluginSupport_create_data(void)
{
    return sumaReplyPluginSupport_create_data_ex(RTI_TRUE);
}


void 
sumaReplyPluginSupport_destroy_data_ex(
    sumaReply *sample,RTIBool deallocate_pointers) {

    sumaReply_finalize_ex(sample,deallocate_pointers);

    RTIOsapiHeap_freeStructure(sample);
}


void 
sumaReplyPluginSupport_destroy_data(
    sumaReply *sample) {

    sumaReplyPluginSupport_destroy_data_ex(sample,RTI_TRUE);

}


RTIBool 
sumaReplyPluginSupport_copy_data(
    sumaReply *dst,
    const sumaReply *src)
{
    return sumaReply_copy(dst,src);
}


void 
sumaReplyPluginSupport_print_data(
    const sumaReply *sample,
    const char *desc,
    unsigned int indent_level)
{


    RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
      RTILog_debug("%s:\n", desc);
    } else {
      RTILog_debug("\n");
    }

    if (sample == NULL) {
      RTILog_debug("NULL\n");
      return;
    }


    RTICdrType_printArray(
        sample->serverServiceId, (4), RTI_CDR_UNSIGNED_LONG_SIZE,
        (RTICdrTypePrintFunction)RTICdrType_printUnsignedLong,
        "serverServiceId", indent_level + 1);
            
    RTICdrType_printArray(
        sample->clientServiceId, (4), RTI_CDR_UNSIGNED_LONG_SIZE,
        (RTICdrTypePrintFunction)RTICdrType_printUnsignedLong,
        "clientServiceId", indent_level + 1);
            
    RTICdrType_printUnsignedLong(
        &sample->numSec, "numSec", indent_level + 1);
            
    RTICdrType_printLong(
        &sample->ddscsRetCode, "ddscsRetCode", indent_level + 1);
            
    RTICdrType_printLong(
        &sample->returnedValue, "returnedValue", indent_level + 1);
            

}

sumaReply *
sumaReplyPluginSupport_create_key_ex(RTIBool allocate_pointers){
    sumaReply *key = NULL;

    RTIOsapiHeap_allocateStructure(
        &key, sumaReplyKeyHolder);

    sumaReply_initialize_ex(key,allocate_pointers);
    return key;
}


sumaReply *
sumaReplyPluginSupport_create_key(void)
{
    return  sumaReplyPluginSupport_create_key_ex(RTI_TRUE);
}


void 
sumaReplyPluginSupport_destroy_key_ex(
    sumaReplyKeyHolder *key,RTIBool deallocate_pointers)
{
    sumaReply_finalize_ex(key,deallocate_pointers);

    RTIOsapiHeap_freeStructure(key);
}


void 
sumaReplyPluginSupport_destroy_key(
    sumaReplyKeyHolder *key) {

  sumaReplyPluginSupport_destroy_key_ex(key,RTI_TRUE);

}



/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */



PRESTypePluginParticipantData 
sumaReplyPlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{

    if (registration_data) {} /* To avoid warnings */
    if (participant_info) {} /* To avoid warnings */
    if (top_level_registration) {} /* To avoid warnings */
    if (container_plugin_context) {} /* To avoid warnings */
    if (type_code) {} /* To avoid warnings */
    return PRESTypePluginDefaultParticipantData_new(participant_info);

}


void 
sumaReplyPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{

  PRESTypePluginDefaultParticipantData_delete(participant_data);
}


PRESTypePluginEndpointData
sumaReplyPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    PRESTypePluginEndpointData epd = NULL;

    unsigned int serializedKeyMaxSize;

    if (top_level_registration) {} /* To avoid warnings */
    if (containerPluginContext) {} /* To avoid warnings */


    epd = PRESTypePluginDefaultEndpointData_new(
            participant_data,
            endpoint_info,
            (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
            sumaReplyPluginSupport_create_data,
            (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
            sumaReplyPluginSupport_destroy_data,
            (PRESTypePluginDefaultEndpointDataCreateKeyFunction)
            sumaReplyPluginSupport_create_key,
            (PRESTypePluginDefaultEndpointDataDestroyKeyFunction)
            sumaReplyPluginSupport_destroy_key);

    if (epd == NULL) {
        return NULL;
    }
   
    serializedKeyMaxSize = sumaReplyPlugin_get_serialized_key_max_size(
        epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);
    
    if (!PRESTypePluginDefaultEndpointData_createMD5Stream(
            epd,serializedKeyMaxSize)) 
    {
        PRESTypePluginDefaultEndpointData_delete(epd);
        return NULL;
    }

    
    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        if (PRESTypePluginDefaultEndpointData_createWriterPool(
                epd,
                endpoint_info,
            (PRESTypePluginGetSerializedSampleMaxSizeFunction)
                sumaReplyPlugin_get_serialized_sample_max_size, epd,
            (PRESTypePluginGetSerializedSampleSizeFunction)
            sumaReplyPlugin_get_serialized_sample_size,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }
    


    return epd;    
}


void 
sumaReplyPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  

    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}


RTIBool 
sumaReplyPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    sumaReply *dst,
    const sumaReply *src)
{
    if (endpoint_data) {} /* To avoid warnings */
    return sumaReplyPluginSupport_copy_data(dst,src);
}

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */


RTIBool 
sumaReplyPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const sumaReply *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    RTIBool retval = RTI_TRUE;


  if (endpoint_data) {} /* To avoid warnings */
  if (endpoint_plugin_qos) {} /* To avoid warnings */


  if(serialize_encapsulation) {

    if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
        return RTI_FALSE;
    }

    position = RTICdrStream_resetAlignment(stream);

  }

  if(serialize_sample) {

    if (!RTICdrStream_serializePrimitiveArray(
        stream, (void*)sample->serverServiceId, (4), RTI_CDR_UNSIGNED_LONG_TYPE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializePrimitiveArray(
        stream, (void*)sample->clientServiceId, (4), RTI_CDR_UNSIGNED_LONG_TYPE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeUnsignedLong(
        stream, &sample->numSec)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeLong(
        stream, &sample->ddscsRetCode)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeLong(
        stream, &sample->returnedValue)) {
        return RTI_FALSE;
    }
            
  }

  if(serialize_encapsulation) {
    RTICdrStream_restoreAlignment(stream,position);
  }


  return retval;
}


RTIBool 
sumaReplyPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    sumaReply *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }
    
    if(deserialize_sample) {


    if (!RTICdrStream_deserializePrimitiveArray(
        stream, (void*)sample->serverServiceId, (4), RTI_CDR_UNSIGNED_LONG_TYPE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializePrimitiveArray(
        stream, (void*)sample->clientServiceId, (4), RTI_CDR_UNSIGNED_LONG_TYPE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeUnsignedLong(
        stream, &sample->numSec)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeLong(
        stream, &sample->ddscsRetCode)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeLong(
        stream, &sample->returnedValue)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}

 
 
RTIBool 
sumaReplyPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    sumaReply **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    if (drop_sample) {} /* To avoid warnings */

    return sumaReplyPlugin_deserialize_sample( 
        endpoint_data, (sample != NULL)?*sample:NULL,
        stream, deserialize_encapsulation, deserialize_sample, 
        endpoint_plugin_qos);
 
}



RTIBool sumaReplyPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (skip_sample) {

    if (!RTICdrStream_skipPrimitiveArray(
        stream, (4), RTI_CDR_UNSIGNED_LONG_TYPE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipPrimitiveArray(
        stream, (4), RTI_CDR_UNSIGNED_LONG_TYPE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipUnsignedLong(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipLong(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipLong(stream)) {
        return RTI_FALSE;
    }
            
    }


    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


unsigned int 
sumaReplyPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getPrimitiveArrayMaxSizeSerialized(
        current_alignment, (4), RTI_CDR_UNSIGNED_LONG_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveArrayMaxSizeSerialized(
        current_alignment, (4), RTI_CDR_UNSIGNED_LONG_TYPE);
            
    current_alignment +=  RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


unsigned int 
sumaReplyPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getPrimitiveArrayMaxSizeSerialized(
        current_alignment, (4), RTI_CDR_UNSIGNED_LONG_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveArrayMaxSizeSerialized(
        current_alignment, (4), RTI_CDR_UNSIGNED_LONG_TYPE);
            
    current_alignment +=  RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


/* Returns the size of the sample in its serialized form (in bytes).
 * It can also be an estimation in excess of the real buffer needed 
 * during a call to the serialize() function.
 * The value reported does not have to include the space for the
 * encapsulation flags.
 */
unsigned int
sumaReplyPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const sumaReply * sample) 
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */
    if (sample) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment += RTICdrType_getPrimitiveArrayMaxSizeSerialized(
        current_alignment, (4), RTI_CDR_UNSIGNED_LONG_TYPE);
            
    current_alignment += RTICdrType_getPrimitiveArrayMaxSizeSerialized(
        current_alignment, (4), RTI_CDR_UNSIGNED_LONG_TYPE);
            
    current_alignment += RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}

/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */


PRESTypePluginKeyKind 
sumaReplyPlugin_get_key_kind(void)
{

    return PRES_TYPEPLUGIN_USER_KEY;
     
}


RTIBool 
sumaReplyPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const sumaReply *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if(serialize_key) {

    if (!RTICdrStream_serializePrimitiveArray(
        stream, (void*)sample->serverServiceId, (4), RTI_CDR_UNSIGNED_LONG_TYPE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializePrimitiveArray(
        stream, (void*)sample->clientServiceId, (4), RTI_CDR_UNSIGNED_LONG_TYPE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeUnsignedLong(
        stream, &sample->numSec)) {
        return RTI_FALSE;
    }
            
    }


    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


RTIBool sumaReplyPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    sumaReply *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;  
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

    if (!RTICdrStream_deserializePrimitiveArray(
        stream, (void*)sample->serverServiceId, (4), RTI_CDR_UNSIGNED_LONG_TYPE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializePrimitiveArray(
        stream, (void*)sample->clientServiceId, (4), RTI_CDR_UNSIGNED_LONG_TYPE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeUnsignedLong(
        stream, &sample->numSec)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


 
RTIBool sumaReplyPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    sumaReply **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    if (drop_sample) {} /* To avoid warnings */
    return sumaReplyPlugin_deserialize_key_sample(
        endpoint_data, (sample != NULL)?*sample:NULL, stream,
        deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
}



unsigned int
sumaReplyPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int encapsulation_size = current_alignment;


    unsigned int initial_alignment = current_alignment;


    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {
        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }


        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }
        

    current_alignment +=  RTICdrType_getPrimitiveArrayMaxSizeSerialized(
        current_alignment, (4), RTI_CDR_UNSIGNED_LONG_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveArrayMaxSizeSerialized(
        current_alignment, (4), RTI_CDR_UNSIGNED_LONG_TYPE);
            
    current_alignment +=  RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


RTIBool 
sumaReplyPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    sumaReply *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

    if (!RTICdrStream_deserializePrimitiveArray(
        stream, (void*)sample->serverServiceId, (4), RTI_CDR_UNSIGNED_LONG_TYPE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializePrimitiveArray(
        stream, (void*)sample->clientServiceId, (4), RTI_CDR_UNSIGNED_LONG_TYPE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeUnsignedLong(
        stream, &sample->numSec)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipLong(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipLong(stream)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}





RTIBool 
sumaReplyPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    sumaReplyKeyHolder *dst, 
    const sumaReply *src)
{  

    if (endpoint_data) {} /* To avoid warnings */

    if (!RTICdrType_copyArray(
        dst->serverServiceId, src->serverServiceId, (4), RTI_CDR_UNSIGNED_LONG_SIZE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyArray(
        dst->clientServiceId, src->clientServiceId, (4), RTI_CDR_UNSIGNED_LONG_SIZE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyUnsignedLong(
        &dst->numSec, &src->numSec)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


RTIBool 
sumaReplyPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    sumaReply *dst, const
    sumaReplyKeyHolder *src)
{

    if (endpoint_data) {} /* To avoid warnings */

    if (!RTICdrType_copyArray(
        dst->serverServiceId, src->serverServiceId, (4), RTI_CDR_UNSIGNED_LONG_SIZE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyArray(
        dst->clientServiceId, src->clientServiceId, (4), RTI_CDR_UNSIGNED_LONG_SIZE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyUnsignedLong(
        &dst->numSec, &src->numSec)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


RTIBool 
sumaReplyPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const sumaReply *instance)
{
    struct RTICdrStream * md5Stream = NULL;

    md5Stream = PRESTypePluginDefaultEndpointData_getMD5Stream(endpoint_data);

    if (md5Stream == NULL) {
        return RTI_FALSE;
    }

    RTIOsapiMemory_zero(
        RTICdrStream_getBuffer(md5Stream),
        RTICdrStream_getBufferLength(md5Stream));
    RTICdrStream_resetPosition(md5Stream);
    RTICdrStream_setDirtyBit(md5Stream, RTI_TRUE);

    if (!sumaReplyPlugin_serialize_key(
            endpoint_data,instance,md5Stream, RTI_FALSE, RTI_CDR_ENCAPSULATION_ID_CDR_BE, RTI_TRUE,NULL)) {
        return RTI_FALSE;
    }
    
    if (PRESTypePluginDefaultEndpointData_getMaxSizeSerializedKey(endpoint_data) > (unsigned int)(MIG_RTPS_KEY_HASH_MAX_LENGTH)) {
        RTICdrStream_computeMD5(md5Stream, keyhash->value);
    } else {
        RTIOsapiMemory_zero(keyhash->value,MIG_RTPS_KEY_HASH_MAX_LENGTH);
        RTIOsapiMemory_copy(
            keyhash->value, 
            RTICdrStream_getBuffer(md5Stream), 
            RTICdrStream_getCurrentPositionOffset(md5Stream));
    }

    keyhash->length = MIG_RTPS_KEY_HASH_MAX_LENGTH;
    return RTI_TRUE;
}


RTIBool 
sumaReplyPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos) 
{   
    char * position = NULL;
    sumaReply * sample;

    if (endpoint_plugin_qos) {} /* To avoid warnings */



    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }


    sample = (sumaReply *)
                PRESTypePluginDefaultEndpointData_getTempSample(endpoint_data);

    if (sample == NULL) {
        return RTI_FALSE;
    }


    if (!RTICdrStream_deserializePrimitiveArray(
        stream, (void*)sample->serverServiceId, (4), RTI_CDR_UNSIGNED_LONG_TYPE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializePrimitiveArray(
        stream, (void*)sample->clientServiceId, (4), RTI_CDR_UNSIGNED_LONG_TYPE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeUnsignedLong(
        stream, &sample->numSec)) {
        return RTI_FALSE;
    }
            
    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    if (!sumaReplyPlugin_instance_to_keyhash(
            endpoint_data, keyhash, sample)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}


/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */
 
struct PRESTypePlugin *sumaReplyPlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
        PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);
    if (plugin == NULL) {
       return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
        (PRESTypePluginOnParticipantAttachedCallback)
        sumaReplyPlugin_on_participant_attached;
    plugin->onParticipantDetached =
        (PRESTypePluginOnParticipantDetachedCallback)
        sumaReplyPlugin_on_participant_detached;
    plugin->onEndpointAttached =
        (PRESTypePluginOnEndpointAttachedCallback)
        sumaReplyPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
        (PRESTypePluginOnEndpointDetachedCallback)
        sumaReplyPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
        (PRESTypePluginCopySampleFunction)
        sumaReplyPlugin_copy_sample;
    plugin->createSampleFnc =
        (PRESTypePluginCreateSampleFunction)
        sumaReplyPlugin_create_sample;
    plugin->destroySampleFnc =
        (PRESTypePluginDestroySampleFunction)
        sumaReplyPlugin_destroy_sample;

    plugin->serializeFnc =
        (PRESTypePluginSerializeFunction)
        sumaReplyPlugin_serialize;
    plugin->deserializeFnc =
        (PRESTypePluginDeserializeFunction)
        sumaReplyPlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
        (PRESTypePluginGetSerializedSampleMaxSizeFunction)
        sumaReplyPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
        (PRESTypePluginGetSerializedSampleMinSizeFunction)
        sumaReplyPlugin_get_serialized_sample_min_size;


    plugin->getSampleFnc =
        (PRESTypePluginGetSampleFunction)
        sumaReplyPlugin_get_sample;
    plugin->returnSampleFnc =
        (PRESTypePluginReturnSampleFunction)
        sumaReplyPlugin_return_sample;

    plugin->getKeyKindFnc =
        (PRESTypePluginGetKeyKindFunction)
        sumaReplyPlugin_get_key_kind;


    plugin->getSerializedKeyMaxSizeFnc =   
        (PRESTypePluginGetSerializedKeyMaxSizeFunction)
        sumaReplyPlugin_get_serialized_key_max_size;
    plugin->serializeKeyFnc =
        (PRESTypePluginSerializeKeyFunction)
        sumaReplyPlugin_serialize_key;
    plugin->deserializeKeyFnc =
        (PRESTypePluginDeserializeKeyFunction)
        sumaReplyPlugin_deserialize_key;
    plugin->deserializeKeySampleFnc =
        (PRESTypePluginDeserializeKeySampleFunction)
        sumaReplyPlugin_deserialize_key_sample;

    plugin->instanceToKeyHashFnc = 
        (PRESTypePluginInstanceToKeyHashFunction)
        sumaReplyPlugin_instance_to_keyhash;
    plugin->serializedSampleToKeyHashFnc = 
        (PRESTypePluginSerializedSampleToKeyHashFunction)
        sumaReplyPlugin_serialized_sample_to_keyhash;

    plugin->getKeyFnc =
        (PRESTypePluginGetKeyFunction)
        sumaReplyPlugin_get_key;
    plugin->returnKeyFnc =
        (PRESTypePluginReturnKeyFunction)
        sumaReplyPlugin_return_key;

    plugin->instanceToKeyFnc =
        (PRESTypePluginInstanceToKeyFunction)
        sumaReplyPlugin_instance_to_key;
    plugin->keyToInstanceFnc =
        (PRESTypePluginKeyToInstanceFunction)
        sumaReplyPlugin_key_to_instance;
    plugin->serializedKeyToKeyHashFnc = NULL; /* Not supported yet */
    
    plugin->typeCode =  (struct RTICdrTypeCode *)sumaReply_get_typecode();
    
    plugin->languageKind = PRES_TYPEPLUGIN_DDS_TYPE; 

    /* Serialized buffer */
    plugin->getBuffer = 
        (PRESTypePluginGetBufferFunction)
        sumaReplyPlugin_get_buffer;
    plugin->returnBuffer = 
        (PRESTypePluginReturnBufferFunction)
        sumaReplyPlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =
        (PRESTypePluginGetSerializedSampleSizeFunction)
        sumaReplyPlugin_get_serialized_sample_size;

    plugin->endpointTypeName = sumaReplyTYPENAME;

    return plugin;
}

void
sumaReplyPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 