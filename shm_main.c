#include "shm_write.h"

#define SHM_SIZE 100
TBandWidthShmStat* g_bandwidshmstat = NULL;
int main()
{
    char* bandwidth_shm_0 = "/dev/shm/bandwidth_shm_0";
    unsigned int mem_size = SHM_SIZE*sizeof(TBandWidthShmStat);
    g_bandwidshmstat=shm_create(bandwidth_shm_0,mem_size);
    if(g_bandwidshmstat == NULL)
    {
        print("create bandwidth_shm_0 failed!\n");
        return 0;
    }
    memset(g_bandwidshmstat,0,mem_size);
    //random logic
    int i=0;
    for(i=0;i<10;i++){
        g_bandwidshmstat[i].bandwidth_id=12345+i;
        g_bandwidshmstat[i].used=1;
        g_bandwidshmstat[i].is_shared=1;
        g_bandwidshmstat[i].eip_nums=1+i;
        g_bandwidshmstat[i].eip=11111111;
        g_bandwidshmstat[i].outmeterid=22;
        g_bandwidshmstat[i].inmeterid=33;
        g_bandwidshmstat[i].tx_bytes=i*100;
        g_bandwidshmstat[i].tx_bytes=i*2;
    }
    shm_del(addr,len);
    return 0;
}
