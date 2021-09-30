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