//
// Created by Administrator on 2018/1/7.
//

//头文件保护符
#ifndef CPP_PROJECTS_CLASS_IMPLEMENTATION_H
#define CPP_PROJECTS_CLASS_IMPLEMENTATION_H
//
//

#include <iostream>
#include <vector>

#include "_class_declaration_father.h"

using namespace std;


/**
 * 0.存放不同的游戏模块。
 */
class ManagerConst {
    //变量
public:
    static vector<BaseHero *> heroList;
    static vector<BaseScene *> sceneList;
    static vector<BaseMonster *> monsterList;

    //方法
public:
    explicit ManagerConst(bool needInit);

    explicit ManagerConst();

private:
    void initConstManager();
};


/**
 * 1.为主角准备的英雄子类。
 */
class LeadingHero : public BaseHero {

    //变量
public:


    int health = 100;
    int attack_ability = 10;
    int defence_ability = 5;
    int money = 50;


    //方法
public:

    void buyItem(BaseHero::Buy_Shop_Type shop_type,
                 BaseHero::Buy_Item_Type item_category,
                 BaseShop::Item good) override;

    void attack() override {

    }

    void run_away() override {

    }

    void check_battle() override {

    }

    void health_add(int num) override {

    }

    void atk_add(int num) override {

    }

    void def_add(int num) override {

    }

    void money_add(int num) override {

    }

    void health_deduce(int num) override {

    }

    void money_deduce(int num) override {

    }

};


/**
 * 2.静态全局变量：所有场景名的列表————>的定义。（声明和定义分离）
 */
//TODO 基于不把全局变量定义在 .h 文件的最佳实践，已移至  "version1_func_implementation.cpp" 里。


/**
 * 3.出生广场类的定义。
 */
class Birth_TownSquare : public BasePeacePosition {

    //变量
public:

    //方法
public:

    void updateStatus() override;

    bool checkAlive_orCompleted() override;

    void describe_scene() override;

    bool continue_switch_action() override;

};


/**
 * 4.实体武器店的定义。
 */
class Weapon_Shop : public BaseShop {


    //变量
public:
    /**
     * 正数，代表武器。
     * 负数，代表防具。
     */
    vector<Item> goods = {
            BaseShop::Item(0, "什么都不买", 0, 0),
            BaseShop::Item(1, "小刀", 10, 2),
            BaseShop::Item(2, "短剑", 80, 20),
            BaseShop::Item(3, "大砍刀", 140, 40),
            BaseShop::Item(4, "双节棍", 200, 60),
            BaseShop::Item(5, "盾牌", 60, -30),
            BaseShop::Item(6, "铠甲", 100, -60),
            BaseShop::Item(7, "离开武器店", 0, 0),
    };

    //方法
public:
    void describe_scene() override;

    void updateStatus() override;

    bool checkAlive_orCompleted() override;

    bool continue_switch_action() override;
};


/**
 * 5.实体药品店的定义。
 */
class Drug_Shop : public BaseShop {

    //变量
public:
    vector<Item> goods = {
            BaseShop::Item(0, "什么都不买", 0, 0),
            BaseShop::Item(1, "1号补血药", 10, 200),
            BaseShop::Item(2, "2号补血药", 50, 1200),
            BaseShop::Item(3, "3号补血药", 100, 2500),
            BaseShop::Item(4, "离开药品店", 0, 0),

    };

    //方法
public:
    void updateStatus() override;

    bool checkAlive_orCompleted() override;

    void describe_scene() override;

    bool continue_switch_action() override;

};


/**
 * 6.小型怪物：多钩猫。
 *
 */

class HookMoreCat : public BaseMonster {
    //变量
public:
//    string label = "多钩猫";
//    int attack_ability = 10;             //攻击力。
//    int defence_ability = 10;           //防御值。
//    int money_remaining = 10;           //掉落金钱。
//    int health = 50;                    //生命健康值。

    //方法
public:
    /**
     * 构造函数。至于为什么这样写……（目前还不得而知，先做笔记记上）
     * 写&引用。可能是为了排除指针类型。
     */
    explicit HookMoreCat(string t_label, const Hardness_Ratio &ratio_obj) : BaseMonster(t_label, ratio_obj) {
        this->label = t_label;
        this->attack_ability *= ratio_obj.atk_ratio;
        this->defence_ability *= ratio_obj.def_ratio;
        this->money_remaining *= ratio_obj.money_ratio;
        this->health *= ratio_obj.health_ratio;
    }

public:
    /**
     * 与上面的有参构造大体类似。
     * 这里添加了一个默认的内置Hardness_Ratio类。
     */
    explicit HookMoreCat() : HookMoreCat("多钩猫", Hardness_Ratio(1, 1, 1, 1)) {
        //构造函数，复用的最新正确写法。
    }

};


/**
 * 7.中型怪物：森林雪人。
 */

class ForestSnowman : public BaseMonster {
    //变量
public:
//    string label = "森林雪人";
//    int attack_ability = 10;             //攻击力。
//    int defence_ability = 10;           //防御值。
//    int money_remaining = 10;           //掉落金钱。
//    int health = 50;                    //生命健康值。

    //方法
public:
    /**
     * 构造函数。至于为什么这样写……（目前还不得而知，先做笔记记上）
     * 写&引用。可能是为了排除指针类型。
     */
    explicit ForestSnowman(string t_label, const Hardness_Ratio &ratio_obj) : BaseMonster(t_label, ratio_obj) {
        this->label = t_label;
        this->attack_ability *= ratio_obj.atk_ratio;
        this->defence_ability *= ratio_obj.def_ratio;
        this->money_remaining *= ratio_obj.money_ratio;
        this->health *= ratio_obj.health_ratio;
    }

public:
    /**
     * 与上面的有参构造大体类似。
     * 这里添加了一个默认的内置Hardness_Ratio类。
     */
    explicit ForestSnowman() : ForestSnowman("森林雪人", Hardness_Ratio(3, 2, 10, 2)) {
        //构造函数，复用的最新正确写法。
    }

};

/**
 * 8.基本战斗场景：比奇镇。
 */
class BiQiTown : public BaseBattleScene {

    //变量
public:

    enum BattleType {
        Cat_Small = 1, Snowman_Large = 2
    };

    BattleType battleType;                          //战斗类型：（火球术小猫。追至村口雪人。）



    bool faceMonster;              //最开始处在寻怪，是否已经遇怪。
    vector<BaseMonster *> monsters = vector<BaseMonster *>();
    vector<LeadingHero *> heros = vector<LeadingHero *>();


    //方法
public:

    BiQiTown(BattleType t_type);

    BiQiTown(BaseMonster *t_monster, BattleType t_type);

    BiQiTown(BaseMonster *t_monster, LeadingHero *t_hero, BattleType t_type);


    void updateStatus() override;

    bool checkAlive_orCompleted() override;

    void describe_scene() override;

    bool continue_switch_action() override;

};



//
//
//头文件保护符
#endif //CPP_PROJECTS_CLASS_DECLARATION_H
