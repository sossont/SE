#include <stdio.h>

class PurchasedProduct{
private:
    int productId;
    int score;
public:
    PurchasedProduct() = default;
    PurchasedProduct(int id);
    bool isPurchased();
    bool isRate();
    int getPurchasedProduct();
    void setProductId(int productId);
    void setScore(int score);
    int getProductId();
};
