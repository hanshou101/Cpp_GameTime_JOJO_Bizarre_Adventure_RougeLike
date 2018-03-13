//
// Created by Administrator on 2018/1/7.
//

//ͷ�ļ�������
#ifndef CPP_PROJECTS_CLASS_DECLARATION_H
#define CPP_PROJECTS_CLASS_DECLARATION_H
//
//

#include <iostream>
#include <vector>

using namespace std;


/**
 * ���ڴ�Ų�ͬ��ģ��
 */
class ManagerConst;


/**
 * �����Ļ��ࡣ
 * �ڲ��ࡪ������Item�ࡣ
 * ��̬�������б�
 */
class BaseScene {

    //�ڲ���
    /**
    * �ڲ��ĳ���Item�ࡣ
    * ���죨��������
    */
    struct Scene {
        string address;

        Scene(string scene_name) : address(scene_name) {}
    };

    //����
public:
    /**
    * ��̬ȫ�ֱ��������г��������б�
    */
    static vector<Scene> scenes;
    //TODO ��Ҫ��implementation�н��ж��塣��ʽ���£�vector<BaseScene::Scene> BaseScene::scenes = { }



    int cur_choice;     //�û�Ŀǰ������ѡ�



    //����
public:

    /**
     * �ڲ��ĳ��󷽷��������������ڴ���������
     */


    /**
     * ��Ҫ�������ǡ�wholeLogic( )
     * wholeLogic���棬������ updateStatus����ʼ����Ա��������check�����Ӣ��״̬����һ��ѭ����������  sayHello�����ܣ��������ֺ�ѡ�����֣���goSwitch���û�����ѡ�����
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

    virtual void describe_scene() =0;                    //�����࣬���м̳�Override��д��

    virtual bool continue_switch_action()=0;            //�ṩ��ѡ����ƶ���Ŀ�����ú�����ѡ���ţ�ѡ��


};


/**
 * ���ڹ��ɵġ���ƽ���򳡾������ࡣ
 * Ŀǰӵ�е����ࣺSquare�㳡��
 */

class BasePeacePosition : public BaseScene {


    //�ڲ���
    /**
     * �˴��ڲ��࣬SpecialEvent�����ڽ�����չ��
     * ���磬�ڹ㳡��������ĳ�������¼������羫��С���Ӵ�ڨ����
     */
    struct SpecialEvent {
        //һ���������Ϸ�¼�
    };


    //����
public:
    vector<SpecialEvent> surprises;


    //����
public:

};


/**
 * ���ڹ���Item�ġ��̵�Shop���Ļ��ࡣ
 * Ŀǰӵ�е����ࣺWeapon�����꣬DrugҩƷ�ꡣ
 */
class BaseShop : public BaseScene {


    //�ڲ���
    /**
     * ����Item��Ʒ���ࡣ
     * ��ƷItem�������ԣ���Ʒ����ǩ����Ʒ���ۡ���ƷЧ��ֵ��
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





    //����
public:
    vector<Item> goods;          //����һ���ں��ġ�������Ʒ�б����ڲ�������




    //����
public:

    //virtual void buyItem()= 0;      //������Ʒ�Ĵ��麯��������                //BaseHero���������������
    //virtual void sayGoodBye() =0;           //TODO ������Shop�ĵ����к����˵ķ�����



    /**
     * ע�⣺
     * �˴������԰�checkMoney�������һ������������
     * C++�����������հ���
     */

    /**
     * TODO ���ͻ����ϵ�Ǯ��
     */
    //virtual void checkMoney() =0;   //TODO ���������ע��һ�£�������ʱ���ڹ��򡢳��۵Ȼ��ڣ������Ե��õġ���������ʵ������Ȼ��pirvate��
};


/**
 * BaseMonster��BaseBattleScene�����õ���
 */
class BaseMonster;

/**
 * �¸��ӵ�ս�������ࡣ
 * ������Monsterʵ���б�
 */
class BaseBattleScene : public BaseScene {

    //����
public:
    int rounds;            //����������ս�Ļغ�����
    vector<BaseMonster> monsters;

    //����
public:

};

/**
 * Ӣ�ۻ��ࡣ
 * �������ԣ�����ֵ��������������������Ǯ��
 * ���������������ܡ���鵱ǰ��ֵ״̬��
 * ��ֵ�������Ӽ�Ѫ���Ӽ��������Ӽ��������Ӽ���Ǯ��
 */
class BaseHero {

    //�ڲ���
public:
    /**
     * ����ʱ���̵������
     */
    enum Buy_Shop_Type {
        Buy_In_Weapon_Shop = 1, Buy_In_Drug_Shop = 2,
    };

    /**
     * ����ʱ����Ʒ�����Ĺ�������
     */
    enum Buy_Item_Type {
        item_health = 1, item_atk = 2, item_def = 3,
    };

    //����
public:
    int *health = nullptr;
    int *attack_ability = nullptr;
    int *defence_ability = nullptr;
    int *money = nullptr;

    //����
public:
    virtual void
    buyItem(BaseHero::Buy_Shop_Type shop_type,
            BaseHero::Buy_Item_Type item_category,
            BaseShop::Item good
    ) = 0;                     //�����̵���Ʒ��
    virtual void attack() = 0;              //����
    virtual void run_away()= 0;            //����
    virtual void check_battle()= 0;             //�����ս���У�������ֵ�Ƿ�ᵼ���Ѿ���������
    virtual void health_add(int num) = 0;           //��ҩ��Ѫ��
    virtual void atk_add(int num) = 0;              //�������ӹ���
    virtual void def_add(int num)=0;              //����߼ӷ���
    virtual void money_add(int num) = 0;            //��ּ�Ǯ��
    virtual void health_deduce(int num) =0;            //��������Ѫ��
    virtual void money_deduce(int num) = 0;             //����Ʒ��Ǯ��
};


/**
 * �����������޵Ļ��ࡣ
 * �ڲ��ࣺ���Ѷȵ����ࡿ��
 * ���캯��������һ�������ֵ�ġ��Ѷȵ����ࡿ��
 * �������ԣ�������������ֵ�������Ǯ����������ֵ��
 * ������
 */
class BaseMonster {


    //�ڲ���
public:
    /**
     * ���ڵ�����ά�ĳɳ�������
     * ������ά�ĳ��̣������Ƴ��ǳ��и���ͻ���ŵ�ͱ���ȱ��Ĺ��
     * ������Ѫ�١��̿͹֡��������߷���Ѫ�١�ǿ���桿�������ͷ���Ѫ�ߡ�Ѫţ���������߷���Ѫ�߽�Ǯ�ߡ�Boss�ֻ�Ӣ�֡���
     */
    struct Hardness_Ratio {
        int atk_ratio;              //��������
        int def_ratio;              //��������
        int money_ratio;            //��Ǯ����
        int health_ratio;           //��������ֵ����

        Hardness_Ratio(int atk_r, int def_r, int money_r, int health_r) :
                atk_ratio(atk_r),
                def_ratio(def_r),
                money_ratio(money_r),
                health_ratio(health_r) {};

    };


    //����
public:
    string label;                           //Monster��ѧ����
    int attack_ability;             //��������
    int defence_ability;           //����ֵ��
    int money_remaining;           //�����Ǯ��
    int health;                    //��������ֵ��


    //����
public:
    /**
     * ���캯������Ҫ����һ�����Ѷȵ����ࡿ��
     *
     * ��������Ϊ������Ϊ��ʹBaseMonster��Ϊ�����࣬��Ϊ�˱��⣬ֱ�Ӵ���BaseMonsterʵ����
     */
    BaseMonster(string t_label, Hardness_Ratio ratio_obj) {

        this->label = t_label;

        attack_ability *= ratio_obj.atk_ratio;
        defence_ability *= ratio_obj.def_ratio;
        money_remaining *= ratio_obj.money_ratio;
        health *= ratio_obj.health_ratio;
    };

    //BaseMonster() {};     //��ʵ�����Ļ����ͻ���⡣��ʵ����д�޲ι��죬�ǲ���Ҫд������޲ι���ġ����ø�����вι���ͺá�


    virtual void makeItVirtual() {};           //�����ǰ�BaseMonster������Ϊһ�������ࡣmakeItVirtual����û�б������<>

};











//
//
//ͷ�ļ�������
#endif //CPP_PROJECTS_CLASS_DECLARATION_H
