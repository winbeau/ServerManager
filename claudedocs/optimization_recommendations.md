# ServerManager 项目优化建议

## 📋 执行摘要

本文档针对 ServerManager 项目的架构、模块划分和代码组织提供全面的优化建议。基于对现有代码的深入分析和 Qt 最佳实践研究,提出了改进项目可维护性、可扩展性和代码质量的具体方案。

---

## 🔍 现状分析

### 当前项目结构
```
ServerManager/
├── src/                    # 所有源代码文件混合存放
│   ├── *.cpp               # 实现文件
│   ├── *.h                 # 头文件
│   └── *.ui                # UI 设计文件
├── resources/              # 资源文件
├── icons/                  # 图标资源
└── CMakeLists.txt
```

### 主要问题识别

#### 1. **架构问题**
- ❌ **缺乏分层架构**: UI、业务逻辑、数据访问层混合在窗口类中
- ❌ **高耦合度**: 窗口类直接操作数据库,无法独立测试
- ❌ **职责不清**: 单个类承担多重职责(UI + 数据 + 业务逻辑)

#### 2. **代码组织问题**
- ❌ **目录结构扁平**: 所有文件放在同一个 `src/` 目录
- ❌ **命名不一致**: `mainwindow` vs `addwindow` vs `boardwindow`
- ❌ **缺少命名空间**: 全局作用域污染风险

#### 3. **依赖关系问题**
**依赖关系矩阵**:
```
mainwindow    → QSqlDatabase, QSqlTableModel, addwindow, boardwindow, imitatewindow
boardwindow   → QSqlDatabase, QSqlQuery (直接数据库操作)
addwindow     → QSqlQuery (直接 SQL 注入)
imitatewindow → QSqlQuery (直接数据库操作)
```

**问题**:
- 窗口类与数据库高度耦合
- 无法在不连接数据库的情况下测试 UI
- 业务逻辑分散在多个窗口类中

#### 4. **安全问题**
- 🚨 **硬编码数据库密码** (mainwindow.cpp:47)
- 🚨 **SQL 注入风险** (addwindow.cpp:19-20)
- 🚨 **资源路径硬编码** (mainwindow.cpp:13)

#### 5. **代码质量问题**
- **UI 逻辑混合**: 样式代码硬编码在 C++ 中 (mainwindow.cpp:115-169)
- **魔法数字**: 大量硬编码常量 (boardwindow.h:22-25)
- **缺少错误处理**: 数据库操作缺乏完善的错误处理
- **内存管理**: 使用 `new` 但依赖 Qt 父子关系管理内存

---

## 🏗️ 优化方案

### 一、目录结构重组

#### 推荐的 MVC 分层目录结构

```
ServerManager/
├── CMakeLists.txt
├── README.md
├── summary.md
│
├── include/                    # 公共头文件
│   └── servermanager/          # 项目命名空间
│       ├── models/
│       ├── views/
│       ├── controllers/
│       ├── services/
│       └── common/
│
├── src/                        # 源代码实现
│   ├── models/                 # 数据模型层
│   │   ├── server.h
│   │   ├── server.cpp
│   │   ├── task.h
│   │   ├── task.cpp
│   │   └── CMakeLists.txt
│   │
│   ├── services/               # 业务逻辑/服务层
│   │   ├── database/
│   │   │   ├── databasemanager.h
│   │   │   ├── databasemanager.cpp
│   │   │   ├── serverrepository.h
│   │   │   ├── serverrepository.cpp
│   │   │   ├── taskrepository.h
│   │   │   └── taskrepository.cpp
│   │   │
│   │   ├── scheduling/
│   │   │   ├── taskscheduler.h
│   │   │   ├── taskscheduler.cpp
│   │   │   ├── resourceallocator.h
│   │   │   └── resourceallocator.cpp
│   │   │
│   │   └── CMakeLists.txt
│   │
│   ├── controllers/            # 控制器层
│   │   ├── maincontroller.h
│   │   ├── maincontroller.cpp
│   │   ├── dashboardcontroller.h
│   │   ├── dashboardcontroller.cpp
│   │   └── CMakeLists.txt
│   │
│   ├── views/                  # 视图层
│   │   ├── windows/
│   │   │   ├── mainwindow.h
│   │   │   ├── mainwindow.cpp
│   │   │   ├── mainwindow.ui
│   │   │   ├── addserverwindow.h
│   │   │   ├── addserverwindow.cpp
│   │   │   ├── addserverwindow.ui
│   │   │   ├── dashboardwindow.h
│   │   │   ├── dashboardwindow.cpp
│   │   │   ├── dashboardwindow.ui
│   │   │   ├── simulationwindow.h
│   │   │   ├── simulationwindow.cpp
│   │   │   └── simulationwindow.ui
│   │   │
│   │   ├── widgets/            # 自定义控件
│   │   │   ├── servertablewidget.h
│   │   │   ├── servertablewidget.cpp
│   │   │   ├── resourcechartwidget.h
│   │   │   └── resourcechartwidget.cpp
│   │   │
│   │   ├── delegates/          # 自定义委托
│   │   │   ├── progressbardelegate.h
│   │   │   └── progressbardelegate.cpp
│   │   │
│   │   └── CMakeLists.txt
│   │
│   ├── utils/                  # 工具类
│   │   ├── config.h
│   │   ├── config.cpp
│   │   ├── logger.h
│   │   ├── logger.cpp
│   │   └── CMakeLists.txt
│   │
│   └── main.cpp                # 程序入口
│
├── resources/                  # Qt 资源文件
│   ├── resources.qrc
│   ├── styles/
│   │   └── style.qss
│   ├── icons/
│   │   ├── logo.png
│   │   ├── cpu.png
│   │   └── disk.png
│   └── config/
│       └── database.ini        # 配置文件
│
├── tests/                      # 单元测试
│   ├── models/
│   ├── services/
│   ├── controllers/
│   └── CMakeLists.txt
│
├── docs/                       # 文档目录
│   ├── architecture.md
│   ├── api.md
│   └── development.md
│
└── claudedocs/                 # Claude 分析文档
    ├── summary.md
    └── optimization_recommendations.md
```

### 二、模块解耦与重构建议

#### 2.1 数据模型层 (Models)

**创建独立的数据模型类**

```cpp
// include/servermanager/models/server.h
#ifndef SERVERMANAGER_MODELS_SERVER_H
#define SERVERMANAGER_MODELS_SERVER_H

#include <QString>
#include <QDateTime>
#include <memory>

namespace ServerManager {
namespace Models {

class Server {
public:
    Server();
    Server(const QString& id, const QString& ip, int port);

    // Getters
    QString id() const { return m_id; }
    QString ip() const { return m_ip; }
    int port() const { return m_port; }
    int totalCpu() const { return m_totalCpu; }
    int freeCpu() const { return m_freeCpu; }
    bool isActive() const { return m_isActive; }

    // Setters
    void setId(const QString& id) { m_id = id; }
    void setIp(const QString& ip) { m_ip = ip; }
    void setFreeCpu(int freeCpu) { m_freeCpu = freeCpu; }
    void setActive(bool active) { m_isActive = active; }

    // Business logic
    bool canAllocateTask(int cpuRequired, int gpuRequired,
                         int diskRequired, int bandwidthRequired) const;
    void allocateResources(int cpu, int gpu, int disk, int bandwidth);
    void releaseResources(int cpu, int gpu, int disk, int bandwidth);

private:
    QString m_id;
    QString m_ip;
    int m_port;
    int m_totalCpu;
    int m_totalGpu;
    int m_totalDisk;
    int m_totalBandwidth;
    int m_freeCpu;
    int m_freeGpu;
    int m_freeDisk;
    int m_freeBandwidth;
    bool m_isActive;
    QDateTime m_lastUpdate;
};

} // namespace Models
} // namespace ServerManager

#endif
```

```cpp
// include/servermanager/models/task.h
#ifndef SERVERMANAGER_MODELS_TASK_H
#define SERVERMANAGER_MODELS_TASK_H

#include <QString>

namespace ServerManager {
namespace Models {

enum class TaskStatus {
    Pending = 0,
    Running = 1,
    Completed = 2,
    Failed = 3
};

class Task {
public:
    Task();
    Task(const QString& id, int cpu, int gpu, int disk, int bandwidth,
         qint64 startTime, qint64 duration);

    // Getters
    QString id() const { return m_id; }
    int cpuRequired() const { return m_cpuRequired; }
    int gpuRequired() const { return m_gpuRequired; }
    TaskStatus status() const { return m_status; }
    qint64 startTime() const { return m_startTime; }
    qint64 duration() const { return m_duration; }

    // Setters
    void setStatus(TaskStatus status) { m_status = status; }

    // Business logic
    bool isExpired(qint64 currentTime) const;

private:
    QString m_id;
    int m_cpuRequired;
    int m_gpuRequired;
    int m_diskRequired;
    int m_bandwidthRequired;
    qint64 m_startTime;
    qint64 m_duration;
    TaskStatus m_status;
};

} // namespace Models
} // namespace ServerManager

#endif
```

#### 2.2 数据访问层 (Repository Pattern)

**解耦数据库操作,使用 Repository 模式**

```cpp
// include/servermanager/services/database/databasemanager.h
#ifndef SERVERMANAGER_SERVICES_DATABASEMANAGER_H
#define SERVERMANAGER_SERVICES_DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QString>
#include <memory>

namespace ServerManager {
namespace Services {

class DatabaseManager {
public:
    static DatabaseManager& instance();

    bool initialize(const QString& configPath);
    bool isConnected() const;
    QSqlDatabase& database();

    // 禁止拷贝
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;

private:
    DatabaseManager() = default;
    ~DatabaseManager();

    bool loadConfig(const QString& configPath);

    QSqlDatabase m_database;
    QString m_hostName;
    QString m_databaseName;
    QString m_userName;
    QString m_password;
    bool m_isConnected = false;
};

} // namespace Services
} // namespace ServerManager

#endif
```

```cpp
// include/servermanager/services/database/serverrepository.h
#ifndef SERVERMANAGER_SERVICES_SERVERREPOSITORY_H
#define SERVERMANAGER_SERVICES_SERVERREPOSITORY_H

#include "servermanager/models/server.h"
#include <QVector>
#include <optional>

namespace ServerManager {
namespace Services {

class ServerRepository {
public:
    ServerRepository();

    // CRUD operations
    bool create(const Models::Server& server);
    std::optional<Models::Server> findById(const QString& id);
    QVector<Models::Server> findAll();
    QVector<Models::Server> findByStatus(bool isActive);
    bool update(const Models::Server& server);
    bool remove(const QString& id);

    // Business queries
    QVector<Models::Server> findOrderedByPerformance();
    bool updateResourceUsage(const QString& id, int freeCpu, int freeGpu,
                            int freeDisk, int freeBandwidth);
    bool activate(const QString& id);

private:
    Models::Server mapFromQuery(const QSqlQuery& query);
};

} // namespace Services
} // namespace ServerManager

#endif
```

```cpp
// include/servermanager/services/database/taskrepository.h
#ifndef SERVERMANAGER_SERVICES_TASKREPOSITORY_H
#define SERVERMANAGER_SERVICES_TASKREPOSITORY_H

#include "servermanager/models/task.h"
#include <QVector>
#include <optional>

namespace ServerManager {
namespace Services {

class TaskRepository {
public:
    TaskRepository();

    // CRUD operations
    bool create(const Models::Task& task);
    std::optional<Models::Task> findById(const QString& id);
    QVector<Models::Task> findByStatus(Models::TaskStatus status);
    bool update(const Models::Task& task);
    bool updateStatus(const QString& id, Models::TaskStatus status);

    // Statistics
    int countByStatus(Models::TaskStatus status);
    int countTotal();

private:
    Models::Task mapFromQuery(const QSqlQuery& query);
};

} // namespace Services
} // namespace ServerManager

#endif
```

#### 2.3 业务逻辑层 (Services)

**提取任务调度算法到独立服务**

```cpp
// include/servermanager/services/scheduling/taskscheduler.h
#ifndef SERVERMANAGER_SERVICES_TASKSCHEDULER_H
#define SERVERMANAGER_SERVICES_TASKSCHEDULER_H

#include "servermanager/models/server.h"
#include "servermanager/models/task.h"
#include <QVector>
#include <queue>
#include <functional>

namespace ServerManager {
namespace Services {

struct SchedulingResult {
    bool success;
    QString serverId;
    QString errorMessage;
};

class TaskScheduler {
public:
    TaskScheduler();

    // 配置调度参数
    void setResourceCeiling(double ceiling) { m_resourceCeiling = ceiling; }
    void setAvailabilityFactor(double factor) { m_availabilityFactor = factor; }

    // 任务调度
    SchedulingResult scheduleTask(const Models::Task& task,
                                  QVector<Models::Server>& activeServers,
                                  QVector<Models::Server>& inactiveServers);

    // 批量调度
    QVector<SchedulingResult> scheduleTasks(const QVector<Models::Task>& tasks,
                                           QVector<Models::Server>& activeServers,
                                           QVector<Models::Server>& inactiveServers);

    // 资源回收
    void releaseTaskResources(const Models::Task& task, Models::Server& server);

private:
    bool canAllocateToServer(const Models::Server& server,
                            const Models::Task& task) const;

    double m_resourceCeiling = 0.8;      // 资源使用上限 80%
    double m_availabilityFactor = 0.98;   // 可用率因子
};

} // namespace Services
} // namespace ServerManager

#endif
```

#### 2.4 控制器层 (Controllers)

**引入控制器协调 UI 和业务逻辑**

```cpp
// include/servermanager/controllers/dashboardcontroller.h
#ifndef SERVERMANAGER_CONTROLLERS_DASHBOARDCONTROLLER_H
#define SERVERMANAGER_CONTROLLERS_DASHBOARDCONTROLLER_H

#include "servermanager/services/database/serverrepository.h"
#include "servermanager/services/database/taskrepository.h"
#include "servermanager/services/scheduling/taskscheduler.h"
#include <QObject>
#include <QTimer>

namespace ServerManager {
namespace Controllers {

class DashboardController : public QObject {
    Q_OBJECT

public:
    explicit DashboardController(QObject* parent = nullptr);
    ~DashboardController();

    // 初始化
    bool initialize();

    // 数据查询接口
    struct ResourceStatistics {
        int totalMemory;
        int freeMemory;
        int occupiedMemory;
        int totalGpu;
        int freeGpu;
        int occupiedGpu;
    };

    struct TaskStatistics {
        int total;
        int completed;
        int failed;
        int running;
        int pending;
    };

    ResourceStatistics getResourceStatistics() const;
    TaskStatistics getTaskStatistics() const;
    QVector<Models::Server> getActiveServers() const;

    // 操作接口
    void startScheduling();
    void stopScheduling();
    void updateServerResources();

signals:
    void dataUpdated();
    void taskStatisticsChanged(const TaskStatistics& stats);
    void resourceStatisticsChanged(const ResourceStatistics& stats);
    void errorOccurred(const QString& error);

private slots:
    void onUpdateTimer();
    void onScheduleTimer();

private:
    void loadInitialData();
    void processCompletedTasks();
    void schedulePendingTasks();

    Services::ServerRepository m_serverRepo;
    Services::TaskRepository m_taskRepo;
    Services::TaskScheduler m_scheduler;

    QTimer* m_updateTimer;
    QTimer* m_scheduleTimer;

    QVector<Models::Server> m_activeServers;
    QVector<Models::Task> m_pendingTasks;
    QVector<Models::Task> m_failedTasks;
};

} // namespace Controllers
} // namespace ServerManager

#endif
```

#### 2.5 视图层改进

**窗口类只负责 UI 交互**

```cpp
// src/views/windows/dashboardwindow.h
#ifndef SERVERMANAGER_VIEWS_DASHBOARDWINDOW_H
#define SERVERMANAGER_VIEWS_DASHBOARDWINDOW_H

#include "servermanager/controllers/dashboardcontroller.h"
#include <QMainWindow>
#include <QChart>
#include <QPieSeries>

namespace Ui { class DashboardWindow; }

namespace ServerManager {
namespace Views {

class DashboardWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit DashboardWindow(Controllers::DashboardController* controller,
                            QWidget* parent = nullptr);
    ~DashboardWindow();

private slots:
    void onTaskStatisticsChanged(const Controllers::DashboardController::TaskStatistics& stats);
    void onResourceStatisticsChanged(const Controllers::DashboardController::ResourceStatistics& stats);
    void onErrorOccurred(const QString& error);

private:
    void setupUi();
    void setupCharts();
    void connectSignals();
    void updateTaskChart(const Controllers::DashboardController::TaskStatistics& stats);
    void updateResourceCharts(const Controllers::DashboardController::ResourceStatistics& stats);

    Ui::DashboardWindow* ui;
    Controllers::DashboardController* m_controller;

    QChart* m_taskChart;
    QChart* m_memoryChart;
    QChart* m_gpuChart;
    QPieSeries* m_taskSeries;
    QPieSeries* m_memorySeries;
    QPieSeries* m_gpuSeries;
};

} // namespace Views
} // namespace ServerManager

#endif
```

### 三、配置管理优化

#### 3.1 外部化配置文件

**resources/config/database.ini**
```ini
[Database]
Type=QMYSQL
HostName=localhost
DatabaseName=servers
UserName=root
# 使用环境变量或加密存储密码,不要硬编码
# Password 从环境变量 DB_PASSWORD 读取
```

**配置加载实现**
```cpp
// src/utils/config.cpp
#include "servermanager/utils/config.h"
#include <QSettings>
#include <QProcessEnvironment>

namespace ServerManager {
namespace Utils {

bool Config::loadDatabaseConfig(const QString& configPath,
                                DatabaseConfig& config) {
    QSettings settings(configPath, QSettings::IniFormat);

    settings.beginGroup("Database");
    config.type = settings.value("Type", "QMYSQL").toString();
    config.hostName = settings.value("HostName", "localhost").toString();
    config.databaseName = settings.value("DatabaseName").toString();
    config.userName = settings.value("UserName").toString();

    // 从环境变量读取密码
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    config.password = env.value("DB_PASSWORD", "");

    if (config.password.isEmpty()) {
        qWarning() << "Database password not found in environment variable DB_PASSWORD";
        return false;
    }

    settings.endGroup();
    return true;
}

} // namespace Utils
} // namespace ServerManager
```

### 四、CMake 子项目组织

**根目录 CMakeLists.txt**
```cmake
cmake_minimum_required(VERSION 3.16)
project(ServerManager VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Qt 包查找
find_package(Qt6 REQUIRED COMPONENTS
    Core
    Gui
    Widgets
    Network
    Sql
    Charts
)

# 包含目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 添加子项目
add_subdirectory(src/models)
add_subdirectory(src/services)
add_subdirectory(src/controllers)
add_subdirectory(src/views)
add_subdirectory(src/utils)

# 主可执行文件
add_executable(${PROJECT_NAME}
    src/main.cpp
    resources/resources.qrc
)

# 链接所有模块
target_link_libraries(${PROJECT_NAME} PRIVATE
    ServerManager::Models
    ServerManager::Services
    ServerManager::Controllers
    ServerManager::Views
    ServerManager::Utils
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Network
    Qt6::Sql
    Qt6::Charts
)

# 测试支持
option(BUILD_TESTS "Build tests" ON)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
```

**Models 模块 CMakeLists.txt**
```cmake
# src/models/CMakeLists.txt
add_library(ServerManager_Models STATIC
    server.cpp
    task.cpp
)

add_library(ServerManager::Models ALIAS ServerManager_Models)

target_include_directories(ServerManager_Models PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(ServerManager_Models PUBLIC
    Qt6::Core
)
```

### 五、安全性改进

#### 5.1 SQL 注入防护

**❌ 错误示范 (当前代码)**
```cpp
// addwindow.cpp - 存在 SQL 注入风险
QString sql = QString("INSERT INTO sers (id, ip, port) \
VALUES ('%1', '%2', '%3');").arg(_id).arg(_ip).arg(_port.toInt());
```

**✅ 正确做法**
```cpp
// serverrepository.cpp - 使用参数化查询
bool ServerRepository::create(const Models::Server& server) {
    QSqlQuery query;
    query.prepare("INSERT INTO sta (id, ip, port, cpu, gpu, disk, bandwidth, "
                  "free_cpu, free_gpu, free_disk, free_bandwidth, status, power) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

    query.addBindValue(server.id());
    query.addBindValue(server.ip());
    query.addBindValue(server.port());
    // ... 其他参数

    if (!query.exec()) {
        qWarning() << "Failed to create server:" << query.lastError().text();
        return false;
    }
    return true;
}
```

#### 5.2 密码管理

**使用环境变量或密钥管理服务**
```cpp
// 设置环境变量 (Linux/WSL)
export DB_PASSWORD="your_secure_password"

// Windows PowerShell
$env:DB_PASSWORD="your_secure_password"

// 或使用 Qt Keychain 库进行加密存储
```

#### 5.3 资源路径管理

**使用 Qt 资源系统代替硬编码路径**
```cpp
// ❌ 错误: 硬编码相对路径
QPixmap pixLogo("../icons/logo.png");

// ✅ 正确: 使用 Qt 资源系统
QPixmap pixLogo(":/icons/logo.png");
```

---

## 📊 代码质量改进

### 6.1 代码风格统一

**命名规范**
```cpp
// 类名: PascalCase
class TaskScheduler {};
class ServerRepository {};

// 成员变量: m_ 前缀 + camelCase
int m_totalCpu;
QString m_serverName;

// 函数/方法: camelCase
void allocateResources();
bool isActive() const;

// 常量: k 前缀 + PascalCase 或全大写
const double kResourceCeiling = 0.8;
constexpr int MAX_SERVERS = 100;

// 命名空间: PascalCase
namespace ServerManager {
namespace Services {}
}
```

### 6.2 消除魔法数字

**定义配置常量类**
```cpp
// include/servermanager/common/constants.h
namespace ServerManager {
namespace Constants {

// 资源管理常量
constexpr double RESOURCE_CEILING = 0.8;           // 80% 资源上限
constexpr double AVAILABILITY_FACTOR_MIN = 0.98;   // 98% 最小可用率
constexpr double AVAILABILITY_FACTOR_MAX = 1.00;   // 100% 最大可用率

// 定时器间隔 (毫秒)
constexpr int UPDATE_INTERVAL_MS = 500;            // 快速更新间隔
constexpr int CHART_UPDATE_INTERVAL_MS = 2000;     // 图表更新间隔

// UI 常量
constexpr int TABLE_COLUMN_ID_WIDTH = 50;
constexpr int TABLE_COLUMN_IP_WIDTH = 150;
constexpr int TABLE_COLUMN_STATUS_WIDTH = 80;

// 随机生成常量
constexpr int RANDOM_ID_LENGTH = 10;
constexpr int MIN_SERVER_CPU_GB = 1;
constexpr int MAX_SERVER_CPU_GB = 64;

} // namespace Constants
} // namespace ServerManager
```

### 6.3 错误处理增强

**统一错误处理策略**
```cpp
// include/servermanager/common/result.h
template<typename T>
class Result {
public:
    static Result<T> success(const T& value) {
        return Result(value, true, "");
    }

    static Result<T> failure(const QString& error) {
        return Result(T(), false, error);
    }

    bool isSuccess() const { return m_success; }
    const T& value() const { return m_value; }
    QString error() const { return m_error; }

private:
    Result(const T& value, bool success, const QString& error)
        : m_value(value), m_success(success), m_error(error) {}

    T m_value;
    bool m_success;
    QString m_error;
};

// 使用示例
Result<Models::Server> result = m_serverRepo.findById(serverId);
if (result.isSuccess()) {
    Models::Server server = result.value();
    // 处理服务器
} else {
    qWarning() << "Error:" << result.error();
    // 错误处理
}
```

### 6.4 日志系统

**实现结构化日志**
```cpp
// include/servermanager/utils/logger.h
namespace ServerManager {
namespace Utils {

enum class LogLevel {
    Debug,
    Info,
    Warning,
    Error,
    Critical
};

class Logger {
public:
    static void log(LogLevel level, const QString& category,
                   const QString& message);

    static void debug(const QString& category, const QString& message);
    static void info(const QString& category, const QString& message);
    static void warning(const QString& category, const QString& message);
    static void error(const QString& category, const QString& message);

    static void setLogLevel(LogLevel level);
    static void setLogFile(const QString& filePath);

private:
    static LogLevel s_logLevel;
    static QString s_logFilePath;
};

// 使用示例
Logger::info("TaskScheduler", QString("Scheduled task %1 to server %2")
             .arg(task.id()).arg(server.id()));
Logger::error("DatabaseManager", "Failed to connect to database");
```

---

## 🧪 测试支持

### 7.1 单元测试框架

**tests/CMakeLists.txt**
```cmake
find_package(Qt6 REQUIRED COMPONENTS Test)

# 模型测试
add_executable(test_models
    models/test_server.cpp
    models/test_task.cpp
)
target_link_libraries(test_models PRIVATE
    ServerManager::Models
    Qt6::Test
)
add_test(NAME ModelsTest COMMAND test_models)

# 服务测试
add_executable(test_services
    services/test_taskscheduler.cpp
    services/test_repositories.cpp
)
target_link_libraries(test_services PRIVATE
    ServerManager::Services
    Qt6::Test
)
add_test(NAME ServicesTest COMMAND test_services)
```

**示例单元测试**
```cpp
// tests/models/test_server.cpp
#include "servermanager/models/server.h"
#include <QtTest/QtTest>

class TestServer : public QObject {
    Q_OBJECT

private slots:
    void testCanAllocateTask();
    void testAllocateResources();
    void testReleaseResources();
};

void TestServer::testCanAllocateTask() {
    ServerManager::Models::Server server;
    server.setTotalCpu(1024);
    server.setFreeCpu(512);

    QVERIFY(server.canAllocateTask(256, 128, 50, 100));
    QVERIFY(!server.canAllocateTask(1024, 128, 50, 100));
}

QTEST_MAIN(TestServer)
#include "test_server.moc"
```

---

## 📈 迁移路线图

### 阶段一: 基础重构 (1-2 周)
1. ✅ 创建新的目录结构
2. ✅ 提取数据模型到独立类 (Server, Task)
3. ✅ 实现 Repository 层 (ServerRepository, TaskRepository)
4. ✅ 移除硬编码密码,实施配置文件管理
5. ✅ 修复 SQL 注入漏洞

### 阶段二: 业务逻辑分离 (2-3 周)
1. ✅ 实现 TaskScheduler 服务
2. ✅ 创建 Controller 层
3. ✅ 重构窗口类,移除业务逻辑
4. ✅ 实现信号/槽通信机制

### 阶段三: 质量提升 (1-2 周)
1. ✅ 添加单元测试
2. ✅ 实现日志系统
3. ✅ 统一错误处理
4. ✅ 代码风格规范化

### 阶段四: 文档与优化 (1 周)
1. ✅ 编写 API 文档
2. ✅ 架构文档
3. ✅ 开发指南
4. ✅ 性能优化

---

## 🎯 预期收益

### 可维护性提升
- ✅ **模块化**: 每个模块职责单一,易于理解和修改
- ✅ **解耦**: UI、业务逻辑、数据访问完全分离
- ✅ **可测试性**: 每层都可以独立测试

### 可扩展性提升
- ✅ **新功能**: 添加新窗口或功能无需修改核心逻辑
- ✅ **数据源切换**: 可轻松切换到其他数据库或 API
- ✅ **算法优化**: 调度算法独立,可以独立改进

### 代码质量提升
- ✅ **安全性**: 消除 SQL 注入和密码泄露风险
- ✅ **可读性**: 统一的命名规范和代码风格
- ✅ **健壮性**: 完善的错误处理和日志记录

### 团队协作提升
- ✅ **并行开发**: 不同层可以由不同开发者并行开发
- ✅ **代码审查**: 模块化代码更易于审查
- ✅ **知识传递**: 清晰的架构降低新人学习成本

---

## 📚 参考资源

1. **Qt 官方文档**
   - [Model/View Programming](https://doc.qt.io/qt-6/model-view-programming.html)
   - [Qt Best Practices](https://doc.qt.io/qt-6/best-practices.html)

2. **设计模式**
   - Repository Pattern
   - MVC/MVVM Pattern
   - Singleton Pattern

3. **C++ 最佳实践**
   - [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
   - SOLID Principles

4. **安全最佳实践**
   - OWASP SQL Injection Prevention
   - Qt Security Guidelines

---

## 📞 后续支持

如需进一步的技术指导或代码审查,建议:

1. **渐进式重构**: 不要一次性重写,逐步迁移现有功能
2. **保持向后兼容**: 在重构过程中确保应用程序始终可运行
3. **增量测试**: 每完成一个模块立即编写测试
4. **文档同步**: 代码和文档同步更新

**生成日期**: 2025-10-03
**文档版本**: 1.0
**分析工具**: Claude Code + SuperClaude Framework
