# Ubuntu 环境配置清单 - ServerManager 项目

## 📋 当前系统状态检测结果

**系统**: Ubuntu 22.04.5 LTS
**编译器**: ✅ g++ 11.4.0 已安装
**CMake**: ❌ 未安装
**Qt**: ⚠️ 只有 Qt 5.15.2 (Anaconda)，项目需要 Qt 6.5.3+
**数据库**: ❌ MySQL/MariaDB 未安装或未运行

---

## 🔧 必需依赖安装步骤

### 1. 安装 CMake 和基础构建工具

```bash
sudo apt update
sudo apt install -y cmake build-essential ninja-build
```

验证安装:
```bash
cmake --version  # 应显示 3.22+ 版本
```

### 2. 安装 Qt 6 开发环境

#### 方案 A: 使用 Ubuntu 仓库 (推荐 - 快速但版本可能较旧)

```bash
# 安装 Qt 6 核心包
sudo apt install -y \
    qt6-base-dev \
    qt6-base-dev-tools \
    libqt6core6 \
    libqt6gui6 \
    libqt6widgets6 \
    libqt6network6 \
    libqt6sql6 \
    libqt6sql6-mysql \
    libqt6charts6-dev \
    qmake6 \
    qt6-qmake

# 安装 Qt 6 Charts 模块
sudo apt install -y qt6-charts-dev

# 安装 Qt 6 Serial Port 模块 (如果需要)
sudo apt install -y qt6-serialport-dev
```

验证安装:
```bash
qmake6 --version
# 或
/usr/lib/qt6/bin/qmake --version
```

#### 方案 B: 使用官方在线安装器 (推荐 - 获取最新版本)

```bash
# 下载 Qt 在线安装器
wget https://download.qt.io/official_releases/online_installers/qt-unified-linux-x64-online.run

# 添加执行权限
chmod +x qt-unified-linux-x64-online.run

# 运行安装器 (需要 Qt 账户)
./qt-unified-linux-x64-online.run
```

安装时选择组件:
- [x] Qt 6.5.3 或更高版本
- [x] Desktop gcc 64-bit
- [x] Qt Charts
- [x] Qt Network
- [x] Qt SQL
- [x] Qt Serial Port

安装后设置环境变量:
```bash
# 添加到 ~/.bashrc 或 ~/.zshrc
export Qt6_DIR="$HOME/Qt/6.5.3/gcc_64"
export PATH="$Qt6_DIR/bin:$PATH"
export LD_LIBRARY_PATH="$Qt6_DIR/lib:$LD_LIBRARY_PATH"

# 立即生效
source ~/.bashrc
```

### 3. 安装 MySQL 数据库

```bash
# 安装 MySQL Server
sudo apt install -y mysql-server mysql-client libmysqlclient-dev

# 启动 MySQL 服务
sudo systemctl start mysql
sudo systemctl enable mysql

# 检查服务状态
sudo systemctl status mysql
```

### 4. 配置 MySQL 数据库

```bash
# 运行安全配置脚本
sudo mysql_secure_installation
```

配置向导:
- 设置 root 密码 (建议与代码中的 `@Geralt123` 一致，或修改代码)
- 移除匿名用户: Yes
- 禁止 root 远程登录: Yes (本地开发)
- 删除测试数据库: Yes
- 重新加载权限表: Yes

### 5. 创建项目数据库

```bash
# 登录 MySQL
sudo mysql -u root -p
```

在 MySQL 提示符下执行:
```sql
-- 创建数据库
CREATE DATABASE servers CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;

-- 创建用户 (如果需要)
CREATE USER 'root'@'localhost' IDENTIFIED BY '@Geralt123';

-- 授予权限
GRANT ALL PRIVILEGES ON servers.* TO 'root'@'localhost';
FLUSH PRIVILEGES;

-- 验证
USE servers;

-- 创建服务器表
CREATE TABLE IF NOT EXISTS sta (
    id VARCHAR(50) PRIMARY KEY,
    ip VARCHAR(15) NOT NULL,
    port INT NOT NULL,
    cpu INT NOT NULL,
    gpu INT NOT NULL,
    disk INT NOT NULL,
    bandwidth INT NOT NULL,
    free_cpu INT NOT NULL,
    free_gpu INT NOT NULL,
    free_disk INT NOT NULL,
    free_bandwidth INT NOT NULL,
    status TINYINT(1) DEFAULT 0,
    power INT DEFAULT 0,
    total_weight INT GENERATED ALWAYS AS (cpu + gpu + disk + bandwidth) STORED
);

-- 创建任务表
CREATE TABLE IF NOT EXISTS task (
    id VARCHAR(50) PRIMARY KEY,
    cpu INT NOT NULL,
    gpu INT NOT NULL,
    disk INT NOT NULL,
    bandwidth INT NOT NULL,
    start BIGINT NOT NULL,
    during BIGINT NOT NULL,
    status TINYINT(1) DEFAULT 0
);

-- 创建备用表 (如果需要)
CREATE TABLE IF NOT EXISTS sers (
    id VARCHAR(50) PRIMARY KEY,
    ip VARCHAR(15) NOT NULL,
    port INT NOT NULL
);

-- 退出
EXIT;
```

### 6. 安装额外开发依赖

```bash
# OpenGL 开发库 (Qt 可能需要)
sudo apt install -y libgl1-mesa-dev libglu1-mesa-dev

# X11 开发库 (Linux GUI)
sudo apt install -y libx11-dev libxext-dev libxfixes-dev libxi-dev libxrender-dev libxcb1-dev libx11-xcb-dev libxcb-glx0-dev

# 字体库
sudo apt install -y libfontconfig1-dev libfreetype6-dev

# 其他可选但推荐的包
sudo apt install -y libxkbcommon-dev libxkbcommon-x11-dev
```

---

## 🔨 项目构建配置

### 修改 CMakeLists.txt

编辑 `/home/winbeau/ServerManager/CMakeLists.txt`:

```cmake
cmake_minimum_required(VERSION 3.16)  # Ubuntu 22.04 自带 3.22
project(ServerManager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# 移除或注释掉 Windows 特定路径
# set(CMAKE_PREFIX_PATH "D:/QtStructure/6.5.3/mingw_64")

# Linux 上 Qt 6 自动检测 (如果使用 apt 安装)
# 或手动指定 Qt6_DIR (如果使用官方安装器)
# set(CMAKE_PREFIX_PATH "$ENV{HOME}/Qt/6.5.3/gcc_64")

set(SRC_DIR "./src")
set(RES_FILES "${CMAKE_SOURCE_DIR}/resources/resources.qrc")

file(GLOB FILES "${SRC_DIR}/*.*")

find_package(Qt6 COMPONENTS
    Core
    Gui
    Widgets
    Network
    SerialPort
    Sql
    Charts
    REQUIRED
)

qt_add_resources(RESOURCES_SRCS ${RES_FILES})

add_executable(ServerManager
    ${FILES}
    ${RESOURCES_SRCS}
)

target_link_libraries(ServerManager
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Network
    Qt6::SerialPort
    Qt6::Sql
    Qt6::Charts
)

# 移除 Windows 特定的 DLL 复制逻辑
# Linux 上通过 LD_LIBRARY_PATH 或系统库路径解决
```

### 构建项目

```bash
cd /home/winbeau/ServerManager

# 创建构建目录
mkdir -p build
cd build

# 配置项目 (方案 A: 使用系统 Qt6)
cmake ..

# 或 (方案 B: 使用官方 Qt6)
cmake -DCMAKE_PREFIX_PATH="$HOME/Qt/6.5.3/gcc_64" ..

# 编译
cmake --build . -j$(nproc)

# 或使用 make
make -j$(nproc)
```

### 运行项目

```bash
# 确保在 build 目录
cd /home/winbeau/ServerManager/build

# 设置数据库密码环境变量 (如果已按建议重构)
export DB_PASSWORD="@Geralt123"

# 运行程序
./ServerManager
```

---

## ⚠️ 常见问题排查

### 问题 1: Qt6 找不到

**症状**: `CMake Error: Could not find a package configuration file provided by "Qt6"`

**解决方案**:
```bash
# 方案 A: 设置 CMAKE_PREFIX_PATH
export CMAKE_PREFIX_PATH="/usr/lib/x86_64-linux-gnu/cmake/Qt6"

# 方案 B: 使用 Qt6_DIR
export Qt6_DIR="$HOME/Qt/6.5.3/gcc_64/lib/cmake/Qt6"

# 重新运行 cmake
cmake ..
```

### 问题 2: MySQL 连接失败

**症状**: `database not connected` 错误

**检查步骤**:
```bash
# 1. 检查 MySQL 服务
sudo systemctl status mysql

# 2. 测试连接
mysql -u root -p@Geralt123 -e "USE servers; SHOW TABLES;"

# 3. 检查防火墙
sudo ufw status

# 4. 查看 MySQL 错误日志
sudo tail -f /var/log/mysql/error.log
```

### 问题 3: libQt6Charts.so 找不到

**症状**: 运行时 `error while loading shared libraries: libQt6Charts.so.6`

**解决方案**:
```bash
# 安装 Charts 库
sudo apt install -y qt6-charts-dev libqt6charts6

# 或添加库路径
export LD_LIBRARY_PATH="$HOME/Qt/6.5.3/gcc_64/lib:$LD_LIBRARY_PATH"
```

### 问题 4: 图标资源加载失败

**症状**: 图标不显示，控制台警告 `pixmap is null`

**原因**: 硬编码路径 `../icons/logo.png` 在 Linux 上可能不工作

**临时解决**:
```bash
# 创建符号链接
cd /home/winbeau/ServerManager/build
ln -s ../icons icons
```

**永久解决**: 使用 Qt 资源系统 (参考优化建议文档)

---

## 📝 快速安装脚本 (一键安装)

创建 `setup_ubuntu.sh`:

```bash
#!/bin/bash
set -e

echo "=== ServerManager Ubuntu 环境配置脚本 ==="

# 更新包索引
echo "[1/5] 更新包索引..."
sudo apt update

# 安装构建工具
echo "[2/5] 安装构建工具..."
sudo apt install -y cmake build-essential ninja-build

# 安装 Qt 6
echo "[3/5] 安装 Qt 6 开发包..."
sudo apt install -y \
    qt6-base-dev \
    qt6-base-dev-tools \
    libqt6charts6-dev \
    qt6-serialport-dev \
    libqt6sql6-mysql \
    qmake6

# 安装 MySQL
echo "[4/5] 安装 MySQL..."
sudo apt install -y mysql-server mysql-client libmysqlclient-dev

# 启动 MySQL
echo "[5/5] 启动 MySQL 服务..."
sudo systemctl start mysql
sudo systemctl enable mysql

echo ""
echo "✅ 基础环境安装完成!"
echo ""
echo "接下来请手动执行:"
echo "1. sudo mysql_secure_installation  # 配置 MySQL"
echo "2. 创建数据库和表 (参考文档中的 SQL)"
echo "3. cd /home/winbeau/ServerManager/build && cmake .. && make"
echo ""
```

运行脚本:
```bash
chmod +x setup_ubuntu.sh
./setup_ubuntu.sh
```

---

## ✅ 验证清单

安装完成后，按顺序验证:

- [ ] `cmake --version` 显示 3.16+
- [ ] `g++ --version` 显示 11.x
- [ ] `qmake6 --version` 或 `/usr/lib/qt6/bin/qmake --version` 显示 Qt 6.x
- [ ] `sudo systemctl status mysql` 显示 active (running)
- [ ] `mysql -u root -p` 能成功登录
- [ ] `USE servers; SHOW TABLES;` 能看到 sta, task, sers 表
- [ ] `cd build && cmake ..` 配置成功
- [ ] `make` 编译成功
- [ ] `./ServerManager` 运行成功

---

**生成时间**: 2025-10-03
**系统**: Ubuntu 22.04 LTS (WSL2)
**目标**: 运行 ServerManager Qt 6 项目
