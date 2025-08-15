# Ubuntu 24.04 开发环境搭建新手指南

## 目录
1. [Ubuntu-24.04](#ubuntu-2404)
2. [Ubuntu-24.04的基本设置](#ubuntu-2404的基本设置)
3. [github使用指南](#github使用指南)
4. [pico开发环境搭建](#pico开发环境搭建)
5. [STM32开发环境搭建](#stm32开发环境搭建)
6. [Anaconda环境搭建](#anaconda环境搭建)
7. [PyTorch环境搭建](#pytorch环境搭建)
8. [Darknet环境搭建](#darknet环境搭建)
9. [网络浏览器，VPN](#网络浏览器vpn)
10. [常用开发软件介绍](#常用开发软件介绍)

---

## Ubuntu-24.04
### 功能说明  
安装最新版本的 Ubuntu 以作为开发环境基础系统。

### 准备工作
1. 从[Ubuntu官网](https://ubuntu.com/download/desktop)下载 Ubuntu 24.04 LTS ISO 镜像
2. 制作启动U盘（推荐使用[Rufus](https://rufus.ie/)或[BalenaEtcher](https://www.balena.io/etcher/)）
3. 备份重要数据

### 安装步骤
1. 插入启动U盘并重启电脑，进入BIOS/UEFI设置U盘为第一启动项
2. 选择"Install Ubuntu"
3. 分区建议：
   - EFI分区：512MB（如已存在可忽略）
   - 交换空间：内存大小的1-2倍（可选）
   - 根分区`/`：至少50GB（推荐100GB以上）
   - 家目录`/home`：剩余空间
4. 设置用户名、密码和计算机名
5. 完成安装后重启

### 首次启动检查
```bash
# 检查系统信息
lsb_release -a
# 检查磁盘空间
df -h
```
### 基本终端指令
```bash
# 查看当前目录
pwd
# 列出目录内容
ls
ls -l         # 列出详细信息
ls -a         # 显示隐藏文件

#切换目录
cd /path/to/directory
cd ..         # 返回上一级
cd ~          # 回到用户主目录

#创建目录和文件
mkdir new_folder
touch file.txt
#复制、移动、删除
cp source.txt dest.txt     # 复制文件
mv old.txt new.txt         # 移动或重命名
rm file.txt                # 删除文件
rm -r folder_name          # 删除目录及内容

#文件查看与编辑
cat file.txt
less file.txt
head file.txt     # 查看前10行
tail file.txt     # 查看最后10行
nano file.txt     # 终端文本编辑器
vim file.txt      # 高级文本编辑器

#系统信息与管理
whoami                    #查看当前用户
uname -a                  #查看系统信息
lsb_release -a            
df -h                     #查看磁盘空间
free -h                   #查看内存使用
sudo apt update           # 更新软件列表
sudo apt upgrade -y       # 更新已安装软件
sudo apt install package  # 安装软件
sudo apt remove package   # 卸载软件

#权限管理
ls -l                               #查看文件权限
chmod 755 file.txt                  #修改文件权限
sudo chown user:group file.txt      #修改文件所有者
```
---

## Ubuntu 24.04 的基本设置
### 说明  
基本设置和软件安装可以直接运行脚本
new_ubuntu_enviroment_setup.sh

### 常用设置
```bash
# 更新系统
sudo apt update && sudo apt upgrade -y

# 安装中文支持
sudo apt install language-pack-zh-hans -y

# 设置时区
sudo timedatectl set-timezone Asia/Shanghai
```

---

## github使用指南
### 说明 
Git 是最常用的版本控制工具，用于管理代码和协作开发。 开始前请先注册github账号

### 安装
1.安装git
```sh
sudo apt update
sudo apt install git -y
git --version
```
2.基本设置
第一次使用 Git 时，需要设置用户名和邮箱，以便提交记录中显示
```sh
# 设置全局用户名
git config --global user.name "你的用户名"
# 设置全局邮箱
git config --global user.email "你的邮箱@example.com"
# 查看配置
git config --list
```
3.常用指令
```sh
# 克隆仓库
git clone https://github.com/用户名/仓库名.git
# 添加修改暂存区
git add 文件名       # 添加单个文件
git add .           # 添加当前目录下所有修改
# 提交修改
git commit -m "提交说明"
#推送到github
git push origin 分支名
#拉取更新
git pull origin 分支名
#分支管理
# 查看本地分支
git branch
# 创建新分支
git branch 新分支名
# 切换分支
git checkout 分支名
# 合并分支
git merge 分支名
# 删除本地分支
git branch -d 分支名
# 删除远程分支
git push origin --delete 分支名
```
---

## pico开发环境搭建
### 说明 
可调用pico官方库进行开发。

### 安装
1.安装构建工具  
```sh
sudo apt-get install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi build-essential
sudo apt-get install pkg-config libusb-1.0-0-dev
```
2.按以下目录结构获取源码
Get the source with the following directory structure:
```sh
screw_drive_unit_pico/
  |->pico-sdk/
  |->pico-examples/
  |->screw_drive_unit_pico/
```
3.更新子模块
```sh
git submodule update --init
cd pico-sdk
git submodule update --init
```
4.设置用户环境变量，并将 $HOME 修改为你仓库的路径:
```sh
cd ~
echo "export PICO_SDK_PATH=$HOME/(to your directory path)/screw_drive_unit_pico/pico-sdk" >> ~/.bashrc
. ~/.bashrc
```
### 使用方法
1.构建方法
```sh
cd ~/screw_drive_unit_pico/screw_drive_unit_pico
mkdir build
cd build
cmake .. -DPICO_BOARD=pico_w -DCMAKE_BUILD_TYPE=Release
make
```
2.加载程序方法
按住 Pico 系列设备上的 BOOTSEL 按钮，同时用 Micro USB 数据线将其连接到开发电脑，以强制进入 USB 大容量存储模式。
将 build 文件夹中的 main.uf2 文件复制到 USB 大容量存储设备中。
---

## STM32开发环境搭建
### 说明 
安装 STM32 单片机开发所需的工具链与 IDE。

### 安装
```bash
# 安装 ARM 工具链
sudo apt install gcc-arm-none-eabi gdb-multiarch -y

# 下载 STM32CubeIDE
wget https://www.st.com/en/development-tools/stm32cubeide.html
# 按官网指引安装
```

### 常用辅助工具
- `st-flash`（烧录工具）
```bash
sudo apt install stlink-tools -y
```

---

## Anaconda环境搭建
### 说明
提供 Python 科学计算与机器学习开发环境。可为每个项目设置独立的运行环境

### 安装步骤
1.访问 Anaconda 官网，选择 “Linux”→“64-bit (x86_64)”，复制下载链接​
2.终端执行：
```bash
wget https://repo.anaconda.com/archive/Anaconda3-2024.02-Linux-x86_64.sh
bash Anaconda3-2024.02-Linux-x86_64.sh
```
### 初始化
```bash
source ~/.bashrc
conda create -n dev python=3.10 -y
conda activate dev
```

---

## PyTorch 环境搭建
### 说明
安装 PyTorch 以进行深度学习开发。

### 安装步骤
1.激活 Anaconda 环境
2.安装 PyTorch（GPU 版本，需先安装 NVIDIA 驱动和 CUDA）
3.访问 PyTorch 官网，选择配置：​
“PyTorch Build”：Stable (2.3.1)​
“Your OS”：Linux​
“Package”：Conda​
“Language”：Python​
“Compute Platform”：CUDA xx.x（需要安装NVIDIA 驱动、NVIDIA CUDA 工具包）

```bash
# 提供有无cuda两种版本选择
conda install pytorch torchvision torchaudio pytorch-cuda=12.1 -c pytorch -c nvidia
conda install pytorch torchvision torchaudio cpuonly -c pytorch
```

**验证：**
```bash
python -c "import torch; print(torch.cuda.is_available())"
```

---

## Darknet环境搭建
### 功能说明
一个使用C/C++语言的CNN神经网络框架,可运行其中的yolo神经网络进行图像识别。

### 安装步骤
1.从github中拉取资源并编译
```bash
git clone https://github.com/pjreddie/darknet.git
cd darknet
make
```
2.根据官网进行基本设置https://pjreddie.com/darknet/
3.验证 Darknet
```bash
# 下载预训练权重（YOLOv3）​
wget https://pjreddie.com/media/files/yolov3.weights​
# 测试目标检测（检测一张图片）​
./darknet detect cfg/yolov3.cfg yolov3.weights data/dog.jpg
```
---

## 网络浏览器，VPN
### 功能说明
安装网络访问与科学上网工具。

### 浏览器安装
1.自带浏览器：系统默认安装 Firefox，可直接使用（支持 Chrome 插件，在 “附加组件” 中安装）​
2.安装 Chrome（推荐）：
```bash
cd ~/Downloads​
wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb
sudo dpkg -i google-chrome-stable_current_amd64.deb​
# 若提示依赖错误，执行：​
sudo apt -f install -y
```

## VPN 建议
- Clash Verge
- v2ray / xray-core

---

## 常用开发软件介绍
###说明 
推荐常用的开发工具与编辑器。

### VSCode（推荐，全功能编辑器）
1.安装 VSCode
图形化方式（新手推荐）：打开 “Ubuntu Software”（应用商店），搜索 “Visual Studio Code”，点击 “Install”
命令行方式：​
```bash
wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > packages.microsoft.gpg
sudo install -D -o root -g root -m 644 packages.microsoft.gpg /etc/apt/trusted.gpg.d/
sudo sh -c 'echo "deb [arch=amd64,arm64,armhf signed-by=/etc/apt/trusted.gpg.d/packages.microsoft.gpg] https://packages.microsoft.com/repos/code stable main" > /etc/apt/sources.list.d/vscode.list'
rm -f packages.microsoft.gpg
sudo apt update
sudo apt install -y code
```
2.VSCode 新手必备插件
打开 VSCode，点击左侧 “Extensions”（图标：方块），搜索安装以下插件：​
-C/C++：微软官方插件，支持 C/C++ 编译调试​
-Python：微软官方插件，支持 Python 语法高亮、调试​
-Git Graph：可视化 Git 提交历史​
-Chinese (Simplified)：中文界面（安装后按Ctrl+Shift+P，输入 “Configure Display Language” 选择中文）​
-Code Runner：右键一键运行代码（支持多语言）​

3.基础使用​
-打开文件夹：点击 “文件”→“打开文件夹”，选择项目目录​
-运行代码：安装 “Code Runner” 后，点击代码右上角 “▶️” 按钮​
-调试代码：按F5，选择对应的调试环境（如 “Python”“C++”）​

### Sublime Text（轻量级编辑器）
1.安装 Sublime Text
```bash
# 添加Sublime源​
wget -qO - https://download.sublimetext.com/sublimehq-pub.gpg | gpg --dearmor | sudo tee /etc/apt/trusted.gpg.d/sublimehq-archive.gpg > /dev/null​
echo "deb https://download.sublimetext.com/ apt/stable/" | sudo tee /etc/apt/sources.list.d/sublime-text.list​
# 安装​
sudo apt update​
sudo apt install -y sublime-text​
```
### Octave（MATLAB 替代品，数值计算）
1.安装 Octave
```bash
sudo apt update
sudo apt install octave -y
#启动
octave --gui
octave
```
2.基础使用
-简单计算
2 + 3        % 加法
5 - 2        % 减法
4 * 3        % 乘法
8 / 2        % 除法
2^3          % 乘方
-变量与矩阵
a = 5;       % 定义变量
b = [1, 2, 3];  % 行向量
c = [1; 2; 3];  % 列向量
A = [1 2; 3 4]; % 2x2 矩阵

-基本矩阵运算
B = A';       % 转置
C = A * A;    % 矩阵乘法
D = A .* A;   % 元素逐个乘

-常用函数
sum(b)       % 求和
mean(b)      % 平均值
max(b)       % 最大值
min(b)       % 最小值
size(A)      % 矩阵大小
eye(3)       % 3x3 单位矩阵
zeros(2,3)   % 2x3 全零矩阵
ones(2,3)    % 2x3 全一矩阵

-绘图
x = 0:0.1:2*pi;
y = sin(x);

plot(x, y)         % 绘制折线图
title('正弦曲线')
xlabel('x')
ylabel('sin(x)')
grid on
plot(x, cos(x), 'r--')  % 红色虚线
hold on                  % 保留当前图
plot(x, sin(x), 'b:')   % 蓝色点线
legend('cos','sin')     % 图例

-函数定义
function y = square_sum(a, b)
    y = a^2 + b^2;
end

result = square_sum(3,4)

-脚本运行
保存脚本文件：example.m
运行脚本：
example

-常用技巧
在 Octave 命令行中使用 help 函数名 查看函数用法
使用 clc 清屏，clear 清除变量，close all 关闭所有图形窗口
支持 MATLAB 大部分语法，可直接运行 .m 文件

### VSCode使用 LaTeX 指南(用于论文格式编排)
1.安装 LaTeX
在 Ubuntu 24.04 上推荐使用 TeX Live：
```bash
sudo apt update
sudo apt install texlive-full -y
```
2.打开 VSCode，安装插件

3.配置 LaTeX Workshop
-打开 settings.json（Ctrl+, → 搜索 settings.json → 编辑 JSON）
-添加或修改配置

4.编写 LaTeX 文档
-新建文件 example.tex
-输入示例内容：
\documentclass[12pt]{article}
\usepackage[UTF8]{ctex} % 支持中文
\usepackage{amsmath, amssymb}

\title{LaTeX 测试文档}
\author{作者姓名}
\date{\today}

\begin{document}
\maketitle

\section{简介}
这是一个使用 VSCode 和 LaTeX Workshop 编写的示例文档。

\section{数学公式}
行内公式示例：$E=mc^2$。

独立公式示例：
\[
\int_0^\infty e^{-x} dx = 1
\]

\end{document}

5.编译与预览
可直接在vscode中运行代码进行预览，或安装第三方预览软件

---

**欢迎加入山西乌金山男子职业技术学校**

