OBJS = main.o shm_write.o
 
meter_dump: $(OBJS)
    gcc $(OBJS) -o meter_dump    //注意：命令前面必须为（tab）
main.o: main.c shm_write.h
    gcc -c main.c -o main.o
shm_write.o: shm_write.c shm_write.h
    gcc -c shm_write.c -o shm_write.o
clean:
    rm -rf *.o meter_dump