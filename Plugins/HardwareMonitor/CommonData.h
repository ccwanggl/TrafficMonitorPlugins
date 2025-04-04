﻿#pragma once
#include <string>
#include <vector>
#include "PluginInterface.h"

namespace HardwareMonitor
{
    struct ItemInfo
    {
        std::wstring identifyer;    //唯一标识符
        int decimal_places{ 1 };         //小数位数
        bool specify_value_width{ true };  //指定数值宽度（不含小数和单位）
        int value_width{ 3 };       //数值宽度
        std::wstring unit;          //单位
        bool show_unit{ true };     //是否显示单位

        ItemInfo()
        {}

        ItemInfo(const std::wstring& _identifyer)
            : identifyer(_identifyer)
        {}

        ItemInfo(const std::wstring& _identifyer, int _decimal_places)
            : identifyer(_identifyer), decimal_places(_decimal_places)
        {}
    };

    //选项设置数据
    struct OptionSettings
    {
        std::vector<ItemInfo> items_info;     //所有监控项目
        ItemInfo& FindItemInfo(const std::wstring& identifyer);     //根据identifyer，在items_info找到ItemInfo对象

        bool hardware_info_auto_refresh{};              //监控信息界面是否自动刷新
        bool show_mouse_tooltip{};
    };

    //分别定义一个用于主窗口和任务栏窗口的设置数据，同时定义一个函数，根据is_taskbar返回对应的值
#define DECLARE_TM_SETTINGS_DATA(type, data) \
    type taskbar_##data{}; \
    type main_wnd_##data{}; \
    type data() const \
    { \
        return is_taskbar ? taskbar_##data : main_wnd_##data; \
    }

    //TrafficMonitor的设置数据
    struct TMSettings
    {
        bool is_taskbar{};
        DECLARE_TM_SETTINGS_DATA(bool, sperate_with_space)  //数值和单位使用空格分隔
    };
}