#include "_class_declaration_father.h"
#include "_class_implementation_son.h"

#include <iostream>
#include <vector>

using namespace std;



void LeadingHero::buyItem(BaseHero::Buy_Shop_Type shop_type,
                          BaseHero::Buy_Item_Type item_category,
                          BaseShop::Item good) {

    //先分支——购物商店的类型。【武器店】【药品店】。
    switch (shop_type) {

        //【武器店】
        case BaseHero::Buy_Shop_Type::Buy_In_Weapon_Shop: {

            //再分支——武器店内商品的具体类型。【武器】【盔甲】。
            switch (item_category) {


                //【武器】
                case BaseHero::Buy_Item_Type::item_atk: {

                    //判断当前金钱是否足够

                    if (good.price <= this->money) {
                        //金钱足够，可以进行购买【武器】
                        this->money -= good.price;           //消耗金钱。
                        this->attack_ability += good.power;        //增加攻击力。

                        printf("已购买%s，攻击力增加%d。当前攻击为%d。当前背包还剩%dG金钱。",
                               good.label.c_str(), good.power, this->attack_ability, this->money);

                    } else {
                        //金钱不够，不能进行购买【武器】
                        printf("购买的金钱不够。%s需要%dG，当前背包仅剩%dG。请继续努力，攒够钱再回来。", good.label.c_str(), good.price, this->money);
                    };
                    break;
                }

                    //【盔甲】
                case BaseHero::Buy_Item_Type::item_def: {

                    //判断当前金钱是否足够

                    if (good.price <= this->money) {
                        //金钱足够，可以进行购买【盔甲】
                        this->money -= good.price;           //消耗金钱。
                        this->defence_ability += (0 - good.power);        //增加防御力。（防御力是用负值表示的。所以取反。）

                        printf("已购买%s，防御力增加%d。当前防御为%d。当前背包还剩%dG金钱。",
                               good.label.c_str(), (0 - good.power), this->defence_ability, this->money);
                    } else {
                        //金钱不够，不能进行购买【盔甲】
                        printf("购买的金钱不够。%s需要%dG，当前背包仅剩%dG。请继续努力，攒够钱再回来。", good.label.c_str(), good.price, this->money);
                    };

                    break;
                }

            }

            break;
        }

            //【药品店】
        case BaseHero::Buy_Shop_Type::Buy_In_Drug_Shop: {

            //再分支——药品店内商品的具体类型。【小】【中】【大】
            switch (item_category) {
                case BaseHero::Buy_Item_Type::item_health: {
                    //【药品】


                    //判断当前金钱是否足够
                    if (good.price <= this->money) {
                        //金钱足够，可以进行购买【药品】
                        this->money -= good.price;           //消耗金钱。
                        this->health += good.power;          //增加生命健康值。

                        printf("已购买%s，生命值增加%d。当前生命为%d。当前背包还剩%dG金钱。",
                               good.label.c_str(), good.power, this->health, this->money);

                    } else {
                        //金钱不够，不能进行购买【药品】
                        printf("购买的金钱不够。%s需要%dG，当前背包仅剩%dG。请继续努力，攒够钱再回来。", good.label.c_str(), good.price, this->money);
                    };

                    break;
                }

            }

            break;
        }

    }

}
