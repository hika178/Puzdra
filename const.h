

// (a)属性
typedef enum Element {FIRE, WATER, WIND, EARTH, LIFE, EMPTY} Element;

// (b)属性別の記号
const char ELEMENT_SYMBOLS[EMPTY+1] = {'$','~','@','#','&', ' '};

// (c)属性別のカラーコード（ディスプレイ制御シーケンス用）
const char ELEMENT_COLORS[EMPTY+1] = {1,6,2,3,5,0};

