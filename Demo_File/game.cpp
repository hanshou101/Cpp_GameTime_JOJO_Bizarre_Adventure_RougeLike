#include "_class_implementation_son.h"             //数据类型
#include "_class_declaration_father.h"             //数据类型
#include "_logic_declaration.h"             //业务逻辑

/**
 * 原版创意地址  《用C++语言写游戏——打怪小游戏》
 *             http://blog.csdn.net/cnyali_ljf/article/details/51340317
 */

int main_main_main() {

    ManagerConst manager = ManagerConst(true);//世界管理类
    Birth_TownSquare *square = (Birth_TownSquare *) (manager.sceneList[0]);               //广场的实例。

    square->whole_logic();           //进入【广场】场景的主逻辑。

    return 0;
}


