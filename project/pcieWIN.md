# pcieWIN驱动开发笔记

## PCIE设备的设计与使用都是依据PCIE协议的，所以首先我们需要对PCIE协议有一个大致的了解

### 首先你需要下载这两个文档《PCI_Express_Base_Specification_Revision》，《PCI Express System Architecture》。

- 第一个文档是将PCIE设备进行通信时包的格式，以及设备中的寄存器的含义和使用，可以看做是一本工具书，当你开发时关于接口，包格式，寄存器问题是随时可以查阅的文档，没有必要去细读它。

- 第二个是非常有必要去读的一个文档，有一个减缩版可以让你快速对整个体系有一个了解。

### 开发学习笔记就从第二本的内容开始，对pcie有一个大体的了解。首先我们都知道在电脑中有很多设备使用pcie总线，例如显卡，网卡，硬盘。

- 首先我们简单介绍一下PCIE，PCIE是一种串行通信协议。在低速情况下，并行结构绝对是一种非常高效的传输方式，但是当传输速度非常高，并行传输的致命性缺点就出现了

	- 因为时钟在高速的情况下，因为每一位在传输线路上不可能严格的一致，并行传输的一个字节中的每个位不会同时到达接受端就被放大了。而串行传输一位一位传输就不会出现这个问题。

	- 串行的优势就出现了，串行因为不存在并行的这些问题，就可以工作在非常高的频率下，用频率的提升掩盖它的劣势。

### PCIE使用一对差分信号来传输一位信号，当D+比D-信号高时，传输的是逻辑1，反之为0，当相同时不工作。同时PCIE系统没有时钟线。

## pcie总线的拓扑结构。

### Fig.1 PCIE拓扑结构

- 从Fig1可以看出这个拓扑结构，CPU连接到根聚合体（Root Complex），RC负责完成从CPU总线域到外设域的转换，并且实现各种总线的聚合。将一部分CPU地址映射到内存，一部分地址映射到相应的相应的设备终端（比如板卡）

- pcie设备有两大类，一种是root port，另一种Endpoint。从字面意思可以了解这两类的作用，root port相当于一个根节点，将多个endpoint设备连接在一个节点，同时它完成数据的路由。上图中的Switch就是一个root port设备。而endpoint就是最终数据的接受者，命令的执行者

## pcie数据的传输方式

### pcie数据的传输方式类似于TCP/IP的方式，将数据按数据包的格式进行传输，同时对结构进行分层。

## PCIE Device layers

## Detailed Block Diagram of PCI Express Device&amp;#39;s Layer

### PCIE的设备都具有这几个结构，每个结构的作用不同。我们首先说明数据传输时候的流程，PCIE协议传输数据是以数据包的形式传输。

- 首先说明在发送端，设备核或者应用软件产生数据信息，交由PCI Express Core Logic Interface将数据格式转换TL层可以接受的格式，TL层产生相应的数据包。然后数据包被存储在缓冲buffer中，准备传输给下一层数据链层（Data Link Layer）。数据链层将上一层传来的数据包添加一些额外的数据用来给接收端进行一些必要的数据正确性检查。然后物理层将数据包编码，通过多条链路使用模拟信号进行传输。

- 在接收端，接收端设备在物理层解码传输的数据，并将数据传输至上一层数据链层，数据链层将入站数据包进行正确性检查，如果没有错误就将数据传输至TL层，TL层将数据包缓冲buffer，之后PCI Express Core Logic Interface将数据包转换成设备核或者软件能够处理的数据。

- 我们使用IP核进行开发时，这三个层都已经写好了。所以我们的主要的任务就是写出fig.2中PCI Express Core Logic Interface，从他的字面我们就可以明白他的作用，就是一个接口，将数据从Device Core输出的数据格式转换IP核TL层接受的数据格式。

￼


## Fig.2 PCIE Device layers

## Fig.3 Detailed Block Diagram of PCI Express Device&amp;#39;s Layer

### PCIE的设备都具有这几个结构，每个结构的作用不同。我们首先说明数据传输时候的流程，PCIE协议传输数据是以数据包的形式传输。

- 首先说明在发送端，设备核或者应用软件产生数据信息，交由PCI Express Core Logic Interface将数据格式转换TL层可以接受的格式，TL层产生相应的数据包。然后数据包被存储在缓冲buffer中，准备传输给下一层数据链层（Data Link Layer）。数据链层将上一层传来的数据包添加一些额外的数据用来给接收端进行一些必要的数据正确性检查。然后物理层将数据包编码，通过多条链路使用模拟信号进行传输。

- 在接收端，接收端设备在物理层解码传输的数据，并将数据传输至上一层数据链层，数据链层将入站数据包进行正确性检查，如果没有错误就将数据传输至TL层，TL层将数据包缓冲buffer，之后PCI Express Core Logic Interface将数据包转换成设备核或者软件能够处理的数据。

- 我们使用IP核进行开发时，这三个层都已经写好了。所以我们的主要的任务就是写出fig.2中PCI Express Core Logic Interface，从他的字面我们就可以明白他的作用，就是一个接口，将数据从Device Core输出的数据格式转换IP核TL层接受的数据格式。

## pcie数据包的处理

### 在TLP包传输的过程中会发生数据包的组装和拆解。

- TLP包的组装

	- 当数据从软件层或者设备核传来之后，TL层添加ECRC，

在DLL层在前段添加序列数字，在后面添加DLL层的CRC，

在物理层添加帧头和帧未。

## Fig.5 TLP Assembly

### TLP的拆解是一个反过程。如Fig.6

## Fig.6 TLP Disassembly
