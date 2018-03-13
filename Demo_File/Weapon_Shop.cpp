#include "_class_declaration_father.h"
#include "_class_implementation_son.h"

#include <iostream>
#include <vector>

using namespace std;


/**
    * ����������������
    * ������������ߡ�
    */
//vector<BaseShop::Item> Weapon_Shop::goods = {
//        BaseShop::Item(0, "ʲô������", 0, 0),
//        BaseShop::Item(1, "С��", 10, 2),
//        BaseShop::Item(2, "�̽�", 80, 20),
//        BaseShop::Item(3, "�󿳵�", 140, 40),
//        BaseShop::Item(4, "˫�ڹ�", 200, 60),
//        BaseShop::Item(5, "����", 60, -30),
//        BaseShop::Item(6, "����", 100, -60),
//        BaseShop::Item(7, "�뿪������", 0, 0),
//};


void Weapon_Shop::updateStatus() {

    /**
    * ׼����ʼֵ��
    */
    cur_choice = 0;

}

bool Weapon_Shop::checkAlive_orCompleted() {
    LeadingHero *hero = (LeadingHero *) (ManagerConst().heroList[0]);

    /**
     * ���Ӣ�۵Ļ���״̬�������߹���״̬��
     */
    if (0 >= hero->health)                       //����������С�ڵ���0ʱ��Ϸ����
    {
        cout << "Ӣ������ֵ���㣬�Ѿ����������ٻأ�" << endl;
        return false;
    }


    if (hero->attack_ability > 9999) {                                //�����˹��ص�����������Ϸ�Զ�����
        cout << "���Դ���ս����ס�" << endl;
        cout << "��ϲ�㣬������ռ��������ڹ����ˣ�" << endl;
        return false;
    }

    return true;
}

void Weapon_Shop::describe_scene() {


    /**
     * �Ƚ��У��̵�����ҽ��ܡ����ṩ�ĸ�������ѡ����ܡ�
     */

    cout << "��ӭ���������꣡\n" << endl;
    for (int i = 1; i < goods.size(); ++i) {
        if (goods[i].power > 0) {
            //cout << goods[i].index << "����" << goods[i].label << "��" << goods[i].price << "G��" << goods[i].power
            //     << "��������" << endl;
            printf("%d����%s��%dG��%d��������", goods[i].index, goods[i].label.c_str(), goods[i].price, goods[i].power);
        }
        if (goods[i].power < 0) {
            //cout << goods[i].index << "����" << goods[i].label << "��" << goods[i].price << "G��" << goods[i].power
            //     << "��������" << endl;
            printf("%d����%s��%dG��%d��������", goods[i].index, goods[i].label.c_str(), goods[i].price, (0 - goods[i].power));
        }
        if (goods[i].power == 0) {
            //cout << goods[i].index << "��" << goods[i].label << endl;
            printf("%d��%s", goods[i].index, goods[i].label.c_str());
        }
        printf("\n");
    };

}


bool Weapon_Shop::continue_switch_action() {
    LeadingHero *hero = ((LeadingHero *) (ManagerConst().heroList[0]));     //ȡ����ǰӢ�۵�ָ�롣


    /**
     * �ȴ��û�����ѡ�����
     *
     * ��ͨ��return��ʽ������false��whole_logic��Ȼ��whole_logic,��Ϊ�յ�false��������whole_logic��return��֧�����������ѭ�����͵����뿪�������ꡣ
     */


    cin >> cur_choice;

    //�ж�choice��ֵ��

    if (cur_choice == goods.size() - 1) {
        return false;              //ѡ�������һ��ѡ��Ļ������˳���ǰ������Ľ��档�ص����Ĺ㳡��
    };


    //ѡ������������
    if (goods[cur_choice].power > 0) {

        //�����ࡣ���ӹ�������

        hero->buyItem(BaseHero::Buy_Shop_Type::Buy_In_Weapon_Shop,
                      BaseHero::Buy_Item_Type::item_atk,
                      goods[cur_choice]
        );


    }
        //ѡ���˿��׹���
    else if (goods[cur_choice].power < 0) {

        //�����ࡣ���ӷ�������

        hero->buyItem(BaseHero::Buy_Shop_Type::Buy_In_Weapon_Shop,
                      BaseHero::Buy_Item_Type::item_def,
                      goods[cur_choice]
        );

    }
        //ѡ����������
    else if (goods[cur_choice].power == 0) {

        //ʲô������ѡ�
        cout << "��ѡ����ʲô������ѡ��" << "��" << "�����ҽ�Ϊ�㽲һ�����£���ǰ����ɽ" << endl;

    };

    return true;

}
