# C Primer Plus 6E


## 关于此仓库

此仓库是《C Primer Plus 6E》所涵盖的代码（有我个人的一些改动）。.vscode 目录下的文件是在 vscode 中运行的相关配置，`ch` 前缀的目录对应着书上的每个章节，目录内的 `ex` 前缀的代码对应着章节中的每个示例。.clang-format 用来控制代码的整体风格。


## 运行环境

可以在 Windows/Linux/MacOS 上运行，因为 CMake 是跨平台的，Windows 上也有相关 GCC 编译器的实现。理论上只要要配置好编译器和CMake，就可以运行此仓库的代码。


## vscode插件推荐

- `C/C++` 核心插件
- `CMake` 提供CMake语法高亮和代码补全
- `CMake Tools` 运行、调试CMake项目的官方插件
- `Clang-Format` 代码格式化插件
- `TabOut` Tab键自动跳出括号
- `Doxygen Documentation Generator` 可以快速生成注释文档


## 推荐教程

- [快速入门 CMake 项目](https://code.visualstudio.com/docs/cpp/CMake-linux)

- [clang-format 配置选项](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)