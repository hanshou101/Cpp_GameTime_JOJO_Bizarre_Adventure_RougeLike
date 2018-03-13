#include "_class_declaration_father.h"
#include "_class_implementation_son.h"

#include <iostream>
#include <vector>

using namespace std;


/**
    * 正数，代表武器。
    * 负数，代表防具。
    */
//vector<BaseShop::Item> Weapon_Shop::goods = {
//        BaseShop::Item(0, "什么都不买", 0, 0),
//        BaseShop::Item(1, "小刀", 10, 2),
//        BaseShop::Item(2, "短剑", 80, 20),
//        BaseShop::Item(3, "大砍刀", 140, 40),
//        BaseShop::Item(4, "双节棍", 200, 60),
//        BaseShop::Item(5, "盾牌", 60, -30),
//        BaseShop::Item(6, "铠甲", 100, -60),
//        BaseShop::Item(7, "离开武器店", 0, 0),
//};


void Weapon_Shop::updateStatus() {

    /**
    * 准备初始值。
    */
    cur_choice = 0;

}

bool Weapon_Shop::checkAlive_orCompleted() {
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
}

void Weapon_Shop::describe_scene() {


    /**
     * 先进行，商店的自我介绍。和提供的各个购买选项介绍。
     */

    cout << "欢迎来到武器店！\n" << endl;
    for (int i = 1; i < goods.size(); ++i) {
        if (goods[i].power > 0) {
            //cout << goods[i].index << "、买" << goods[i].label << "（" << goods[i].price << "G加" << goods[i].power
            //     << "攻击力）" << endl;
            printf("%d、买%s（%dG加%d攻击力）", goods[i].index, goods[i].label.c_str(), goods[i].price, goods[i].power);
        }
        if (goods[i].power < 0) {
            //cout << goods[i].index << "、买" << goods[i].label << "（" << goods[i].price << "G加" << goods[i].power
            //     << "防御力）" << endl;
            printf("%d、买%s（%dG加%d防御力）", goods[i].index, goods[i].label.c_str(), goods[i].price, (0 - goods[i].power));
        }
        if (goods[i].power == 0) {
            //cout << goods[i].index << "、" << goods[i].label << endl;
            printf("%d、%s", goods[i].index, goods[i].label.c_str());
        }
        printf("\n");
    };

}


bool Weapon_Shop::continue_switch_action() {
    LeadingHero *hero = ((LeadingHero *) (ManagerConst().heroList[0]));     //取到当前英雄的指针。


    /**
     * 等待用户输入选项键。
     *
     * （通过return方式，返回false给whole_logic。然后whole_logic,因为收到false，所以走whole_logic的return分支。）跳出这个循环，就等于离开了武器店。
     */


    cin >> cur_choice;

    //判断choice的值。

    if (cur_choice == goods.size() - 1) {
        return false;              //选择了最后一个选项的话，则退出当前武器店的界面。回到中心广场。
    };


    //选择了武器购买。
    if (goods[cur_choice].power > 0) {

        //武器类。增加攻击力。

        hero->buyItem(BaseHero::Buy_Shop_Type::Buy_In_Weapon_Shop,
                      BaseHero::Buy_Item_Type::item_atk,
                      goods[cur_choice]
        );


    }
        //选择了盔甲购买。
    else if (goods[cur_choice].power < 0) {

        //防具类。增加防御力。

        hero->buyItem(BaseHero::Buy_Shop_Type::Buy_In_Weapon_Shop,
                      BaseHero::Buy_Item_Type::item_def,
                      goods[cur_choice]
        );

    }
        //选择了其它。
    else if (goods[cur_choice].power == 0) {

        //什么都不买选项。
        cout << "你选择了什么都不买选项" << "，" << "下面我将为你讲一个故事：从前有座山" << endl;

    };

    return true;

}
