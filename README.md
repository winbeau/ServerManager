# ServerManager

## 介绍
ServerManager 是一个服务器管理工具，提供服务器信息展示、任务分配、资源监控等功能。该工具基于 Qt 开发，具备图形化界面，便于用户直观地查看和管理服务器状态。

## 软件架构
本项目采用 C++ 编写，使用 Qt 框架进行界面开发。主要模块包括：
- **主窗口 (mainwindow)**：提供系统导航和服务器概览。
- **添加窗口 (addwindow)**：用于添加新的服务器信息。
- **仪表盘窗口 (boardwindow)**：展示服务器资源使用情况（CPU、内存、GPU）及任务分布。
- **模拟窗口 (imitatewindow)**：模拟生成随机服务器和任务数据。

## 安装教程
1. 确保已安装 Qt 开发环境（推荐 Qt 6.x）。
2. 使用 CMake 构建项目：
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```
3. 运行生成的可执行文件 `ServerManager.exe`。

## 使用说明
- **添加服务器**：点击主界面“添加”按钮，填写服务器信息并保存。
- **查看仪表盘**：点击“仪表盘”按钮，实时查看服务器资源使用情况。
- **模拟数据**：在“模拟”界面生成随机服务器和任务数据，用于测试和演示。

## 参与贡献
欢迎贡献代码！请遵循以下步骤：
1. Fork 本仓库。
2. 创建新分支 (`git checkout -b feature/new-feature`)。
3. 提交代码 (`git commit -am 'Add new feature'`)。
4. Push 到分支 (`git push origin feature/new-feature`)。
5. 提交 Pull Request。

## 特技
- 实时资源监控与可视化。
- 支持模拟生成测试数据。
- 简洁直观的图形用户界面。

MIT License，请参阅 LICENSE 文件获取详细信息
