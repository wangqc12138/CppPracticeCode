# **计算机系统结构**
- 层次结构
	- 计算机系统的基本组成
	- 计算机硬件的基本组成
	- 计算机软件和硬件的关系
	- 计算机系统的工作原理
		- 存储程序工作方式
		- 高级语言程序与机器语言程序之间的转换
		- 程序和指令的执行过程
- 性能指标 
	- 吞吐量、响应时间
	- CPU时钟周期、主频、CPI、CPU执行时间
	- MIPS、MFLOPS、GFLOPS
# **数据的表示和应用**
- 进制与编码
	- 进位计数制及其数据之间的相互转换
	- 定点数的编码表示
- 运算方法和运算电路
	- 基本运算部件
		- 加法器、算数逻辑部件
	- 加减运算
		- 补码加减运算器、标志位的生成
	- 乘除运算
		- 基本原理、电路基本结构
- 整数的表示和运算
	- 无符号整数
	- 带符号整数
- 浮点数的表示和运算
	- 表示
		-IEEE 754标准
	- 加减运算
# **存储器**
- 存储器的分类
- 层次化存储器的基本结构
- 半导体随机存取存储器
	- SRAM
	- DRAM
	- Flash
- 主存储器
	- DRAM芯片和内存条
	- 多模块存储器
	- 主存和CPU之间的连接
- 外部存储器
	- 磁盘存储器
	- 固态硬盘
- 高速缓冲存储器
	- cache的基本原理
	- 和主存的映射方式
	- 主存块的替换算法
	- 写策略
- 虚拟存储器
	- 基本概念
	- 页式虚拟存储器
		- 基本原理
		- 页表
		- 地址转换
		- TLB快表
	- 段式虚拟存储器
	- 段页式
# **指令系统**
- 指令系统的基本概念
- 指令格式
- 寻址方式
- 数据对齐和大小端存放方式
- CISC和RISC的基本概念
- 高级语言程序和机器级代码之间的对应
	- 编译器、汇编器、链路器的基本概念
	- 选择结构语句的机器级表示
	- 循环结构语句的机器级表示
	- 过程（函数）调用对应的机器级表示
# **CPU**
- CPU的功能和基本结构
- 指令执行过程
- 数据通路的功能和基本结构
- 控制器的功能和工作原理
- 异常和中断机制
	- 异常和中断的基本概念
	- 异常和中断的分类
	- 异常和中断的检测和响应
- 指令流水线
	- 基本概念
	- 基本实现
	- 结构冒险、数据冒险、控制冒险的处理
	- 超标量和动态流水线的基本概念
- 多处理器基本概念
	- SISD、SIMD、MIMD、向量处理器的基本概念
	- 硬件多线程的基本概念
	- 多核处理器的基本概念
	- 共享内存多处理器（SMP）的基本概念
# **总线和IO**
- 总线
	- 基本概念
	- 组成和性能指标
	- 总线事务和定时
- I/O接口
	- 功能和基本结构
	- 端口及其编址
- I/O方式
	- 程序查询方式
	- 程序中断方式
		- 中断基本概念
		- 响应过程
		- 处理过程
		- 多重中断、中断屏蔽
	- DMA方式
		- DMA控制器的组成
		- DMA传送过程