Build from Source
1. Install Dependencies
```sh
sudo apt-get update && sudo apt-get upgrade -y
sudo apt-get install -y git cmake libssl-dev libusb-1.0-0-dev pkg-config libgtk-3-dev \
     libglfw3-dev libgl1-mesa-dev libglu1-mesa-dev python3-dev python3-pip
```

3. Clone librealsense Repository
```sh
git clone https://github.com/IntelRealSense/librealsense.git
cd librealsense
```

4. Prepare Kernel Modules (For USB Permissions)
```sh
./scripts/setup_udev_rules.sh
```

5. Build and Install
```sh
mkdir build && cd build
cmake .. -DBUILD_EXAMPLES=true -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
sudo make install
```

6. Rebuild Kernel Modules (if needed)
If the camera isn’t detected:
```sh
cd ../scripts/
./patch-realsense-ubuntu-lts.sh  # Applies kernel patches for Ubuntu LTS
```

Post-Installation Checks
Check Device Recognition:
```sh
lsusb | grep "Intel(R) RealSense"
```

Run the Viewer:
```sh
realsense-viewer
```
