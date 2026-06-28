## Make device node without this you can't access kernel driver

sudo mknod /dev/mydevice c 64 0
ls /dev/mydevice -al
crw-r--r-- 1 root root 90, 0 Jun 28 18:20 /dev/mydevice
sudo chmod 656 /dev/mydevice

##for testing userspace compile test.c file

gcc test.c -o test

run for access that device

./test
