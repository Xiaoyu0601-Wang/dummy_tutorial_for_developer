# Radxa SBC
https://netplan.readthedocs.io/en/latest/netplan-yaml/#properties-for-device-type-wifis
https://github.com/Joshua-Riek/ubuntu-rockchip/wiki/Ubuntu-24.04-LTS

## Install U-Boot to an SD Card or eMMC
Installing the latest bootloader version to your eMMC can be done with the below command:
```sh
sudo u-boot-install /dev/mmcblk0
```

## Install Ubuntu onto an eMMC from Linux
The ubuntu-rockchip-install command can copy your currently running system onto an eMMC.
```sh
sudo ubuntu-rockchip-install /dev/mmcblk0
```

## Radxa Zero 3W
Ubuntu Noble 24.04 LTS

ROS2 Rolling
