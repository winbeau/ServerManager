## 编译

```bash
mkdir build && cd build        # 1️⃣ 创建独立构建目录
cmake ../                      # 2️⃣ 配置项目，生成 Makefile 或 Ninja 文件
make -j$(nproc)                # 3️⃣ 编译项目，使用所有 CPU 核心
```

## 运行
```bash
./ServerManager
```
