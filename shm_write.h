#ifndef _SHM_H                                                                                                                               
#define _SHM_H
#include  <inttypes.h>


typedef struct _stBandWidthShmStat{
    uint32_t bandwidth_id;
    uint8_t used;
    uint8_t is_shared;
    uint16_t eip_nums;
    union{
        uint32_t eip;
        unsigned long eip_array;
    };
    uint32_t outmeterid;
    uint32_t inmeterid;

    unsigned long rx_bytes;
    unsigned long rx_pkts;
    unsigned long tx_bytes;
    unsigned long tx_pkts;
    unsigned long rx_rldrop_pkts;
    unsigned long rx_rldrop_bytes;
    unsigned long tx_rldrop_pkts;
    unsigned long tx_rldrop_bytes;
}TBandWidthShmStat;

void *shm_create(char *name, unsigned int len);
int shm_del(void *addr, unsigned int len);
#endif