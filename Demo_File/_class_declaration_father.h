//
// Created by Administrator on 2018/1/7.
//

//头文件保护符
#ifndef CPP_PROJECTS_CLASS_DECLARATION_H
#define CPP_PROJECTS_CLASS_DECLARATION_H
//
//

#include <iostream>
#include <vector>

using namespace std;


/**
 * 用于存放不同的模块
 */
class ManagerConst;


/**
 * 场景的基类。
 * 内部类——场景Item类。
 * 静态场景名列表。
 */
class BaseScene {

    //内部类
    /**
    * 内部的场景Item类。
    * 构造（地名）。
    */
    struct Scene {
        string address;

        Scene(string scene_name) : address(scene_name) {}
    };

    //变量
public:
    /**
    * 静态全局变量：所有场景名的列表。
    */
    static vector<Scene> scenes;
    //TODO 需要在implementation中进行定义。形式如下：vector<BaseScene::Scene> BaseScene::scenes = { }



    int cur_choice;     //用户目前做出的选项。



    //方法
public:

    /**
     * 内部的抽象方法的声明。（仅在此声明。）
     */


    /**
     * 主要方法就是。wholeLogic( )
     * wholeLogic里面，包含了 updateStatus（初始化成员变量）、check（检查英雄状态）、一个循环（包含了  sayHello（介绍：背景文字和选项文字）、goSwitch（用户输入选项））。
     */

    virtual bool whole_logic() final {

        updateStatus();


        do {

            if (false == checkAlive_orCompleted()) {
                return false;
            };

            describe_scene();

            if (false == continue_switch_action()) {

                return false;
            }


        } while (true);

    };

    virtual void updateStatus()=0;

    virtual bool checkAlive_orCompleted()=0;

    virtual void describe_scene() =0;                    //由子类，进行继承Override重写。

    virtual bool continue_switch_action()=0;            //提供可选择的移动项目，由用后输入选项编号，选择。


};


/**
 * 用于过渡的【和平城镇场景】基类。
 * 目前拥有的子类：Square广场。
 */

class BasePeacePosition : public BaseScene {


    //内部类
    /**
     * 此处内部类，SpecialEvent，用于将来拓展。
     * 比如，在广场，遇到了某个特殊事件（比如精灵小妹子搭讪）。
     */
    struct SpecialEvent {
        //一个特殊的游戏事件
    };


    //变量
public:
    vector<SpecialEvent> surprises;


    //方法
public:

};


/**
 * 用于购买Item的【商店Shop】的基类。
 * 目前拥有的子类：Weapon武器店，Drug药品店。
 */
class BaseShop : public BaseScene {


    //内部类
    /**
     * 单个Item商品的类。
     * 商品Item所含属性：商品名标签、商品单价、商品效果值。
     */
public:
    struct Item {
        int index;
        string label;
        int price;
        int power;

        Item(int t_index, string t_label,
             int t_price, int t_power) : index(t_index), label(t_label),
                                         price(t_price), power(t_power) {}
    };





    //变量
public:
    vector<Item> goods;          //声明一个内含的【待售商品列表】的内部变量。




    //方法
public:

    //virtual void buyItem()= 0;      //购买物品的纯虚函数声明。                //BaseHero已声明这个方法。
    //virtual void sayGoodBye() =0;           //TODO 独属于Shop的店主招呼客人的方法。



    /**
     * 注意：
     * 此处，可以把checkMoney，比拟成一个函数变量。
     * C++，面向函数，闭包。
     */

    /**
     * TODO 检查客户身上的钱。
     */
    //virtual void checkMoney() =0;   //TODO 这个方法，注意一下，可以随时，在购买、出售等环节，都可以调用的。建议做成实方法，然后pirvate。
};


/**
 * BaseMonster在BaseBattleScene中有用到。
 */
class BaseMonster;

/**
 * 新附加的战斗场景类。
 * 变量：Monster实例列表。
 */
class BaseBattleScene : public BaseScene {

    //变量
public:
    int rounds;            //代表现在鏖战的回合数。
    vector<BaseMonster> monsters;

    //方法
public:

};

/**
 * 英雄基类。
 * 基本属性：生命值、攻击力、防御力、金钱。
 * 动作：攻击、逃跑、检查当前数值状态。
 * 数值增减：加减血、加减攻击、加减防御、加减金钱。
 */
class BaseHero {

    //内部类
public:
    /**
     * 购买时，商店的类型
     */
    enum Buy_Shop_Type {
        Buy_In_Weapon_Shop = 1, Buy_In_Drug_Shop = 2,
    };

    /**
     * 购买时，商品所属的功用类型
     */
    enum Buy_Item_Type {
        item_health = 1, item_atk = 2, item_def = 3,
    };

    //变量
public:
    int *health = nullptr;
    int *attack_ability = nullptr;
    int *defence_ability = nullptr;
    int *money = nullptr;

    //方法
public:
    virtual void
    buyItem(BaseHero::Buy_Shop_Type shop_type,
            BaseHero::Buy_Item_Type item_category,
            BaseShop::Item good
    ) = 0;                     //购买商店物品。
    virtual void attack() = 0;              //攻击
    virtual void run_away()= 0;            //逃跑
    virtual void check_battle()= 0;             //检查在战斗中，健康数值是否会导致已经被打死。
    virtual void health_add(int num) = 0;           //吃药加血。
    virtual void atk_add(int num) = 0;              //买武器加攻。
    virtual void def_add(int num)=0;              //买防具加防。
    virtual void money_add(int num) = 0;            //打怪加钱。
    virtual void health_deduce(int num) =0;            //被怪物打减血。
    virtual void money_deduce(int num) = 0;             //买物品减钱。
};


/**
 * 用于描述怪兽的基类。
 * 内部类：【难度调整类】。
 * 构造函数：传入一个已填充值的【难度调整类】。
 * 基本属性：攻击力、防御值、掉落金钱、生命健康值。
 * 动作：
 */
class BaseMonster {


    //内部类
public:
    /**
     * 用于调整四维的成长比例。
     * 根据四维的长短，来定制出非常有个人突出优点和薄弱缺点的怪物。
     * （攻高血少【刺客怪】——攻高防高血少【强化版】——攻低防高血高【血牛】——攻高防高血高金钱高【Boss怪或精英怪】）
     */
    struct Hardness_Ratio {
        int atk_ratio;              //攻击倍率
        int def_ratio;              //防御倍率
        int money_ratio;            //金钱掉率
        int health_ratio;           //生命健康值倍率

        Hardness_Ratio(int atk_r, int def_r, int money_r, int health_r) :
                atk_ratio(atk_r),
                def_ratio(def_r),
                money_ratio(money_r),
                health_ratio(health_r) {};

    };


    //变量
public:
    string label;                           //Monster的学名。
    int attack_ability;             //攻击力。
    int defence_ability;           //防御值。
    int money_remaining;           //掉落金钱。
    int health;                    //生命健康值。


    //方法
public:
    /**
     * 构造函数。需要传入一个【难度调整类】。
     *
     * 这里设置为抽象，是为了使BaseMonster成为抽象类，是为了避免，直接创建BaseMonster实例。
     */
    BaseMonster(string t_label, Hardness_Ratio ratio_obj) {

        this->label = t_label;

        attack_ability *= ratio_obj.atk_ratio;
        defence_ability *= ratio_obj.def_ratio;
        money_remaining *= ratio_obj.money_ratio;
        health *= ratio_obj.health_ratio;
    };

    //BaseMonster() {};     //其实熟练的话，就会理解。其实子类写无参构造，是不需要写父类的无参构造的。调用父类的有参构造就好。


    virtual void makeItVirtual() {};           //仅仅是把BaseMonster，设置为一个抽象类。makeItVirtual方法没有别的意义<>

};











//
//
//头文件保护符
#endif //CPP_PROJECTS_CLASS_DECLARATION_H
