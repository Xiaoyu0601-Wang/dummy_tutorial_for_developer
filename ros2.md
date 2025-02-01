# ROS2

## Installation By Script
Make executable:
`chmod +x install_ros2.sh`
Run with:
`./install_ros2.sh`

## Installation Step By Step
Reference: https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debs.html
```sh
sudo apt install software-properties-common
sudo add-apt-repository universe

sudo apt update && sudo apt install curl -y
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg

echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null

sudo apt update
sudo apt upgrade
sudo apt install ros-humble-desktop
sudo apt install ros-dev-tools

echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
. ~/.bashrc
```

### Install colcon
```sh
sudo apt install python3-colcon-common-extensions
# test
mkdir -p ~/ros2_ws/src
cd ros2_ws/
colcon build
```

## ROS Related Command
Check whether ROS2 is installed correctly or not:
```sh
ros2 --version
```
