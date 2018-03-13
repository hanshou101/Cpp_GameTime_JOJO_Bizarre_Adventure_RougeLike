#include "_class_declaration_father.h"
#include "_class_implementation_son.h"

#include <iostream>
#include <vector>

using namespace std;


//vector<BaseShop::Item> Drug_Shop::goods = {
//        BaseShop::Item(0, "ʲô������", 0, 0),
//        BaseShop::Item(1, "1�Ų�Ѫҩ", 10, 200),
//        BaseShop::Item(2, "2�Ų�Ѫҩ", 50, 1200),
//        BaseShop::Item(3, "3�Ų�Ѫҩ", 100, 2500),
//        BaseShop::Item(4, "�뿪ҩƷ��", 0, 0),
//
//};


void Drug_Shop::updateStatus() {
    /**
    * ׼����ʼֵ��
    */
    cur_choice = 0;

}

bool Drug_Shop::checkAlive_orCompleted() {
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

void Drug_Shop::describe_scene() {

    /**
     * �Ƚ��У��̵�����ҽ��ܡ����ṩ�ĸ�������ѡ����ܡ�
     */

    cout << "��ӭ����ҩƷ�꣡\n" << endl;
    for (int i = 1; i < goods.size(); ++i) {
        printf("%d����%s��%dG��%d��������ֵ��", goods[i].index, goods[i].label.c_str(), goods[i].price, goods[i].power);
        printf("\n");
    };


}

bool Drug_Shop::continue_switch_action() {
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


    //ѡ����ҩƷ����
    if (goods[cur_choice].power > 0) {
        //ҩƷ�ࡣ������������ֵ��
        hero->buyItem(BaseHero::Buy_Shop_Type::Buy_In_Drug_Shop,
                      BaseHero::Buy_Item_Type::item_health,
                      goods[cur_choice]
        );
    }
        //ѡ����������
    else if (goods[cur_choice].power == 0) {

        //ʲô������ѡ�
        cout << "��ѡ����ʲô������ѡ��" << "��" << "�����ҽ�Ϊ�㽲һ�����£�ɽ��������" << endl;

    };

    return true;
}
