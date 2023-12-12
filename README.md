# Windows Driver Learning Project

这是一个用于学习编写windows驱动的项目，它包含了三个简单的驱动测试程序，分别是：

- `drv1`：一个基本的驱动程序，它在加载和卸载时分别打印`Hello, world!`和`Goodbye, world!`到系统日志中。
- `drv2`：一个使用`IRP_MJ_CREATE`和`IRP_MJ_CLOSE`请求的驱动程序，它在用户程序打开和关闭设备时分别打印`Device opened`和`Device closed`到系统日志中。
- `drv3`：一个使用`IRP_MJ_READ`和`IRP_MJ_WRITE`请求的驱动程序，它在用户程序读取和写入设备时分别打印`Read from device`和`Write to device`到系统日志中。

## 如何使用

要使用这些驱动测试程序，你需要以下步骤：

- 安装[Windows Driver Kit (WDK)](https://docs.microsoft.com/en-us/windows-hardware/drivers/download-the-wdk)和[Visual Studio](https://visualstudio.microsoft.com/)，并确保你的系统支持[测试签名](https://docs.microsoft.com/en-us/windows-hardware/drivers/install/the-testsigning-boot-configuration-option)。
- 克隆或下载本项目到你的本地目录，然后用Visual Studio打开`DriverLearning.sln`解决方案文件。
- 在解决方案资源管理器中，右键单击你想要编译的驱动测试程序（`drv1`，`drv2`或`drv3`），然后选择“生成”。
- 在输出窗口中，你可以看到生成的驱动文件（`.sys`）的路径，例如`C:\DriverLearning\x64\Debug\drv1\drv1.sys`。
- 使用[OSR Driver Loader](https://www.osronline.com/article.cfm?article=157)或其他工具将驱动文件加载到你的系统中，然后使用[DebugView](https://docs.microsoft.com/en-us/sysinternals/downloads/debugview)或其他工具查看系统日志中的打印信息。
- 你也可以编写一个用户程序来与驱动程序交互，例如使用[CreateFile](https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilew)，[ReadFile](https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-readfile)，[WriteFile](https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-writefile)和[CloseHandle](https://docs.microsoft.com/en-us/windows/win32/api/handleapi/nf-handleapi-closehandle)函数来打开，读取，写入和关闭设备。

## 参考资料

以下是一些有用的参考资料，你可以通过它们来学习更多关于windows驱动的知识：

- [Windows 驱动程序文档](https://docs.microsoft.com/en-us/windows-hardware/drivers/)
- [Windows 驱动程序教程](https://www.codeproject.com/Articles/9504/Driver-Development-Part-1-Introduction-to-Drivers)
- [Windows 驱动程序示例](https://github.com/microsoft/Windows-driver-samples)

## 贡献者

这个项目是由忠诚的byby作的，如果你有任何问题或建议，请联系
