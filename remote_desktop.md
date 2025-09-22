# Remote desk setup

Remote controlling an Ubuntu desktop that uses Xorg (the default display server for many versions of Ubuntu) is most commonly achieved by setting up an RDP (Remote Desktop Protocol) or VNC (Virtual Network Computing) server. The simplest and most compatible method is to use xrdp to enable RDP connections, which works well with clients on Windows, macOS, and Linux. 

This method allows you to connect to a new desktop session on your Ubuntu machine using a standard RDP client. It is generally the fastest and most secure option. 

## On the Ubuntu machine (Server)

Install xrdp. Open a terminal and run the following commands to install the xrdp and xorgxrdp packages:
```sh
sudo apt update
sudo apt install xrdp xorgxrdp
```

Ensure xrdp is running. By default, the xrdp service should start automatically. You can check its status with:
```sh
sudo systemctl status xrdp
```

If it is not active, start and enable it:
```sh
sudo systemctl enable xrdp
sudo systemctl start xrdp
```

Configure the firewall. RDP uses port 3389. Allow traffic on this port through Ubuntu's firewall (ufw):
```sh
sudo ufw allow 3389
```

Restart the xrdp service.
```sh
sudo systemctl restart xrdp
```

## On the client machine (Windows, macOS, or Linux)

Use your RDP client to connect to the Ubuntu machine's IP address.
Windows: Search for "Remote Desktop Connection" in the Start menu.
macOS: Download the "Microsoft Remote Desktop" app from the App Store.
Linux: Use a client like remmina.
At the xrdp login screen, make sure "Xorg" is selected as the session type.
Enter the `username` and `password` for your Ubuntu account and click "OK". 
