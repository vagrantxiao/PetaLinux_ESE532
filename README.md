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

## 4 Boot from SD Card

4.1 Plug in the sd card into Ultra96.
4.2 Remember to change our U96 into SD card boot mode as below.

![](/images/SDmode.jpg)

4.3 You can still use `SDx Terminal` in SDx to connect the board. Power on the board and in the `SDx Terminal`, you should see the boot information as below.

4.4 Wait until you see `login`. The login name and password are all `root`.
 
![](/images/login.png)

4.5 Plug in a USB device into U96-v2 board.

![](/images/USB.jpg)

4.6 In `SDx Terminal`, type in the command bellow.

````c
mount /dev/mmcblk0p1 /mnt

mkdir /usb1
mount /dev/sda1 /usb1
echo "I love ESE532" > /usb1/myfile.txt
cd /mnt
cp ./libsds_lib.so /usr/lib
./usbRW.elf
ls /usb1 -l
````

You should see the output file `myout.txt` under directory `/usb1`

## Conclusion
We mount a USB device to `/usb1`. In host.cpp, we can read and write all the files in that directory without other drivers.














