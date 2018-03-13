#include "_class_declaration_father.h"
#include "_class_implementation_son.h"

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;


void Birth_TownSquare::updateStatus() {
    cur_choice = 0;
}


bool Birth_TownSquare::checkAlive_orCompleted() {

    LeadingHero *hero = (LeadingHero *) (ManagerConst().heroList[0]);

    /**
     * 检测英雄的基本状态：存活或者过关状态。
     */
    if (0 >= hero->health)                       //主角生命力小于等于0时游戏结束
    {
        cout << "英雄生命值不足，已经被世界树召回！" << endl;
        return false;
    }


    if (hero->attack_ability > 9999) {                                //触发了过关的条件，则游戏自动进阶
        cout << "可以穿戴战神盔甲。" << endl;
        cout << "恭喜你，完成了终极任务，终于过关了！" << endl;
        return false;
    }

    return true;
};

void Birth_TownSquare::describe_scene() {
    //TODO 基本场景描述。（为选项做铺垫。写给玩家看的环境背景和选项分支）。【背景】+【选项】
    //进行最基本的，【场景】【上下文】介绍。


    cout << "经过了片刻时间后，你来到了：" << endl;
    cout << "小镇\n" << endl;
    cout << "一个1000年的小镇。周围有一条河，有一片树林，很多房子和很多人。\n有一家药店" << endl;
    cout << "和一家武器店。\n" << endl;

    /**
     * 前情选项提醒。在每次循环的最前面（甚至在输入选项指令之前。）
     */

    cout << "1.去武器店" << endl;
    cout << "2.去药品店" << endl;
    cout << "3.去打小怪物" << endl;
    cout << "4.去打大怪物" << endl;
    cout << "5.显示你的状态" << endl;
    cout << "6.退出游戏" << endl;
}


bool Birth_TownSquare::continue_switch_action() {

    LeadingHero *hero = (LeadingHero *) (ManagerConst().heroList[0]);

    cin >> cur_choice;

    if (cur_choice == 6) {
        //如果是输入了  分支6  的话，则自动结束该游戏。（可以考虑加入先存盘再退出系统。）

        //hWnd，消息框所在窗口。 lpText，消息框的内容。  lpCaption，消息框的标题。   uType，消息框的种类。
        //int box_result_1 = MessageBox(nullptr, "这是一个\n确定 取消\n的消息框", "标题栏①", MB_OKCANCEL);
        //int box_result_2 = MessageBox(nullptr, "这是一个警告的消息框", "标题栏②", MB_ICONEXCLAMATION);
        //int box_result_3 = MessageBox(nullptr, "这是一个\n两种属性\n的消息框", "标题栏③", MB_ICONEXCLAMATION|MB_OKCANCEL);
        //int box_result_4 = MessageBox(nullptr, "应用模式、一", "标题栏④", MB_ICONINFORMATION|MB_OKCANCEL);
        //int box_result_5 = MessageBox(nullptr, "按钮模式、一", "标题栏⑤", MB_ICONINFORMATION|MB_OKCANCEL);
        //int box_result_6 = MessageBox(nullptr, "按钮模式、二", "标题栏⑥", MB_ICONINFORMATION|MB_YESNO);
        //int box_result_7 = MessageBox(nullptr, "按钮模式、三", "标题栏⑦", MB_ICONINFORMATION|MB_OK);
        //int box_result_8 = MessageBox(nullptr, "按钮模式、四", "标题栏⑧", MB_ICONINFORMATION|MB_CANCELTRYCONTINUE);//取消、重试、继续
        //int box_result_9 = MessageBox(nullptr, "按钮模式、五", "标题栏⑨", MB_ICONINFORMATION | MB_YESNOCANCEL);//是、否、取消
        int box_result_10 = MessageBox(nullptr, "你确定要退出游戏吗？", "退出游戏", MB_ICONINFORMATION | MB_YESNOCANCEL);//是、否、取消
        switch (box_result_10) {
            case IDYES: {
                cout << "点击了是按钮" << endl;
                MessageBox(nullptr, "青山不改，绿水长流！", "退隐江湖！", MB_ICONEXCLAMATION);
                return false;
            }
            case IDNO: {
                cout << "点击了否按钮" << endl;
                return true;
            }
            case IDOK: {
                cout << "点击了确定按钮" << endl;        //IDOK竟然和IDYES是不同的，匪夷所思。
                return false;               //中断当前方法。返回False。进而中断whole_logic里的循环。使Birth_TownSquare的whole_logic走到尽头，进而退出Birth_TownSquare。
            }
            case IDCANCEL: {
                cout << "点击了取消按钮" << endl;
                return true;                //中断当前方法。但不中断whole_logic里的循环。
            }
            case IDRETRY: {
                cout << "点击了重试按钮" << endl;
                return true;
            }

            case IDCONTINUE: {
                cout << "点击了继续按钮" << endl;
                return true;
            }
        }

    };


    switch (cur_choice) {
        case 1:
            //去武器店。
            ((Weapon_Shop *) (ManagerConst().sceneList[1]))->whole_logic();
            break;

        case 2:
            //去药品店。
            ((Drug_Shop *) (ManagerConst().sceneList[2]))->whole_logic();
            break;

        case 3:
            //去打多钩猫。
            ((BiQiTown *) (ManagerConst().sceneList[3]))->whole_logic();
            break;

        case 4:
            //去打森林雪人。
            ((BiQiTown *) (ManagerConst().sceneList[4]))->whole_logic();
            break;

        case 5:
            //检查自身状态。
            printf("\n");
            printf("当前状态：   \n生命健康值：%d   \n攻击力：%d   \n防御力：%d   \n背包金钱：%d   ",
                   hero->health, hero->attack_ability, hero->defence_ability, hero->money);
            printf("\n");
            printf("\n");
            break;

        default:
            cout << "你输入的选项编号，暂无法识别";
            break;


    }

    return true;

}


