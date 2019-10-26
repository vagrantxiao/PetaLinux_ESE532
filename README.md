# PetaLinux_ESE532
This is a tutorial to use PetaLinux platform for Ultra96-v2.

## 1 Linux Platform
clone this repo, and the petalinux platform is under /platform/ese532. You can integrated this platform as the [tutorial](https://github.com/vagrantxiao/ultra96_ese532) we gave you before.

## 2 SD Card format
You need to reformat your SD card as below in Ubuntu.
2.1 Open "disks" tool in Ubuntu, delete your original SD card format.

![](/images/delete_format.png)

2.2 Create first partition named "boot". The size is 1GB and the format is "FAT" as below.

![](/images/boot.png)

2.3 Create another partition named "rootfs". The size is 15GB and the format is "Ext4" as below.

![](/images/rootfs.png)

2.4 Mount the two partitions by click the triangle as below.

![](/images/mount.png)

2.5 Now, go to [/platform/sys_files](/platform/sys_files) in the terminal as below. Type in the code below.

````c
cp ./libsds_lib.so /media/<USER_NAME>/boot/
sudo cp rootfs.cpio /media/<USER_NAME>/rootfs
cd /media/<USER_NAME>/rootfs
sudo pax -rvf rootfs.cpio
cd ../
sync
````

![](/images/cp.png)

## 3 Create SDx project based on current platform.

3.1 Add the source file under [/examples/usbRW/host.cpp](/examples/usbRW/) into your project.
3.2 Compile it and copy the files under <project_name>/Debug/SD_card to /boot in SD Card.

![](/images/sdcard.png)




















