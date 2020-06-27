#include <sys/mman.h>                                                                                                                                  
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/queue.h>
#include <inttypes.h>
#include <stdarg.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shm_wirte.h"

void *shm_create(char *name, unsigned int len)
{
    void *retval = NULL;                                                                                                                                         
    int result;                                                                                                                                                  
    int fd = open(name, O_CREAT | O_RDWR, 00777);
    if (fd < 0) {                                                                                                                                                    
        print("create share memory %s failed\n", name);
        return NULL;
    }
    if(ftruncate(fd,len)){
        close(fd);
        return NULL;
    }                           
    result = lseek(fd, len-1, SEEK_SET);                                                                                                                        
    if (result == -1) {                                                                                                                                              
    close(fd);                                                                                                                                                   
    return NULL;                                                                                                                                             
    }                                                                                                                                                            
    result = write(fd, "", 1);                                                                                                                                  
    if (result != 1) {                                                                                                                                             
    close(fd);                                                                                                                                                   
    return NULL;                                                                                                                                            
    }                                                                                                                                                            
    retval = mmap(0, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);                                                                                            
    close(fd);                                                                                                                                                   
    print("shm_create return mmap addr=%p\n", retval);
    return retval;
}


int shm_del(void *addr, unsigned int len)
{
    if(addr == NULL)
        return 0;
    return munmap(addr,len);
}