# ISFPPlugin

ISFPPlugin 是一个 EuroScope 插件，为 ISFPFLY 虚拟航空提供增强功能。

## 功能特性

### 1. 雷达屏幕水印
在 EuroScope 雷达屏幕左下角显示水印：
- **ISFPPlugin**
- **Powered by ISFPFLY**

水印特点：
- 位置：左下角，距左边 120 像素，距底部 130 像素
- 字体：Arial 粗体，20 像素
- 颜色：浅灰色 (RGB 200, 200, 200)

### 2. 欢迎信息
插件加载时自动显示欢迎信息：
```
ISFPPlugin Powered by ISFPFLY
Welcome to ISFPFLY!
Server Address: fsd.flyisfp.com
TeamSpeak Address: ts.flyisfp.com
QQ Group: 644614465
Have a good time!
```

## 安装说明

### 前提条件
- EuroScope 3.2 或更高版本
- Windows 操作系统

### 安装步骤

1. **下载插件**
   - 从发布页面下载 `ISFPPlugin.dll`

2. **放置文件**
   - 将 `ISFPPlugin.dll` 复制到你的 EuroScope 插件目录

3. **加载插件**
   - 打开 EuroScope
   - 进入 **OTHER SET** → **Plug-ins...**
   - 点击 **Load**，选择 `ISFPPlugin.dll`
   - 在插件列表中选择 **ISFPPlugin**
   - 将 **"Standard ES radar screen"** 从 **"Forbidden to draw on types"** 移动到 **"Allowed to draw on types"**
   - 点击 **Close**

4. **保存配置**
   - 进入 **OTHER SET** → **Save profile**

## 使用方法

### 启用雷达屏幕水印
1. 确保已按照安装步骤允许插件在标准雷达屏幕上绘制
2. 打开或刷新雷达屏幕即可看到水印

### 查看欢迎信息
- 每次加载插件时，欢迎信息会自动显示在消息框中

## 项目结构

```
ISFPPlugin/
├── CESPlugIn.h          # 主插件类头文件
├── CESPlugIn.cpp        # 主插件类实现
├── ISFPRadarScreen.h    # 雷达屏幕类头文件
├── ISFPRadarScreen.cpp  # 雷达屏幕类实现（水印绘制）
├── ISFPPlugin.vcxproj   # Visual Studio 项目文件
├── include/             # EuroScope SDK 头文件和库
│   ├── EuroScopePlugIn.h
│   └── EuroScopePlugInDll.lib
└── README.md            # 本文件
```

## 编译说明

### 环境要求
- Visual Studio 2022 或更高版本
- Windows SDK
- MFC 支持

### 编译步骤

1. 打开 `ISFPPlugin.vcxproj`
2. 选择 **Release** 配置和 **Win32** 平台
3. 点击 **生成** → **生成解决方案**
4. 生成的 `ISFPPlugin.dll` 位于 `Release/` 目录

## 技术细节

### 插件信息
- **名称**: ISFPPlugin
- **版本**: 1.0.0
- **作者**: ISFPFLY
- **版权**: Powered by ISFPFLY

### API 使用
- 继承 `EuroScopePlugIn::CPlugIn` 实现主插件类
- 继承 `EuroScopePlugIn::CRadarScreen` 实现雷达屏幕绘制
- 使用 `OnRadarScreenCreated` 接管标准雷达屏幕
- 使用 `OnRefresh` 在 `REFRESH_PHASE_AFTER_LISTS` 阶段绘制水印

## 许可证

本项目采用 MIT 许可证开源。

## 联系我们

- **服务器**: fsd.flyisfp.com
- **TeamSpeak**: ts.flyisfp.com
- **QQ 群**: 644614465

---

Powered by [ISFPFLY](https://www.flyisfp.com)
