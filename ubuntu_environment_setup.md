## Github
### Github SSH PublicKey
Use the URL below to set the public key for SSH: https://docs.github.com/en/authentication
```sh
cd ~/.ssh
ssh-keygen -t rsa -f id_rsa_github
gedit ~/.ssh/id_rsa_github.pub
```

### Github Submodule
```sh
# Add submodule
git submodule add https://github.com/raspberrypi/pico-examples.git pico-examples
# Remove submodule
git rm --cached pico-examples
```

## ssh
### Install OpenSSH Server
SSH is not installed by default on Ubuntu Server, so you need to install it manually.
```sh
sudo apt-get update && sudo apt-get install openssh-server -y
# Once installed, verify that the SSH service is running:
sudo systemctl status ssh
# If the service is inactive, start and enable it:
sudo systemctl enable --now ssh
```
### Configure Firewall (If Enabled)
If UFW (Uncomplicated Firewall) is enabled, allow SSH connections:
```sh
sudo ufw allow ssh
sudo ufw enable   # Enable firewall if not already enabled
sudo ufw status   # Verify firewall rules
```
By default, SSH uses port 22. If you changed the port, allow that specific port instead:
```sh
sudo ufw delete allow 22/tcp  # Example if SSH is on port 2222
sudo ufw allow 2222/tcp  # Example if SSH is on port 2222
```

### Edit the SSH Configuration File
Open the SSH daemon config file using nano or your preferred text editor:
```sh
sudo nano /etc/ssh/sshd_config
# Uncomment it (remove #) and change 22 to your new port, e.g.:
# Port 22
```