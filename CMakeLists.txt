CMAKE_MINIMUM_REQUIRED(VERSION 3.9)
PROJECT(CPP_Projects)

SET(CMAKE_CXX_STANDARD 11)

#自己设置常量
SET(EASYX_DIR F:/CPP_Projects/CPP11/Graphic_File)

# set(my_link_libs F:\\CPP_Projects\\C++11\\Graphic_File\\lib)  #不建议这种方式。

# 添加include
INCLUDE_DIRECTORIES(${EASYX_DIR}/include)

# 添加lib
# LINK_DIRECTORIES(${my_link_lib_dirs})

# 添加lib子文件
# LINK_LIBRARIES(${my_link_lib_dirs}/EasyXa.lib ${my_link_lib_dirs}/EasyXw.lib)


ADD_EXECUTABLE(CPP_Projects Code_Life/1.cpp Code_Life/2.cpp Code_Life/3.cpp
        Code_Life/4.cpp Code_Life/5.cpp Code_Life/6.cpp
        Code_Life/Sales_data.h
        Code_Life/7.cpp Code_Life/8.cpp Code_Life/9.cpp Code_Life/10.cpp
        Code_Life/11.cpp Code_Life/12.cpp Code_Life/13.cpp Code_Life/14.cpp
        Code_Life/15.cpp Code_Life/16.cpp Code_Life/17.cpp Code_Life/18.cpp
        Code_Life/19.cpp Code_Life/20.cpp Demo_File/template_game/game_1.cpp
        Demo_File/_class_implementation_son.h Demo_File/_logic_implementation.cpp
        Demo_File/_class_declaration_father.h Demo_File/game.cpp
        Demo_File/_logic_declaration.h Demo_File/Birth_TownSquare.cpp
        Demo_File/ManagerConst.cpp Demo_File/BaseScene.cpp Demo_File/Weapon_Shop.cpp
        Demo_File/LeadingHero.cpp Demo_File/Drug_Shop.cpp
        Demo_File/BiQiTown.cpp
        #[[Graphic_File/1.cpp Graphic_File/2.cpp]] #[[临时增加]]
        Graphic_File/include/easyx.h Graphic_File/include/graphics.h
        Graphic_File/3.cpp)


# 手动完成库的链接操作
# target_link_libraries(CPP_Projects ${my_link_lib_dirs}\\EasyXa.lib ,${my_link_lib_dirs}\\EasyXw.lib)
TARGET_LINK_LIBRARIES(CPP_Projects ${EASYX_DIR}/lib/EasyXa.lib ${EASYX_DIR}/lib/EasyXw.lib)

# 设置把静态库，静态链接进.exe，而不是放在外面，动态链接.dll。网上说，-static-libstdc++ -static-libgcc。设置过程如下
SET(CMAKE_EXE_LINKER_FLAGS "-static-libstdc++ -static-libgcc")


# 添加"this file does not belong to any project target"？
# set(SOURCE_FILES CPP_Projects Code_Life/1.cpp Code_Life/2.cpp Code_Life/3.cpp Code_Life/4.cpp Code_Life/5.cpp Code_Life/6.cpp Code_Life/Sales_data.h Code_Life/7.cpp Code_Life/8.cpp Code_Life/9.cpp Code_Life/10.cpp Code_Life/11.cpp Code_Life/12.cpp Code_Life/13.cpp Code_Life/14.cpp Code_Life/15.cpp Code_Life/16.cpp Code_Life/17.cpp Code_Life/18.cpp Code_Life/19.cpp Code_Life/20.cpp Demo_File/template_game/game_1.cpp Demo_File/_class_implementation_son.h Demo_File/_logic_implementation.cpp Demo_File/_class_declaration_father.h Demo_File/game.cpp Demo_File/_logic_declaration.h Demo_File/Birth_TownSquare.cpp Demo_File/ManagerConst.cpp Demo_File/BaseScene.cpp Demo_File/Weapon_Shop.cpp Demo_File/LeadingHero.cpp Demo_File/Drug_Shop.cpp Demo_File/BiQiTown.cpp Graphic_File/1.cpp Graphic_File/include/easyx.h Graphic_File/include/graphics.h)

# target_link_libraries("Graphic_File/lib/EasyXa.lib Graphic_File/lib/EasyXw.lib")