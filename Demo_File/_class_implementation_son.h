//
// Created by Administrator on 2018/1/7.
//

//ͷ�ļ�������
#ifndef CPP_PROJECTS_CLASS_IMPLEMENTATION_H
#define CPP_PROJECTS_CLASS_IMPLEMENTATION_H
//
//

#include <iostream>
#include <vector>

#include "_class_declaration_father.h"

using namespace std;


/**
 * 0.��Ų�ͬ����Ϸģ�顣
 */
class ManagerConst {
    //����
public:
    static vector<BaseHero *> heroList;
    static vector<BaseScene *> sceneList;
    static vector<BaseMonster *> monsterList;

    //����
public:
    explicit ManagerConst(bool needInit);

    explicit ManagerConst();

private:
    void initConstManager();
};


/**
 * 1.Ϊ����׼����Ӣ�����ࡣ
 */
class LeadingHero : public BaseHero {

    //����
public:


    int health = 100;
    int attack_ability = 10;
    int defence_ability = 5;
    int money = 50;


    //����
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
 * 2.��̬ȫ�ֱ��������г��������б�������>�Ķ��塣�������Ͷ�����룩
 */
//TODO ���ڲ���ȫ�ֱ��������� .h �ļ������ʵ����������  "version1_func_implementation.cpp" �


/**
 * 3.�����㳡��Ķ��塣
 */
class Birth_TownSquare : public BasePeacePosition {

    //����
public:

    //����
public:

    void updateStatus() override;

    bool checkAlive_orCompleted() override;

    void describe_scene() override;

    bool continue_switch_action() override;

};


/**
 * 4.ʵ��������Ķ��塣
 */
class Weapon_Shop : public BaseShop {


    //����
public:
    /**
     * ����������������
     * ������������ߡ�
     */
    vector<Item> goods = {
            BaseShop::Item(0, "ʲô������", 0, 0),
            BaseShop::Item(1, "С��", 10, 2),
            BaseShop::Item(2, "�̽�", 80, 20),
            BaseShop::Item(3, "�󿳵�", 140, 40),
            BaseShop::Item(4, "˫�ڹ�", 200, 60),
            BaseShop::Item(5, "����", 60, -30),
            BaseShop::Item(6, "����", 100, -60),
            BaseShop::Item(7, "�뿪������", 0, 0),
    };

    //����
public:
    void describe_scene() override;

    void updateStatus() override;

    bool checkAlive_orCompleted() override;

    bool continue_switch_action() override;
};


/**
 * 5.ʵ��ҩƷ��Ķ��塣
 */
class Drug_Shop : public BaseShop {

    //����
public:
    vector<Item> goods = {
            BaseShop::Item(0, "ʲô������", 0, 0),
            BaseShop::Item(1, "1�Ų�Ѫҩ", 10, 200),
            BaseShop::Item(2, "2�Ų�Ѫҩ", 50, 1200),
            BaseShop::Item(3, "3�Ų�Ѫҩ", 100, 2500),
            BaseShop::Item(4, "�뿪ҩƷ��", 0, 0),

    };

    //����
public:
    void updateStatus() override;

    bool checkAlive_orCompleted() override;

    void describe_scene() override;

    bool continue_switch_action() override;

};


/**
 * 6.С�͹���๳è��
 *
 */

class HookMoreCat : public BaseMonster {
    //����
public:
//    string label = "�๳è";
//    int attack_ability = 10;             //��������
//    int defence_ability = 10;           //����ֵ��
//    int money_remaining = 10;           //�����Ǯ��
//    int health = 50;                    //��������ֵ��

    //����
public:
    /**
     * ���캯��������Ϊʲô����д������Ŀǰ�����ö�֪�������ʼǼ��ϣ�
     * д&���á�������Ϊ���ų�ָ�����͡�
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
     * ��������вι���������ơ�
     * ���������һ��Ĭ�ϵ�����Hardness_Ratio�ࡣ
     */
    explicit HookMoreCat() : HookMoreCat("�๳è", Hardness_Ratio(1, 1, 1, 1)) {
        //���캯�������õ�������ȷд����
    }

};


/**
 * 7.���͹��ɭ��ѩ�ˡ�
 */

class ForestSnowman : public BaseMonster {
    //����
public:
//    string label = "ɭ��ѩ��";
//    int attack_ability = 10;             //��������
//    int defence_ability = 10;           //����ֵ��
//    int money_remaining = 10;           //�����Ǯ��
//    int health = 50;                    //��������ֵ��

    //����
public:
    /**
     * ���캯��������Ϊʲô����д������Ŀǰ�����ö�֪�������ʼǼ��ϣ�
     * д&���á�������Ϊ���ų�ָ�����͡�
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
     * ��������вι���������ơ�
     * ���������һ��Ĭ�ϵ�����Hardness_Ratio�ࡣ
     */
    explicit ForestSnowman() : ForestSnowman("ɭ��ѩ��", Hardness_Ratio(3, 2, 10, 2)) {
        //���캯�������õ�������ȷд����
    }

};

/**
 * 8.����ս��������������
 */
class BiQiTown : public BaseBattleScene {

    //����
public:

    enum BattleType {
        Cat_Small = 1, Snowman_Large = 2
    };

    BattleType battleType;                          //ս�����ͣ���������Сè��׷�����ѩ�ˡ���



    bool faceMonster;              //�ʼ����Ѱ�֣��Ƿ��Ѿ����֡�
    vector<BaseMonster *> monsters = vector<BaseMonster *>();
    vector<LeadingHero *> heros = vector<LeadingHero *>();


    //����
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
//ͷ�ļ�������
#endif //CPP_PROJECTS_CLASS_DECLARATION_H
