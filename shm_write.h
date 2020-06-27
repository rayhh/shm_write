  1#ifndef _SHM_H                                                                                                                                          2 #define HGW_SHM_H
  3#define _SHM_H


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

  4 void *shm_create(char *name, unsigned int len);
  5 int shm_del(void *addr, unsigned int len);
  6
  7 #endif