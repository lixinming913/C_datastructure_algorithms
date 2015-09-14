/*洗牌算法，保证每张牌都是随机取得*/

void shuffle(int cards[], int n)
{
    if(cards == NULL)
        return;
        
    srand(time(0)); // 设置种子，才能产生随机数
    for(int i = 0; i < n-1; ++i) {
        /*保证每次第i位的值不会涉及到第i位以前*/
        int index = i + rand() % (n-i);//产生i 到n - i之间的随机数
        int temp = cards[i];
        cards[i]  = cards[index];
        cards[index] = temp;
    }

}