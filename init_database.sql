-- ServerManager 数据库初始化脚本
-- Ubuntu/Linux MySQL 8.0+
-- 执行方式: sudo mysql -u root -p < init_database.sql

-- 创建数据库
CREATE DATABASE IF NOT EXISTS servers
CHARACTER SET utf8mb4
COLLATE utf8mb4_unicode_ci;

USE servers;

-- 创建服务器状态表
CREATE TABLE IF NOT EXISTS sta (
    id VARCHAR(50) PRIMARY KEY COMMENT '服务器唯一标识',
    ip VARCHAR(15) NOT NULL COMMENT 'IP 地址',
    port INT NOT NULL COMMENT '端口号',
    cpu INT NOT NULL COMMENT '总 CPU 容量 (MB)',
    gpu INT NOT NULL COMMENT '总 GPU 容量 (MB)',
    disk INT NOT NULL COMMENT '总磁盘容量 (GB)',
    bandwidth INT NOT NULL COMMENT '总带宽 (Mbps)',
    free_cpu INT NOT NULL COMMENT '空闲 CPU (MB)',
    free_gpu INT NOT NULL COMMENT '空闲 GPU (MB)',
    free_disk INT NOT NULL COMMENT '空闲磁盘 (GB)',
    free_bandwidth INT NOT NULL COMMENT '空闲带宽 (Mbps)',
    status TINYINT(1) DEFAULT 0 COMMENT '状态: 0=未激活, 1=已激活',
    power INT DEFAULT 0 COMMENT '功耗 (W)',
    total_weight INT GENERATED ALWAYS AS (cpu + gpu + disk + bandwidth) STORED COMMENT '总权重 (计算列)'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COMMENT='服务器状态表';

-- 创建任务表
CREATE TABLE IF NOT EXISTS task (
    id VARCHAR(50) PRIMARY KEY COMMENT '任务唯一标识',
    cpu INT NOT NULL COMMENT '需要 CPU (MB)',
    gpu INT NOT NULL COMMENT '需要 GPU (MB)',
    disk INT NOT NULL COMMENT '需要磁盘 (GB)',
    bandwidth INT NOT NULL COMMENT '需要带宽 (Mbps)',
    start BIGINT NOT NULL COMMENT '开始时间 (毫秒)',
    during BIGINT NOT NULL COMMENT '持续时间 (毫秒)',
    status TINYINT(1) DEFAULT 0 COMMENT '状态: 0=待处理, 1=已完成, 2=失败',
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '更新时间'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COMMENT='任务表';

-- 创建备用服务器表 (addwindow 使用)
CREATE TABLE IF NOT EXISTS sers (
    id VARCHAR(50) PRIMARY KEY COMMENT '服务器 ID',
    ip VARCHAR(15) NOT NULL COMMENT 'IP 地址',
    port INT NOT NULL COMMENT '端口号',
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COMMENT='服务器信息备用表';

-- 创建索引优化查询
CREATE INDEX idx_sta_status ON sta(status);
CREATE INDEX idx_sta_total_weight ON sta(total_weight DESC);
CREATE INDEX idx_task_status ON task(status);
CREATE INDEX idx_task_start ON task(start);

-- 授予权限 (确保 root 用户可以访问)
-- 如果需要创建新用户，取消下面注释:
-- CREATE USER IF NOT EXISTS 'servermanager'@'localhost' IDENTIFIED BY 'your_password';
-- GRANT ALL PRIVILEGES ON servers.* TO 'servermanager'@'localhost';
-- FLUSH PRIVILEGES;

-- 插入测试数据 (可选)
INSERT INTO sta (id, ip, port, cpu, gpu, disk, bandwidth, free_cpu, free_gpu, free_disk, free_bandwidth, status, power) VALUES
('SRV001', '192.168.1.101', 8001, 8192, 16384, 500, 1000, 8192, 16384, 500, 1000, 0, 150),
('SRV002', '192.168.1.102', 8002, 4096, 8192, 250, 500, 4096, 8192, 250, 500, 0, 80);

INSERT INTO task (id, cpu, gpu, disk, bandwidth, start, during, status) VALUES
('TSK001', 1024, 2048, 50, 100, 0, 5000, 0),
('TSK002', 512, 1024, 25, 50, 1000, 3000, 0);

-- 显示创建结果
SELECT 'Database and tables created successfully!' AS Result;
SHOW TABLES;
SELECT COUNT(*) AS server_count FROM sta;
SELECT COUNT(*) AS task_count FROM task;
