#!/bin/bash

# ROS 2 Installation Script (Supports Ubuntu 22.04/20.04)
# Author: AI Assistant | Last Updated: 2023-10-18

# Exit script immediately if any command fails
set -e

# Define color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Detect system version
UBUNTU_VERSION=$(lsb_release -sc)
ROS_VERSION=""

# Set corresponding ROS version
case $UBUNTU_VERSION in
    "noble")    # Ubuntu 24.04
        ROS_VERSION="jazzy"
        ;;
    "jammy")    # Ubuntu 22.04
        ROS_VERSION="humble"
        ;;
    *)
        echo -e "${RED}Error: Unsupported system version $UBUNTU_VERSION${NC}"
        echo "Supported versions: Ubuntu 24.04 (noble) or 22.04 (jammy)"
        exit 1
        ;;
esac

# User confirmation
echo -e "${YELLOW}About to install ROS 2 $ROS_VERSION on Ubuntu $UBUNTU_VERSION${NC}"
read -p "Continue? [Y/n] " -n 1 -r
echo
if [[ ! $REPLY =~ ^[Yy]$ ]]; then
    echo -e "${RED}Installation canceled${NC}"
    exit 0
fi

# Record start time
START_TIME=$(date +%s)

# Step 1: Configure locales
echo -e "${GREEN}[1/5] Configuring locales...${NC}"
# sudo apt update && sudo apt install -y locales
# sudo locale-gen en_US en_US.UTF-8
# sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
# export LANG=en_US.UTF-8

# Step 2: Add ROS 2 repository
echo -e "${GREEN}[2/5] Adding repository...${NC}"
sudo apt install software-properties-common
sudo add-apt-repository universe
sudo apt install -y curl
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $UBUNTU_VERSION main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null

# Step 3: Install ROS 2 packages
echo -e "${GREEN}[3/5] Installing ROS 2 packages...${NC}"
sudo apt update
sudo apt install -y ros-$ROS_VERSION-desktop

# Step 4: Install development tools
echo -e "${GREEN}[4/5] Installing development tools...${NC}"
sudo apt install ros-dev-tools
sudo apt install -y python3-rosdep python3-colcon-common-extensions
sudo rosdep init
rosdep update

# Step 5: Environment setup
echo -e "${GREEN}[5/5] Configuring environment...${NC}"
if ! grep -q "ROS 2 $ROS_VERSION" ~/.bashrc; then
    echo -e "\n# ROS 2 $ROS_VERSION Environment" >> ~/.bashrc
    echo "source /opt/ros/$ROS_VERSION/setup.bash" >> ~/.bashrc
    echo "source /usr/share/colcon_cd/function/colcon_cd.sh" >> ~/.bashrc
    echo "export _colcon_cd_root=/opt/ros/$ROS_VERSION/" >> ~/.bashrc
    # echo "export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp" >> ~/.bashrc
fi

# Calculate installation time
END_TIME=$(date +%s)
DURATION=$((END_TIME - START_TIME))

# Completion message
echo -e "\n${GREEN}✔ Successfully installed ROS 2 $ROS_VERSION${NC}"
echo -e "Duration: $((DURATION / 60))m $((DURATION % 60))s"
echo -e "\nNext steps:"
echo -e "1. Reload environment: ${YELLOW}source ~/.bashrc${NC}"
echo -e "2. Verify installation: ${YELLOW}printenv | grep ROS${NC}"
echo -e "3. Run demo nodes:"
echo -e "   - Terminal 1: ${YELLOW}ros2 run demo_nodes_cpp talker${NC}"
echo -e "   - Terminal 2: ${YELLOW}ros2 run demo_nodes_cpp listener${NC}"

exit 0