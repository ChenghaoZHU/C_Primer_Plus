#include <stdio.h>
#define PRICE_ARTICHOKE 2.05
#define PRICE_BEET 1.15
#define PRICE_CARROT 1.09
#define MIN_DISCOUNT 100.0
#define DISCOUNT_RATE 0.05
#define WEIGHT_BREAK1 5
#define WEIGHT_BREAK2 20
#define PACK_FEE1 6.5
#define PACK_FEE2 14
#define RATE 0.5

int main(void)
{
    char type;
    float price, weight;
    float pack_fee, final_price;
    float a_price, b_price, c_price, total_price, discount;
    float a_weight, b_weight, c_weight, total_weight;
    total_weight = a_weight = b_weight = c_weight = 0.0;
    discount = total_price = a_price = b_price = c_price = 0.0;
    pack_fee = final_price = 0.0;

    printf("What would you like?\n");
    printf("a for artichoke, b for beet, c for carrot, q to quit\n");
    while ((scanf("%c", &type) == 1) && type != 'q')
    {
        if (type == '\n')
            continue;
        if (type != 'a' && type != 'b' && type != 'c')
        {
            printf("Only a b c q are valid option.\n");
            continue;
        }
        printf("Enter how much you want: ");
        scanf("%f", &weight);
        switch (type)
        {
            case 'a': a_weight += weight; break;
            case 'b': b_weight += weight; break;
            case 'c': c_weight += weight; break;
            default: break;
        }
        printf("What would still you like?\n");
        printf("a for artichoke, b for beet, c for carrot, q to quit\n");
    }
    printf("You buy %.2f pounds of artichokes, %.2f pounds of beets and %.2f pounds of carrots\n", a_weight, b_weight, c_weight);
    printf("The prices are:\n");
    printf("artichoke: %.2f dpp, beet: %.2f dpp, carrot: %.2f dpp\n", PRICE_ARTICHOKE, PRICE_BEET, PRICE_CARROT);
    a_price = PRICE_ARTICHOKE * a_weight;
    b_price = PRICE_BEET * b_weight;
    c_price = PRICE_CARROT * c_weight;
    printf("You should pay $%.2f for artichokes, $%.2f for beets and $%.2f for carrots.\n", a_price, b_price, c_price);
    total_price = a_price + b_price + c_price;
    printf("So total price for veges is $%.2f.\n", total_price);

    if (total_price >= MIN_DISCOUNT)
    {
        discount = DISCOUNT_RATE * total_price;
        printf("You can get $%.2f discount.", discount);
    }
    total_weight = a_weight + b_weight + c_weight;
    if (total_weight <= 0)
    {
    }
    else if (total_weight <= WEIGHT_BREAK1)
    {
        pack_fee = PACK_FEE1;
    }
    else if (total_weight <= WEIGHT_BREAK2)
    {
        pack_fee = PACK_FEE2;
    }
    else
    {
        pack_fee = PACK_FEE2 + (total_weight - WEIGHT_BREAK2) * RATE;
    }
    printf("The pack fee is $%.2f\n", pack_fee);

    final_price = total_price - discount + pack_fee;
    printf("The final total fee is $%.2f\n", final_price);

    return 0;
}