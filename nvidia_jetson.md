# Nvidia Jetson Orin NX

## System installation and update by using SDKManager
https://docs.isarsoft.com/administration/install-jetpack/

Nvidia Jetson Orin NX won't wake up after suspend (deep sleep), so use command below to disable suspend:

### Modify systemd Sleep Settings
You can configure systemd to avoid entering deep sleep by adjusting its sleep settings. Edit the sleep.conf file:
bash
```sh
sudo nano /etc/systemd/sleep.conf
```
Add or update the following line to prevent the system from entering deeper power states:
plaintext
```sh
SuspendMode=freeze
```
Setting SuspendMode=freeze tells the system to use a lighter sleep mode that doesn’t power down as much as deep sleep.
