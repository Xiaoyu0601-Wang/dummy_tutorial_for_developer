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
Enable SSH shell color output, add these lines to `~/.bashrc`:
```sh
alias ls='ls --color=auto'  # Linux
alias ls='ls -G'            # macOS
export CLICOLOR=1           # macOS 启用颜色
export LSCOLORS="ExGxFxdaCxDaDahbadacec"  # macOS 颜色方案
alias grep='grep --color=auto'
export TERM=xterm-256color
export PS1='\[\e[1;32m\]\u@\h:\w\$\[\e[0m\] '  # 绿色提示符
```

## Install Texstudio and texlive
### Installation
```sh
# Install Texstudio editor in snap store, then install texlive from terminal:
sudo apt-get install texlive-full
# Pregenerating ConTeXt MarkIV format. This may take some time...
# Keep pressing the key Return about 10 times and the install went on.
```
### Interface Config
#### Load config file

Go to menu bar -> Click in `Options`  -> Click on `Load Profile...`


#### Dark IDE

Firstly, this repo was intended for only helping to replace the text editor colors but as soon as I realize that `TeXstudio` have various dark IDE themes I decided to add it.  
Basically you could only change the text editor colors or change the text editor colors + the IDE theme  
To change to the dark IDE theme:

1. Go to menu bar -> Click in `Options`  -> Click on `Configure TeXstudio...`
2. In the Configure TeXstudio window clic on `General` tab.
3. In the `Appereance` group choose the style of your preference
4. In `Color Scheme` select `Modern - dark`
5. Clic OK, most times no need to restart TeXstudio
6. If TeXstudio does not look full dark repeat step 1 and continue with the next steps, if does restart TeXstudio
7. In the left-bottom corner mark the `Show Advanced Options` checkbox
8. In the `General` tab, in the `Appereance` group mark the `Ignore Most System Colors` checkbox
9. Restart TeXstudio

Now we can proceed to change the text editor colors.

## OpenGL
### Install Basic OpenGL Packages
```sh
sudo apt update
sudo apt install mesa-utils libgl1-mesa-dev libglu1-mesa-dev freeglut3-dev
```

### Verify Installation
Check if OpenGL is working:
```sh
glxinfo | grep "OpenGL version"
```
