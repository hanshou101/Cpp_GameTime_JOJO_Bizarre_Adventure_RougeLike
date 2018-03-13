#include "_class_declaration_father.h"
#include "_class_implementation_son.h"

#include <iostream>
#include <vector>

using namespace std;



void LeadingHero::buyItem(BaseHero::Buy_Shop_Type shop_type,
                          BaseHero::Buy_Item_Type item_category,
                          BaseShop::Item good) {

    //�ȷ�֧���������̵�����͡��������꡿��ҩƷ�꡿��
    switch (shop_type) {

        //�������꡿
        case BaseHero::Buy_Shop_Type::Buy_In_Weapon_Shop: {

            //�ٷ�֧��������������Ʒ�ľ������͡��������������ס���
            switch (item_category) {


                //��������
                case BaseHero::Buy_Item_Type::item_atk: {

                    //�жϵ�ǰ��Ǯ�Ƿ��㹻

                    if (good.price <= this->money) {
                        //��Ǯ�㹻�����Խ��й���������
                        this->money -= good.price;           //���Ľ�Ǯ��
                        this->attack_ability += good.power;        //���ӹ�������

                        printf("�ѹ���%s������������%d����ǰ����Ϊ%d����ǰ������ʣ%dG��Ǯ��",
                               good.label.c_str(), good.power, this->attack_ability, this->money);

                    } else {
                        //��Ǯ���������ܽ��й���������
                        printf("����Ľ�Ǯ������%s��Ҫ%dG����ǰ������ʣ%dG�������Ŭ�����ܹ�Ǯ�ٻ�����", good.label.c_str(), good.price, this->money);
                    };
                    break;
                }

                    //�����ס�
                case BaseHero::Buy_Item_Type::item_def: {

                    //�жϵ�ǰ��Ǯ�Ƿ��㹻

                    if (good.price <= this->money) {
                        //��Ǯ�㹻�����Խ��й��򡾿��ס�
                        this->money -= good.price;           //���Ľ�Ǯ��
                        this->defence_ability += (0 - good.power);        //���ӷ������������������ø�ֵ��ʾ�ġ�����ȡ������

                        printf("�ѹ���%s������������%d����ǰ����Ϊ%d����ǰ������ʣ%dG��Ǯ��",
                               good.label.c_str(), (0 - good.power), this->defence_ability, this->money);
                    } else {
                        //��Ǯ���������ܽ��й��򡾿��ס�
                        printf("����Ľ�Ǯ������%s��Ҫ%dG����ǰ������ʣ%dG�������Ŭ�����ܹ�Ǯ�ٻ�����", good.label.c_str(), good.price, this->money);
                    };

                    break;
                }

            }

            break;
        }

            //��ҩƷ�꡿
        case BaseHero::Buy_Shop_Type::Buy_In_Drug_Shop: {

            //�ٷ�֧����ҩƷ������Ʒ�ľ������͡���С�����С�����
            switch (item_category) {
                case BaseHero::Buy_Item_Type::item_health: {
                    //��ҩƷ��


                    //�жϵ�ǰ��Ǯ�Ƿ��㹻
                    if (good.price <= this->money) {
                        //��Ǯ�㹻�����Խ��й���ҩƷ��
                        this->money -= good.price;           //���Ľ�Ǯ��
                        this->health += good.power;          //������������ֵ��

                        printf("�ѹ���%s������ֵ����%d����ǰ����Ϊ%d����ǰ������ʣ%dG��Ǯ��",
                               good.label.c_str(), good.power, this->health, this->money);

                    } else {
                        //��Ǯ���������ܽ��й���ҩƷ��
                        printf("����Ľ�Ǯ������%s��Ҫ%dG����ǰ������ʣ%dG�������Ŭ�����ܹ�Ǯ�ٻ�����", good.label.c_str(), good.price, this->money);
                    };

                    break;
                }

            }

            break;
        }

    }

}
