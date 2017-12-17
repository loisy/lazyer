[最终用户使用说明]

    兴业证券股份有限公司遵循勤勉尽责的原则，尽力维护UT极速行情系统的正常运行及数据正确性。
但由于多种不可控的因素存在，兴业证券股份有限公司无法保证UT极速行情系统在任意时刻、任意网络
接入条件下，都能保持系统可用性、数据正确性、数据及时性，亦不为以上各种情况导致的用户损失承
担任何责任。

[使用方法简介]

    UT极速行情系统是一套C/C++语言的程序接口，需要windows环境、Visual Studio 2010以上的开发环
境运行。
    当前UT系统处于测试阶段，提供了32和64位两种平台下的debug/release各版本的运行库与链接库，
并提供了简单的样例程序供参考。文件列表如下：

API                                     接口头文件
 |_XYZQ_UT_API.h
 |_XYZQ_UT_constant.h
 |_XYZQ_UT_datatype.h
bin					接口DLL文件
 |_Win32
 |   |_Debug
 |   |   |_xyzq_ut_api.dll
 |   |_Release
 |       |_XYZQ_UT_API.dll
 |       |_Config.ini			登录信息，UT_Show.exe使用
 |       |_UT_Show.exe			带UI的样例程序
 |_x64
    |_Debug
    |   |_xyzq_ut_api.dll
    |_Release
        |_XYZQ_UT_API.dll
lib					接口链接库文件
 |_Win32
 |   |_Debug
 |   |   |_xyzq_ut_api.lib
 |   |_Release
 |       |_XYZQ_UT_API.lib
 |_x64
    |_Debug
    |   |_xyzq_ut_api.lib
    |_Release
        |_XYZQ_UT_API.lib
xyzq_ut_api_demo			样例程序
 |_ReadMe.txt
 |_stdafx.cpp
 |_stdafx.h
 |_targetver.h
 |_xyzq_ut_api_demo.cpp
 |_xyzq_ut_api_demo.vcxproj
 |_xyzq_ut_api_demo.vcxproj.filters
 |_xyzq_ut_api_demo.vcxproj.user
xyzq_ut_api_c_demo			C语言样例程序
 |_xyzq_ut_api_c_demo.c
 |_xyzq_ut_api_c_demo.vcxproj
 |_xyzq_ut_api_c_demo.vcxproj.filters
 |_xyzq_ut_api_c_demo.vcxproj.user

    大家进行程序开发时可参考demo程序及其工程设置。
    请在QQ群282891067内进行交流与问题反馈。


[Changelog]
[2016-10-31]
新增：C语言API用户文档
新增：C语言开发样例程序
新增：订阅和退订时新增提示包
新增：更新了UT_SHOW，增加逐笔数据订阅内容
修复：修复get_snapshot函数不起作用的问题
修复：修复用户文档中的错误信息或过时信息

[2016-07-18]
新增：C语言API
新增：逐笔成交订阅接口
修复：修复断线重连偶然登陆不上的问题
修复：修复某些错误信息乱码或不匹配的问题
修复：修复其他一些小问题
优化：统一开发版本

[2015-12-31]
新增：期货数据
新增：修改密码接口
修复：修复偶然登陆不上的问题
修复：修复代码表大小写问题
修复：修复其他一些小问题
优化：优化了数据发送速度

[2015-7-22]
新增：数据可按实际类型推送(int和double)
新增：用户参数设置功能
新增：错误信息反馈
新增：系统状态反馈
新增：增强了登录安全性
新增：断线自动重连功能
新增：logout登出功能
新增：心跳功能，减少断线现象
修复：修复某些情况下丢失数据问题
修复：修复大量订阅时可能崩溃问题
修复：其他一些数据不准确的问题
优化：优化了带宽占用
优化：优化了品种代码格式