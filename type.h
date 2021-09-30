



// (f) モンスター
typedef struct MONSTER {
  char* name;
  Element element;
  int maxhp;
  int hp;
  int attack;
  int defense;
} Monster;

// (g)ダンジョン
typedef struct DUNGEON {
  Monster* monsters;
  const int numMonsters;
} Dungeon;

// (h)パーティ
typedef struct PARTY {
  char*       playerName;   // HINT: プレイヤー名を格納するメンバ
  Monster*    monsters;     // HINT: 味方モンスター配列の先頭アドレスを格納するメンバ
  const int   monsterNum;   // HINT: 味方モンスター数を格納するメンバ
  const int   maxHp;        // HINT: 最大HP（不変）を格納するメンバ
  int         hp;           // HINT: HPを格納するメンバ
  int         defense;      // HINT: 防御力（不変）を格納するメンバ
} Party;