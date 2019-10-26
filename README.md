# PetaLinux_ESE532
This is a tutorial to use PetaLinux platform for Ultra96-v2.

## Linux Platform
clone this repo, and the petalinux platform is under /platform/ese532. You can integrated this platform as the [tutorial](https://github.com/vagrantxiao/ultra96_ese532) we gave you before.

## SD Card format
You need to reformat your SD card as below in Ubuntu.
1. Open "disks" tool in Ubuntu, delete your original SD card format.

![](/images/delete_format.png)

2. Create first partition named "boot". The size is 1GB and the format is "FAT" as below.

![](/images/boot.png)

3. Create another partition named "rootfs". The size is 15GB and the format is "Ext4" as below.

![](/images/rootfs.png)

4. Mount the two partitions by click the triangle as below.


![](/images/mount.png)

























