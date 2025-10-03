#!/bin/bash
set -e

echo "========================================="
echo "  ServerManager Ubuntu 环境配置脚本"
echo "  Ubuntu 22.04 LTS"
echo "========================================="
echo ""

# 检查是否为 root
if [[ $EUID -eq 0 ]]; then
   echo "⚠️  请不要使用 sudo 运行此脚本"
   echo "   脚本会在需要时提示输入密码"
   exit 1
fi

# 更新包索引
echo "[1/6] 更新包索引..."
sudo apt update

# 安装构建工具
echo "[2/6] 安装构建工具 (CMake, GCC, Ninja)..."
sudo apt install -y cmake build-essential ninja-build

# 安装 Qt 6 开发包
echo "[3/6] 安装 Qt 6 开发环境..."
echo "❗注意: 若为 WSL Ubuntu，且 Windows 已安装 MySQL，3306端口会被 Windows 占用"
echo "WSL 请先在 Windows PS 上运行: "
echo "  netstat -ano | findstr 3306"
echo "  netstat -ano | findstr 33060"
echo "查看 3306/33060 端口是否被占用"
sudo apt install -y \
    qt6-base-dev \
    qt6-base-dev-tools \
    libqt6charts6-dev \
    libqt6serialport6-dev \
    libqt6sql6-mysql \
    qmake6 \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    libxkbcommon-dev

# 安装 MySQL
echo "[4/6] 安装 MySQL 数据库..."
sudo apt install -y mysql-server mysql-client libmysqlclient-dev

# 启动 MySQL
echo "[5/6] 启动 MySQL 服务..."
sudo systemctl start mysql
sudo systemctl enable mysql

# 验证安装
echo "[6/6] 验证安装..."
echo ""
echo "✅ CMake: $(cmake --version | head -1)"
echo "✅ GCC: $(g++ --version | head -1)"
echo "✅ Qt6: $(qmake6 --version 2>&1 | grep "Qt version" || echo "请检查 /usr/lib/qt6/bin/qmake")"
echo "✅ MySQL: $(sudo systemctl is-active mysql)"

echo ""
echo "========================================="
echo "  ✅ 基础环境安装完成!"
echo "========================================="
echo ""
echo "📋 接下来的手动步骤:"
echo ""
echo "1️⃣  配置 MySQL 安全设置:"
echo "   sudo mysql_secure_installation"
echo ""
echo "2️⃣  创建数据库 (使用 root 权限):"
echo "   sudo mysql -u root -p < /path/to/init.sql"
echo "   或参考文档手动创建"
echo ""
echo "3️⃣  修改 CMakeLists.txt (移除 Windows 路径):"
echo "   编辑 ServerManager/CMakeLists.txt"
echo "   注释掉: set(CMAKE_PREFIX_PATH \"D:/...\")"
echo ""
echo "4️⃣  构建项目:"
echo "   cd ServerManager"
echo "   mkdir -p build && cd build"
echo "   cmake .."
echo "   make -j\$(nproc)"
echo ""
echo "5️⃣  运行程序:"
echo "   ./ServerManager"
echo ""
echo "📖 详细文档: claudedocs/ubuntu_setup_guide.md"
echo ""
