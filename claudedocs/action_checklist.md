# ServerManager 重构行动清单

## 🎯 优先级 P0 - 立即修复 (安全性)
- [ ] 移除硬编码数据库密码 (mainwindow.cpp:47) → 使用环境变量 `DB_PASSWORD`
- [ ] 修复 SQL 注入漏洞 (addwindow.cpp:19-20) → 使用 `QSqlQuery::prepare()` 参数化查询
- [ ] 资源路径改用 Qt 资源系统 `:/` 替代硬编码相对路径 `../`

## 📁 优先级 P1 - 目录结构重组 (1周)
- [ ] 创建分层目录: `src/{models, services, controllers, views, utils}/`
- [ ] 移动现有文件到对应目录: `views/windows/`, `views/delegates/`
- [ ] 创建 `include/servermanager/` 公共头文件目录
- [ ] 添加命名空间: `namespace ServerManager { namespace Models/Services/Controllers/Views }`

## 🏗️ 优先级 P2 - 架构解耦 (2-3周)
- [ ] **数据层**: 创建 `Server.h/cpp`, `Task.h/cpp` 独立模型类
- [ ] **数据访问层**: 实现 `DatabaseManager`, `ServerRepository`, `TaskRepository`
- [ ] **业务逻辑层**: 提取 `TaskScheduler`, `ResourceAllocator` 服务类
- [ ] **控制器层**: 创建 `DashboardController` 协调 UI 和业务逻辑
- [ ] **视图层**: 重构窗口类,移除所有数据库和业务逻辑代码

## 🔧 优先级 P3 - 配置与工具 (1周)
- [ ] 创建 `resources/config/database.ini` 外部配置文件
- [ ] 实现 `Config` 类加载配置
- [ ] 实现 `Logger` 结构化日志系统
- [ ] 定义 `Constants.h` 消除魔法数字 (0.8, 0.98, 500ms, 2000ms 等)

## 📊 优先级 P4 - 代码质量 (持续)
- [ ] 统一命名规范: 类 `PascalCase`, 成员 `m_camelCase`, 函数 `camelCase`
- [ ] 添加错误处理: Repository 返回 `Result<T>` 或 `std::optional<T>`
- [ ] 实现 CMake 子项目组织: 每个模块独立 `CMakeLists.txt`

## 🧪 优先级 P5 - 测试支持 (后期)
- [ ] 创建 `tests/` 目录结构
- [ ] 为 Models 和 Services 编写单元测试
- [ ] 配置 Qt Test 框架和 CTest 集成

---
**总计**: 24 项核心任务 | **预计时间**: 6-8周 | **优先级**: P0 → P1 → P2 → P3 → P4 → P5
