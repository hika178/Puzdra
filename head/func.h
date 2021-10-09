#include "stdio.h"  // printf用
#include "const.h"  // 定義ヘッダー
#include "prot.h"   // プロトタイプ宣言ヘッダー



int goDungeon(Party* pParty, Dungeon* pDungeon)
{
  int winCount = 0;
    for(int i = 0; i < pDungeon->numMonsters; i++)
    {

        winCount += doBattle(pParty, &(pDungeon->monsters[i]));

        printf("%sはさらに奥へと進んだ\n",pParty->playerName);
    
    }

  printf("%sはダンジョンを制覇した！\n", pParty->playerName);
  return winCount;
}

int doBattle(Party* pParty, Monster* pEnemy)
{
    printMonsterName(pEnemy);

    printf("が現れた！\n");

    while(pParty->hp > 0 || pEnemy->hp > 0)
    {
        
        onPlayerTurn(pParty,pEnemy);
        
        if(pEnemy->hp <= 0)
        {
            break;
        }

        onEnemyTurn(pParty,pEnemy);

        if(pParty->hp <=0)
        {
            break;
        }

    }

    printMonsterName(pEnemy);

    printf("を倒した！\n");

    return 0;
}

Party organizeParty(char* playerName, Monster* monsters,int monsterNum )
{
  int hp = 0;
  int deffense = 0;

  for (int i = 0;i < monsterNum; i++){
    hp += monsters[i].hp;
    deffense += monsters[i].defense;
  }
  int avg = deffense / monsterNum;
  Party party = {
    playerName,
    monsters,
    monsterNum,
    hp,
    hp,
    avg
  };

  return party;
}

void onPlayerTurn(Party * pParty, Monster* pEnemy)
{
    printf("【%sのターン】\n",pParty->playerName);

    doAttack(pEnemy);
}

void doAttack(Monster* pEnemy)
{
    pEnemy->hp -= 80;

    printf("ダミー攻撃で80のダメージを与えた\n");
}

void onEnemyTurn(Party * pParty, Monster* pEnemy)
{
    printf("【%sのターン】\n",pEnemy->name);

    doEnemyAttack(pParty); 
}

void doEnemyAttack(Party* pParty)
{
    pParty->hp -= 20;

    printf("20のダメージを受けた\n");
}

void showParty(Party* pParty)
{
  printf("＜パーティ編成＞----------\n");
  for(int i = 0;i < pParty->monsterNum;i++)
    {
      printMonsterName(&(pParty->monsters[i]));

      printf("HP=%4d\n 攻撃=%3d\n 防御=%3d\n",

      pParty->monsters[i].hp,

      pParty->monsters[i].attack,

      pParty->monsters[i].defense);
    }
    
  printf("------------------------\n\n");
}

void printMonsterName(Monster* pMonster)
{
  char symbol = ELEMENT_SYMBOLS[pMonster->element];

  printf("\x1b[3%dm", ELEMENT_COLORS[pMonster->element]);
  printf("%c%s%c", symbol, pMonster->name, symbol);
  printf("\x1b[0m");
}

// 現在のバトルフィールドの状況を画面に映す関数
void showBattleField(BattleField* pBF)
{
  printf("------------------------------\n\n");
  printf("          ");
  printMonsterName(pBF->bfEnemy->name);
  printf("\n       HP= %4d / %4d\n", pBF->bfEnemy->hp, pBF->bfEnemy->maxhp);
  printf("\n\n");
  for(int i = 0; i < pBF->bfParty->monsterNum; i++) {
    printMonsterName(&(pBF->bfParty->monsters[i]));
    printf("  ");
  }
  printf("\n");
  printf("       HP= %4d / %4d\n", pBF->bfParty->hp, pBF->bfParty->maxHp);
  printf("------------------------------\n");
  printf(" ");
  for(int i = 0; i < MAX_GEMS; i++ ){
    printf("%c ", 'A'+i);
  }
  printf("\n");
  printGems(pBF->bfGems);
  printf("------------------------------\n");
}

// 宝石をランダムに発生させる関数
void fillGems(Element* bfGems)
{
  int i;
  for (i=0;i<MAX_GEMS;i++)
  {
    bfGems[i] = rand() % EMPTY;
  }
}

// 宝石一個分を画面に表示する
void printGem(Element e)
{
  printf("\x1b[30m");       // 黒文字
  printf("\x1b[4%dm", ELEMENT_COLORS[e]); // 属性色背景
  printf("%c", ELEMENT_SYMBOLS[e]);
  printf("\x1b[0m");        // 色指定解除
}

// 宝石14個を画面に表示する
void printGems(Element* pGems)
{
  int i=0;
  for (i;i<MAX_GEMS;i++)
  {
    printGem(pGems);
  }
}